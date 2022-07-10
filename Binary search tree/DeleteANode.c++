class Solution{
    public:
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root == NULL) return NULL;
        if(root->data == key){
            return helper(root)
        }
        TreeNode* temp = root;
        while(temp){
            if(temp->data > key){
                if(temp->left != NULL && temp->left->data == key){
                    temp->left = helper(temp->left);
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right != NULL && temp->right->data == key){
                    temp->right = helper(temp->right);
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }

        return temp;
    }


    TreeNode* helper(TreeNode* root){
        if(root->right == NULL) return root->left;
        if(root->left == NULL) return root->right;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findlastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findlastRight(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return root->right;
    }
}