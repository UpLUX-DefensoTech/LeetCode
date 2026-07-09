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
    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* back = nullptr;
        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = back;
            back = temp;
            temp = front;
        }
        return back;
    }

    // Function to get the k-th node from current position
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    // Function to reverse nodes in k-group
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp != nullptr) {
            ListNode* kThNode = getKthNode(temp, k);
            if (kThNode == nullptr) {
                if (prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = nullptr;

            // Reverse current group
            ListNode* newHead = reverseList(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prevLast->next = newHead;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};
