#include <iostream>

using namespace std;

struct node{
    int date;
    struct node *leftchild;
    struct node *rightchild;
};

struct node *root = NULL;

void inserare (int date)
{
    struct node *tempnode = (struct node*) malloc(sizeof(struct node));
    struct node *curent;
    struct node *parent;

    tempnode -> date = date;
    tempnode -> leftchild = NULL;
    tempnode -> rightchild = NULL;

    if (root == NULL)
        root = tempnode;
    else {

        curent = root;
        parent = NULL;

        while(1)
        {
            parent = curent;

            if( date < parent ->date ){
                curent = curent -> leftchild;
                if (curent == NULL){
                    parent -> leftchild = tempnode;
                    return;
                }
            }
            else {
                 curent = curent -> rightchild;
                if (curent == NULL){
                    parent -> rightchild = tempnode;
                    return;
            }
        }
    }
}
}

void IOT(node *root)
{
    if(root == NULL)
        return;
    IOT(root->leftchild);
    cout<<root->date<<" ";
    IOT(root->rightchild);
}

void PreOT(node *root)
{
    if(root == NULL)
        return;
    cout<<root->date<<" ";
    PreOT(root->leftchild);
    PreOT(root->rightchild);
}

void PostOT(node *root)
{
    if(root == NULL)
        return;
    PostOT(root->leftchild);
    PostOT(root->rightchild);
    cout<<root->date<<" ";
}

int main( )
{  
    int i;
    int vector[8]={23, 18 ,16 ,70, 59, 27, 19, 31};    

    for (i=0; i<8; i++)
        inserare(vector[i]); 
    cout<<"Parcurgere in-order a arborelui: ";
    IOT(root);
    cout<<"\nParcurgere pre-order a arborelui: ";
    PreOT(root);
    cout<<"\nParcurgere post-order a arborelui: ";
    PostOT(root);
    cout<<"\n";


      
}