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
    int findlen(ListNode* head){
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) 
            return head; // Edge cases
        
        int n = findlen(head);
        k = k % n; // Ensure k is within [0, n-1]
        if (k == 0) 
            return head; // No rotation needed
        
        ListNode* temp = head;
        for (int i = 0; i < n - k - 1; ++i) {
            temp = temp->next;
        }
        
        ListNode* newHead = temp->next;
        temp->next = nullptr; // Breaking the list at the new end
        
        ListNode* tail = newHead;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        
        tail->next = head; // Connecting the new end to the old head
        
        return newHead;
    }
};