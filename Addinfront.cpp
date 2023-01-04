#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
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
// Code
int main()
{
    node *head = NULL, *tail = NULL;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    for (int i = 0; i < n; i++){
        int x;
        cin>>x;
        insertatfront(head,tail,x);
    }
    printll(head);


    return 0;
}
