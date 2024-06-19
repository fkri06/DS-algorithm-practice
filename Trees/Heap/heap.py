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
        return (index * 2) + 1

    def find_right_child(self, index: int):
        return (index * 2) + 2

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
        left_index = self.find_left_child(index)
        right_index = self.find_right_child(index)
        
        if index >= self.length or left_index >= self.length:
            return

        left_value = self.data[left_index]
        right_value = self.data[right_index]
        value = self.data[index]

        if left_value > right_value and left_value > value:
            self.data[left_index], self.data[index] = value, left_value
            self.heap_down(left_index)
        elif right_value > left_value and right_value > value:
            self.data[right_index], self.data[index] = value, right_value
            self.heap_down(right_index)
 

    def insert(self, value: int):
        self.data.append(value)
        self.heap_up(self.length)
        self.length += 1

    def remove(self):
        if self.length == 0:
            return

        out = self.data.pop()
        self.length -= 1
        if self.length == 1:
            self.data = []
            return out
        
        remove_root = self.data[0]
        self.data[0] = out # move the last element to the root position, effectively remove the root.
        self.heap_down(0) # heap down the current root element to its correct position to maintain the heap conditions.
        return remove_root


