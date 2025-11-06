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

    Node* swap(Node* head){
        Node* first = head;
        Node* sec = head->next;
        Node* prev = NULL;

        while(first != NULL && sec != NULL){
            Node* third = sec->next;
            sec->next = first;
            first->next = third;
            if(prev != NULL){
                prev->next = sec;
            }
            else{
                head = sec;
            }
            prev = first;
            first = third;
            if(third != NULL){
                sec = third->next;
            }
            else{
                sec = NULL;
            }
        }
        return head;
    }

    void display(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};

int main(){
    list ll;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    Node* nhead = ll.swap(head);
    ll.display(nhead);
}