#include<queue>
#include<iostream>
using namespace std;
#include"Tree_class.h"

TreeNode<int>* TakeInput(){
  int rootData;
  cout <<"Enter The Root Data : ";
  cin >>rootData;
  TreeNode<int>* root = new TreeNode<int> (rootData);
  queue<TreeNode<int>*> pendingNode;
  pendingNode.push(root);
  while(!pendingNode.empty())
  {
    TreeNode<int>* front = pendingNode.front();
    pendingNode.pop();
    int numChild;
    cout <<"Enter The Number Of Children Of "<<front->data<<endl;
    cin >>numChild;
    for(int i=0;i<numChild;i++)
    {
      int childData;
      cout <<"Enter The "<<i<<"Th Child Of "<<front->data<<endl;
      cin >>childData;
      TreeNode<int>* child = new TreeNode<int> (childData);
      front->children.push_back(child);
      pendingNode.push(child);
    }
  }
  return root;
}

//Preorder

void postorder(TreeNode<int>* root)
{
  if(root==NULL)
  {
    return ;
  }
    for(int i=0;i<root->children.size();i++)
    {
        postorder(root->children[i]);
    }
    cout <<root->data<<" ";
}

int main()
{
  TreeNode<int>* root  = TakeInput();
  postorder(root);
  delete root;
}
