bicycles = ['trek', 'cannodale', 'redline', 'specialized']
print(bicycles)
bicycles[0] = "Shandi"
print(bicycles)
bicycles.append("Sifei")
print(bicycles)
bicycles = []
bicycles.append("trek")
bicycles.append("sifei")
bicycles.append("shandi")
print(bicycles)
bicycles.insert(0,"horse")
print(bicycles)
del bicycles[0]
print(bicycles)
poped_bicycles = bicycles.pop()
print(bicycles)
print(poped_bicycles)
last_own = bicycles.pop()
print(last_own)
bicycles = ['trek', 'cannodale', 'redline', 'specialized']
first_owned = bicycles.pop(0)
print(first_owned)
bicycles.remove("cannodale")
print(bicycles)
too_expensive = "redline"
bicycles.remove(too_expensive)
print(bicycles)
print(f"\nA {too_expensive} is too expensive for me")
