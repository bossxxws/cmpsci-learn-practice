def read_content(filename):
    lines = []
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            if line:
                lines.append(line)
    return lines
def get_tag_words(line):
    line = line.split(":")
    lst = list(line[2])
    tag = line[1]
    group = (tag,lst)
    return group
def create_tags_dictionary(filename):
    lines = read_content(filename)
    dic = {}
    for line in lines:
        group = get_tag_words(line)
        key = group[1]
        dic[key] = group[2]
    return dic



    