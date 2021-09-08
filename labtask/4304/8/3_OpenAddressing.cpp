// Hashing & collision handling techniques using Open Addressing
// Linear probing,Qudratic probing,Double hashing
#include <iostream>

// Load factor (lamda) :
// lamda = number_of_nodes / table_size (have to be between 0~1 except in separate chaining it can be >1)
// lamda is inversely proportional to HashTableSize

// HashFunc(key) = {x + f(i)} % HashTableSize
// in L.P -- f(i) = i ; in Q.P -- f(i) = i^2 or i*i
// In DoubleHashing f(i) can be any other hash function
// Here in D.H -- f(i) = i*hash2(key) and hash2(key)=R-(key%R) where R better be a Prime Number

const int attempts = 6; // attempt to insert
class Hashing
{
    virtual int f(int i) { return 0; } // calling virtual from constructor isnt virtual at all

protected:
    void insert(int num)
    {
        bool inserted = false;
        for (int k = 0; k < attempts; k++)
        {
            int index = hash(num, k);
            if (!hashTable[index]) // not equal to zero
            {
                hashTable[index] = num;
                totalInserted++;
                inserted = true;
                printf("Inserted : Index-%d (L.F=%f)\n", index, computeLF());
                break;
            }
            else
                printf("Collision : Index-%d\n", index);
        }
        if (!inserted)
            printf("Input Abandoned\n");
    }
    inline float computeLF()
    {
        return (float)totalInserted / (float)hashtableSize; // damn floats ＼(｀0´)／
    }
    inline virtual int hash(int num, int i)
    {
        return (num + f(i)) % hashtableSize;
    }

public:
    int hashtableSize, query;
    int *hashTable;
    int totalInserted;
    Hashing() : totalInserted(0)
    {
        printf("Enter Hash Table Size and Number of Queries: \n");
        std::cin >> hashtableSize >> query;
        hashTable = new int[hashtableSize];
    }
    void create()
    {
        int num;
        while (query--)
        {
            printf("Inserting Numbers:\n");
            std::cin >> num;
            insert(num);
        }
    }
    ~Hashing()
    {
        delete[] hashTable;
    }
    void printTable()
    {
        for (int i = 0; i < hashtableSize; i++)
            std::cout << hashTable[i] << " ";
        std::cout << std::endl;
    }
};
class LinearProbing : public Hashing
{
    int func(int i)
    {
        return i;
    }
};
class QudraticProbing : public Hashing
{
    int func(int i)
    {
        return i * i;
    }
};
class DoubleHashing : public Hashing
{
    int hash(int num, int i)
    {
        return (num + f(i, num)) % hashtableSize;
    }
    int f(int i, int key)
    {
        return i * hash2(key);
    }
    int hash2(int key)
    {
        const int R = 7;
        return R - (key % R);
    }
};

int main()
{
    int choice;
    std::cin >> choice;
    switch (choice) // switch is basically goto in disguise and c++ standards forbid initialization with gotos
    {               // so these braces remove the problem(creates scopes) or could've used if-else block
    case 1:
    {
        LinearProbing table;
        table.create();
        table.printTable();
        break;
    }
    case 2:
    {
        QudraticProbing table;
        table.create();
        table.printTable();
        break;
    }
    case 3:
    {
        DoubleHashing table;
        table.create();
        table.printTable();
        break;
    }
    default:
        break;
    }
}

// 1 10 8
// 35
// 45
// 73
// 36
// 5
// 24
// 13
// 99
// Inserted : Index-5 (L.F=.1)
// Collision: Index-5
// Inserted : Index-6 (L.F=.2)
// Inserted : Index-3 (L.F=.3)
// Inserted : Index-7 (L.F=.4)
// Collision: Index-5
// Collision: Index-6
// Collision: Index-7
// Inserted : Index-8 (L.F=.5)
// Inserted : Index-4 (L.F=.6)
// Collision: Index-3
// Collision: Index-4
// Collision: Index-5
// Collision: Index-6
// Collision: Index-7
// Collision: Index-8
// Input Abandoned
// Inserted : Index-9 (L.F=.7)

// 2 8 7
// 67
// 15
// 86
// 63
// 47
// 33
// 8
// Inserted : Index-3 (L.F = 0.125)
// Inserted : Index-7 (L.F = 0.25)
// Inserted : Index-6 (L.F = 0.375)
// Collision: Index-7
// Inserted : Index-0 (L.F = 0.5)
// Collision: Index-7
// Collision: Index-0
// Collision: Index-3
// Collision: Index-0
// Collision: Index-7
// Collision: Index-0
// Input Abandoned
// Inserted : Index-1 (L.F = 0.625)
// Collision: Index-0
// Collision: Index-1
// Inserted : Index-4 (L.F = 0.75)

// 3 15 11
// 94
// 46
// 61
// 29
// 85
// 77
// 46
// 63
// 67
// 93
// 61
// Inserted : Index-4 (L.F = 0.0666667)
// Inserted : Index-1 (L.F = 0.133333)
// Collision: Index-1
// Inserted : Index-3 (L.F = 0.2)
// Inserted : Index-14 (L.F = 0.266667)

// Inserted : Index-10 (L.F = 0.333333)
// Inserted : Index-2 (L.F = 0.4)
// Collision: Index-1
// Collision: Index-4
// Inserted : Index-7 (L.F = 0.466667)
// Collision: Index-3
// Collision: Index-10
// Collision: Index-2
// Inserted : Index-9 (L.F = 0.533333)
// Collision: Index-7
// Collision: Index-10
// Inserted : Index-13 (L.F = 0.6)
// Collision: Index-3
// Inserted : Index-8 (L.F = 0.666667)
// Collision: Index-1
// Collision: Index-3
// Inserted : Index-5 (L.F = 0.733333)
