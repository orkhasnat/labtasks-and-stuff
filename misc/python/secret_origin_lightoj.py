t= int (input())

for case in range(1,t+1):
    n=int(input())
    s=0
    for i in bin(n)[2:] :
        if i=='1':
            s=s+1
    while n!= 0 :
        n=n+1
        s2=0
        for j in bin(n)[2:]:
            if j=="1":
                s2=s2+1
        if s==s2 :
            print(f"Case {case}: {n}")
            break
        else: 
            pass
        #print("case {} : {}".format(case,t))