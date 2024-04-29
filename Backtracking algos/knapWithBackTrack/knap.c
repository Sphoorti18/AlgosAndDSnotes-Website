//TIME COMPLEXITY ---> O(2^n);
#include <stdio.h>
#include <stdlib.h>
#define sin(x) scanf("%d",&x)
#define new printf("\n")
#define MAX 50
int n,m, w[MAX][MAX],p[MAX][MAX];
int bound(int cp[][MAX], int cw[][MAX], int k){
    int b[n][n]=cp[n][n], c[n][n]=cw[n][n],i,j,w[n][n],p[n][n];
    for(i=k+1;i<n;i++){
        for(j=k+1;j<n;j++){
            c[i][j]+=w[i][j];
        if(c[i][j]<m[i][j]){
            b[i][j]+=p[i][j];
        }
        else{
            return b[i][j]+(1-(c[i][j]-m[i][j])/w[i][j])*p[i][j];
        }
        return b;
        } 
    }
}
void bKnap(int k, int cp[][MAX], int cw[][MAX]){

    int y[n][n],fp[n][n],fw[n][n],j,x[n][n];

    if(cw[k][k]+w[k][k]<=m){
y[k][k]=1;

if(k<n){
    bKnap(k+1,cp[k][k]+p[k][k],cw[k][k]+w[k][k]);
    }

if((cp[k][k]+p[k][k]>fp[n][n])&&(k==n)){

    fp[n][n] = cp[k][k]+p[k][k]; fw[n][n] = cw[k][k] + w[k][k];
   
   for(j=0;j<k;j++){
    x[j][j]=y[j][j];
    }
}
    }

    if(bound(cp[k][k],cw[k][k],k)>=fp[k][k]){
        y[k][k]=0;
        if(k<n){bKnap(k+1,cp[k][k],cw[k][k]);}
        if((cp[k][k]>fp[k][k]) && (k==n)){
            fp[k][k]=cp[k][k]; fw[k][k]=cw[k][k];
            for(j=0;j<k;j++){x[j][j]=y[j][j];}
        }
    }
    }
int main(){int i,j;
    printf("Enter the maximum knapsack capacity : ");
   sin(m);
   printf("Enter the # of items : ");
   sin(n);
printf("Enter the profits for each of the items : ");
new;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){sin(p[i][j]);}
}
printf("Enter the weights for each of the items : ");
new;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){sin(w[i][j]);}
}
bKnap(0,0,0);
    return 0;
}
