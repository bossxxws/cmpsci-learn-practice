import heapq

def dijkstra(adj_matrix, start_node):
    n = len(adj_matrix)
    INF = float('inf')

    dist = [INF] * n
    paths = [None for _ in range(n)]
    dist[start_node] = 0
    paths[start_node] = [start_node]

    min_heap = [(0, start_node)]

    while min_heap:
        curr_dist, curr_node = heapq.heappop(min_heap)
        for neighbor in range(n):
            if adj_matrix[curr_node][neighbor] > 0:
                new_dist = curr_dist + adj_matrix[curr_node][neighbor]
                if new_dist < dist[neighbor]:
                    dist[neighbor] = new_dist
                    paths[neighbor] = paths[curr_node] + [neighbor]
                    heapq.heappush(min_heap, (new_dist, neighbor))
    for i in range(n):
        if dist[i] == INF:
            dist[i] = float('inf')

    return dist, paths


# adj_matrix = [
#     [0, 3, 8, 0, 0],
#     [2, 0, 0, 2, 0],
#     [0, 1, 0, 7, 2],
#     [0, 3, 2, 0, 5],
#     [0, 0, 0, 0, 0]
# ]

# start_node = 0
# distances, shortest_paths = dijkstra(adj_matrix, start_node)
# print("Shortest distances from node", start_node, "to all nodes:", distances)
# print("Shortest paths from node", start_node, "to all nodes:", shortest_paths)
