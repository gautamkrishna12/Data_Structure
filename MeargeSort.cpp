#include<iostream>
using namespace std;
void Merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++,i++;
        }
        else{
            arr[k]=b[j];
            k++,j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        i++,k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++,k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        Merge(arr,l,mid,r);
    }
}
int main(){
    int arr[10],n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"\nEnter the array elements :\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    cout<<"The sorted array is : \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
