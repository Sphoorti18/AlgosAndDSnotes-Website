#include <stdio.h>
#define MAX 50
#define sin(x) scanf("%d",&x)
#define new printf("\n")
#define tab printf("\t")
#define out(x) printf("%d",x)

int n,m;
int w[MAX];
void sumOfSub(int s, int k, int r){
    int x[n],i;
    x[k]=1;
    if(s+w[k]==m){
        for(i=0;i<k;i++){
        out(x[i]);
    }
    }
    else{
        if(s+w[k]+w[k+1]<=m){
            sumOfSub(s+w[k],k+1,r-w[k]);
        }
    }
    if((s+r-w[k]>=m)&&(s+w[k+1]<=m)){
        x[k]=0;
        sumOfSub(s,k+1,r-w[k]);
    }
}
int main(){int i,s[MAX],r[MAX];
printf("Enter the sum to be obtained from the subset of integers : ");
sin(m);
printf("# of integers in a subset : ");
sin(n);
printf("Enter the integers : ");
new;
for(i=0;i<n;i++){
    sin(w[i]);
}

    return 0;
}
/*
Test case :
m = 27
n = 7
S = 1 2 3 6 17 22 27
*/
