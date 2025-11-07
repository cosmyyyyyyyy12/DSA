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

    void del(Node* node){
        if(node == NULL || node->next  == NULL){
            return;
        }
        Node* nextNode = node->next;
        node->data = nextNode->data;
        node->next = nextNode->next;
        nextNode->next = NULL;
    }

    void display(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;

    }
};

int main(){
    list ll;
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = new Node(9);
    ll.del(head->next->next);
    ll.display(head);
}