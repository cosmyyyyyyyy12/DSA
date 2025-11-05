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

class linkedlist{
    Node* head;
    public:
    linkedlist(){
        head = NULL;
    }

    void display(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    Node* reversekgroup(Node* head, int k){
        if(head == NULL){
            return head;
        }

        Node* temp = head;
        int cnt = 0;
        while(cnt<k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            cnt++;
        }

        Node* prevNode = reversekgroup(temp,k);
        Node* next;
        temp = head;
        cnt = 0;
        while(cnt < k){
            next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }
        return prevNode;
    }
};

int main(){
    linkedlist ll;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int k = 3;
    Node* head1 = ll.reversekgroup(head,k);
    ll.display(head1);
}