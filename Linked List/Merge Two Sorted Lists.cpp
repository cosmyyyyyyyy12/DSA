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
    public:
        Node* merge(Node* head1, Node* head2){
            if(head1 == NULL){
                return head2;
            }
            if(head2 == NULL){
                return head1;
            }
            if(head1->data <= head2->data){
                head1->next = merge(head1->next, head2);
                return head1;
            }
            else{
                head2->next = merge(head1, head2->next);
                return head2;
            }
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
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(4);

    Node* head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(4);
    Node* head = ll.merge(head1, head2);
    ll.display(head);
}