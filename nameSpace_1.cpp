/*******************************************************************************************************
Namespace is C++ feature not available in C
A namespace is a declarative region that provides a scope to the identifiers (names of the types, function, variables etc) inside it.
Multiple namespace blocks with the same name are allowed. All declarations within those blocks are declared in the named scope.
*******************************************************************************************************/
#include<iostream>
int main(){
    std::cout<<"RAM"<<std::endl;  //its working becuse std namespace is bydefault available in system for access 
 return 0;   
}

/* This will also work 
#include<iostream>
using namespace std;
int main(){
    cout<<"RAM"<<endl;
 return 0;   
}
*/

/* will throw compile time error for unknown cout and endl
#include<iostream>
int main(){
    cout<<"RAM"<<endl;
 return 0;   
}
*/

/* will throw compile time error for unknown cout 
#include<iostream>
int main(){
    cout<<"RAM"<<std::endl;
 return 0;   
}
*/

