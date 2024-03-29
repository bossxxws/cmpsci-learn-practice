def read_content(filename):
    lines = []
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            if line:
                lines.append(line)
    return lines
def get_tag_words(lines):
    for i in range(0,1):
        if i == 0:
            lines1 = lines1[i].split()
            lst1 = lines1[1].split()
            tag1 = lines1[0]
            group1 = (tag1,lst1)
        if i == 1:
            lines2 = lines[i].split()
            lst2 = lines2[1].split()
            tag2 = lines2[0]
            group2 = (tag2,lst2)
        group = [group1,group2]
    return group
def create_tags_dictionary(filename):
    lines = read_content(filename)
    group = get_tag_words(lines)
    dic = {}
    for key in range(0,1):
        dic[key] = group[key][key]
    return dic

    

    
    
    