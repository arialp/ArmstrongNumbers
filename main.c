#include <stdio.h>
#include "math.h"

void precomputePowers(int numOfDigits, int powers[restrict 10]){
  for(int i = 0; i < 10; i++){
    powers[i] = (int)pow(i, numOfDigits);
  }
}

static inline int
findSumOfDigits(int num, const int powers[restrict 10]){
  int _num = num;
  int sumOfDigits = 0;
  while(_num != 0){
    int digit = (int)(_num % 10);
    sumOfDigits += powers[digit];
    _num /= 10;
  }
  return sumOfDigits;
}

static inline int
isArmstrongNumber(int num, int powers[restrict 10]){
  return findSumOfDigits(num, powers) == num;
}

void printArmstrongNumbers(int numOfDigits){
  int lowr = (int)pow(10, numOfDigits - 1);
  int uppr = lowr * 10;
  int powers[10];
  precomputePowers(numOfDigits, powers);
  for(int num = lowr; num < uppr; num++){
    if(isArmstrongNumber(num, powers)){
      printf("%d is an Armstrong Number\n", num);
    }
  }
}

int main(void){
  printf("Num of digits:");
  int numOfDigits;
  if(scanf("%d", &numOfDigits) != 1 || numOfDigits <= 0
      || numOfDigits > 9){
    puts("Invalid input.");
    puts("Input should be between 1 <= n <= 9");
    return 1;
  }
  printArmstrongNumbers(numOfDigits);
  return 0;
}
