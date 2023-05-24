#include<iostream>
using namespace std;
int GetBit(int n,int pos){
    return(1&(n>>pos));
}
int setBit(int n,int pos){
    return(n|(1<<pos));
}
int clearBit(int n,int pos){
    int mask=~(1<<pos);
    return(n&mask);
}
int updateBit(int n,int pos,int val){
    int mask=~(1<<pos);
    n=n&mask;
    return(n|(val<<pos));
}
int totalBit(int n){
    int coun;
    while(n){
        n=(n&(n-1));
        coun++;
    }
    return coun;
}
int ispower2(int n){
    return(n&(n-1));
}
int main(){
    /*cout<<GetBit(5,2);
    cout<<setBit(5,1);
    cout<<clearBit(7,1);
    cout<<updateBit(5,1,1);*/
    //cout<<totalBit(12);
    cout<<ispower2(102);
    return 0;
}
