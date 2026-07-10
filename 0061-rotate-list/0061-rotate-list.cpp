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
    ListNode* findNthNode(ListNode* temp, int k){
        int cnt = 1;
        while(temp != nullptr){
            if(cnt == k) return temp;
            cnt++;
            temp = temp -> next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;
        ListNode* tail = head;
        int len = 1;

        while(tail -> next != nullptr){
            tail = tail -> next;
            len++;
        }
        if(k % len == 0) return head;

        k = k % len;

        tail -> next = head;

        ListNode* newNode = findNthNode(head, len - k);

        head = newNode -> next;
        newNode -> next = nullptr;

        return head;
    }
};

//brute
// ListNode* rotateRight(ListNode* head, int k) {
//         if(head == nullptr || head -> next == nullptr || k == 0) return head;

//         for(int i = 1; i <= k; i++){
//             ListNode* temp = head;
//             ListNode* connect = head;
//             while(temp -> next -> next != nullptr){
//                 temp = temp -> next;
//             }
//             head = temp -> next;
//             head -> next = connect;
//             temp -> next = nullptr;
//         }
//         return head;
        
//     }