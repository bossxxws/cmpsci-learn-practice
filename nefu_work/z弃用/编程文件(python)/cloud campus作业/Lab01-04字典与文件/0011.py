def read_content(filename):
    lines = []
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            if line:
                lines.append(line)
    return lines
    

            