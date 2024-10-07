#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    char data;
    Node* next;

    Node()
    {
        this->data;
        this->next = NULL;
    }
};

int main()
{
    string c1;
    getline(cin, c1);
    cout<<"\n";
    Node* head = new Node();
    head->data = c1[0];
    Node* temp = head;
    Node* prev = head;
    for(int i=1; i<c1.length(); i++)
    {
        Node* newnode = new Node();
        newnode->data = c1[i];
        newnode->next = head;
        head = newnode;
    }
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp = temp->next;
    }
}