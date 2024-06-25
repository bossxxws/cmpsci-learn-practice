def main():
    n = eval(input("enter number of disks:"))
    print("The moves are：")
    movedisks(n, "A", "C" ,"B")
def movedisks(n,fromtower,totower,auxtower):
    if n == 1 :
        print("Move disk",n,"from",fromtower,"to",totower)
    else:
        movedisks(n-1,fromtower,auxtower,totower)
        print("Move disk",n,"from",fromtower,"to",totower)
        movedisks(n-1,auxtower,totower,fromtower)
main()



    
