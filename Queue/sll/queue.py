# Queue implementation using singly linked list.
# Basic stacks operation:
#   - Enqueue  : add element onto the queue.
#   - Dequeue   : remove an element from the queue.
#   - Peek : return the front of a queue's value withuot removing the value.

class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    def enqueue(self, value: int):
        new_node = Node(value)
        if self.front == None:
            self.front = self.rear = new_node
            return
        self.rear.next = new_node
        self.rear = new_node

    def dequeue(self):
        if self.front == None:
            raise IndexError("Dequeue from an empty queue")
        value_to_pop = self.front
        self.front = value_to_pop.next # fix the link
        return value_to_pop.data # return the value

    def peek(self) -> int:
        if self.front == None:
            raise IndexError("Peek from an empty queue")
        return self.front.data
