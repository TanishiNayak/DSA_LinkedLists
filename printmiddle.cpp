// Header Files and namespaces
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    //*******constructor*******
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

node* printmiddle(node* &head, node* &tail){

    node* slow = head;
    node* fast = head;

    while(fast != tail && fast->next->next != NULL){
        
        
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
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

    cout << printmiddle(head, tail) -> data;

    return 0;
}
