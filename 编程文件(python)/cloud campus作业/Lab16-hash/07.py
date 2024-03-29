class DoubleHashTable:
    def __init__(self, size=7, second_hash_value=5):
        self.__size = size
        self.__slots = [None] * size
        self.second_hash_value=second_hash_value
        self.cou=0
    def __str__(self):
        return str(self.__slots)

    def get_hash_code(self, key):
        return key % self.__size

    def get_size(self):
        return self.__size
    def get_new_hash_code_linear_probing(self, index):
        while self.__slots[index]!=None:
            index=(index+1)%self.__size
        return index
    
    def __len__(self):
        return self.cou
    def is_empty(self):
        if self.cou:
            return False
        else :
            return True
    def clear(self):
        for i in self.__slots:
            i=None
        self.cou=0
    def rehashing(self, new_size):
        oldha=self.__slots
        self.__size=new_size
        self.__slots=[None]*new_size
        for i in oldha:
            if i:
                self.put(i)
    def put(self, key):
        if self.cou==self.__size:
            raise IndexError("ERROR: The hash table is full.")
        if self.__slots[key%self.__size]==None:
            self.__slots[key%self.__size]=key
            self.cou+=1
        else:
            newi=self.get_new_hash_code_double_hashing(key)
            self.__slots[newi]=key
            self.cou+=1
    def get_new_hash_code_double_hashing(self, key):
        step=1
        step_size=self.second_hash_value-(key%self.second_hash_value)
        con=key%self.__size
        newkey=1
        while self.__slots[newkey]!=None:
            newkey=(con+step*step_size)%self.__size
            step+=1
        return newkey
my_hash_table=DoubleHashTable()
my_hash_table.put(1)
print(my_hash_table)
my_hash_table.put(8)
print(my_hash_table)
my_hash_table.put(15)
print(my_hash_table)
my_hash_table.put(22)
print(my_hash_table)
my_hash_table.put(41)
print(my_hash_table)
