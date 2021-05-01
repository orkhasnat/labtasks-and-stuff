def mod(num, a): 
    # Initialize result 
    res = 0
  
    # One by one process all digits 
    # of 'num' 
    for i in range(0, len(num)):
        res = (res * 10 + int(num[i])) % a; 
    return res 

t= int(input())
while(t):
    n= input()
    rem= mod(n,7)
    mob=int(int(n)/7)
    ans=mob*2+mob*7
    if(rem<=3): 
        ans+=rem;
    elif (rem==4):
        ans+=rem+1;
    else :
        ans+=rem+2;
    print(ans)
    t-=1