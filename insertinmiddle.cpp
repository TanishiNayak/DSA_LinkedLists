
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    //****************constructor*****************creation of a dynamic node*****************
    node(int d){

        data = d;
        next = NULL;

    }
};

int lengthll(node* head){
    int ans=0;
    while (head!=NULL){
        head = head -> next;
        ans++;

    }

    return ans;
}

void insertatfront(node* &head, node* &tail, int d){

    if (head==NULL){
        node* n = new node(d); //creation of node (pointer) n
        head=tail=n; // n points to head and tail
    }

    else{
        node* n = new node(d); 
        n->next = head; //next(address) of new node points towards head
        head=n; // head points towards n(new node)
    }

}

void insertatend(node* &head, node* &tail, int d){

    if (head==NULL){
        node* n = new node(d); //creation of node (pointer) n
        head=tail=n; // n points to head and tail
    }

    else{
        node* n = new node(d); 
        tail ->next = n; //next(address) of new node points towards tail
        tail=n; // tail points towards n(new node)
    }

}

void insertinmiddle(node* &head, node* &tail, int d, int pos){

    if (pos==0){
        insertatfront(head,tail,d);
    }

    else if (pos>=lengthll(head)){
        insertatend(head,tail,d);
    }
    else{
        node* t = head;
        for (int i=1 ; i<=pos-1 ; i++){

            t=t->next;
        }
        
            node* n = new node(d); 
            n->next = t->next; //next(address) of new node points towards tail
            t -> next = n; // tail points towards n(new node)
    }
}


void printll(node* head){

    while (head!=NULL){

        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL\n";
}

int main()
{
    node *head = NULL, *tail = NULL;
    int fr;
    cout<<"how many elements do you want to insert at the front? ";
    cin>>fr;

    for (int start=0 ; start<fr ; start++){

        int elem;
        cout<<"Enter element: ";
        cin>>elem;
        insertatfront(head,tail,elem);

    }

    printll(head);

    insertinmiddle(head,tail,100,2);
    insertinmiddle(head,tail,100,11);
    insertinmiddle(head,tail,100,0);

    printll(head);


    return 0;
}
