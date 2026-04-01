#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int find(int in[], int s, int e, int val) {
    for(int i = s; i <= e; i++)
        if(in[i] == val) return i;
}

struct Node* build(int pre[], int in[], int s, int e, int *pi) {
    if(s > e) return NULL;

    struct Node* root = newNode(pre[(*pi)++]);

    if(s == e) return root;

    int idx = find(in, s, e, root->data);

    root->left  = build(pre, in, s, idx-1, pi);
    root->right = build(pre, in, idx+1, e, pi);

    return root;
}

void post(struct Node* root) {
    if(!root) return;
    post(root->left);
    post(root->right);
    printf("%d ", root->data);
}

int main() {
    int n; scanf("%d",&n);
    int pre[n], in[n];

    for(int i=0;i<n;i++) scanf("%d",&pre[i]);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);

    int pi = 0;
    struct Node* root = build(pre, in, 0, n-1, &pi);

    post(root);
    return 0;
}