/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //By Using extra space O(n) space & O(n) Time
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*,Node*>m;
//         Node* temp=head;
//         while(temp){
//             m[temp]=new Node(temp->val);
//             temp=temp->next;
//         }
        
//         temp=head;
//         while(temp){
//             if(temp) m[temp]->next=m[temp->next];
//             else m[temp]->next=NULL;
//             temp=temp->next;
//         }
//         temp=head;
//         while(temp){
//             if(temp->random) m[temp]->random=m[temp->random];
//             else m[temp]->random=NULL;
//             temp=temp->next;
//         }
        
//         return m[head];
//     }
    
    //Most optimized way O(1)space ingoring the extra space and O(n) time complexity
    Node* copyRandomList(Node* head) {
        Node* curr=head,*front=head;
        
        //here we made the copies and inserted in between the original nodes
        while(curr){
            front=curr->next;
            Node* copy=new Node(curr->val);
            curr->next=copy;
            copy->next=front;
            curr=front;
        }
            
        curr=head;
        
        while(curr){
            if(curr->random)curr->next->random=curr->random->next;
            else curr->next->random=NULL;
            curr=curr->next->next;
        }
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        curr=head;
        while(curr){
            front=curr->next->next;
            temp->next=curr->next;
            curr->next=front;
            curr=curr->next;
            temp=temp->next;
        }
        return dummy->next;
            
            
    }
};