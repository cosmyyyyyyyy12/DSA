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
        ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* even_head = head->next;
        ListNode* odd = head;
        ListNode* even = even_head;
        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = even_head;
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
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    headA = ll.oddEvenList(headA);
    ll.display(headA);
}