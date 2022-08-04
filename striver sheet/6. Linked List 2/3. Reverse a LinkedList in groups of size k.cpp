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
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head==NULL || k==1) return head;
        
        ListNode* curr=head,*prev=NULL,*next,*temp=head;
        int count=0;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
            
        }
        if(length<k) return head;
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=next;
            count++;
        }
        head->next=reverseKGroup(next,k);
        return prev;
    }
};