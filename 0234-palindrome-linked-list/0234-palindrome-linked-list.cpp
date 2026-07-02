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
    ListNode* reverseL(ListNode* head) {
        ListNode* temp = head;
        ListNode* back = nullptr;
        while(temp != nullptr){
            ListNode* front = temp -> next;
            temp -> next = back;
            back = temp;
            temp = front;
        }
        return back;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != nullptr && fast -> next -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* newHead = reverseL(slow -> next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second != nullptr){
            if(first -> val != second -> val){
                reverseL(newHead);
                return false;
            }

            first = first -> next;
            second = second -> next;

        }
        reverseL(newHead);
        return true;

    }
};