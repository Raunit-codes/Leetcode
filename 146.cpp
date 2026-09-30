class LRUCache {
private:
    class Node{
    public:
        int key, value;
        Node* prev;
        Node* next;
        Node(int k , int v){
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    void addnode(Node* newnode){
        Node* oldnode = head -> next;
        newnode->next = oldnode;
        newnode->prev = head;
        head->next = newnode;
        oldnode->prev = newnode;
    }
    void deletenode(Node* oldnode){
        Node* oldprev = oldnode -> prev;
        Node*oldnext = oldnode -> next;
        oldprev -> next = oldnext;
        oldnext -> prev = oldprev;
    }

    Node* tail = new Node(-1,-1);
    Node* head = new Node(-1, -1);

    unordered_map<int,Node*> m;
    int limit;
public:
    LRUCache(int capacity) {
        limit = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        int ans = m[key]->value;
        Node* ansnode = m[key];
        m.erase(key);
        deletenode(ansnode);
        addnode(ansnode);
        m[key] = ansnode;
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* oldnode = m[key];
            deletenode(oldnode);
            m.erase(key);
        }
        if(m.size()==limit){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        Node* newnode = new Node(key, value);
        addnode(newnode);
        m[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
