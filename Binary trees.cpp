#include"bits/stdc++.h"
using namespace std;
struct Node{
    int value;
    struct Node* left;
    struct Node* right;
    Node(int val){
        value=val;
        left=NULL;
        right=NULL;
    }
};
void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->value<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->value<<" ";
}
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}
int searching(int arr[],int s,int e,int x){
    for(int i=s;i<=e;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}
Node* Buildtree(int pre[],int in[],int s,int e){
    static int id=0;
    if(s>e){
        return NULL;
    }
    int curr=pre[id];
    id++;
    Node* node=new Node(curr);
    if(s==e){
        return node;
    }
    int pos=searching(in,s,e,curr);
    node->left=Buildtree(pre,in,s,pos-1);
    node->right=Buildtree(pre,in,pos+1,e);
    return node;
}
Node* buildtree(int post[],int in[],int s,int e){
    static int id=4;
    if(s>e){
        return NULL;
    }
    int curr=post[id];
    id--;
    Node* node=new Node(curr);
    if(s==e){
        return node;
    }
    int pos=searching(in,s,e,curr);
    node->right=Buildtree(post,in,pos+1,e);
    node->left=Buildtree(post,in,s,pos-1);
    return node;
}
void levelorder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
       Node* node=q.front();
       q.pop();
       if(node!=NULL){
        cout<<node->value<<" ";
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
       }
       else if(!q.empty()){
        q.push(NULL);
       }
    }
}
int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
}
int sumNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+root->value;
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return (max(left,right)+1);
}
int sumatk(Node* root,int k){
    if(root==NULL){
        return 0;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    int level=0,sum=0;
    while(!q.empty()){
       Node* node=q.front();
       q.pop();
       if(node!=NULL){
       if(level==k){
        sum+=node->value;
       }
       if(node->left){
        q.push(node->left);
       }
       if(node->right){
        q.push(node->right);
       }
       }
       else if(!q.empty()){
        q.push(NULL);
        level++;
       }
    }
    return sum;
}
int calheight(Node* root){
    if(root==NULL){
        return 0;
    }
    return (max(calheight(root->left),calheight(root->right)));
}
int calcdiameter(Node* root){
    int leftheight=calheight(root->left);
    int rightheight=calheight(root->right);
    int currdiameter=leftheight+rightheight+1;
    int ldiameter=calcdiameter(root->left);
    int rdiameter=calcdiameter(root->right);
    return max(currdiameter,max(ldiameter,rdiameter));
}
void sumreplace(Node* root){
    if(root==NULL){
        return;
    }
    sumreplace(root->left);
    sumreplace(root->right);
    if(root->left!=NULL){
        root->value+=root->left->value;
    }
    if(root->right!=NULL){
        root->value+=root->right->value;
    }
}
void rightview(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            Node* curr=q.front();
            q.pop();
            if(i==n){
                cout<<curr->value<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}
void leftview(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(i==0){
                cout<<curr->value<<" ";
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}
int main(){
    int n;
    /*cout<<"Enter the number of data :";
    cin>>n;
    int post[n],in[n];
    cout<<"Enter the postorder expression : ";
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    cout<<"Enter the inorder expression : ";
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    Node* root=buildtree(post,in,0,4);
    postorder(root);*/
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    levelorder(root);
    cout<<endl;
    rightview(root);
    cout<<endl;
    leftview(root);
    return 0;
}
