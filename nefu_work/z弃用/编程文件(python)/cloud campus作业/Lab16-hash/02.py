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
    def put(self, key):
        self.__slots[key%self.__size]=key
        self.cou+=1
    def __len__(self):
        return self.cou
my_hash_table=SimpleHashTable(13)
my_hash_table.put(26)
my_hash_table.put(54)
my_hash_table.put(94)
my_hash_table.put(17)
print(my_hash_table)
print("The hash table contains {} items.".format(len(my_hash_table)))