// Header Files and namespaces
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

};

void printll(node* head){

    while (head!=NULL){

        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL\n";
}

void printfrombackK(node* &head, node* &tail, int k){

    node* slow = head;
    node* fast = head;

    for (int i = 0 ; i < k ; i++){
        fast = fast -> next;
    }

    while(fast != tail){
        slow = slow -> next;
        fast = fast -> next;
    }

    cout<< slow -> data;
}

// Code
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
    
    printfrombackK(head, tail, 2);

    return 0;
}
