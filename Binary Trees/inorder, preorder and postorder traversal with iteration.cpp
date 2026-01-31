#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

node* buildTree(node* root){
    cout << "Enter the data " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    
    cout << "Enter data for inserting in left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void inorder(node* root){
    stack <node*> st;
    node* temp = root;

    while (temp != NULL || !st.empty()) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void preorder(node* root){
    if(root == NULL) return;
    stack <node*> st;
    st.push(root);
    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
}

void postorder(node* root){
    if(root == NULL) return;
    stack <node*> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        node* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left) st1.push(temp->left);
        if(temp->right) st1.push(temp->right);
    }
    while(!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}
int main() {
    node* root = NULL;
    root = buildTree(root);
    
    cout << "inorder traversal: " << endl;
    inorder(root);
    
    cout << endl << "preorder traversal: " << endl;
    preorder(root);
    
    cout << endl << "postorder traversal: " << endl;
    postorder(root);
    return 0;
}