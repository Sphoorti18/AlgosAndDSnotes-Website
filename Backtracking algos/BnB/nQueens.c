//TIME COMPLEXITY ====> O(n); REFER TO HOLA.TXT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
#define new printf("\n");
int n,m; // n = # of profits + weights, m = Max capacity 
//NOT defining MACROS coz it will lead to unexpected behavior by the computer
int p[MAX][MAX], w[MAX][MAX], s[MAX][MAX], x[MAX][MAX]; //Refer to hola.txt
int main(){ int n,m,i,j;
printf("Enter the # of profits and weights : "); scanf("%d", &n);
printf("Enter the Max capacity : "); scanf("%d", &m);
new
  printf("Enter each profits and weights, Here : \n");
for(i=0;i<n;i++){
  for(j=0;j<n;j++){
    scanf("%d %d",&p[i][j], &w[i][j]);
  }
}
  printf("Enter each profits and weights, Here : \n");
  for(i=0;i<m;i++){
  for(j=0;j<m;j++){
    scanf("%d %d",&p[i][j], &w[i][j]);
  }
}         
  return 0;
}
