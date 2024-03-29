def get_tag_words(line):
    line = line.split(":")
    lst = list(line[2])
    tag = line[1]
    group = (tag,lst)
    return group