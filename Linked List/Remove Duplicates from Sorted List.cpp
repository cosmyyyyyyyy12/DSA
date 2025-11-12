#include <iostream>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int data){
            val = data;
            next = NULL;
        }
};

class list{
    public:
        ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->next != NULL && temp->val == temp->next->val){
                ListNode* next = temp->next;
                temp->next = next->next;
                delete(next);
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
    
        void display(ListNode* head){
            ListNode* temp = head;
            while(temp!=NULL){
                cout << temp->val << "->";
                temp = temp->next;
            }
            cout << "NULL";
        }
};

int main(){
    list ll;
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(2);
    headA = ll.deleteDuplicates(headA);
    ll.display(headA);
}