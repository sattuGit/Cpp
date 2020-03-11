#include <iostream>
#include<cassert>
#include<stack>
#include<cstdlib>

/*STACK is Container Adaptors : provide a different interface for sequential containers*/

using namespace std;

class Stack
{
    private:
        int head ;
        int limit;
        int *stack;
    public:
        Stack(int index=-1,int size=100):head(index),limit(size){
            cout<<"Constructer triggred\n";
            assert(stack = new int[size]);
            for(int i=0;i<size;++i) stack[i]=0;
        }
        bool    empty();
        int     pop();
        bool    push(int);
        int     top();
        int     size();
        bool    isFull();
};      

bool Stack::isFull(){
    return (size()<=limit)? false:true;
}

int Stack::size(){
    cout<<"***"<<head<<"***\n";
    return (head+1);
}

bool Stack::push(int argVal){
    if(!isFull()) //checkOverFlow
    {
        ++head;
        stack[head]=argVal;
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
    cout<<"Head Value is "<<head<<endl;
    int tValue;assert(tValue=stack[5]);
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
    Stack *ls = new Stack();
    cout<<"\n"<<ls->empty()<<":"<<ls->isFull()<<":"<<ls->size()<<endl;
    cout<<ls->push(10);
    cout<<ls->push(30);
    cout<<ls->push(20);
    cout<<ls->push(5);
    cout<<ls->push(99);
    cout<<ls->push(88);
    cout<<"\n"<<ls->empty()<<":"<<ls->isFull()<<":"<<ls->size()<<endl;
    cout<<ls->top()<<":"<<ls->size()<<endl;
    cout<<ls->pop()<<":"<<ls->size()<<":"<<ls->top()<<endl;
    
    
    return 0;
}
