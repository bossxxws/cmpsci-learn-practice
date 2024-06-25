def reverse(adj_matrix):

    reversed_matrix = {vertex: [] for vertex in adj_matrix}
    
    for vertex, neighbors in adj_matrix.items():
        for neighbor in neighbors:
            reversed_matrix[neighbor].append(vertex)
    
    return reversed_matrix
