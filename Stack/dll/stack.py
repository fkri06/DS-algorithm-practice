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
        pass 
    
    def pop(self) -> int:
        pass 
    
    def peek(self) -> int:
        pass
