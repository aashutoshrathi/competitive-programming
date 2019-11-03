#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
};

TreeNode* createNode(int value) {
    TreeNode *temp = new TreeNode();
    temp->value = value;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert(TreeNode* node, int val) {
    if(node == NULL) {
        return createNode(val);
    }
    if(val < node->value) {
        node->left = insert(node->left, val);
    }
    else if(val > node->value) {
        node->right = insert(node->right, val);
    }
    return node;
}

TreeNode* rm(TreeNode* node, int val) {
    if(node == NULL) {
        return node;
    }
    if(val < node->value) {
        node->left = rm(node->left, val);
    }
    else if(val > node->value) {
        node->right = rm(node->right, val);
    }
    else {
        if (node->left == NULL) { 
            TreeNode *temp = node->right; 
            free(node); 
            return temp; 
        } else if (node->right == NULL) { 
            TreeNode *temp = node->left; 
            free(node); 
            return temp; 
        }
        TreeNode* temp = node->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        node->value = temp->value; 
        node->right = rm(node->right, temp->value);
    }
    return node;
}

int LCA(TreeNode* root, int left, int right) {
    // cout << root->value << " " << left << " " << right << endl;
    if(root == NULL)
        return -1;
    else if(root->value < min(left, right)) {
        return LCA(root->right, left, right);
    }
    else if(root->value > max(left, right)) {
        return LCA(root->left, left, right);
    }
    return root->value;
}

void inorder(TreeNode* node) {
    if(node != NULL) {
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
}

void pre(TreeNode* node) {
    if(node != NULL) {
        cout << " " << node->value;
        pre(node->left);
        pre(node->right);
    }
}

void post(TreeNode* node) {
    if(node != NULL) {
        post(node->left);
        post(node->right);
        cout << " " << node->value;
    }
}

int main() {
    TreeNode *root = NULL;
    root = insert(root, 15);
    insert(root, 5);
    insert(root, 3);
    insert(root, 10);
    insert(root, 20);
    insert(root, 9);

    inorder(root);

    cout << endl;
    // rm(root, 10);
    // inorder(root);
    // cout << endl;
    cout << LCA(root, 3, 5) << endl;

}
