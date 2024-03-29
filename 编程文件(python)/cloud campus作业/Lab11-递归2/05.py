def get_merge_list(list_of_lists):
    #合并列表中的列表
    if len(list_of_lists)==1:
        return list_of_lists[0]
    else:
        return list_of_lists[0]+get_merge_list(list_of_lists[1:])