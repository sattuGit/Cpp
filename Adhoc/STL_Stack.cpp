/*
Author   :  Satendra K Gupta 
Hands on :  STL Stack and Implement our own stack for learning 
*/
#include <iostream>
#include<cassert>
#include<stack>
#include<cstdlib>

/*STACK is Container Adaptors : provide a different interface for sequential containers*/

using namespace std;

class Stack
{
    /*
    TODO: Implement elastic stack , increse or decrese dynaminc, 
            Therer could be two approch , (A) is redinfe(vertical), another one (B) is horizontal scale up by adding memory pools
            A) is costly everytime, when we increse or decrese
            B) every operation will need bit more instruction cycle but over all it will deliver good performance 
    2)  Implement Copy Constructer and display method for class Stack 
    */
    
    
    private:
        int head ;
        int limit;
        int *stack;
    public:
        Stack(int size=100,int index=-1):head(index),limit(size){
            //cout<<"Constructer triggred\n";
            try
            {
                assert(stack = new int[size]);
            }
            catch(std::bad_alloc&){
                cout<<"Dynamic memory Error\n";
            }
            //for(int i=0;i<size;++i) stack[i]=0;
            
        }
        bool    empty();
        int     pop();
        bool    push(int);
        int     top();
        int     size();
        bool    isFull();
};      

bool Stack::isFull(){
    return (head>=(limit-1))? true:false;
}

int Stack::size(){
    return (head+1);
}

bool Stack::push(int argVal){
    if(!isFull()) //checkOverFlow
    {
        stack[head+1]=argVal;
        ++head;
        return true;
    }
    return false;
}
bool Stack::empty(){
    return ((head>-1)? false:true);
}

int Stack::top(){
    /*Its accessing the memory without any check, in case of empty stack its going to raise exception , 
    * we assumend devlper will handle this scenarios
    */
    int tValue;assert(tValue= stack[head]);
    return (tValue); //assert will throw exception during underflow
}

int Stack::pop(){
    //cout<<"POP Head Value is "<<head<<endl;
    int tValue;assert(tValue=stack[head]);
    --head;
    return (tValue);
}


void travelStack(stack<int> obj){
    /*for stack there is no iterater in STL so we implemented workaaround using a, copy object*/
    unsigned int limit = obj.size();
    for(int i=0;i<limit;++i){
        cout<<"["<<obj.top()<<"] "<<endl;
        obj.pop();
    }
}

void travelStack(Stack obj){        //overloaded function 
    //for ()
}


int main()
{
    cout<<"SIMEPLE STACK";
    stack <int> s;      // I dont know weather we can declare the memory size of satck, 
    cout<<s.size()<<endl;
    if(s.empty())cout<<"STACK IS EMPTY"<<endl;
    
    /*  below two line will caise for segmantation fault or core dump as STL wont check bound checking in stack's operation 
    s.top();
    s.pop(); */
    
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);
    
    cout<<s.size()<<":"<<s.top()<<":"<<s.size()<<endl;
    s.pop();
    cout<<s.top()<<":"<<s.size()<<endl;
    
    travelStack(s);
    cout<<s.size()<<endl;
    travelStack(s);
    
    
    /* LOCAL implementation of stack*/
    Stack *ls = new Stack(5);
    cout<<"\n"<<ls->empty()<<":"<<ls->isFull()<<":"<<ls->size()<<endl;
    if(!ls->push(10))cout<<"Push Operation is rejected \n";
    if(!ls->push(30))cout<<"Push Operation is rejected \n";
    if(!ls->push(20))cout<<"Push Operation is rejected \n";
    if(!ls->push(5) )cout<<"Push Operation is rejected \n";
    if(!ls->push(99))cout<<"Push Operation is rejected \n";
    if(!ls->push(88))cout<<"Push Operation is rejected \n";
    cout<<"\n"<<ls->empty()<<":"<<ls->isFull()<<":"<<ls->size()<<endl;
    cout<<ls->top()<<":"<<ls->size()<<endl;
    cout<<ls->pop()<<":"<<ls->size()<<":"<<ls->top()<<":"<<ls->pop()<<endl;  // NOTE COUT expression resolve in right to left menner 
    
    
    return 0;
}
