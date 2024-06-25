
import sys

def solve():
    for line in sys.stdin:
        
        str = list(line)
        count = 0
        length = 0
        temp = []
        dig = []
        for i in range(str.__len__()):
            if (str[i] >= '0' and str[i] <= '9'):
                
                count += 1
                temp.append(str[i])
            else:
                if count >= length:
                    
                    length = count
                    count = 0
                    dig = temp.copy()
                    temp = []
                else:
                    
                    temp = []
                    count = 0
        
        result = ''.join(dig)
        print("%s,%d" % (result, length))
n = input()
solve(n)