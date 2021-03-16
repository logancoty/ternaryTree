#include <iostream>
#include <string>
using namespace std;

const int PSEUDO = 9999999;

struct terTreeNode {
    int val1;
    int val2;
    terTreeNode *left;
    terTreeNode *middle;
    terTreeNode *right;
};

terTreeNode *makeNode(int key) {
   terTreeNode *newNode = new terTreeNode;
   newNode->val1 = key;
   newNode->val2 = PSEUDO;
   newNode->left = newNode->middle = newNode->right = NULL;
   return newNode;
}//terTreeNode() with custom data

void setVal1(terTreeNode *tree, int key){
   tree->val1 = key;
}//setVal1

void setVal2(terTreeNode *tree, int key){
   if (key < tree->val1) {
      //swap vals if key is less than the first value in the tree
      int temp = tree->val1;
      tree->val1 = key;
      tree->val2 = temp;
   } else {
      tree->val2 = key;
   }
}//setVal2

/*terTreeNode* search(terTreeNode *tree, int key) {
   if (tree == NULL)
      return NULL;
   //if key is either value return the tree 
   else if (tree->val1 == key || tree->val2 == key)
      return tree;
   //if key is less than val1, look at left child
   else if (key <= tree->val1)
      return search(tree->left, key);
   //if key is in between two vals, look at middle child
   else if (key > tree->val1 && key <= tree->val2)
      return search(tree->middle, key);
   //if key is greater than val2, look at right child
   else if (key > tree->val2)
      return search(tree->right, key);
   //else return NULL
   else 
      return NULL;
}//search() */
 
void insert(terTreeNode *tree, int key) {
   //Create and return a one-node tree if val2 is pseudo
   if (tree->val2 == PSEUDO) 
      setVal2(tree, key);
   //insert left if key is less than val1
   else if (key <= tree->val1) {
      //make a node if child is NULL
      if (tree->left == NULL)
         tree->left = makeNode(key);        
      else
         insert(tree->left, key);
   }  
   //insert right if key > val2
   else if (key > tree->val2) {
      if (tree->right == NULL)
         tree->right = makeNode(key);        
      else
         insert(tree->right, key);
   }
   //insert middle if key is in between val1 and val2
   else if (key > tree->val1 && key <= tree->val2) {
      if (tree->middle == NULL)
         tree->middle = makeNode(key);        
      else
         insert(tree->middle, key);
   }   
   //else do nothing
   else {}   
}

void print(terTreeNode *tree) {
   //recursive print that prints all vals inorder
   if (tree->left != NULL) {
      cout << "(";
      print(tree->left);
      cout << ") ";
   }
   cout << tree->val1;

   if (tree->middle != NULL) {
      cout << " (";
      print(tree->middle);
      cout << ")";
   }   

   if (tree->val2 != PSEUDO) {
      cout << " " << tree->val2;
   }

   if (tree->right != NULL) {
     cout << " (";
     print(tree->right);
     cout << ")";
  }
}

int main(int argc, char* argv[]) {
   //set command line argument to a variable
   int n = atoi(argv[1]);
   
   //error message if there is a ridiculous paramter
   if (n <= 0) {
      cout << "Invalid paramter value! n must be greater than 0.";
      return 0;
   }
   
   //initialize tree and give it data from standard input (randomized)
   int data;
   cin >> data;
   terTreeNode *tree = makeNode(data);
   
   //insert every value into the tree
   for (int index = 0; index < n; index++){
      cin >> data;
      insert(tree, data);
   }

   //print the tree
   print(tree);
   return 0;
}
