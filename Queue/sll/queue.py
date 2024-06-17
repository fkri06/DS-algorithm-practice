# Queue implementation using singly linked list.
# Basic stacks operation:
#   - Enqueue  : add element onto the queue.
#   - Dequeue   : remove an element from the queue.
#   - Peek : return the front of a queue's value withuot removing the value.

class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.front = None
        self.rear = None

    def enqueue(self, value: int):
        pass 
    def dequeue(self):
        pass
    def peek(self) -> int:
        pass
