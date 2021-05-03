#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

// int* freqCount(vector<int> &op){
//     static int arr[9];
//     memset(arr,0,9);
//     for(int it : op){
//         switch (it)
//         {
//         case 1:
//             arr[0]++;
//             break;
//         case 2:
//             arr[1]++;
//             break;
//         case 3:
//             arr[2]++;
//             break;
//         case 4:
//             arr[3]++;
//             break;
//         case 5:
//             arr[4]++;
//             break;
//         case 6:
//             arr[5]++;
//             break;
//         case 7:
//             arr[6]++;
//             break;
//         case 8:
//             arr[7]++;
//             break;
//         case 9:
//             arr[8]++;
//             break;
//         default:
//             break;
//         }    
//     }
//     return arr;
// }

void freq(vector<int> &op){
    unordered_map<int,int> map;
    for(int it : op) map[it]++;
    for(pair<int,int> it:map) printf("%d has occured %d times\n",it.first,it.second); // map returns a pair

}

int main()
{
    vector<int> input;
    int tmp;
    while (cin >> tmp && tmp > 0)
        input.push_back(tmp);
    //int* arr = freqCount(input);
    freq(input);
    // for (int it : input){
    //     
    // }

}