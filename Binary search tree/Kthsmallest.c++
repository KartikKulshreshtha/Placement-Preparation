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


void solve(Node* root, vector<int> &res){
	if(root == NULL){
		return;
	}
	solve(root->left, res);
	res.push_back(root->data);
	solve(root->right, res);
}

int kthsmallest(Node *root, int K) {
	vector<int> res;
	solve(root, res);
	if(K > res.size()) return -1;
	return res[K-1];
}

int main(){
    int arr[]={10,40,45,20,25,30,50},i;
	node* root=NULL;
	for(i=0;i<7;i++)
	{
		root=insertBST(root,arr[i]);
	}
	cout<<"\n";
    int k = 1;
    int j = 0;
    int large = kthsmallest(root, k, j);
    cout<<"Smallest element is "<<large;
}