# Queue implementation using doubly linked list.
# Basic stacks operation:
#   - Enqueue  : add element onto the queue.
#   - Dequeue   : remove an element from the queue.
#   - Peek : return the front of a queue's value withuot removing the value.

class Node:
    def __init__(self, data = None):
        self.data = data
        self.prev = None
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
        new_node.next = self.front
        self.front.prev = new_node
        self.front = new_node

    def dequeue(self):
        if self.rear == None:
            raise IndexError("Dequeue an empty queue")
        node_to_dequeue = self.rear
        # fix the rear's link
        self.rear = node_to_dequeue.prev
        self.rear.next = None
        return node_to_dequeue.data

    def peek(self):
        if self.rear != None:
            return self.rear.data
 
