class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None
        self.prev = None

class DLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def prepend(self, value: int):
        new_node = Node(value)
        self.length += 1
        if self.head == None:
            self.head = new_node
            self.tail = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    def append(self, value: int):
        new_node = Node(value)
        self.length += 1
        if self.tail == None:
            self.head = new_node
            self.tail = new_node
            return

        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node

    def remove_head(self):
        if self.head == None or self.tail == None:
            print("-=-=-=-=- Trying to remove an empty list -=-=-=-=-")
            return

        if self.length == 1:
            self.length -= 1
            self.head = self.tail = None
            return

        self.length -= 1
        node_to_delete = self.head
        self.head = node_to_delete.next
        self.head.prev = None
        node_to_delete = None

    def remove_tail(self):
        if self.head == None or self.tail == None:
            print("-=-=-=-=- Trying to remove an empty list -=-=-=-=-")
            return

        if self.length == 1:
            self.length -= 1
            self.head = self.tail = None
            return
        
        self.length -= 1
        node_to_delete = self.tail
        self.tail = node_to_delete.prev
        self.tail.next = None
        node_to_delete =  None


    def traverse(self):
        print("--- TRAVERSE LINKED LIST ---")
        node = self.head
        while node != None:
            print(f"{node.data} -> ", end = " ")
            node = node.next

        print("null")

    def traverse_reverse(self):
        print("--- TRAVERSE LINKED LIST IN REVERSE ---")
        node = self.tail
        while node != None:
            print(f"{node.data} -> ", end = " ")
            node = node.prev

        print("null")


# 56 9 77 5 10
node = DLinkedList()
node.prepend(77)
node.append(5)
node.prepend(9)
node.append(10)
node.prepend(56)

node.traverse()
node.remove_tail()
node.traverse()
node.remove_head()
node.traverse()
node.remove_tail()
node.remove_tail()
node.remove_tail()
node.remove_tail()
node.traverse()

