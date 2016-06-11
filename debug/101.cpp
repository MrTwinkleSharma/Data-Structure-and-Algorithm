#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node* tail;

node* createNode(int item);
void showStack(node* root);
node* push(node* root,int item);
node* pop(node* root,int* popItem);

int main(){
    node *root,*nptr,*tptr;
    root=NULL;
    int popItem,height;


    cout<<"STACK ITEMS: ";
    cin>>height;
    //enter values
    tail=root;
    for(int i=0;i<height;i++){
        int item;
        cout<<"PUSH: ";
        cin>>item;
        //push node into stack
        tptr=push(tptr,item);
    }

    cout<<"TAIL: "<<tail->data<<endl;

    //pop values
    int popNum;
    cout<<"How many items to Pop: ";
    cin>>popNum;
    /*
    if(popNum>=height){
        cout<<"INVALID INPUT"<<end;
    }
    */
    for(int i=0;i<popNum;i++){
        tptr=pop(tptr,&popItem);
    }

    //display stack (linked List)

    tptr=root;
    cout<<"AFTER POP"<<endl;
    showStack(tptr);
}

node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}

void showStack(node* root){
    if(root==NULL){
        cout<<"STACK EMPTY"<<endl;
        return;
    }
    while(true){
        cout<<root->data<<endl;
        if(root->next==NULL){
            break;
        }
        root=root->next;
    }
}

node* push(node* root,int item){
    node *nptr,*tptr;
    nptr=new node;
    nptr=createNode(item);

    if(root==NULL){
        root=nptr;
        //tptr=nptr;
    }else{
        tptr=root;
        root=nptr;
        nptr->next=tptr;
    }
    return root;
}

node* pop(node* root,int* popItem){

    if(root==NULL){
        cout<<"\nSTACK EMPTY"<<endl;
        return 0;
    }else{
        node* tptr;
        tptr=root;
        tptr=tptr->next;
        *popItem=root->data;
        cout<<"POP: "<<*popItem<<endl;
        delete root;
        return tptr;
    }


}
