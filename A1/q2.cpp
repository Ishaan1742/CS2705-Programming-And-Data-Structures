#include<bits/stdc++.h>
using namespace std;

//doubly linked list node
struct node
{
    int data;
    node* next; //pointer to next node
    node* prev; //pointer to previous node
    node(int x) //constructor
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void printList(node* head)
{
    node* temp = head;
    while(temp!=NULL) //traverse the list and print
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void printListReverse(node* tail)
{
    node* temp = tail;
    while(temp!=NULL) //traverse the list in reverse and print
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

void fit_linked_list_at_desired_spot(node* head1, node* head2, node* tail1, node* tail2, char ch, int pos, int l1, int l2)
{
    //disconnect the second list from the first
    tail1->next = NULL;
    head2->prev = NULL;
    //declare new heads and new tails
    node* new_head = head1;
    node* new_tail = tail1;
    if(ch == 'L') //second list has to be inserted at the 'pos' position from the left
    {
        if(pos == 1) //second list is right at the beginning of the combined list
        {
            tail2->next = head1;
            head1->prev = tail2;
            new_head = head2;
        }
        else //general case
        {
            node* temp = head1;
            for(int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            tail2->next = temp->next;
            temp->next->prev = tail2;
            temp->next = head2;
            head2->prev = temp;
        }
    }
    else //second list has to be inserted at the 'pos' position from the right
    {
        if(pos == l1) //second list is right at the beginning of the combined list
        {
            tail2->next = head1;
            head1->prev = tail2;
            new_head = head2;
        }
        else //general case
        {
            node* temp = tail1;
            for(int i = 1; i <= pos; i++)
            {
                temp = temp->prev;
            }
            tail2->next = temp->next;
            temp->next->prev = tail2;
            temp->next = head2;
            head2->prev = temp;
        }
    }
    printList(new_head);
    printListReverse(new_tail);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int l1, l2;
    cin >> l1 >> l2;
    node* head1 = NULL;
    node* head2 = NULL;
    node* tail1 = NULL;
    node* tail2 = NULL;
    for(int i = 0; i < l1; i++)
    {
        int x;
        cin >> x;
        node* temp = new node(x);
        if(head1 == NULL)
        {
            head1 = temp;
            tail1 = temp;
        }
        else
        {
            tail1->next = temp;
            temp->prev = tail1;
            tail1 = temp;
        }
    }
    for(int i = 0; i < l2; i++)
    {
        int x;
        cin >> x;
        node* temp = new node(x);
        if(head2 == NULL)
        {
            head2 = temp;
            tail2 = temp;
        }
        else
        {
            tail2->next = temp;
            temp->prev = tail2;
            tail2 = temp;
        }
    }
    //given that second list is attached to the end of the first list
    tail1->next = head2;
    head2->prev = tail1;
    char ch;
    int pos;
    cin >> ch >> pos;
    fit_linked_list_at_desired_spot(head1, head2, tail1, tail2, ch, pos, l1, l2);
}
