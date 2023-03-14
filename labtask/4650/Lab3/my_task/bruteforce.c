#include <stdio.h>

// #define long long long

long generate_hash(long num)

{
  long k;
  long k2;
  long msb;
  
  msb = num >> 63;
  k = num / 1000 + msb;
  k2 = k - msb;
  if(!k2) return 0;
  num = num + ((num + (k - msb) * -1000) * k2 >> 2);
  return (num - num / k2) % 1901498371;
}

int main(){
	for(long i=0; i<1901498371;i++){
		if(generate_hash(i)==806366757){
			printf("%ld\n",i);
			break;
			}
	}	
}
