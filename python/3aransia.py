# 3aransia is a Latin/Digit Moroccan Language Framework 

import requests

response = requests.get('https://api3aransia.herokuapp.com/translate_moroccan_arabic/ahlen+w+shlen+b7bibna+lkbir')

print(response.text)

# {"moroccan_translation_arabic":[{"arabian_word":"اهـلـُْن","moroccan_word":"ahlen"},{"arabian_word":"و","moroccan_word":"w"},{"arabian_word":"شــلـُْن","moroccan_word":"shlen"},{"arabian_word":"بــحــبــيــبــنـا","moroccan_word":"b7bibna"},{"arabian_word":"لــكــبــيـر","moroccan_word":"lkbir"}]}
