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

