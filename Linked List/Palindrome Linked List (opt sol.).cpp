#include <iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;
        ListNode(int val){
            data = val;
            next = NULL;
        }  
};

class list{
    ListNode* head;
    public:
        list(){
            head = NULL;
        }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next;
        }
        ListNode* first = head;
        ListNode* sec = prev;
        while(sec != NULL){
            if(first->data != sec->data){
                return false;
            }
            first = first->next;
            sec = sec->next;
        }
        return true;
    }
};

int main(){
    list ll;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    bool ans = ll.isPalindrome(head);
    if(ans){
        cout << "true";
    }
    else{
        cout << "false";
    }
}