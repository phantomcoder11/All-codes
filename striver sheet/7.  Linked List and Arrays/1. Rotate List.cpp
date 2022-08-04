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
    ListNode* rotateRight(ListNode* head, int k) {
        int size=0;
        if(head==NULL) return NULL;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        if(k%size==0) return head;
        k=k%size;
        size=size-k-1;
 
        temp=head;
        
        while(size--){
            temp=temp->next;
        }
        ListNode* front=temp->next;
        ListNode* sec=front;
        temp->next=NULL;
        
        while(front->next){
            front=front->next;
        }
        front->next=head;
        return sec;
    }
};