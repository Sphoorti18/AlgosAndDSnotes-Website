#include <stdio.h>
#define sin(x) scanf("%d",&x)
#define new printf("\n")
#define MAX 50
int n,m, w[MAX],p[MAX];
int bound(int cp, int cw, int k){
    int b=cp, c=cw,i,w[n],p[n];
    for(i=k+1;i<n;i++){
        c+=w[i];
        if(c<m){
            b+=p[i];
        }
        else{
            return b+(1-(c-m)/w[i])*p[i];
        }
        return b;
    }
}
void bKnap(int k, int cp, int cw){
    int y[n],fp,fw,j,x[n],y[n];
    if(cw+w[k]<=m){
y[k]=1;
if(k<n){bKnap(k+1,cp+p[k],cw+w[k]);}
if((cp+p[k]>fp)&&(k==n)){
    fp=cp+p[k]; fw=cw+w[k];
   for(j=0;j<k;j++){x[j]=y[j];}
}
    }

    if(bound(cp,cw,k)>=fp){
        y[k]=0;
        if(k<n){bKnap(k+1,cp,cw);}
        if((cp>fp)&&(k==n)){
            fp=cp; fw=cw;
            for(j=0;j<k;j++){x[j]=y[j];}
        }
    }
    }
int main(){int i;
    printf("Enter the maximum knapsack capacity : ");
   sin(m);
   printf("Enter the # of items : ");
   sin(n);
printf("Enter the profits for each of the items : ");
new;
for(i=0;i<n;i++){
    sin(p[i]);
}
printf("Enter the weights for each of the items : ");
new;
for(i=0;i<n;i++){
    sin(w[i]);
}
bKnap(0,0,0);
    return 0;
}
