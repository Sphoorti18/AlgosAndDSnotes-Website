//TIME COMPLEXITY ====> O(n); REFER TO HOLA.TXT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
int n,m; // n = # of profits + weights, m = Max capacity 
//NOT defining MACROS coz it will lead to unexpected behavior by the computer
int p[MAX][MAX], w[MAX][MAX], s[MAX][MAX], x[MAX][MAX]; //Refer to hola.txt
int main(){
printf("Enter the # of profits and weights : "); scanf("%d", &n);
printf("Enter the Max capacity : "); scanf("%d", &m);
  return 0;
}
