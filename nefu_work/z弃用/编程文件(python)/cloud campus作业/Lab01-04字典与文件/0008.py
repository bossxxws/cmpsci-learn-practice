def print_keys_values_inorder(dictionary) :
    for key in sorted(dictionary.keys()): 
        s = sorted(dictionary[key])
        print(key,' '.join(s))
            
                
      


        









my_dict = {6:['monday', 'coffee', 'strong'], 5:['short'], 3:['may', 'and']}
print_keys_values_inorder(my_dict)