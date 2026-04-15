words = {}
for i in range(int(input())):
    word = input()
    words[word] = len(word)
sorted_words = sorted(words.items(), key=lambda x: (x[1], x[0]))
for i in sorted_words:
    print(i[0])