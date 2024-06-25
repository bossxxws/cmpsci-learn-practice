def get_permutations(sequence):
    if len(sequence) == 1:
        return[sequence]
    else:
        permutations = []
        first = sequence[0]
        rest = sequence[1:]
        for permutation in get_permutations(rest):
            for index in range(len(permutation)+1):
                if permutation[:index] + first + permutation[index:] in permutations:
                    continue
                permutations.append(permutation[:index]+ first + permutation[index:])
        return permutations
print(get_permutations(input()))
