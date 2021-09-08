// fixed the issue
#include "SegmentTree.cpp"
using std::cout, std::cin, std::endl;
int main()
{
    int n, q, i, j, val, v;
    cin >> n >> q;
    std::vector<int> vec;
    vec.push_back(0);
    for (int k = 0; k < n; k++)
    {
        cin >> val;
        vec.push_back(val);
    }
    SegTreeLazy segTree(vec);
    for (int k = 0; k < q; k++)
    {
        cin >> val;
        switch (val)
        { // 1 for update -- lowerBound, upperBound , value
        case 1:
            cin >> i >> j >> v;
            segTree.update(i, j, v);
            break;
        case 2: //2 for query -- lowerBound ,upperBound
            cin >> i >> j;
            cout << segTree.query(i, j) << endl;
            break;
        default:
            break;
        }
    }
}
