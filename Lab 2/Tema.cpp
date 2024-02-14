#include <iostream>
#include <cstring>
using namespace std;

struct node{
int data;
int key;
struct node *next;
};
struct node *head=NULL;
struct node *curent = NULL;

void print_lista(){

struct node *ptr = head;

while (ptr!=NULL)
{
    cout<<"\n[ ";
    cout<<ptr-> key<< " "<<ptr->data;
    ptr=ptr->next;
    cout<<" ] ";
}


}

void inserare_primul(int key, int data){

struct node *link = (struct node*) malloc(sizeof(struct node));
link -> key= key;
link -> data= data;

link -> next= head;
head= link;

}

struct node* sterge (int key) {
struct node* curent= head;
struct node*previous= NULL;
if (head == NULL)
    return NULL;
while (curent ->key!= key)
{
    if (curent->key == NULL)
    {
        return NULL;
    }
    else{
        previous = curent;
        curent = curent -> next;
    }
}
if(curent == head)
    head= head->next;
else
    previous->next= curent->next;

return curent;

}


void reverse (struct node** head_ref){

struct node* prev = NULL;
struct node* curent= *head_ref;
struct node* next;

while(curent != NULL){
next= curent->next;
curent->next = prev;
prev = curent;
curent= next;
}

*head_ref= prev;

}

struct node* cauta(int key){
    struct node* curent = head;
    if (head == NULL)
    {
        return NULL;
    }
    while (curent -> key != key)
    {
        if(curent->next != NULL)
            return NULL;
        else 
            curent= curent-> next;
    }   
return curent;
}

/*void sortare(){

int i,j,k, cheietemp, datetemp;
struct node *curent;
struct node *next;
 
int size =length();

}*/



int main()
{
    for(int i=10;i>=1;i--)
        inserare_primul(i,200);
    print_lista();
    sterge(3);
    cout<<"\nafisez lista dupa ce am sters elementul 3";
    print_lista();
    cout<<"\nmai jos am cautat al doilea element\n";
    cout<<cauta(2)<<"\n";
    /*cout<<reverse(*next);
    cout<<"lista dupa ce am apelat functia reverse\n";*/
    cout<<"Probleme:\n\tNu am reusit sa gasesc a carei biblioteci apartine functia 'length' , nici macar pe google\n\t Nu stiu ce parametrii sa ii dau funtiei reverse\n";

}
