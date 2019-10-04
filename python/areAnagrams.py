# Run `python areAnagrams.py` for a standalone anagram checker.
# Import `check_anagram` function if integrating into another program.


def check_anagram(val_one, val_two):
    val_one = val_one.replace(" ", "")
    val_two = val_two.replace(" ", "")
    for v in val_one:
        try:
            if val_two.index(v) != -1:
                val_two = val_two.replace(v, "", 1)
        except:
            return False
    if val_two != "":
        return False
    else:
        return True
    
def main():
    print("Check if two given words are anagrams of each other. Enter q to exit.")
    
    while True:
        try:
            val_one = input("Enter the first word: ")
            if val_one.lower() == 'q':
                break
            val_two = input("Enter the second word: ")
            if val_two.lower() == 'q':
                break
            
            if check_anagram(val_one, val_two):
                print(val_one + " and " + val_two + " are anagrams of each other!")
            else:
                print(val_one + " and " + val_two + " are not anagrams of each other!")
        except:
            print("Unknown error occured. Terminating program.")
            break
    return 0

if __name__ == '__main__':
    main()
