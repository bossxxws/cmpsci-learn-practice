def get_total_cost(items_dict, items_list):
    res=0
    couk=0
    cout=0
    for i in range(0,len(items_list)):
        try:
            res+=items_dict[items_list[i]]
        except KeyError:
                couk+=1
        except TypeError:
                cout+=1
    return (res,couk,cout)





items = {'apple': 12, 'banana': 7,'cherry': 10, 'dragonfruit': 35}
selected = ['apple', 'apple', 'cherry', 'dragonfruit', 'cherry']
cost = get_total_cost(items, selected)
print(cost)

items = {'apple': 12, 'banana': 7,
         'cherry': 10, 'dragonfruit': 35}
selected = ['apple', 'apple', 'cherry', 'eggplant', 'cherry']
cost = get_total_cost(items, selected)
print(cost)

items = {'apple': 'XXXXX', 'banana': 7,
         'cherry': 10, 'dragonfruit': 35}
selected = ['apple', 'apple', 'cherry', 'dragonfruit', 'cherry']
cost = get_total_cost(items, selected)
print(cost)
