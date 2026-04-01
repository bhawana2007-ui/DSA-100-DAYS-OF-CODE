#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

int find(int in[], int s, int e, int val) {
    for(int i = s; i <= e; i++)
        if(in[i] == val) return i;
}

struct Node* build(int in[], int post[], int s, int e, int *pi) {
    if(s > e) return NULL;

    struct Node* root = newNode(post[(*pi)--]);

    if(s == e) return root;

    int idx = find(in, s, e, root->data);

    // build right first!
    root->right = build(in, post, idx+1, e, pi);
    root->left  = build(in, post, s, idx-1, pi);

    return root;
}

void preorder(struct Node* root) {
    if(!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n; scanf("%d",&n);
    int in[n], post[n];

    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    for(int i=0;i<n;i++) scanf("%d",&post[i]);

    int pi = n-1;
    struct Node* root = build(in, post, 0, n-1, &pi);

    preorder(root);
    return 0;
}