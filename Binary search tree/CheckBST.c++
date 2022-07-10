// All the creation of BST is same

class Solution{
    public:
    bool isBST(Node* root){
        long INT_MIN = -10000;
        long INT_MAX = 10000;
        return isValidate(root, INT_MIN, INT_MAX);
    }

    bool isValidate(Node* root, int minval, int maxval){
        if(root == NULL){
            return true;
        }
        return isValidate(root->left, minval, root->data) && isValidate(root->right, root->data, maxval);
    }
};