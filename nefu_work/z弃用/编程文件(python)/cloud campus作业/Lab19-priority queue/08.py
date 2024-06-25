class PriorityQueue:
    def __init__(self):
        self.__binary_heap = [0]
        self.__size = 0

    def __str__(self):
        return str(self.__binary_heap)

    def __len__(self):
        return self.__size

    def add_all(self, a_list):
        self.__size += len(a_list)
        self.__binary_heap.extend(a_list)
        self.build_heap()

    def percolate_up(self, index):
        while index // 2 > 0:
            if self.__binary_heap[index] < self.__binary_heap[index // 2]:
                self.__binary_heap[index], self.__binary_heap[index // 2] = self.__binary_heap[index // 2], self.__binary_heap[index]
            index = index // 2

    def insert(self, element):
        self.__binary_heap.append(element)
        self.__size += 1
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

    def percolate_down(self, index):
        while index * 2 <= self.__size:
            smaller_child_idx = self.get_smaller_child_index(index)
            if self.__binary_heap[index] > self.__binary_heap[smaller_child_idx]:
                self.__binary_heap[index], self.__binary_heap[smaller_child_idx] = self.__binary_heap[smaller_child_idx], self.__binary_heap[index]
            index = smaller_child_idx

    def build_heap(self):
        for i in range(self.__size // 2, 0, -1):
            self.percolate_down(i)

    def delete_minimum(self):
        if self.__size == 0:
            raise IndexError("Priority queue is empty")

        minimum = self.__binary_heap[1]
        self.__binary_heap[1] = self.__binary_heap[self.__size]
        self.__size -= 1
        self.__binary_heap.pop()
        self.percolate_down(1)

        return minimum


def heap_sort(values):
    pq = PriorityQueue()
    pq.add_all(values)

    sorted_list = []
    while len(pq) > 0:
        sorted_list.insert(0, pq.delete_minimum())

    return sorted_list[::-1]