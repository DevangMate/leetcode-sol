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
    ListNode* get_kthnode(ListNode* start, int k) {
        int cnt=k;
        while(cnt>0 && start){
            start=start->next;
            cnt--;
        }
        return start;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;
        while(true){
        ListNode* kthnode=get_kthnode(groupPrev,k);
        if(!kthnode) break;
        ListNode* groupnext=kthnode->next;
        ListNode* curr=groupPrev->next;
        ListNode* prev=groupnext;
        for(int i=0;i<k;i++){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        ListNode* temp = groupPrev->next;
        groupPrev->next=kthnode;
        groupPrev = temp;
        }
        return dummy->next;
    }
};