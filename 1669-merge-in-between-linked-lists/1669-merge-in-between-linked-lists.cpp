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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* temp=list1;
        ListNode* aa=list1;
        for(int i=1;i<a;i++){
            temp=temp->next;   
        }
        for(int i=1;i<=b;i++){
            aa=aa->next;   
        }
        temp->next=list2;
        while(list2->next!=NULL){
            list2=list2->next;
        }
        list2->next=aa->next;
        aa->next=NULL;
        
        return list1;
    }
};