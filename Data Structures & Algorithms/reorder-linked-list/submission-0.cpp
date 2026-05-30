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
    // void reorderList(ListNode* head) {
    //     vector<int> ans,temp;

    //     while(head){
    //         ans.push_back(head->val);
    //         head = head->next;
    //     }

    //     ListNode* dummy = new ListNode(-1);

    //     ListNode* helper = dummy;
    //     int n = ans.size();
    //     for(int i = 0 ; i < n/2 ; i++){
    //         temp.push_back(ans[i]);
    //         if(i!=n-1-i){
    //             temp.push_back(ans[n-1-i]);
    //         }
    //     }
    //     for(int i = 0 ; i < n ; i++){
    //         cout<<temp[i];
    //         ListNode* newNode = new ListNode(temp[i]);
    //         helper->next = newNode;
    //         helper = helper->next;
    //     }
     

    // }
   void reorderList(ListNode* &head) {
    if (!head || !head->next) return;  // Handle empty or single-node list

    vector<int> ans, temp;

    // Collect values from the original list
    ListNode* current = head;
    while (current) {
        ans.push_back(current->val);
        current = current->next;
    }

    int n = ans.size();
    
    // Populate the temp vector with the desired reordering
    for (int i = 0; i < (n + 1) / 2; ++i) {
        temp.push_back(ans[i]);
        if (i != n - i - 1) {
            temp.push_back(ans[n - i - 1]);
        }
    }

    // Rebuild the linked list
    ListNode* dummy = new ListNode(-1);
    ListNode* helper = dummy;
    for (int i = 0; i < temp.size(); ++i) {
        ListNode* newNode = new ListNode(temp[i]);
        helper->next = newNode;
        helper = helper->next;
    }

    // Make sure the final node points to nullptr
    helper->next = nullptr;

    // Update the head to point to the new reordered list
    head = dummy->next;

    // Clean up the dummy node
    delete dummy;
}

};
