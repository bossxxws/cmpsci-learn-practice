def induced(adj_list, node_list):
    subgraph = {}
    
    for node in node_list:
        if node in adj_list:
            subgraph[node] = [neighbor for neighbor in adj_list[node] if neighbor in node_list]
    
    return subgraph
