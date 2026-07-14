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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        // Step 1: Reverse the list
        head = reverseList(head);

        // Step 2: Traverse reversed list, keep nodes >= max_so_far
        int max_so_far = INT_MIN;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* curr = head;

        while (curr) {
            if (curr->val >= max_so_far) {
                tail->next = curr;
                tail = curr;
                max_so_far = curr->val;
            }
            curr = curr->next;
        }
        tail->next = nullptr;

        // Step 3: Reverse again to restore original order
        return reverseList(dummy->next);
    }
};
