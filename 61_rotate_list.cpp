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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* temp;
        ListNode* nhead;
        int n=0;
        temp = head;
            while(temp != NULL)
            {
                temp = temp->next;
                n++;
            }
        nhead = head;
        k = k%n;
        if(k == 0)
        {
            return head;
        }
        cout<<"k = "<<k<<"n = "<<n<<endl;
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
        temp = head;
        for(int i=0; i<n-k-1; i++)
        {
            temp = temp->next;
        }
        nhead = temp->next;
        temp->next = NULL;
        return nhead;
    }
};