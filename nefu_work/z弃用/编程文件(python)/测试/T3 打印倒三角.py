n=int(input())

for a in range(1,n+1):

    for b in range(n-a,0,-1):

       print(' ',end='')

    for c in range(1,2*a):

          print('*',end='')

    print()

m=n-1

for q in range(m,0,-1):

    print(' ',end='')

    for w in range(m-q+1,1,-1):

        print(' ',end='')

    for e in range(1,2*q):

        print('*',end='')

    print()
