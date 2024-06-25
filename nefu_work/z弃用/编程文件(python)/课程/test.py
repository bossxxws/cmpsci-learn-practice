def permute(arr, start=0):
    if start == len(arr):
 
        print(" ".join(arr))
    else:
 
        for i in range(start, len(arr)):
            arr[start], arr[i] = arr[i], arr[start]
            permute(arr, start + 1)
            arr[start], arr[i] = arr[i], arr[start]  


input_list = input()

input_list=input_list[1::]

input_list=input_list[0:-1]
#print(input_list)
input_list=input_list.split(',')

#print(input_list)

permute(input_list)