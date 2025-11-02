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

        void insertatbegin(int val){
            Node* newNode = new Node(val);    
            if(head == NULL){
                head = newNode;
                return;
            } 
            else{
                newNode->next = head;
                head = newNode;
            }
        }

        void reverse(){
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;
            while(curr!=NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;

            }
            head = prev;
        }

        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL";
        }

};
int main(){
    list ll;
    ll.insertatbegin(3);
    ll.insertatbegin(2);
    ll.insertatbegin(1);
    ll.reverse();
    ll.display();
}