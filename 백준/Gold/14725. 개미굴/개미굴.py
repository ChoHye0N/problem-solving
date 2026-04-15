class TrieNode:
    def __init__(self):
        self.children = {}
        self.height = 0
        self.is_end_of_node = False

def insert(root, words):
    node = root
    height = 1
    for word in words:
        if word not in node.children:
            node.children[word] = TrieNode()
            node.children[word].height = height
        height += 1
        node = node.children[word]
    node.is_end_of_node = True
def print_trie(node, current_word):
    if not node:
        return
    if current_word:
        print(current_word)

    sorted_children = sorted(node.children.items(), key=lambda x: x[0])
    for char, child_node in sorted_children:
        print_trie(child_node, "--"*node.height + char)

root = TrieNode()
n = int(input())
for i in range(n):
    kl = list(input().split())
    kl.pop(0)
    insert(root, kl)
print_trie(root, "")