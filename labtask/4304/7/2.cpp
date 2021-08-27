#include "SegmentTree.cpp"
using std::cout, std::cin, std::endl;
int main()
{
    int n, q, i, j, val;
    cin >> n >> q;
    std::vector<int> vec;
    vec.push_back(0);
    for (int k = 0; k < n; k++)
    {
        cin >> val;
        vec.push_back(val);
    }
    SegmentTree segTree(vec);
    for (int k = 0; k < q; k++)
    {
        cin >> val;
        switch (val)
        {
        case 1:
            cin >> i;
            vec[i] = 0;
            segTree.updateSubstitute(i);
            cout << i << "( ";
            for (auto a : vec)
                cout << a << " ";
            cout << ")\n";
            break;
        case 2:
            cin >> i >> j;
            vec[i] += j;
            segTree.updateIncrement(i, j);
            cout << i << "( ";
            for (auto a : vec)
                cout << a << " ";
            cout << ")\n";
            break;
        case 3:
            cin >> i >> j;
            cout << segTree.query(i, j) << endl;
            break;
        default:
            break;
        }
    }
}
