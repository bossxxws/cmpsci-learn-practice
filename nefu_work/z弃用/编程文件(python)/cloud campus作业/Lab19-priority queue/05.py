class PriorityQueue:
    def __init__(self) :
        self.__binary_heap=[0]
        self.__size=0
    def __str__(self):
        return str(self.__binary_heap)
    def __len__(self):
        return self.__size
    def add_all(self, a_list):
        self.__size+=len(a_list)
        for ele in a_list:
            self.__binary_heap.append(ele)
    def percolate_up(self, index):
        while index // 2 > 0:
            if self.__binary_heap[index] < self.__binary_heap[index // 2]:
                self.__binary_heap[index], self.__binary_heap[index // 2] = self.__binary_heap[index // 2],self.__binary_heap[index]
            index = index//2
    def insert(self,element):
        self.__binary_heap.append(element)
        self.__size+=1
        self.percolate_up(self.__size)
    def get_smaller_child_index(self, index):
            left_child_idx = 2 * index
            right_child_idx = 2 * index + 1

            if right_child_idx <= self.__size:
                if self.__binary_heap[left_child_idx] < self.__binary_heap[right_child_idx]:
                    return left_child_idx
                else:
                    return right_child_idx
            elif left_child_idx <= self.__size:
                return left_child_idx
            else:
                return None

