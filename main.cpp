#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct ArboreNode
{
    struct ArboreNode * left = NULL;
    struct ArboreNode * right = NULL;
    string ingredient = "";
} ;


typedef struct ArboreNode Node;

void inorder(Node * root, ofstream & out)
{
    if(root->left != NULL)
        inorder(root->left, out);
    out << root->ingredient << '\n';
    if(root->right != NULL)
        inorder(root->right, out);
}

void preorder(Node * root, ofstream & out)
{
    out << root->ingredient << '\n';
    if(root->left != NULL)
        preorder(root->left, out);
    if(root->right != NULL)
        preorder(root->right, out);
}

void postorder(Node * root, ofstream & out)
{
    if(root->left != NULL)
        postorder(root->left, out);
    if(root->right != NULL)
        postorder(root->right, out);
    out << root->ingredient << '\n';
}

int main()
{
    Node * root = NULL;
    ofstream out("Sandwich.txt");
    for(int i=0; i<3;i++)
    {
        out<<"Sandwichul clientului numarul "<<i+1<<"creat in inordine este: \n";
        inorder(root, out);
        out<<"Sandwichul clientului numarul "<<i+1<<"creat in preordine este: \n";
        preorder(root, out);
        out<<"Sandwichul clientului numarul "<<i+1<<"creat in postordine este: \n";
        postorder(root, out);
    }
    return 0;
}