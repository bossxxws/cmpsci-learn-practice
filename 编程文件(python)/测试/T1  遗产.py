qin = input()
zi = input()
yichan = 100000
guan = 100000 * 0.015
q = int(qin)
z = int(zi)
r = z * 100
t = 200
fenshu = str(q + r + t )
f = int(fenshu)
y1 = (( int(q) / f ) * (100000 - 1500)) / int(q) 
y2 = (( int(r) / f ) * (100000 - 1500)) / int(z)
y3 = 100000 - int(guan) - int(y1) - int(y2)
print(int(guan),int(y1),int(y2),int(y3))





