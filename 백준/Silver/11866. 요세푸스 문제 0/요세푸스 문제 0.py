k,n=map(int, input().split())

class Node:
    def __init__(self):
        self.data=None
        self.next=None

tail = None
for i in reversed(range(k)):
    node = Node()
    node.data = i+1
    if(tail == None):
        tail = node
        node.next = node
    else:
        node.next=tail.next
        tail.next=node

josephus = []
cur = tail
pre = None
for i in range(0, k):
    for j in range(0, n):
        pre = cur
        cur = cur.next
    pre.next = cur.next
    josephus.append(cur.data)
print("<" + ", ".join(str(x) for x in josephus) + ">")