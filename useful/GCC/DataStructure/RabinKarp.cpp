//Rabin-Karp String matching Algo -- uses rolling-hash function
// case insentive only for a-z
#include <iostream>
#include <string>
#include <cmath>

const int prime = 10;
inline int toNum(char ch)
{                            // at this point can be replaced by std::tolower
    return std::tolower(ch); //- 'a' + 1;
}
inline long chhs(char ch, int pos)
{
    return toNum(ch) * ((long)pow(prime, pos));
}
long hash(std::string const &str)
{
    long hash = 0;
    int pos = str.length() - 1;
    for (char ch : str)
    {
        hash += chhs(ch, pos);
        pos--;
    }
    return hash;
}

bool matchString(std::string &text, std::string &pattern)
{
    long phash = hash(pattern);
    int m = text.length(), i;
    int n = pattern.length();
    long thash = hash(text.substr(0, n));
    for (i = 0; i < m - n + 1; i++)
    { // m-n+1 ensures no out of bound error for text
        if (thash == phash)
            if (pattern == text.substr(i, n)) // necessary??
                return true;
        // optimization
        thash = thash - chhs(text[i], n - 1);
        thash *= prime;
        thash += (long)toNum(text[i + n]);
    }
    return false;
}

int main()
{
    std::string pattern, text;
    std::cout << "Input the text\n";
    std::cin >> text;
    std::cout << "Input the pattern to search for\n";
    std::cin >> pattern;
    matchString(text, pattern) ? std::cout << "Found\n" : std::cout << "Not found\n";
}