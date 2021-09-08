// Segment Tree
// 1 based indexing?
// still needs lots of work
#include <iostream>
#include <vector>
#define dbg std::cout << "done\n"

class SegmentTree
{
protected:
    int *tree;
    //std::vector<int> tree;
    int arrSize;
    void init(std::vector<int> &arr, int node, int begin, int end)
    {
        if (begin == end)
        { // leaf node
            tree[node] = arr[begin];
            return;
        }
        int left = node * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        init(arr, left, begin, mid);
        init(arr, right, mid + 1, end);
        tree[node] = compare(tree[left], tree[right]);
    }
    void updateSubstitute(int node, int begin, int end, int index, int newValue)
    {
        if (index > end || index < begin) //out of bounds or no overlap
            return;
        if (begin >= index && end <= index) //total overlap
        {
            tree[node] = newValue;
            return;
        }
        int left = node * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        updateSubstitute(left, begin, mid, index, newValue);
        updateSubstitute(right, mid + 1, end, index, newValue);
        tree[node] = compare(tree[left], tree[right]);
    }
    void updateIncrement(int node, int begin, int end, int index, int newValue)
    {
        if (index > end || index < begin) //out of bounds or no overlap
            return;
        if (begin >= index && end <= index) //total overlap
        {
            tree[node] += newValue;
            return;
        }
        int left = node * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        updateIncrement(left, begin, mid, index, newValue);
        updateIncrement(right, mid + 1, end, index, newValue);
        tree[node] = compare(tree[left], tree[right]);
    }
    int query(int node, int begin, int end, int i, int j)
    {                             // node -- tree , begin,end --recursion , i,j -- query range
        if (i > end || j < begin) //out of bounds or no overlap
        {
            //return INT16_MAX; //minimun
            //return INT16_MIN; //maximum
            return 0; // sum
        }
        if (begin >= i && end <= j) //total overlap
            return tree[node];
        int left = node * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        int q1 = query(left, begin, mid, i, j);
        int q2 = query(right, mid + 1, end, i, j);
        return compare(q1, q2);
    }
    int compare(int a, int b)
    {
        //return a < b ? a : b; //minimum
        //return a < b ? b : a; //maximum
        return a + b; //sum
    }

public:
    SegmentTree(std::vector<int> &arr)
    {
        arrSize = arr.size() - 1; // BEWARE DONT FORGET THE -1
        tree = new int[4 * arrSize];
        init(arr, 1, 1, arrSize);
    }
    ~SegmentTree()
    {
        delete[] tree;
    }
    int query(int lowerBound, int upperBound)
    {
        return query(1, 1, arrSize, lowerBound, upperBound);
    }
    void updateSubstitute(int index, int newValue = 0)
    {
        updateSubstitute(1, 1, arrSize, index, newValue);
    }
    void updateIncrement(int index, int newValue)
    {
        updateIncrement(1, 1, arrSize, index, newValue);
    }
};

class SegTreeLazy // alternative way (no probs fixed it) by shafayet
{                 // segment tree with lazy propagation
    struct TreeNode
    {
        int prop, data;
    };
    TreeNode *tree;
    //std::vector<int> tree;
    int arrSize;
    void init(std::vector<int> &arr, int node, int begin, int end)
    {
        if (begin == end)
        { // leaf node
            tree[node].data = arr[begin];
            tree[node].prop = 0;
            return;
        }
        int left = node * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        init(arr, left, begin, mid);
        init(arr, right, mid + 1, end);
        tree[node].data = compare(tree[left].data, tree[right].data);
        tree[node].prop = 0;
    }
    void update(int node, int begin, int end, int i, int j, int newValue)
    { // node -- tree , begin,end --recursion , i,j -- query range
        // newvalue -- value being added to all the values in range i to j
        if (i > end || i < begin) //out of bounds or no overlap
            return;
        if (begin >= i && end <= j) //total overlap
        {
            tree[node].data += newValue * (end - begin + 1); // e-b+1 is the the number of nodes under this node
            tree[node].prop += newValue;                     // saving this value for adding later
            return;
        }
        int left = node * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        update(left, begin, mid, i, j, newValue);
        update(right, mid + 1, end, i, j, newValue);
        tree[node].data = tree[left].data + tree[right].data + (end - begin + 1) * tree[node].prop;
    }
    int query(int node, int begin, int end, int i, int j, int carry)
    {                             // node -- tree , begin,end --recursion , i,j -- query range
        if (i > end || j < begin) //out of bounds or no overlap
        {
            //return INT16_MAX; //minimun
            //return INT16_MIN; //maximum
            return 0; // sum
        }
        if (begin >= i && end <= j) //total overlap
            return tree[node].data + (end - begin + 1) * carry;
        int left = node * 2;
        int right = left + 1;
        int mid = (begin + end) / 2;
        int q1 = query(left, begin, mid, i, j, carry + tree[node].prop);
        int q2 = query(right, mid + 1, end, i, j, carry + tree[node].prop);
        //return compare(q1, q2);
        return q1 + q2;
    }
    int compare(int a, int b)
    {
        //return a < b ? a : b; //minimum
        //return a < b ? b : a; //maximum
        return a + b; //sum
    }

public:
    SegTreeLazy(std::vector<int> &arr)
    {
        arrSize = arr.size() - 1; // BEWARE DONT FORGET THE -1
        tree = new TreeNode[4 * arrSize];
        init(arr, 1, 1, arrSize);
    }
    ~SegTreeLazy()
    {
        delete[] tree;
    }
    int query(int lowerBound, int upperBound)
    {
        return query(1, 1, arrSize, lowerBound, upperBound, 0);
    }
    void update(int i, int j, int newValue)
    {
        update(1, 1, arrSize, i, j, newValue);
    }
};

// class SegTreeLazy : public SegmentTree // for some reason it doesnt work (┛ಠ_ಠ)┛彡┻━┻
// {
//     int *lazy;
//     void updateLazy(int node, int begin, int end, int i, int j, int val)
//     {
//         // taking care of pending updates
//         if (lazy[node] != 0)
//         {
//             tree[node] += lazy[node];
//             if (begin != end) // if not a leaf node
//             {
//                 lazy[node * 2] += lazy[node];
//                 lazy[node * 2 + 1] += lazy[node];
//             }
//             lazy[node] = 0;
//         }

//         if (begin > i or end < j) //no overlap
//             return;
//         if (begin >= i and end < j)
//         {
//             tree[node] += val;
//             if (begin != end)
//             {
//                 lazy[node * 2] += val;
//                 lazy[node * 2 + 1] += val;
//             }
//             return;
//         }
//         int mid = (begin + end) / 2;
//         updateLazy(node * 2, begin, mid, i, j, val);
//         updateLazy(node * 2 + 1, mid + 1, end, i, j, val);
//         tree[node] = compare(tree[node * 2], tree[node * 2 + 1]);
//     }

// public:
//     SegTreeLazy(std::vector<int> &arr) : SegmentTree(arr)
//     {
//         //lazy.reserve(arrSize * 4);
//         lazy = new int[arrSize * 4];
//     }
//     ~SegTreeLazy()
//     {
//         delete[] lazy;
//     }
//     void updateLazy(int i, int j, int newValue)
//     {
//         updateLazy(1, 1, arrSize, i, j, newValue);
//     }
// };