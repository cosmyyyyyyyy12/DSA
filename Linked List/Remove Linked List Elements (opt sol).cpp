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
        void display(ListNode* head){
            ListNode* temp = head;
            while(temp!=NULL){
                cout << temp->val << "->";
                temp = temp->next;
            }
            cout << "NULL";
        }
        
        ListNode* removeElements(ListNode* head, int val) {
            while(head != NULL && head->val == val){
                ListNode* temp = head;
                head = head->next;
                delete(temp);
            }
            ListNode* curr = head;
            while (curr != NULL && curr->next != NULL) {
                if (curr->next->val == val) {
                    ListNode* next = curr->next;
                    curr->next = next->next; 
                    delete next;
                } 
                else {
                    curr = curr->next;
                }
            }
            return head;
        }
};

int main(){
    list ll;
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(6);
    headA->next->next->next = new ListNode(3);
    headA->next->next->next->next = new ListNode(4);
    headA->next->next->next->next->next = new ListNode(5);
    headA->next->next->next->next->next->next = new ListNode(6);
    headA = ll.removeElements(headA, 6);
    ll.display(headA);
}