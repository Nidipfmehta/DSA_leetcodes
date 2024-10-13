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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1==NULL)
        {
            return list2;
        }
        if (list2==NULL)
        {
            return list1;
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp3 = NULL;
        //smaller should be temp1
        if(temp1->val < temp2->val)
        {
            temp3 = list2;
            list2 = list1;
            list1 = temp3;
        }
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->next==NULL)
            {
                temp1->next = temp2;
                break;
            }
            else if (temp1->val <= temp2->val && temp1->next->val > temp2->val)
            {
                //temp3 = temp2->next;
                temp2->next = temp1->next;
                temp1->next = temp2;
                temp1 = temp1->next->next;
                temp2 = temp2->next;
            }
            else
            {
                temp1 = temp1->next;
            }

        }
        return temp1;
    }
};