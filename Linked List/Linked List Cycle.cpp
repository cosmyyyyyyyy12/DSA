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

        void iscycle(Node* head){
            bool yes = false;
            Node* slow = head;
            Node* fast = head;
            while(fast!=NULL && fast->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    yes = true;
                    cout << "this linked list is a cycle";
                    break;
                }
            }
            if(!yes){
                cout << "this is a linear ll";
            }
        }
};

int main(){
    list ll;
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    Node* temp = head->next;
    head->next->next->next = temp;
    ll.iscycle(head);
}