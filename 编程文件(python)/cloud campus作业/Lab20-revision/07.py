def duplicate_list(my_linked_list):
    current = my_linked_list.get_head()

    while current is not None:
        data = current.get_data()
        current.add_after(data)
        current = current.get_next().get_next()