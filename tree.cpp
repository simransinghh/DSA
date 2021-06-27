#include <bits/stdc++.h>
using namespace std;
struct Node
{
 int key;
 struct Node *left, *right;
struct Node *newNode(int item)
{
 struct Node *temp = new Node;
 temp->key = item;
 temp->left = temp->right = NULL;
 return temp;
}

