class LRUCache {
public:
    class node{
    public:
        int key_;
        int val_;
        node* prev,*next;
        node(int key,int value){
        key_=key;
        val_=value;
    }
    };
    
    node* head= new node(-1,-1);
    node* tail= new node(-1,-1);
    int size;
    unordered_map<int,node *>m;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node* x=m[key];
            int ans=x->val_;
            m.erase(key);
            deletenode(x);
            addnode(x);
            m[key]=head->next;
            return ans;
        }
        return -1;

    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* existingnode=m[key];
            m.erase(key);
            deletenode(existingnode);
            
        }
         if(m.size()==size){
            node* x=tail->prev;
            m.erase(x->key_);
            deletenode(x);  
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
    
    void addnode(node* newnode){
        node* x=head->next;
        newnode->next=x;
        newnode->prev=head;
        head->next=newnode;
        x->prev=newnode;
    }
    void deletenode(node* x){
        node* a=x->prev;
        node* b=x->next;
        a->next=b;
        b->prev=a;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */