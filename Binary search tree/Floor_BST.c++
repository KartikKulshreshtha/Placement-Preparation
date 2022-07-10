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


int findFloor(Node* root, int x){
    int floor = -1;
    while(root){
        if(root->data == x){
            floor = root->data;
            return floor;
        }
        else if(root->data > x){
            root = root->left;
        }
        else{
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}