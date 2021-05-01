#Still dont understand why
k,n=map(int,input().split())
array=[int(x) for x in input().split()]
#array=list(map(int,input().split()))
#summation=sum(array)
maximum=0
previous=0
for i in array:
    maximum=max(maximum,abs(previous-i))
    previous=i

maximum=max(maximum,k-array[-1]+array[0])

print(k-maximum)

# for (int i = 0; i < n; i++) {
# 		ma = max(ma, abs(prev - a[i]));
# 		prev = a[i];
# 	}
 
# 	ma = max(ma, k - a.back() + a[0]);
 
# 	ll ans = k - ma;
# 	cout << ans << endl;

# C:Traveling Salesman around Lake
# Split the circumference of the pond into the N segments by the houses 
# When the salesmanvisits all the house, there are at most 1 segment out of the N segments 
# which the salesman doesnot pass. 
# Also, it is possible to visit all the houses so that the salesman does
# not pass the longestsegment of the N segments while passing the other segments exactly once.
# The longest segmentcan be found in a total ofO(N) time, so the problem could be solved. 
# When implementing, becareful of the treatment of the segment that strides over the due north.


# AHSANS CODE ALTHOUGH FLAWED



#include<iostream>
# using namespace std;
# int arr[100005];
# int main()
# {
#     int i, j, k, n, large, small, a, b;
#     cin >> k;
#     cin >> n;
#     for(i=1; i<=n; i++)
#     {
#         cin >> arr[i];
#     }
#     large=arr[1];
#     for(i=1; i<=n; i++)
#     {
#         if(arr[i]>large)
#         {
#             large = arr[i];
#         }
#     }
#     small=INT_MAX;
#     for(i=1; i<=n; i++)
#     {
#           if(arr[i]==0)
#             {
 
#             }
#             else
#             {
#         if(arr[i]<small )
#         {
#             small=arr[i];
#         }
#         }
#     }
 
#     a=large-small;
#     b=(k+small)-large;
#     if(a>=b)
#     {
#         cout << b;
#     }
#     else
#     {
#         cout << a;
#     }
 
#     return 0;
# }