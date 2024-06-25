class SimpleHashTable:
    def __init__(self, size=7):
        self.__size = size
        self.__slots = [None] * size

    def __str__(self):
        return str(self.__slots)

    def get_hash_code(self, key):
        return key % self.__size

    def get_size(self):
        return self.__size
my_hash_table = SimpleHashTable()
print(my_hash_table)
print(type(my_hash_table))
print(my_hash_table.get_hash_code(12))
print(my_hash_table.get_size())
    

    