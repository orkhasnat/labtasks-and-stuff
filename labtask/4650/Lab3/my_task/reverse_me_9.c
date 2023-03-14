// Author: Imtiaj Ahmed Chowdhury, Lecturer, CSE, IUT
// Course: CSE 4650 (Systems Programming Lab)

#include <stdio.h>

#define ORIGINAL_HASH 806366757

long generate_hash(long num)

{
  long k;
  long k2;
  long msb;
  
  msb = num >> 63;
  k = num / 1000 + msb;
  k2 = k - msb;
  num = num + ((num + (k - msb) * -1000) * k2 >> 2);
  return (num - num / k2) % 1901498371;
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


// ANS 686124701
