#返回字典
def build_person(firstname,lastname,age = None):
    person = {'first' : firstname,'last' : lastname}
    if age:
        person['age'] = age
    return person
musician = build_person("wei","qing",age = 27 )
print(musician)
