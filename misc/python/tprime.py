#Run time error in sample cases!! 
#maybe because we have to press enter everytime to take input whether in cpp we used spaces instead .Because the sample works here !!

# t=int(input())
# while(t!=0):
#     a=int (input())
#     j=a**0.5
#     if a==1 or j-int(j)!=0 :
#         print("NO")
#     else :
#         k=2
#         f=7
#         while (k*k<=j):
#             if int(j) %k == 0 :
#                 f=1
#                 break
#             else :
#                 f=0
#                 break
#         k+=1
#         if f==1 :
#             print("NO")
#         else :
#             print("YES")
#     t-=1

#Sarthoks code
# sieve=[0]*2+[1]*1000001
# for i in range(2,1001):
#      if sieve[i]:
#           for j in range(i*2,1000001,i):
#                sieve[j]=0
#
# n = input()
# for i in map(int,raw_input().split()):
#      print ['NO','YES'][int(i**0.5)*int(i**0.5) == i and sieve[int(i**0.5)]]


# the code that works : well no it doesnt; no rounding error
# should use a better algo to find primes
t=int(input())
listed= input().split()
for q in range(0,t) :
    
    a=int (listed[q])

    j=a**0.5
    if a==1 or j-int(j)!=0 :
        print("NO")
    
    else :
        k=2
        f=7
        while (k<=int(j**0.5)) :
            if int(j) %k == 0 :
                f=1
                break
            else :
                f=0
                break
        k+=1
        if f==1 :
            print("NO")
        else :
            print("YES")

