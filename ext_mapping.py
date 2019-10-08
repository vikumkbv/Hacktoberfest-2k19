
# Input text needs to be preprocessed and in string format.

import logging, numpy as np

class seq_map:

    def __init__(self, word_index, index_word):
        self.word_index = None
        self.index_word = None

    def build_vocab(self, text):
        logging.basicConfig(level=logging.INFO)
        logging.info('Building vocabulary.')

        var_ = {}
        var_['UNK'] = 0

        for n, word in enumerate(text.split()):
            n += 1
            if word not in var_:
                var_[word] = n

        self.word_index = var_

        var_ = {}

        for key, value in self.word_index:
            var_[value] = key

        self.index_word = var_

    def transform(self, text, max_len):

        'max_len :Max length for text sequence'

        logging.basicConfig(level=logging.INFO)
        logging.info('Transforming text to sequence.')

        array_seq = np.zeros((max_len,), dtype=int)

        for n, word in enumerate(text.split()):

            if n == max_len:
                logging.basicConfig(level=logging.INFO)
                logging.info('Length of text over max limit.')
                return array_seq

            if word in self.word_index:
                array_seq[n] = self.word_index[word]

        return array_seq
