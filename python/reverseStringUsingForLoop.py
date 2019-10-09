def reverse_for_loop(s):
    s1 = ''
    for c in s:
        s1 = c + s1  # appending chars in reverse order
    return s1

input_str = 'Hello World!'

if __name__ == "__main__":
    print('Reverse String using for loop =', reverse_for_loop(input_str))