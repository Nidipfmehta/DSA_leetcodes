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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* s_step = head;
        ListNode* l_step = head;
        while (l_step != NULL and l_step->next != NULL)
        {
            s_step = s_step->next;
            l_step = l_step->next->next;
        }
        return s_step;
    }
};