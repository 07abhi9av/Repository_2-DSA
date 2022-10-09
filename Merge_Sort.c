#include <stdio.h>

void Merge(int A[], int l, int h, int mid){
    int i = l;
    int j = mid+1;
    int k = l;
    int B[100];
    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    for(;i<mid;i++){
        B[k++] = A[i];
    }
    for(;j<=h;j++){
        B[k++] = A[j];
    }
    for(i=l;i<=h;i++){  // To copy the elements of B into A
        A[i] = B[i];
    }
}

void Merge_Sort(int A[], int n){   // n is no.of elements
    int p,l,i,h,mid;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A,l,h,mid);
        }

    }
    if(p/2<n){       // If odd elements are present in the list
        Merge(A,0,n-1,p/2-1);
    }
}

int main(){
    int A[]={11,9,14,2,6,3,1};
    int n=7;
    Merge_Sort(A,n);
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    //printf("\n");
    return 0;
}