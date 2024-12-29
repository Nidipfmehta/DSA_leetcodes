/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) 
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            if (temp->child != NULL)
            {
                Node* temp2 = temp->next;
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
                Node* head1 = flatten(temp->next);
                while(head1->next!=NULL)
                {
                    head1 = head1->next;
                }
                head1->next = temp2;
                if (temp2 != NULL)
                {
                    temp2->prev = head1;
                }
                //temp->next = nextode;
                //nextnode->prev = temp;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};