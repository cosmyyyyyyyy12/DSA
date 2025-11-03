#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* random;
        Node(int val){
            data = val;
            next = NULL;
        }
};

class list{
    Node* head;
    public: 
        list(){
            head = NULL;
        }

        void display(Node* newhead){
            Node* temp = newhead;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void copy(Node* head){
            if(head == NULL){
                cout << "empty list";
            }
            unordered_map <Node* , Node*> m;
            Node* newhead = new Node(head->data);
            m[head] = newhead;
            Node* oldtemp = head->next;
            Node* newtemp = newhead;
            while(oldtemp != NULL){
                Node* copynode = new Node(oldtemp->data);
                m[oldtemp] = copynode;
                newtemp->next = copynode;
                oldtemp = oldtemp->next;
                newtemp = newtemp->next;
            }
            oldtemp = head;
            newtemp = head;

            while(oldtemp != NULL){
                newtemp->random = m[oldtemp->random];
            }
            display(newhead);
        }
};
