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
class Solution {
private:
    ListNode* reverseKnode(ListNode* head, int k, ListNode*& nexthead)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nnext = head;
        while(curr!=NULL && k>0)
        {
            //temp = temp->next;
            nnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nnext;
            k--;
        }
        nexthead = nnext;
        return prev;
    }

    int getlength(ListNode* head)
    {
        ListNode* temp = head;
        int n=0;
        while(temp != NULL)
        {
            temp = temp->next;
            n++;
        }
        return n;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(k == 1 || head == NULL)
        {
            return head;
        }
        ListNode* temp = head;
        int l = getlength(head);
        if (l < k)
        {
            return head;
        }
        //k = k % l;
        //int i=0;
        ListNode* newhead = NULL;
        ListNode* prevtail = NULL;
        ListNode* currhead = head;
        while(l>=k)
        {
            //knode = getKnode(temp, k);
            ListNode* nexthead = NULL;
            ListNode* reversehead = reverseKnode(currhead, k, nexthead);
            if(newhead == NULL)
            {
                newhead = reversehead;
            }
            if(prevtail != NULL)
            {
                prevtail->next = reversehead;
            }
            prevtail = currhead;
            currhead = nexthead;
            l -= k;
        }
        
        if (prevtail != NULL)
        {
            prevtail->next = currhead;
        }
        return newhead;
    }
};