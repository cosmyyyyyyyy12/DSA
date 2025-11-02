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
            if(head==NULL){
                head=newNode;
                return;
            }
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;

        }

        void middle(){
            int size = 0;
            Node* temp = head;
            while(temp!=NULL){
                size++;
                temp = temp->next;
            }
            temp = head;
            for(int i=0;i<size/2;i++){
                temp = temp->next;
            }
            cout << "middle of the list is: " << temp->data;
        }
};
int main(){
    list ll;
    ll.insertatend(1);
    ll.insertatend(2);
    ll.insertatend(3);
    ll.insertatend(4);
    ll.insertatend(5);
    ll.middle();
}