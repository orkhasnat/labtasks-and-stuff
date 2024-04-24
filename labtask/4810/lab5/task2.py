def max_container(h):
    l,r= 0,len(h) -1
    max_water=0

    while l<r:
        water= min(h[l],h[r])*(r-l)
        max_water=max(water,max_water)

        if h[l]<h[r]:
            l+=1
        else:
            r-=1

    return max_water


h= [1,8,6,2,5,4,8,3,7]
print(max_container(h))

h= [1,1]
print(max_container(h))
