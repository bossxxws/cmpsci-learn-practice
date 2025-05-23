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