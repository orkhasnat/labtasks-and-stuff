// Trie data structure (a-z only)
// TODO : remove funcs
#include <iostream>
#include <string>

#define ALPHABET_SIZE 26 // a-z only
// A-z -- 52 and + 'A'
// 0-z -- 62 and + '0'
class Trie
{
    const char firstLetter = 'a'; // change to be more inclusive ie. (A-z)='A' or (0-z)='0'
    struct trienode
    {
        trienode *nxt[ALPHABET_SIZE];
        bool end;
        int prefixCount;
        trienode()
        {
            end = false;
            prefixCount = 0;
            for (int i = 0; i < ALPHABET_SIZE; i++)
                nxt[i] = NULL;
        }
    };
    trienode *root;
    int insertedWords, maxLen;
    void display(trienode *, char[], int, char);

public:
    Trie() : maxLen(0)
    {
        root = new trienode();
    }
    Trie(std::string const &str) : maxLen(0)
    {
        root = new trienode();
        insert(str);
        insertedWords = 1;
    }
    ~Trie()
    {
        delete root;
    };
    int getTotalWords()
    {
        return insertedWords;
    }
    int getMaxLength()
    {
        // maximum length of word in th trie
        return maxLen;
    }
    void display(char separator = ' ')
    {
        // display all the words in the trie lexographically
        char str[maxLen];
        std::cout << "Contents of Trie: \n";
        display(root, str, 0, separator);
        printf("\b \b\n"); // moving backwards, writing a space, and then moving backwards again to remove the extra separator character
    }
    void insert(std::string const &);
    bool searchWord(std::string const &);
    bool searchPrefix(std::string const &);
    int commonPrefixWordCount(std::string const &);
};

void Trie::insert(std::string const &str)
{
    trienode *curr = root;
    for (char ch : str)
    {
        int index = std::tolower(ch) - firstLetter; // change to be more inclusive ie. (A-z) or (0-z)
        if (!curr->nxt[index])                      // curr->nxt[index] == NULL
            curr->nxt[index] = new trienode();      //basically insertion
        //<wrong> curr->prefixCount++; // this is wrong!!! because it doesnt increment for the last letter
        curr = curr->nxt[index];
        curr->prefixCount++; // this also remembers if a word gets inserted more than once
    }
    curr->end = true;
    insertedWords++;
    maxLen = str.length() > maxLen ? str.length() : maxLen;
}
bool Trie::searchWord(std::string const &str)
{ // search whole words in the trie
    trienode *curr = root;
    for (char ch : str)
    {
        int index = std::tolower(ch) - firstLetter; // change to be more inclusive ie. (A-z) or (0-z)
        if (!curr->nxt[index])                      //curr->nxt[index] == NULL
            return false;
        curr = curr->nxt[index];
    }
    return curr->end;
}
bool Trie::searchPrefix(std::string const &str)
{ // search part of word in the trie
    trienode *curr = root;
    for (char ch : str)
    {
        int index = std::tolower(ch) - firstLetter; // change to be more inclusive ie. (A-z) or (0-z)
        if (!curr->nxt[index])                      //curr->nxt[index] == NULL
            return false;
        curr = curr->nxt[index];
    }
    return true;
}
int Trie::commonPrefixWordCount(std::string const &str)
{
    // returns number of words with given common prefix
    // word gets inserted more than once will be considered ie word inserted twice will return 2
    // only the full word eg. appple twice inserted then searching for apple will return 2 but not for app(1).
    trienode *curr = root;
    for (char ch : str)
    {
        int index = std::tolower(ch) - firstLetter; // change to be more inclusive ie. (A-z) or (0-z)
        if (!curr->nxt[index])                      //curr->nxt[index] == NULL
            return 0;
        curr = curr->nxt[index];
    }
    return curr->prefixCount;
}
void Trie::display(trienode *x, char str[], int level, char sep)
{
    // display helper function
    if (x->end)
    { // end == true
        str[level] = '\0';
        std::cout << str << sep;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (x->nxt[i]) // nxt[i] != NULL
        {
            str[level] = i + firstLetter;            // change to be more inclusive ie. (A-z) or (0-z)
            display(x->nxt[i], str, level + 1, sep); // ++level is dangerous here use print statements to know why; wasted 2 hours to find the bug uggh!!!
        }
    }
}

// one way to remove nodes using prefixCount (doesnt remove the memory occupied by nodes)(glicthy!)
// have to add if(curr->child[index]==NULL || curr->child[index]->wc == 0) in commonPrefix and search funcs
// found here --- https://drive.google.com/file/d/1w6UpLK6HwkAQcvZ6BaK_DQy09_sf3aE0/view
// bool Triedelete(char *s)
// {
//     if(search(s))
//     {
//         Trienode *curr = root;
//         int index;
//         for(int i=0; s[i]!='\0'; ++i)
//         {
//             index = s[i]-'a';
//             curr->child[index]->wc -=1;
//             curr = curr->child[index];
//         }
//     }
// }