import heapq
from typing import List


class Edge:
    def __init__(self, w, weight):
        self.w = w
        self.weight = weight

    def __lt__(self, other):
        return self.weight < other.weight


def mst_prim(graph, start, v):
    min_heap = []
    heapq.heappush(min_heap, Edge(start, 0))

    visit = [False] * v
    total = 0

    while min_heap:
        curr_edge = heapq.heappop(min_heap)

        if visit[curr_edge.w]:
            continue

        visit[curr_edge.w] = True
        total += curr_edge.weight

        for edge in graph[curr_edge.w]:
            if not visit[edge.w]:
                heapq.heappush(min_heap, edge)

    return total


v_n, e_n = map(int, input().split())
graph: List[List[Edge]] = [[] for _ in range(v_n)]

for i in range(e_n):
    v, w, weight = map(int, input().split())
    graph[v - 1].append(Edge(w - 1, weight))
    graph[w - 1].append(Edge(v - 1, weight))

print(mst_prim(graph, 0, v_n))