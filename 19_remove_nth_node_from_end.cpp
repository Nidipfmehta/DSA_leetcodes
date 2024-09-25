/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int c=0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            temp = temp->next;
            c++;
        }
        if(n==c)
        {
            ListNode* new_head = head->next;
            return new_head;
        }
        temp = head;
        ListNode* temp1 = temp;
        for (int i=0; i<c-n; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        return head;
    }
};