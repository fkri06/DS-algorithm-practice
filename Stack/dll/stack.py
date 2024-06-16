# 
# Stack implementation using doubly linked list.
# Basic stacks operation:
#
#   - Push  : add data at the front of a list.
#   - Pop   : remove and return the value at the end of a list.
#   - Top/peek : return the front of a stack's value withuot removing the value.
#
# In this program we use tail as the front of the stack.
#

class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None
        self.prev = None

class Stack:
    def __init__(self):
        self.head = None
        self.tail = None

    def push(self, value: int):
        new_node = Node(value)
        if self.tail == None:
            self.head = self.tail = new_node
            return
        new_node.prev = self.tail
        self.tail.next = new_node
        self.tail = new_node
    
    def pop(self):
        if self.tail == None:
            return
        node_to_pop = self.tail
        self.tail = node_to_pop.prev
        self.tail.next = None
        return node_to_pop.data
    
    def peek(self):
        if self.tail != None:
            return self.tail.data

