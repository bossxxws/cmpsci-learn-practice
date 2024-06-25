class SimpleHashTable:
    def __init__(self, size=7):
        self.__size = size
        self.__slots = [None] * size
        self.step=None
        self.stepsize=None
    def __str__(self):
        return str(self.__slots)

    def get_hash_code(self, key):
        return key % self.__size

    def put(self, key):
        index = self.get_hash_code(key)

        if self.__slots[index] is None:  # empty slot
            self.__slots[index] = key
            return False  # Linear probing is used

        new_index_linear_probing = index
        collisions_linear_probing = 0

        while self.__slots[new_index_linear_probing] is not None:  # look for an empty slot
            new_index_linear_probing = self.get_new_hash_code_linear_probing(new_index_linear_probing)
            collisions_linear_probing += 1

        self.step=0
        self.stepsize=5 - (key % 5)
        new_index_double_hashing = index
        collisions_double_hashing = 0

        while self.__slots[new_index_double_hashing] is not None:  # look for an empty slot
            new_index_double_hashing = self.get_new_hash_code_double_hashing(new_index_double_hashing)
            collisions_double_hashing += 1
        self.__slots[new_index_linear_probing] = key
        if collisions_double_hashing < collisions_linear_probing:
            return True  
        else:
            return False  

    def get_new_hash_code_linear_probing(self, index):
        return (index + 1) % self.__size

    def get_new_hash_code_double_hashing(self, index):
        self.step+=1
        return (index+self.step*self.stepsize)%self.__size