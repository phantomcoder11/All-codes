    Node* merge(Node* t1,Node* t2){
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(t1 && t2){
            if(t1->data<=t2->data){
                temp->bottom=t1;
                t1=t1->bottom;
                temp=temp->bottom;
            }else{
                temp->bottom=t2;
                t2=t2->bottom;
                temp=temp->bottom;
            }
        }
        while(t1){
                temp->bottom=t1;
                t1=t1->bottom;
                temp=temp->bottom;
        }
        while(t2){
                temp->bottom=t2;
                t2=t2->bottom;
                temp=temp->bottom;
        }
        
        return dummy->bottom;
    }
Node *flatten(Node *root)
{
   // Your code here
  Node* temp=root,*x=root;
    while(temp->next){
        x=merge(x,temp->next);
        temp=temp->next;
    }

    return x;
}