# Heap implementation using doubly linked list.
# Basic Heap operation:
#	- Insert -> insert an element to a heap. Insertion
#         in a Heap always start from the bottom/end of list/array.
#
#	- Remove -> remove the root element from a heap. Deletion
#         in a Heap always delete the root node, and then from there
#         fix the heap arrangements.
#

class Heap:
    def __init__(self):
        self.data = []
        self.length = 0
    
    def find_parent(self, index: int):
        return (index - 1) // 2

    def find_left_child(self, index: int):
        pass

    def find_right_child(self, index: int):
        pass

    def heap_up(self, index: int):
        parent_index = self.find_parent(index)
        if self.length == 0:
            return

        parent_value = self.data[parent_index]
        value = self.data[index]

        if parent_value < value:
            self.data[index], self.data[parent_index] = parent_value, value
            self.heap_up(parent_index)

    def heap_down(self, index: int):
        pass

    def insert(self, value: int):
        self.data.append(value)
        self.heap_up(self.length)
        self.length += 1

    def remove(self):
        pass

