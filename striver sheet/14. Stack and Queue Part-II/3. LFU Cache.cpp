class Node{
    public:
   int count,val_,key_;
    Node* next;
    Node* prev;
    Node(int key,int val){
        val_=val;
        key_=key;
        count=1;
    }
};

class List{
    public:
    int size;
    Node* head;
    Node* tail;
    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addnode(Node* x){
        Node* temp=head->next;
        x->prev=head;
        x->next=temp;
        head->next=x;
        temp->prev=x;
        size++;
    }
    void deletenode(Node* x){
        Node* delprev=x->prev;
        Node* delnext=x->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};
class LFUCache {
public:
    map<int,Node*>keyNode;
    map<int,List*>freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;
    
    LFUCache(int capacity) {
        maxSizeCache=capacity;
        currSize=0;
        minFreq=0;
    }
    void updateList(Node* node){
        keyNode.erase(node->key_);
        freqListMap[node->count]->deletenode(node);
        if(node->count==minFreq && freqListMap[node->count]->size==0){
            minFreq++;
        }
        List* updatedList = new List();
        if(freqListMap.find(node->count+1)!=freqListMap.end()){
            updatedList=freqListMap[node->count+1];
        }
        node->count+=1;
        updatedList->addnode(node);
        freqListMap[node->count]=updatedList;
        keyNode[node->key_]=node;
    }
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* x=keyNode[key];
           
            int ans=x->val_;
            updateList(x);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(maxSizeCache==0) return;
        
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->val_=value;
            updateList(node);
        }else{
           
            if(currSize == maxSizeCache){
                List* list=freqListMap[minFreq];
            keyNode.erase(list->tail->prev->key_);
            freqListMap[minFreq]->deletenode(list->tail->prev);
            
            currSize--;
            }
            
            currSize++;
            minFreq=1;
            Node* node=new Node(key,value);
            List* list = new List();
            
            if(freqListMap.find(minFreq)!=freqListMap.end()) list=freqListMap[minFreq];
            
            list->addnode(node);
            keyNode[key]=node;
            freqListMap[minFreq]=list;
        }
        
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */