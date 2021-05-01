# k,n=map(int,input().split())
# array=[int(x) for x in input().split()]
# #array=list(map(int,input().split()))
# print(sum(array))


# import turtle

# t = turtle.Turtle()

# for c in ['red', 'green', 'yellow', 'blue']:
#     t.color(c)
#     t.forward(75)
#     t.left(90)
def recurse(n):
    if n==5:
        return
    print("recursing no",n)
    recurse(n+1)
    #return

if __name__ =="__main__":
   recurse(1)
    