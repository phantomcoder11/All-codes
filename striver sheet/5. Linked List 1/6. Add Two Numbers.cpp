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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int sum;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp;
        temp=dummy;
        while(l1 && l2){
            sum=(l1->val+l2->val+carry);
            temp->next=new ListNode(sum%10);
            carry=(sum)/10;
            l1=l1->next;
            l2=l2->next;
            temp=temp->next;
        }
        while(l1){
            cout<<l1->val<< " "<<carry;
            sum=(l1->val+carry);
            temp->next=new ListNode(sum%10);
            cout<<" "<<sum<<endl;
            carry=(sum)/10;
            l1=l1->next;
            temp=temp->next;
        }
        while(l2){
            sum=(l2->val+carry);
            temp->next=new ListNode(sum%10);
            carry=(sum)/10;
            l2=l2->next;
            temp=temp->next;
        }
        if(carry){
            temp->next=new ListNode(1);
        }
        return dummy->next;
    }
};