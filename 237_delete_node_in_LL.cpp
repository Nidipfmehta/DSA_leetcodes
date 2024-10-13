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
    void deleteNode(ListNode* node) 
    {
        ListNode* next_node = node->next;
        ListNode* temp = node;
        //if(next_node == NULL)
        //{
        //    return;
        //}
        while(next_node->next!=NULL)
        {
            temp->val = next_node->val;
            temp = temp->next;
            next_node = next_node->next;
        }
        temp->val = next_node->val;
        temp->next = NULL;
    }
};