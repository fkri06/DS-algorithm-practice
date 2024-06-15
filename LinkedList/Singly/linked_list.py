class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.length = 0

    def insert(self, value: int):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node
        self.length += 1

    def insert_at(self, value: int, index: int):
        if index > self.length or index < 0:
            print("Trying to add value to overlapping index")
            return
        new_node = Node(value)
        self.length += 1
        if index == 0:
            new_node.next = self.head
            self.head = new_node
            return

        node = self.head
        for i in range(index - 1):
            node = node.next

        new_node.next = node.next
        node.next = new_node

    
    def remove(self):
        if self.length <= 0 or self.head == None:
            print("Trying to remove to an empty list")
            return
        node_to_remove = self.head
        self.head = node_to_remove.next
        node_to_remove = None
        self.length -= 1
    
    def remove_at(self, index: int):
        if index > self.length -1 or index < 0:
            print("Trying to remove value to overlapping index")
            return
        
        node = self.head
        self.length -= 1
        if index == 0:
            self.head = node.next
            node = None
            return

        for i in range(index - 1):
            node = node.next

        node_to_delete = node.next
        node.next = node_to_delete.next
        node_to_delete = None

    def traverse(self):
        print("--- TRAVERSE LINKED LIST ---")
        node = self.head
        while node != None:
            print(f"{node.data} -> ", end = " ")
            node = node.next

        print("null")

    def reverse_traverse(self, node: Node):
        if node == None:
            return
        self.reverse_traverse(node.next)
        print(f"{node.data} -> ", end = " ")

    def reversed_recurse(self, node: Node):
        if node == None:
            return
        if node.next == None:
            self.head = node
            return node

        next_node = self.reversed_recurse(node.next)
        next_node.next = node
        node.next = None
        return node
    
    def reversed_iterative(self):
        if self.length <= 1 or self.head == None:
            print("Empty list or list has only one node.")
            return

        prev = None
        current = self.head
        next_node = current.next
        
        while(current.next != None):
            current.next = prev
            prev = current
            current = next_node
            next_node = current.next

        current.next = prev
        self.head = current


node = LinkedList()
node.insert(77)
node.insert(5)
node.insert(9)
node.insert(10)
node.insert(56)

node.traverse()
node.reverse_traverse(node.head)
print()

# node.remove()
# node.remove()

node.insert_at(69, 6)
node.traverse()
print(node.length)

node.remove_at(5)
node.traverse()
print(node.length)

node.reversed_recurse(node.head)
node.traverse()

node.reversed_iterative()
node.traverse()

print(node.length)
