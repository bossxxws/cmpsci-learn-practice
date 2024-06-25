class SimpleHashTable:
    def __init__(self, size=7):
        self.__size = size
        self.__slots = [None] * size
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
    def put(self, key):
        if self.cou==self.__size:
            raise IndexError("ERROR: The hash table is full.")
        if self.__slots[key%self.__size]==None:
            self.__slots[key%self.__size]=key
            self.cou+=1
        else:
            newi=self.get_new_hash_code_linear_probing(key%self.__size)
            self.__slots[newi]=key
            self.cou+=1
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
            
try:
    my_hash_table = SimpleHashTable(3)
    my_hash_table.put(13) 
    my_hash_table.put(26) 
    my_hash_table.put(39)
    my_hash_table.put(52)
except IndexError as e:
    print(e)
print(my_hash_table)
print(my_hash_table.is_empty())
my_hash_table.clear()
print(my_hash_table.is_empty())