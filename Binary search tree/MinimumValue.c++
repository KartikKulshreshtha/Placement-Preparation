class Node {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    Node(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
    ~Node() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};

int minValue(Node* root) {
    if(root == NULL) return -1;
    if(root->left == NULL) return root->data;
    return min(minValue(root->left), root->data);
}