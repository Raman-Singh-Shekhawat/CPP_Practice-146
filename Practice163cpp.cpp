// 164. Construct Tree from Postorder and Inorder: For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

/***********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

BinaryTreeNode<int> *helper(int *postorder, int *inorder, int postS, int postE, int inS, int inE)
{
    if (postS > postE)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postE]);

    int length = 0;
    for (int i = inS; inorder[i] != root->data; i++)
    {
        length++;
    }

    int lPostS = postS;
    int lPostE = postS + length - 1;
    int lInS = inS;
    int lInE = inS + length - 1;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;
    int rInS = lInE + 2;
    int rInE = inE;

    BinaryTreeNode<int> *leftChild = helper(postorder, inorder, lPostS, lPostE, lInS, lInE);
    BinaryTreeNode<int> *rightChild = helper(postorder, inorder, rPostS, rPostE, rInS, rInE);

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder, int inLength)
{
    return helper(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
}