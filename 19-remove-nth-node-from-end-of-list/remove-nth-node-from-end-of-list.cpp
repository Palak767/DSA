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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *low = dummy;
        ListNode *high = dummy;
        for(int i=0;i<n;i++) high = high -> next;
        while(high -> next != NULL){
            low = low -> next;
            high = high -> next;
        }
        low -> next = low -> next -> next;
        return dummy -> next;
    }
};