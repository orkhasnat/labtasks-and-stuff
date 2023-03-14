// Author: Imtiaj Ahmed Chowdhury, Lecturer, CSE, IUT
// Course: CSE 4650 (Systems Programming Lab)

#include <stdio.h>

#define ORIGINAL_HASH 6565806

long generate_hash(long num)
{
    long hashed_value;
    /*
    *    __REDACTED CODE__
    *
    *    Reverse the given x86-64 assembly to figure out the code
    */

    return hashed_value;
}

int main()
{
    long input;

    printf("Welcome to School of Reversing!\n");
    printf("To enter into the school, you need to prove your worth\n");

    printf("Please enter the password that will hash to the value: %ld \n", ORIGINAL_HASH);

    scanf("%ld", &input);

    long hashed_value = generate_hash(input);
    
    if (hashed_value == ORIGINAL_HASH)
        printf("Congrats! Enter into the path of Wizardry!\n");
    else
        printf("Sorry! Please go and come back when you're ready.\n");

}