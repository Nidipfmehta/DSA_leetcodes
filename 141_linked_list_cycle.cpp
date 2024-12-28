/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *small_step = head;
        ListNode *big_step = head;
        while(big_step!=NULL && big_step->next!=NULL)
        {
            small_step = small_step->next;
            big_step = big_step->next->next;
            if(small_step == big_step)
            {
                return true;
            }
        }
        return false;
    }
};