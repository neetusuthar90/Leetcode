//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* contructTree(int in[], int post[], int inStart, int inEnd, int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd){
        return NULL;
    }
    
    Node* root = new Node(post[postEnd]);
    int rIdx;
    for(int i = inStart; i <= inEnd; i++){
        if (root->data == in[i]){
            rIdx = i;
            break;
        }
    }
    //int rIdx = mp[post[postEnd]];
    int nElem = rIdx - inStart;
    
    root->left = contructTree(in, post, inStart, rIdx-1, postStart, postStart+nElem-1);
    root->right = contructTree(in, post, rIdx+1, inEnd, postStart+nElem, postEnd-1);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    /*map<int,int> mp;
    for(int i =0; i < n; i++){
        mp[in[i]] = i;
    }
    Node* root = contructTree(in, post, 0, n-1, 0, n-1,mp);
    */
    Node* root = contructTree(in, post, 0, n-1, 0, n-1);
    return root;
}
