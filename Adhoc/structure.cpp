/******************************************************************************
URLs    :   https://www.geeksforgeeks.org/structures-in-cpp/
            https://www.geeksforgeeks.org/structures-c/
            https://www.geeksforgeeks.org/difference-c-structures-c-structures/
            https://www.geeksforgeeks.org/structure-vs-class-in-cpp/
            http://www.tutorialdost.com/Cpp-Programming-Tutorial/30-Cpp-Union.aspx
			
			Structure padding issue 
			https://www.geeksforgeeks.org/how-to-avoid-structure-padding-in-c/?ref=rp
			https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/
Q what we can do in class but not in structure and vice varsa
*******************************************************************************/

#include <iostream>
using namespace std;


struct Node /*struct naming conventions is similer to class*/
{
    int data        =   0;          //  data and nextNode are data Member in structure , allowd in c and c++
    Node *nextNode  =   nullptr;    //  initilazation during declare in not supported in C and {blow C++11 version in C++}### Need to confirm #### */
    
}/* you can declare variable here also like ' } node1; ' */;

struct DNode			/*unlike class , structure member are public by default*/
{
    int 	data    ,
			data2	;
    Node *preNode   ;
    Node *postNode  ;
    
};


struct      /* Unnamed structre, usefull when you want to declare all varibale in one go only */
{
    int data;           
} unNamedNode, unNamedNode2;

class Base {
	public: 
	int x;
};
struct Drive : Base {  //  yes inheritance is possible 
		int y ;
		Drive(int a){ z=a;}
		private :			// structure can have access modifier
		int z ;
	
};	
struct Top : Drive {
	Top():Drive(9){
		x=7;
		y=8;
	}
};

int main()
{
    cout<<"structure is derived datatype by using hetrogenious datatype"<<endl;
    
    /*Unnamed structure */
    unNamedNode.data = 99;
    unNamedNode2.data = 98;
    cout<<unNamedNode.data<<endl;
    cout<<unNamedNode2.data<<endl;
    
    /** decaring struct variable */
    struct Node node1;  /* Prefix struct keyword is optional in C++, its mandatory in C */
    //Node node2 = {1,(Node*)nullptr};  /*Compile time error : You can't use both , delcare time initilazation and variable creation time initilazation*/
    DNode 	dnode1 = {2,1,nullptr,nullptr};
	//DNode	dnode2 = {.data2=3, .data=1, .preNode=nullptr, .postNode=nullptr};  need to test its not working it may work in C but need to chekc 
    DNode 	*pdnode1 = &dnode1;
			//*pdnode2 = &dnode2;
    
	cout<<"node1 "<<node1.data<<" : node2 "<<dnode1.data<<endl;
    cout<<pdnode1->data<<endl;
	//cout<<pdnode2->data<<":"<<pdnode2->data2<<endl;
    /**/
	Top test;
	cout<<test.x<<":"<<test.y<<":"<<sizeof(test)<<endl;
	test.x = 1;
	test.y=2;
	//test.z=3;  compile time error is its private in structure 
	cout<<test.x<<":"<<test.y<<":"<<sizeof(test)<<endl;
	
	
	
	// no static allowed in C 
	// no access modifier as its not availble in C by default its public  
	// 
	
    return 0;
}

