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

class Linkedlist{
    public:
        Node* head;
        Linkedlist(){
            head = NULL;
        }
        void insertatbegin(int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
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

        void insertatspecificloc(int index,int val){
            Node* newNode = new Node(val);
            Node* temp=head;
            if(index==0){
                insertatbegin(val);
                return;
            }
            for(int i=0; temp!=NULL && i < index-1;i++){
                temp=temp->next;
            }
            if(temp==NULL){
                cout << "out of range" << endl;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }

        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout << temp->data << " -> ";
                temp=temp->next;
            }
            cout << "NULL";
        }
};
int main(){
    Linkedlist list;
    list.insertatbegin(10);
    list.insertatend(20);
    list.insertatbegin(30);
    list.insertatend(40);
    list.insertatspecificloc(2,50);
    cout << "Linkedlist" << endl;
    list.display();
}
