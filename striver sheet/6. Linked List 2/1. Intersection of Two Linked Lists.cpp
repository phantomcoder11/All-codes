/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Approach 1 Space Complexity O(n)
        // unordered_map<ListNode*, int>m;
        // while(headA){
        //     m[headA]=1;
        //     headA=headA->next;
        // }
        // while(headB){
        //     if(m.find(headB)!=m.end()){
        //         return headB;
        //     }
        //     headB=headB->next;
        // }
        // return NULL;
        // Approach 2 Space Complexity O(1)
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* ptr1=headA, *ptr2=headB;
        while(ptr1!=ptr2){
            ptr1= (ptr1)?ptr1->next:headB;
            ptr2= (ptr2)?ptr2->next:headA;
        }
        return ptr1;
    }
};