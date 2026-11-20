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
        ListNode *low = head;
        ListNode *high = head;
        for(int i=0;i<n;i++) low = low -> next;
        if(!low) return head -> next;
        while(low -> next){
            low = low -> next;
            high = high -> next;
        }
        high -> next = high -> next -> next;
        return head;
    }
};