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
class list {
    ListNode* head;
    public:
        list(){
            head = NULL;
        }
        ListNode* reverse(ListNode* head){
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = NULL;
            while(curr != NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            return head;
        }

        ListNode* deepcopy(ListNode* head){
            if(head == NULL){
                return NULL;
            }
            ListNode* temp = head;
            ListNode* newhead = new ListNode(temp->val);
            ListNode* newtemp = newhead;
            temp = temp->next;
            while(temp != NULL){
                ListNode* newNode = new ListNode(temp->val);
                newtemp->next = newNode;
                newtemp = newtemp->next;
                temp = temp->next;
            }
            return newhead;
        }

        void isPalindrome(ListNode* head) {
            ListNode* temp1 = head;
            ListNode* head2 = deepcopy(head);
            ListNode* head3 = reverse(head2);
            ListNode* temp2 = head3;
            while(temp1 != NULL){
                if(temp1->val != temp2->val){
                    cout << "false";
                    return;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            cout << "true";
            return;
    }
};

int main(){
    list ll;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    ll.isPalindrome(head);
}