fptr = open('emojitis.txt', 'r', encoding='utf-8')

emojis = fptr.read()
emoji_list = emojis.split(' ') 

binary_list = []
for emoji in emoji_list:
    binary_list.append(emoji.replace('😴', '0').replace('😀', '1'))

for binary in binary_list:
    char = chr(int(binary, 2))
    print(char, end='')

print('')
