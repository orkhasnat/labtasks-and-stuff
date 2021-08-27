#include "SegmentTree.cpp"
using std::cout, std::cin, std::endl;
int main()
{
    int n, q, i, j, val;
    cin >> n >> q;
    std::vector<int> vec;
    vec.push_back(INT16_MAX);
    for (int k = 0; k < n; k++)
    {
        cin >> val;
        vec.push_back(val);
    }
    SegmentTree segTree(vec);
    for(int k=0;k<q;k++){
        cin>>i>>j;
        cout<<segTree.query(i,j)<<endl;
    }
}