#include<iostream>
using namespace std;
void countsort(int arr[],int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }
    int coun[k]={0};
    for(int i=0;i<n;i++){
        coun[arr[i]]++;
    }
    for(int i=1;i<=k;i++){
        coun[i]+=coun[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--coun[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
int main(){
    int n,arr[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
