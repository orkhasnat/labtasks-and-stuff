#include <iostream>
#include <algorithm>
#include <cmath>
#define NUM 100000 //10e5

int lowerBound(long long arr[], int high, int target)
{   // lower bound returns the elements position which element is equal or greater than the target
    //// so when arr[mid] is equal to target we make high = mid -1 and if arr[mid] is less then low = mid+1 and return low
    int low = 0;
    while (low <= high)
    { // DONT RETURN MID
        int mid = (low + high) / 2;
        if (arr[mid] < target) // if upper-bound then arr[mid]<=target then low = mid + 1;
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int upperBound(long long arr[], int high, int target)
{   // upper bound returns the elements position which element is greater than the target
    // so when arr[mid] is equal to target we make low = mid+1 and return that
    int low = 0;
    while (low <= high)
    { // DONT RETURN MID
        int mid = (low + high) / 2;
        if (arr[mid] <= target) // if lower-bound then arr[mid]<target then low = mid + 1;
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{ // self made DP-BS approach
    long long arr[NUM];
    // arr[0]=0; cpp alredy initialises everything to zero unlike C
    for (long long i = 1; i <= NUM; i++)
        arr[i] = arr[i - 1] + 3 * i - 1; // i have to long long or 3*i has to be typecasted to long long (type related problem)
    //for(int i=0;i<NUM;i++) std::cout<<arr[i]<<"   ";
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, result = 0;
        std::cin >> n;
        while (n > 1)
        {
            int h = upperBound(arr, NUM - 1, n);
            h--;
            n = n - arr[h];
            result++;
        }
        std::cout << result << "\n";
    }
}

// //====== alternate/elegant DP-BS approach ========
// long long arr[NUM]; // NUM = 10e5 or 100000
//          // arr[0]=0; cpp alredy initialises everything to zero unlike C
// for (long long i = 1; i <= NUM; i++)
//     arr[i] = arr[i - 1] + 3 * i - 1; // i have to long long or 3*i has to be typecasted to long long (type related problem)
//
// while (t--)
//     {
//         int n, result = 0;
//         std::cin >> n;
//         while (n > 1)
//         {    // <algorithm>
//             long long a = std::upper_bound(arr, arr + NUM, n) - arr; // return a pointer (actually an iterator) which then subtracting from the base address(pointer arithmetic) we get the actual position
//             a--; //because we use upper bound we get the position which is 1 more than the actual position hence the --
//             n = n - arr[a]; //read the problem
//             result++;
//         }
//         std::cout << result << "\n";
//     }
//

// // =================== Mathmatical approach ===============
// while (t--)
// {
//     int n;
//     std::cin >> n;
//     int ans = 0;
//     while (n > 1)
//     {                                                        // <cmath>
//         long long height = (-1 + std::sqrt(1 + 24 * n)) / 6; //quadratic equation solving
//         //the extra thingy after decimal point will be gone so we will find the highest possible height from n cards
//         long long cardNum = (height * (3 * height + 1)) / 2;
//         n = n - cardNum;
//         ans++;
//     }
//     std::cout << ans << std::endl;
// }

// // ============== the explanation ===============
// // https://youtu.be/mB8XfACw1Zc thanks for the explanation
// f(h)= f(h-1)+3h-1
// f(h-1)= f(h-2)+3(h-1) -1
// f(h-2)= f(h-3) +3(h-2) -1
//  .......
// f(2) = f(1) + 3*2-1
// f(1) = f(0){which is zero} + 3*1 -1
// substarcting everything we find on one side f(h) and the other side a quadratic equation
// because every f(h-x) gets substracted
// so we find,
// f(h) = 3*(1+2+3+......(h-1)+h) - (1+1+1+1+1+1....)
//      = 3*h(h+1)/2 -h
//      = h(3h +1)/2
//     in this case because h cant be greater than 10e9 and this is a quadratic equation,
//     we can assume that any number over 10e5 will cross 10e9 and become 10e10\\(10e5)^2\\ 
//     so can loop to 10e5 safely
//
//