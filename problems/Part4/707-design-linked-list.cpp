class Node{
public:
    int val;
    Node* next;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList {
    Node* head;
    int size;
    
public:
    MyLinkedList() {
        this->head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size) return -1;
        Node* temp = head;
        
        if(index == 0)
            return temp->val;
        
        for(int i=0; i<index; i++)
            temp = temp->next;
        
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }
    
    void addAtTail(int val) {
        if(!head) {
            addAtHead(val);
            return;
        }
        
        Node* temp = head;
        Node* node = new Node(val);
        
        while(temp->next)
            temp = temp->next;
        
        temp->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index == 0) {
            addAtHead(val);   
            return;
        }
         
        Node* curr=head, *prev=NULL;
        Node* newNode = new Node(val);
        
        for(int i=0; i<index; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        if(prev) prev->next = newNode;
        newNode->next = curr;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size) return;
        if(index == 0){
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        
        Node* curr=head,*prev=NULL;
        
        for(int i=0; i<index; i++){
            prev = curr;
            curr = curr->next;
        }
        
        if(prev && curr){
            Node* t = curr;
            prev->next = curr->next;
            delete t;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */