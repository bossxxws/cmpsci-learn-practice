def create_username_dictionary(names_list):
    dic  ={}
    for ele in names_list:
        if ele[1] in dic:
            print(f"ERROR: {ele[1]} is already in the dictionary.")
        else:
            dic[ele[1]]=ele[0]
    return dic 