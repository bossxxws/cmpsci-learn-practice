def get_study_guide(filename, keyword):
    if not isinstance(keyword, str):
        return "ERROR: Invalid input!"
    if keyword == '':
        return "ERROR: Invalid keyword!"
    try:
        with open(filename, 'r') as file:
            study_guide = {}
            for line in file:
                concept, meaning = line.strip().split(':')
                study_guide[concept] = meaning
            return study_guide[keyword]
    except KeyError:
        return f"ERROR: {keyword} is not available."


