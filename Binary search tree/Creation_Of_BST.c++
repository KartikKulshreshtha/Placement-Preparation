#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left,*right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};

node* insertBST(node *root,int val)
{
	if(root==NULL)
	{
		return new node(val);
	}
	if(val<root->data)
	{
		root->left=insertBST(root->left,val);
	}
	else
	{
		root->right=insertBST(root->right,val);
	}
	return root;
}

int main(){
    int arr[]={10,40,45,20,25,30,50},i;
	node* root=NULL;
	for(i=0;i<7;i++)
	{
		root=insertBST(root,arr[i]);
	}
	cout<<"\n";
}