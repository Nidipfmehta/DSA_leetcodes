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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) {
            return NULL;
        }
        ListNode* temp = headA;
        vector<ListNode*> nodes;
        while(temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }
        temp = headB;
        while(temp) {
            if(find(begin(nodes), end(nodes), temp) != end(nodes)) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};