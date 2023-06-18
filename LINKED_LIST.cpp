#include<iostream>
using namespace std;
class node{
public:
    int value;
    node* next;
    node(int val){
        value=val;
        next=NULL;
    }
};
void insertattail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void insertathead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
bool searching(node* head,int val){
    while(head!=NULL){
        if(head->value==val){
            return true;
        }
        head=head->next;
    }
    return false;
}
void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
    }
    node* temp=head;
    while(temp->next->value!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
void deleteathead(node* &head){
    node* temp=head;
    head=head->next;
    delete temp;
}
node* reveresing(node* &head){
    node* previous=NULL;
    node* current=head;
    node* cnext;
    while(current!=NULL){
        cnext=current->next;
        current->next=previous;
        previous=current;
        current=cnext;
    }
    return previous;
}
node* recrev(node* &head){
    if(head==NULL||head->next==NULL){
        return head;
    }
   node* newhead=recrev(head->next);
   head->next->next=head;
   head->next=NULL;
   return newhead;
}
node* reversek(node* &head,int k){
    node* previous=NULL;
    node* current=head;
    node* cnext;
    int counter=1;
    while(current!=NULL&&counter<=k){
        cnext=current->next;
        current->next=previous;
        previous=current;
        current=cnext;
        counter++;
    }
    if(cnext!=NULL){
        head->next=reversek(cnext,k);
    }
    return previous;
}
void makeacycle(node* &head,int pos){
    node* temp=head;
    node* startcycle;
    int coun=1;
    while(temp->next!=NULL){
        if(coun==pos){
            startcycle=temp;
        }
        temp=temp->next;
        coun++;
    }
    temp->next=startcycle;
}
bool detectcycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
void deletecycle(node* &head){
    node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next;
    }while(fast!=slow);
    fast=head;
    while(fast->next!=fast->next){
        slow=slow->next;
        fast=fast->next;

    }
    slow->next=NULL;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        insertattail(head,e);
    }
    insertathead(head,6);
    //deletion(head,7);
    display(head);
    /*cout<<searching(head,6)<<endl;
    node* newhead=reversek(head,3);
    display(newhead);*/
    makeacycle(head,4);
    cout<<detectcycle(head);
    deletecycle(head);
    cout<<detectcycle(head);
    return 0;
}
