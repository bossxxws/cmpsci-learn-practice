strl = input()
string = ""
number = 0
for sa in strl:
    if "0" <= sa <= "9":
        number += int(sa)
    else:
        string += sa
print(string,number)
