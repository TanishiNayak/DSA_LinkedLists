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

void deleteatend(node* &head, node* &tail){

    if (head == NULL){

        return;
    }

    else if (head->next == NULL){

        delete head;
        head =  tail = NULL;
    }
    
    else{
        node* t = head;

        while  (t->next != tail){
            t = t -> next;
        }

        delete tail;
        t->next = NULL;
        tail = t;
    }
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

    deleteatend(head,tail);

    printll(head);


    return 0;
}
