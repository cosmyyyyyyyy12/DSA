#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
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

        void insertatend(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                return;
            }
            else{
                Node* temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void middle(){
            Node* slow = head;
            Node* fast = head;
            while(fast!=NULL && fast->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << "middle element of the list: " << slow->data;
        }
};

int main(){
    list ll;
    ll.insertatend(1);
    ll.insertatend(2);
    ll.insertatend(3);
    ll.insertatend(4);
    ll.insertatend(5);
    ll.insertatend(6);
    ll.middle();
}