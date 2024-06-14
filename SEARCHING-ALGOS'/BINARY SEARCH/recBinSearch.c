#include <stdio.h>
int recBinarySearch(char a[], int m, int n, char item);
int main(){int i;
char a[11]={'C', 'E', 'G', 'J', 'L', 'O', 'P', 'T', 'U', 'W', 'Z'};
printf("Elements in an character array: ");
for(i=0;i<11;i++){printf("%c ", a[i]);}
printf("\n\n");
printf("Finding the indexes of \'C\' and \'Q\' via recursive binary search function\n\n");
printf("\'C\' is found at index %d\n\n",recBinarySearch(a,0,10,'C')+1);
if(recBinarySearch(a,0,10,'Q')==-1){printf("Not found!");}
else{
    printf("\'Q\' is found at index %d\n",recBinarySearch(a,0,10,'Q')+1);
}

}

int recBinarySearch(char a[], int m, int n, char item){ int mid; int low=m; int high=n;

if(n==m){
    if(item==a[m]){return m;}
    else{return -1;}
}
else{
    mid=(m+n)/2;
    printf("low = %d, mid = %d and high = %d\n",low+1,mid+1,high+1);
    if(item==a[mid]){return mid;}
    else{
        if(item<a[mid]){return recBinarySearch(a,m,mid-1,item);}
        else{return recBinarySearch(a,mid+1,n,item);}
    }
}
}
