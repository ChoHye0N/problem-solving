def word_counter(words):
    word_dict = {}
    for word in words:
        if word in word_dict:
            word_dict[word] += 1
        else:
            word_dict[word] = 1
    return word_dict


n = int(input())
same_word_count = 0

w_first = word_counter(input())

for _ in range(n-1):
    w_input = word_counter(input())

    if sum(w_first.values()) > sum(w_input.values()):
        w1 = w_first
        w2 = w_input
    else:
        w1 = w_input
        w2 = w_first

    left_words = word_counter(w2)

    for word, count in w1.items():
        if word in w2:
            left_words[word] = abs(w2.get(word) - count)
        else:
            left_words[word] = count

    if sum(left_words.values()) <= 2 and sum(w1.values()) - sum(w2.values()) < 2:
        same_word_count += 1
print(same_word_count)