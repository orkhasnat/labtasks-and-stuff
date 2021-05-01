def Printbin(n):
    while (n!=0):
        print(n&1,end = '')
        #n=n//2
        n=n>>1 #same as dividing a binary number by 2

def Inputintolist ():
    array=[int(x) for x in input().split()]
    #array=list(map(int,input().split()))


def SieveFunc(N):
    # N represents upto high we want to create a sieve 
    # It is usally N=10**6
    # True is for primality
    # $prime=[False]*2 + [True]*(N-1)  declare this before the func
    # Try not to use the argument N 
    sqn=int(N**0.5)+1
    for i in range (2,sqn):
        if prime[i] :
            for j in range (i*i,N+1,i):
                prime[j]=False
    # For printing the primes write the following
    for p in range (2, N):
        if prime[p]:
            print (p,end=' ')


def Islucky(v):
    #checks for lucky number
    #the numbers which eiter have 4 or 7 or both 
    #and nothing else but 4 and 7 are considered lucky
    for i in v:
        if i == "4" or i == "7":
            pass
        else:
            return False
    return True


