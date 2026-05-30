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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if(list1 != NULL && list2 == NULL){
        //     return list1;
        // }
        // if(list2 != NULL && list1 == NULL){
        //     return list2;
        // }
        // ListNode* dummy = new ListNode(-1);
        // ListNode* head = dummy;
        // while(list1 != NULL && list2 != NULL){
        //      if(list1->val < list2->val){
        //         ListNode* newNode = new ListNode(list1->val);
        //         dummy->next = newNode;
        //         list1 = list1 -> next;
        //      }
        //      else{
        //         ListNode* newNode = new ListNode(list2->val);
        //         dummy->next = newNode;
        //         list2 = list2 -> next;
        //      }
        //      dummy = dummy->next;
        // }
        // while(list1!=NULL){
        //     dummy->next = list1;
          
        // }
        // while(list2!=NULL){
        //     dummy->next = list2;
         
        // }
        // return head->next;
        ListNode* dummy = new ListNode(-1);;
        ListNode* node = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }

        if (list1) {
            node->next = list1;
        } else {
            node->next = list2;
        }

        return dummy->next;
    }
};
