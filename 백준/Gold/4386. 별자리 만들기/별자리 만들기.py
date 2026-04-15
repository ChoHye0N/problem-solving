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


v_n = int(input())
point_list = []
graph: List[List[Edge]] = [[] for _ in range(v_n)]

# 각 별의 좌표 저장
for _ in range(v_n):
    x, y = map(float, input().split())
    point_list.append([x, y])

# 모든 별 사이의 간선 가중치 계산
for i in range(v_n):
    for j in range(i + 1, v_n):
        distance = ((point_list[i][0] - point_list[j][0]) ** 2 +
                    (point_list[i][1] - point_list[j][1]) ** 2) ** 0.5
        graph[i].append(Edge(j, distance))
        graph[j].append(Edge(i, distance))

print(mst_prim(graph, 0, v_n))