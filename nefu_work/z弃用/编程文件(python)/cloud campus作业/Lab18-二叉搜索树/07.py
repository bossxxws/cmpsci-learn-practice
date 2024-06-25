class BinarySearchTree:
    def __init__(self, data, left=None, right=None):
        self.__data = data
        self.__left = left
        self.__right = right
    def insert_left(self, new_data):
        if self.__left == None:
            self.__left = BinarySearchTree(new_data)
        else:
            t = BinarySearchTree(new_data, left=self.__left)
            self.__left = t
    def insert_right(self, new_data):
        if self.__right == None:
            self.__right = BinarySearchTree(new_data)
        else:
            t = BinarySearchTree(new_data, right=self.__right)
            self.__right = t
    def get_left(self):
        return self.__left
    def get_right(self):
        return self.__right
    def set_left(self, left):
        self.__left = left
    def set_right(self, right):
        self.__right = right
    def set_data(self, data):
        self.__data = data
    def get_data(self):
        return self.__data
    def __contains__(self, value):
        return self._contains_recursive(self, value)
    def _contains_recursive(self, node, value):
        if node is None:
            return False
        if value == node.get_data():
            return True
        elif value < node.get_data():
            return self._contains_recursive(node.get_left(), value)
        else:
            return self._contains_recursive(node.get_right(), value)
    def search(self, value):
        return self.searchx(self,value)
    def searchx(self,subtree,value):
        if subtree is None:
            return None
        if value==subtree.get_data():
            return subtree
        elif value<subtree.get_data():
            return self.searchx(subtree.get_left(),value)
        else:
            return self.searchx(subtree.get_right(),value)
        
    def insert(self, value):
        if self is None:
            self=BinarySearchTree(value)
        else:
            self._insert_recursive(self, value)
    
    def _insert_recursive(self, node, value):
        if value < node.get_data():
            if node.get_left() is None:
                node.set_left(BinarySearchTree(value)) 
            else:
                self._insert_recursive(node.get_left(), value)
        else:
            if node.get_right() is None:
                node.set_right(BinarySearchTree(value))
            else:
                self._insert_recursive(node.get_right(), value)
def create_bst_from_list(values):
    n=len(values)
    tree=BinarySearchTree(values[0])
    for i in range(1,n):
        tree.insert(values[i])
    return tree
def create_bst_from_sorted(values):
    if not values:
        return None
    mid = len(values) // 2
    root_value = values[mid]
    root = BinarySearchTree(root_value)
    left_values = values[:mid]
    right_values = values[mid+1:]
    root.set_left(create_bst_from_sorted(left_values))
    root.set_right(create_bst_from_sorted(right_values))  
    return root
def get_bst_postorder(bst):
    result = []
    _get_bst_postorder_recursive(bst, result)
    return result

def _get_bst_postorder_recursive(node, result):
    if node is None:
        return
    _get_bst_postorder_recursive(node.get_left(), result)
    _get_bst_postorder_recursive(node.get_right(), result)
    result.append(node.get_data())
def get_maximum(bst):
    if bst==None:
        return '0'
    if bst.get_right()==None:
        return bst.get_data()
    else:
        r=get_maximum(bst.get_right())
    cmax=max(r,bst.get_data())
    return cmax

