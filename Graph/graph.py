# Undirected and Unweighted Graph implementation using adjacency list.

class Graph:
    def __init__(self, value = None):
        self.value = value
        self.adjacency_vertices = []

    def add_adjecency_vertex(self, vertex):
        if vertex in self.adjacency_vertices:
            return
        self.adjacency_vertices.append(vertex)
        vertex.adjacency_vertices.append(self)

    def dfs_traversal(self, starting_vertex, visited_vertices = {}):
        visited_vertices[starting_vertex.value] = True
        print(starting_vertex.value)
        for vertex in starting_vertex.adjacency_vertices:
            if visited_vertices.get(vertex.value):
                continue
            self.dfs_traversal(vertex, visited_vertices)

    def bfs_traversal(self, starting_vertex):
        visited_vertices = {}
        visited_vertices[starting_vertex.value] = True
        queue = [starting_vertex]
        print("BFS TRAVERSAL")
        while queue:
            current_vertex = queue.pop(0)
            print(current_vertex.value)
            
            for vertex in current_vertex.adjacency_vertices:
                if not visited_vertices.get(vertex.value):
                    visited_vertices[vertex.value] = True
                    queue.append(vertex)

