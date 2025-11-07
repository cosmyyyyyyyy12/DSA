class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class MyLinkedList {
    Node* head;
    int size;
public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size || index < 0){ // when (index == size) the code may traverse too far or out of bounds
            return -1;
        }
        else if(head == NULL){
            return -1;
        }
        else{
            Node* temp = head;
            for(int i=0;i<index;i++){
                temp = temp->next;
            }
            if(temp == NULL){
                return -1;
            }
            else{
                return temp->data;
            }
        }
    }
    
    void addAtHead(int val) {
        // create a new node
        Node* newNode = new Node(val);

        // if the list is empty
        if(head == NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }

        // size is inc.
        size++;
    }
    
    void addAtTail(int val) {
        // create a new node
        Node* newNode = new Node(val);

        // if list is empty
        if(head == NULL){
            head = newNode;
        }
        else{
            // create a temp node
            Node* temp = head;
            
            //traverse to the end node
            while(temp->next != NULL){ // if used temp!=null
                temp = temp->next;
            }
            temp->next = newNode; // this line crash the code 
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0){
            return;
        }
        else if(index == 0){
            addAtHead(val);
        }
        else if(index == size){
            addAtTail(val);
        }
        else{
            Node* newNode = new Node(val);
            Node* temp = head;
            for(int i=0;i<index-1;i++){
                temp = temp->next;
            }
            Node* nextNode = temp->next;
            temp->next = newNode;
            newNode->next = nextNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index < 0){
            return;
        }
        else if(index == 0){
            Node* temp = head;
            head = head->next;
            delete(temp);
        }
        else{
            Node* temp = head;
            for(int i=0;i<index-1;i++){
                temp = temp->next;
            }
            Node* nextNode = temp->next;
            if(temp == NULL || temp->next == NULL){
                return;
            }
            else{
                temp->next = nextNode->next;
                nextNode->next = NULL;
                delete(nextNode);
            }
        }
        size--;
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
