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

node* mergeTwoLists(node* list1, node* list2, node* &head3, node* &tail3) {
        
        node* temp1 = list1;
        node* temp2 = list2;

        while (temp1 != NULL && temp2 != NULL){
            if(temp1 -> data < temp2 -> data){

                int x = temp1 -> data;
                insertatend(head3, tail3, x);
                temp1 = temp1 -> next;
            }

            else if(temp1 -> data > temp2 -> data){

                int x = temp2 -> data;
                insertatend(head3, tail3, x);
                temp2 = temp2 -> next;
            }

            else{

                int x = temp1 -> data;
                insertatend(head3, tail3, x);
                int y =  temp2 -> data;
                insertatend(head3, tail3, y);

                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
        }

        if (temp1 != NULL){

                while (temp1 != NULL){               int x = temp1 -> data;
                insertatend(head3, tail3, x);
                temp1 = temp1 -> next;
                }
        }

        else{
                while (temp2 != NULL){               int x = temp2 -> data;
                insertatend(head3, tail3, x);
                temp2 = temp2 -> next;
                }

        }

        return head3;
    }

void printll(node* x){

    while (x!=NULL){

        cout<<x->data<<"-->";
        x=x->next;
    }
    cout<<"NULL\n";
}

// Code
int main()
{
    node *list1 = NULL, *list2 = NULL, *tail1 = NULL, *tail2 = NULL, *head3 = NULL, *tail3 = NULL;
    insertatend(list1,tail1,1);
    insertatend(list1,tail1,2);
    insertatend(list1,tail1,3);
    insertatend(list1,tail1,4);
    insertatend(list1,tail1,5);

    insertatend(list2,tail2,2);
    insertatend(list2,tail2,3);
    insertatend(list2,tail2,6);
    insertatend(list2,tail2,10);
    insertatend(list2,tail2,11);

    printll(list1);
    printll(list2);


    mergeTwoLists(list1, list2, head3, tail3);

    printll(head3);

    return 0;
}
