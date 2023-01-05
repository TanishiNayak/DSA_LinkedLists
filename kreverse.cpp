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

}


void printll(node* head){

    while (head!=NULL){

        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL\n";
}

void reversell(node* &head, node* &tail){

    node* prev = NULL;
    node* current = head;
    node* after = NULL;

    while (current != NULL){


        after = current -> next;
        current -> next = prev;

        prev = current;
        current = after;
        
        
    }
    head = tail;
   
}

node* kreversell(node* head, int k){

    if (!head)
        return NULL;


    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;
 
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
        head->next = kreversell(next, k);
 
    return prev;
    
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

    head = kreversell(head, 3);

    printll(head);


    return 0;
}
