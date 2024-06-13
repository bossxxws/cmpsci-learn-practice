'''
In our previous lab, we have developed a binary heap. Now, we want to extend our previous heap class to support Dijkstra's algorithm. Remind that in Dijkstra's algorithm, we want to update the dist array if a shorter path is found.

In this lab exercise, you will be provided a heap class with some functions implemented. To simplify the problem, we don't implement the insert function in this lab.

Different from the previous class, we store a set of key-value pairs as data. Your task is to add a function called decrease_key(key, value), which is used to update a key with a smaller value.  If the key is not found in the heap, then print 'There is no such a key!'. If the value is greater than the old one, print 'The new value should be smaller!'. There are two key steps in the decrease_key function. The first step is to find the position of the data with the input key in the heap. The second step is the update the value and keep the heap property. Note that the decrease_key function can be done in O(logN)
.

To support the first step for efficient position look-up, we maintain a dictionary ptr that stores the location for each (key, value) pair in the data array. For instance, ptr[0] = 2, means that the data with a key=0 is stored at position 2 in the data array. When we swap the data, we need to update the dictionary ptr. Complete the function decrease_key in the answer box.

For example:

Test	
h = heap([(0, 5),(1, 2),(2, 4),(3, 3),(4, 1)])
print(h)
h.decrease_key(3, 0)
print(h)
print(h.delete())
print(h)

Result
(4, 1), (1, 2), (2, 4), (3, 3), (0, 5)
(3, 0), (4, 1), (2, 4), (1, 2), (0, 5)
(3, 0)
(4, 1), (1, 2), (2, 4), (0, 5)

'''
class heap:
    def __init__(self, lst):
        self.data = lst  # The input list is a list of (key, value) tuples
        self.ptr = {lst[n][0]:n for n in range(len(lst))} # initialize the pointers
        self.size = len(lst)
        for i in range(self.size // 2 - 1, -1, -1):
            self.__heapify(i)
    
    def __len__(self):
        return self.size
    
    def __repr__(self):
        return ', '.join([str(self.data[i]) for i in range(self.size)])
    
    def __heapify(self, i):
        l = 2 * i + 1; # Find the left child of i
        r = 2 * i + 2; # Find the right child of i
        
        # Find the one with smallest values of the three
        smallest_pos = i
        if l < self.size and self.data[l][1] < self.data[smallest_pos][1]:
            smallest_pos = l
        if r < self.size and self.data[r][1] < self.data[smallest_pos][1]:
            smallest_pos = r
            
        # swap if i is not the smallest
        if smallest_pos != i:
            self.data[smallest_pos], self.data[i] = self.data[i], self.data[smallest_pos]
            # change the pointers to the data
            self.ptr[self.data[smallest_pos][0]] = smallest_pos
            self.ptr[self.data[i][0]] = i
            self.__heapify(smallest_pos);
        
    def delete(self):
        if self.size <= 0:
            print('The list is empty!')
            return None
        else:
            min_ele = self.data[0]
            self.data[0] = self.data[self.size-1]
            self.ptr.pop(min_ele[0])
            self.ptr[self.data[0][0]] = 0
            self.size -= 1
            self.__heapify(0)
            return min_ele
    
    def decrease_key(self, key, value):
        if key not in self.ptr:
            print('There is no such a key!')
            return
        i = self.ptr[key]
        if self.data[i][1] < value:
            print('The new value should be smaller!')
            return
        self.data[i] = (key, value)
        while i != 0 and self.data[self.parent(i)][1] > self.data[i][1]:
   
            self.ptr[self.data[i][0]], self.ptr[self.data[self.parent(i)][0]] = i, self.parent(i)
            self.data[i], self.data[self.parent(i)] = self.data[self.parent(i)], self.data[i]
            i = self.parent(i)
    
    def parent(self, i):
        return (i - 1) // 2


