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

        void findidx(Node* head){
            Node* slow = head;
            Node* fast = head;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    slow = head;
                    while(slow != fast){
                        slow = slow->next;
                        fast = fast->next;
                    }
                    cout << "the node from where cycle starts: " << slow->data;
                    break;
                }
            }
        }
};

int main(){
    list ll;
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = head->next;
    ll.findidx(head);
}