struct Trie {
    struct Node {
        char ch;
        int is_ending;
        int cnt;                    // Telling number of children of this Node
        Node* ptr[26];

        Node(char c = '\0') : ch(c), is_ending(false), cnt(0) {
            for (int i = 0; i < 26; i++) {
                ptr[i] = nullptr;
            }
        }
    };

    Node* root_ = new Node();
    Trie() {}

    void insert(string s) {
        Node* temp = root_;
        for(char &ch : s) {
            int x = ch - 'a';
            if(temp->ptr[x] == nullptr) {
                temp->ptr[x] = new Node(ch);
                temp->cnt++;
            }
            temp = temp->ptr[x];
        }
        temp->is_ending++;
    }

    bool find(string s) {
        Node* temp = root_;
        for(char &ch : s) {
            int x = ch - 'a';
            if(temp->ptr[x] == nullptr) {
                return false;
            }
            temp = temp->ptr[x];
        }
        return temp->is_ending;
    }

    bool deleter(Node* temp, string s, int level, int len) {
        if(level == len) {
            if(temp->cnt > 0) {
                temp->is_ending--;
                return false;
            } else {
                return true;
            }
        } else {
            int x = s[level] - 'a';
            if(deleter(temp->ptr[x], s, level+1, len)) {
                free(temp->ptr[x]);
                temp->ptr[x] = nullptr;
                temp->cnt--;
            }
            return (!temp->is_ending && temp->cnt == 0);
        }
    }

    void erase(string s) {
        if(!find(s)) {
            return;
        }
        Node* temp = root_;
        deleter(temp, s, 0, s.size());
    }

    void clear(Node* temp) {
        if(temp == nullptr) {
            return;
        }
        for(int i = 0; i < 26; i++) {
            clear(temp->ptr[i]);
        }
        delete(temp);
    }

    void clear() {
        clear(root_);
        root_ = new Node();
    }
};
