class Solution{
    public:
    Node* BSTfromPreorder(vector<int>& A){
        int i = 0;
        return build(A, i, INT_MAX);
    }

    Node* build(vector<int> A, int &i, int bound){
        if(i == A.size() || A[i] > bound) return NULL;
        Node* root = new Node(A[i++]);
        root->left = build(A, i, root->data);
        root->right = bulid(A, i, bound);
        return root;
    }
};