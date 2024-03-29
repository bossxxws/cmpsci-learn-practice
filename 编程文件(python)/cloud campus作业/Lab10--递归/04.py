def print_between(start, end):
    start = int(start)
    end = int(end)
    if start > end:
        return
    else:
        print(str(start) + " ",end="")
        print_between(start + 1, end)
print_between(1, 5)

