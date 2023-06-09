#include <iostream>
#include <algorithm>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};
struct node* FindMin(struct node* node)
{
    struct node* Min = node;
    while (Min && Min->left != NULL)
        Min = Min->left;
 
    return Min;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->key<<" ";
        traverseInOrder(root->right);
    }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == NULL)
    {
      struct  node *temp = (struct node *)malloc(sizeof(struct node));
      temp->key=key;
      temp->left=temp->right=NULL;
      return temp;
    }

  if (node->key > key)
    {
      node->left = insertNode (node->left, key);
    }

  else
    {
      node->right = insertNode (node->right, key);
    }
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root==NULL)return root;
  else if (key < root->key) root->left=deleteNode(root->left,key);
  else if (key > root->key) root->right=deleteNode(root->right,key);
  else {
    if (root->left==NULL && root->right==NULL){
      delete root;
      root = NULL;
    }
    else if (root->right== NULL){
      struct node *temp = root;
      root = root->left;
      delete temp;
    }
    else if (root->left== NULL){
      struct node *temp = root;
      root = root->right;
      delete temp;
    }
    else {
      struct node * temp= FindMin(root->right);
      root->key=temp->key;
      root->right=deleteNode(root->right,temp->key);
    }
  } 
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}