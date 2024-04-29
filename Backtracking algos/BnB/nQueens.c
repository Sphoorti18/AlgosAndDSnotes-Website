//TIME COMPLEXITY ====> O(n); REFER TO HOLA.TXT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d",&x)
#define MAX 100
#define new printf("\n");
int n,m; // n = # of profits + weights, m = Max capacity 
//NOT defining MACROS coz it will lead to unexpected behavior by the computer
int p[MAX][MAX], w[MAX][MAX], s[MAX][MAX]; //Refer to hola.txt
bool l=false;
bool t=true;
bool place(int k, int i){
    int j,i;
    for(i=0;i<k-1;i++){
    for(j=0;j<k-1;j++){
        if(i==s[i][j] || abs(s[i][j]-i)==abs(j-k) ){
            return l;
        }
    } return t;}
}
void nQueens(int k, int n){
    int i,j;
    for(i=0;i<n;i++){
        if(place(k,i)){
            s[k][i]=i;
            if(k==n){
                for(i=0;i<n;i++){
                    for(j=0;j<n;j++){
               out(s[i][j]);}
                }
            }
            else{
                nQueens(k+1,n);
            }
        }
    }
    return;
}
int main(){
    int n,m,i,j;
printf("Enter the # of profits and weights : "); scanf("%d", &n);
printf("Enter the Max capacity : "); scanf("%d", &m);
new
  printf("Enter each profits and weights, Here : \n");
for(i=0;i<n;i++){
  for(j=0;j<n;j++){
    scanf("%d %d",&p[i][j], &w[i][j]);
  }
}

  nQueens(0,n);
  for(i=0;i<m;i++){
  for(j=0;j<m;j++){
    out(s[i][j]);
  }
}  
  return 0;
}
