# Stack implementation using singly linked list.
# Basic stacks operation:
#   - Push  : add data at the front of a list.
#   - Pop   : remove and return the value at the end of a list.
#   - Top/peek : return the front of a stack's value withuot removing the value.

class Node:
    def __init__(self. data = None):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.front = None

    def push(self, value: int):
        new_node = Node(value)
        new_node.next = self.front
        self.front = new_node

    def pop(self) -> int:
        if self.front == None:
            return -1
        node_to_pop = self.front
        self.front = node_to_pop.next # fix the link
        return node_to_pop.data

    def peek(self) -> int:
        if self.front == None:
            return -1
        return self.front.data

