#include<iostream>
using namespace std;
class Node{
public:
    int value;
    Node* next;
    Node(int val){
        value=val;
        next=NULL;
    }
};
void insertatbeginning(Node* &head,int val){
    Node* n=new Node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void insertattail(Node* &head,int val){
    if(head==NULL){
        insertatbeginning(head,val);
        return;
    }
    Node* n=new Node(val);
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void deleteathead(Node* &head){
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    Node* todelete=head;
    temp->next=head->next;
    head=head->next;
    delete todelete;
}
void deletion(Node* &head,int pos){
    if(pos==1){
        deleteathead(head);
        return;
    }
    Node* temp=head;
    int coun=2;
    while(coun!=pos){
        temp=temp->next;
        coun++;
    }
    Node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
void display(Node* head){
    Node* temp=head;
    do{
        cout<<temp->value<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<"NULL"<<endl;
}
int main(){
   Node* head=NULL;
   insertatbeginning(head,1);
   insertattail(head,2);
   insertattail(head,3);
   insertattail(head,4);
   insertattail(head,5);
   insertattail(head,6);
   deletion(head,6);
   //deletion(head,5);
   deletion(head,2);
   display(head);
   return 0;
}
