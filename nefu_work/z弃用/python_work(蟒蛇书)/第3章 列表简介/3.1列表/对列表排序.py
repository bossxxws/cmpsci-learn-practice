bicycles = ['trek', 'cannodale', 'redline', 'specialized']
bicycles.sort()
print(bicycles)
bicycles.sort(reverse=True)
print(bicycles)
bicycles = ['trek', 'cannodale', 'redline', 'specialized']
print("Here is the original list")
print(bicycles)
print("\nHere is the sorted list")
print(sorted(bicycles))
print('\nHere is the original list again')
print(bicycles)
print("\nmore example")
print(sorted(bicycles))#如何将reverse = True传递到函数sorted（）？
print(sorted(bicycles,reverse=True))

