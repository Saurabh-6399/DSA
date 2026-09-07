#include<iostream>  //binary search tree
#define UNDEFIRE_TREE 0
using namespace std;
struct node
{
    int items;
    node *left;
    node *right;
};
class BST{
    private:
        node* root;
    protected:
       void preorderrec(node *);
       void inorderrerc(node *);
       void postorrderrec(node *); 
       node* deleteNode(node*,int);  
    public:
       BST();  
       bool Is_empty(); 
       void Insert(int);
       void preorder(); 
       void Inorder();
       void Postorder();
       void del(int);
       node* search(int);
       ~BST();

};
BST::BST()
{
    root==nullptr;
}
bool BST::Is_empty()
{
    return root==nullptr;
}
void BST::Insert(int data)
{
    node *ptr;
    node *n=new node;
    n->items=data;
    n->left=nullptr;
    n->right=nullptr;
    if(Is_empty)
    {
        root=n;
    }
    else
    {
        ptr=root;
        while(ptr->items!=data)
        {
            if(data < ptr->items)
            { // go to left subtree
                if(ptr->left!=nullptr)
                {
                    ptr=ptr->left;
                }
                else{
                    ptr->left=n;
                    break;
                }
            }
            else
            {//go to right subtree
                if(ptr->right!=nullptr)
                {
                    ptr=ptr->right;
                }
                else{
                    ptr->right=n;
                    break;
                }
            }
        }
        if(ptr->items==data)
        {
            delete n;
        }

    }
}
void BST::preorder() //root left right;
{
    preorderrec(root);
}
void BST::preorderrec(node *ptr)
{
    if(ptr!=nullptr)
    {
        cout<<" "<<ptr->items;
        preorderrec(ptr->left);
        preorderrec(ptr->right);
    }
}
void BST::Inorder()  //left root right
{
    inorderrerc(root);
}
void BST::inorderrerc(node *ptr)
{
    if(ptr!=nullptr)
    {
        inorderrerc(ptr->left);
        cout<<" "<<ptr->items;
        inorderrerc(ptr->right);
    }
}
void BST::Postorder()  //left right root
{
    postorrderrec(root);
}
void BST::postorrderrec(node *ptr)
{
    if(ptr!=nullptr)
    {
        postorrderrec(ptr->left);
        postorrderrec(ptr->right);
        cout<<" "<<ptr->items;
    }
}
void BST::del(int data)
{
    root=deleteNode(root,data);
}
node* BST::deleteNode(node *ptr,int data)
{
    if(ptr==nullptr)
       return ptr;
    if(data < ptr->items)
        ptr->left=deleteNode(ptr->left,data); 
    else if(data > ptr->items)
        ptr->right=deleteNode(ptr->right,data);
    else
    {  // node found;

       // no child
       if(ptr->left==nullptr && ptr->right==nullptr)
       {
           delete ptr;
           return nullptr;
       } 
       // single child
       if(ptr->left==nullptr || ptr->right==nullptr)
       {
          node* parent=ptr;
          delete ptr;
          return parent;
       }
       else  
       {
           // two children
           node *parpred,*pred;
           parpred=ptr;
           pred=ptr->left;
           while(pred->right!=nullptr)
           {
              parpred=pred;
              pred=pred->right;
           }
           ptr->items=pred->items;
           if(parpred->right==pred)
                parpred->right=deleteNode(pred,pred->items);
            else
                parpred->left=deleteNode(pred,pred->items);    
       }

    } 
    return ptr;   
}
node* BST::search(int data)
{
    node* ptr=root;
    while(ptr!=nullptr)
    {
        if(ptr->items==data)
          return ptr;
        if(data<ptr->items)
        {
            ptr=ptr->left;
        } 
        else
        {
            ptr=ptr->right;
        } 
    }
    return nullptr;
}
BST::~BST()
{
    while(root!=nullptr)
    {
        del(root->items);
    }
}