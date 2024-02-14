#include <iostream>

using namespace std;


class Stack {

private:

    int date[1000];
    int top;

public:
    Stack()
    {
        top=1;
    }

    void peek(int top){
        cout<<"Pe pozitia "<<top<<" se afla valoarea ";
       cout<< date[top]<<"\n";
    }

    void push(int valoare)
    {
        if (top==1000)
            cout<<"Stiva este plina!!\n";
        else{
            date[top]=valoare;
            top++;
            cout<<"Valoarea "<<valoare<<" a fost adaugata\n"; 
        }
    }
    void pop (){
        if (top==0)
            cout<<"Stiva este goala!!\n";
        else{
            date[top]=NULL;
            cout<<"Valoare "<<top<<" a fost eliminata\n";
            top--;
        }
    }
    void este_goala(){
        if(top==0)
            {
                cout<<"Stiva este goala";
            }
        else {
            cout<<"Stiva este plina!";
        }
    }
    void este_plina()
    {
        if (top==1000)
           {
            cout<<"Stiva este plina!";
           }
        else {
            cout<<"Stiva este goala";
        }
    }

};

class Queue{

private:

int rear;
int front;
int date[1000];

public:

    Queue(){
        front=1;
        rear=1;
    }

    void enqueue(int valoare){
        if (rear == 1000)
            cout<<"Coada este plina!\n";
        else {
            date[rear]=valoare;
            cout<<"Valoarea "<<date[rear]<<" a fost adaugata int coada!\n";
            rear++;
        }
    }

    void dequeue(){
        if(front==1)
            cout<<"Coada este goala\n";
        else {
            cout<<"Valoare "<<date[front]<<" a fost eleminata din coada\n";
            date[front]=NULL;
            front++;
        }
    }
    void peek(int valoare){
        if(valoare >= front && valoare<= rear)
            cout<<"Pe pozitia "<<valoare<<" se afla valoarea "<<date[valoare]<<"\n";
        else cout<< "Nu se afla nimic pe pozitia inserata!\n";
    }

    void este_goala(){
        if(front==rear)
            {
                cout<<"Coada este goala";
            }
        else {
            cout<<"Coada nu este goala!";
        }
    }

    void este_plina()
    {
        if (rear==1000)
           {
            cout<<"Coada este plina!";
           }
        else {
            cout<<"Stiva nu este plina";
        }
    }
};

int main( )
{
    Stack stiva;
    stiva.push(1);
    stiva.push(90);
    stiva.pop();
    stiva.peek(2);
    Queue coada;
    coada.enqueue(57);
    coada.peek(1);
    coada.dequeue();
    
}