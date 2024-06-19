# Binary Search Tree implementation using doubly linked list.
# Basic BST operation:
#
#	- Insert -> insert an element to a tree.
#	- Delete -> remove an element from a tree.
#	- Search -> searching an element in a tree.
#	- Traversal:
#		* Preorder
#		* Inorder
#		* Postorder
#		* Level Order

class BinaryTree:
    def __init__(self, value = None):
        self.value = value
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, node: BinaryTree, value_to_insert: int):
        if node == None:
            new_node = BinaryTree(value_to_insert)
            self.root = node = new_node
            return

        if value_to_insert < node.value:
            if node.left == None:
                new_node = BinaryTree(value_to_insert)
                node.left = new_node
            else:
                self.insert(node.left, value_to_insert)

        elif value_to_insert > node.value:
            if node.right == None:
                new_node = BinaryTree(value_to_insert)
                node.right = new_node
            else:
                self.insert(node.right, value_to_insert)

    def search(self, node: BinaryTree, value_to_search: int):
        if node == None:
            return False
        if value_to_search == node.value:
            return True
        elif value_to_search < node.value:
            return self.search(node.left, value_to_search)
        else:
            return self.search(node.right, value_to_search)
    
    def find_sucessor_node(self, node: BinaryTree, node_to_delete: BinaryTree):
        if node.left:
            node.left = self.find_sucessor_node(node.left, node_to_delete)
            return node
        else:
            node_to_delete.value = node.value
            return node.right

    def remove(self, node: BinaryTree, value_to_remove: int):
        if node == None:
            return
        
        # if the value we want to delete is 
        # less or greater than the current node's value
        if value_to_remove < node.value:
            node.left = self.remove(node.left, value_to_remove)
        elif value_to_remove > node.value:
            node.right = self.remove(node.right, value_to_remove)
        
        # 
        # if we found the value we want to delete,
        # consider following condition when the current node has:
        #   1. No children    -> simply delete.
        #   2. only one child -> simply move the node's child to current node's place.
        #   3. two child      -> find the successor by returning the node with minimum value from the current node's right subtree.
        #
        else:
            if node.right == None and node.left == None: 
                node = None
            elif node.left == None:
                return node.right
            elif node.right == None:
                return node.left
            else:
                node.right = self.find_sucessor_node(node.right, node)
        
        return node
     
    def preorder(self, node: BinaryTree):
        if node == None:
            return
        print(node.value, end = " ")
        self.preorder(node.left)
        self.preorder(node.right)

    def inorder(self, node: BinaryTree):
        if node == None:
            return
        self.inorder(node.left) 
        print(node.value, end = " ")
        self.inorder(node.right)

    def postorder(self, node: BinaryTree):
        if node == None:
            return
        self.postorder(node.left)
        self.postorder(node.right)
        print(node.value, end = " ")

    def levelorder(self):
        if self.root == None:
            return

        queue = [self.root]
        
        while queue:
            current_node = queue.pop(0)
            print(current_node.value, end = " ")
            if current_node.left:
                queue.append(current_node.left)
            if current_node.right:
                queue.append(current_node.right)
        print()

