def read_content(filename):
    with open(filename, 'r') as file:
        content = file.read()
    lines = content.split('\n')
    non_empty_lines = [line for line in lines if line.strip()]
    return non_empty_lines