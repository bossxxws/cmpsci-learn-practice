#删除为特定值的所有列表元素
pets = ["dog", "cat", "dog", "fidsh", "cat", "cat", "rabbit"]
print(pets)
while "cat" in pets:
    pets.remove("cat")
print(pets)