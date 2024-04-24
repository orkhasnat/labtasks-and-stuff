
def expand(s,left,right):
    while left >=0 and right <len(s) and s[left] == s[right]:
        left-=1
        right+=1
    return left+1,right-1

def lps(s):
    if not s:
        return ""
    start,end=0,0
    for i in range(len(s)):
        # single center
        l1,r1 = expand(s,i,i)
        # two char center
        l2,r2= expand(s,i,i+1)

        if r1-l1 > end-start :
            start,end =l1,r1
        if r2-l2 > end-start :
            start,end =l2,r2

    return s[start:end+1]

    
for i in range(5):
    s = input()
    print(lps(s))