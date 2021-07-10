#include<iostream>
#include<list>

bool even (const int& val) {return val%2==0?true:false;}

bool compare (const int& v1,const int& v2){ /*std::cout<<"["<<v1<<","<<v2<<"]";*/return v1==v2?true:false;}

int main(){
    std::list<int> l1;
    if(l1.empty()){
        std::cout<<"Empty size should be zero "<<l1.size()<<std::endl;    
    }
    /*
    front() – Returns the value of the first element in the list.
    back() – Returns the value of the last element in the list .
    push_front(g) – Adds a new element ‘g’ at the beginning of the list .
    push_back(g) – Adds a new element ‘g’ at the end of the list.
    pop_front() – Removes the first element of the list, and reduces size of the list by 1.
    pop_back() – Removes the last element of the list, and reduces size of the list by 1
    list::begin() and list::end() in C++ STL– begin() function returns an iterator pointing to the first element of the list
    end()– end() function returns an iterator pointing to the theoretical last element which follows the last element.
    list rbegin() and rend() function in C++ STL– rbegin() returns a reverse iterator which points to the last element of the list. rend() returns a reverse iterator which points to the position before the beginning of the list.
    list cbegin() and cend() function in C++ STL– cbegin() returns a constant random access iterator which points to the beginning of the list. cend() returns a constant random access iterator which points to the end of the list.
    list crbegin() and crend() function in C++ STL– crbegin() returns a constant reverse iterator which points to the last element of the list i.e reversed beginning of container. crend() returns a constant reverse iterator which points to the theoretical element preceding the first element in the list i.e. the reverse end of the list.
    empty() – Returns whether the list is empty(1) or not(0).
    insert() – Inserts new elements in the list before the element at a specified position.
    erase() – Removes a single element or a range of elements from the list.
    */
    
    /*assign()*/
    l1.assign(5,1);
    std::list<int>::iterator it = l1.begin();
    int j=0;
    while(it!=l1.end()){
        std::cout << *it<<",";
        *it=++j;
        advance(it,1); // OR ++it;
    }
    std::cout << std::endl;
    
    /*insert()*/
    l1.insert(l1.begin(),5);  // by default its append in front
    it = l1.begin();
    l1.insert(++(l1.begin()),6);
    advance(it,2);
    l1.insert(it,7);
    
    
    /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {
        std::cout << *i<<",";
    }std::cout << std::endl;
    
    it=l1.end();
    advance(it,-1);
    l1.insert(it,3,99); // 3 elemenrs with value 99 at it(iterator position)
    /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {
        std::cout << *i<<",";
    }std::cout << std::endl;
    
    /*erase*/
    l1.erase(l1.begin());
    /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {
        std::cout << *i<<",";
    }std::cout << std::endl;
    
    it=l1.end();
    std::list<int>::iterator eof =l1.end();
    advance(it,-4);
    advance(eof,-1);
    l1.erase(it,eof);
    /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    
    /*,remove  , remove all element matches with value */
    l1.push_front(7);   /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    l1.remove(9);       /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    l1.remove(3);       /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    l1.remove(7);       /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    
    //bool even const (const int& val){return val%2==0?true:false;}
    l1.remove_if(even); //even is function name with return tyoe bool, element will pass it as arg
    /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    
    /* clear() will remove all set size 0*/
    /*resize(n,x)  if size m , if m=n no action , if m>n, remove n+1 to m , if m<n, add n-m element with value x (if x is not provided then default value) */
    
    /* UNIQUE()  */
    
    //bool compare (const int& v1,const int& v2){ return v1==v2?true:false;}
    
    l1.clear();
    l1.push_front(1);l1.push_front(3);l1.push_front(1);l1.push_front(4);l1.push_front(3);
    
    /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    l1.unique(); /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    l1.sort();  /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    l1.unique(compare); /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    
    /*splice*/  // its MOVE element , cross list 
    
    std::list<int> l2;
    l2.push_front(1);l2.push_front(0);l2.push_front(3);
    
    it=l1.end();
    advance(it,-1);
    
    // MOVE ALL 
    /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    /*Display*/for (auto i = l2.begin(); i != l2.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    l1.splice(it,l2);  // add all members of l2 list  at position of "it" in l1 list 
    /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    /*Display*/for (auto i = l2.begin(); i != l2.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    
    
    //MOVE SPECIFIC 
    l2.splice(l2.begin(),l1,l1.begin());  // add l2.begin()  element in l2 list  at position of "it" in l1 list 
    /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    /*Display*/for (auto i = l2.begin(); i != l2.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    
    //MOVE RANGE
    {
    auto x = l2.begin();
    advance(x,1);
    
    auto by= l1.end();
    advance(by,-4);
    auto be=l1.end();
    
    l2.splice(x,l1,by,be);
    }
    /*Display*/for (auto i = l1.begin(); i != l1.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    /*Display*/for (auto i = l2.begin(); i != l2.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;

    std::cout<<"----------------MERGE-----------------------"<<std::endl;
    //MERGE 
    {
        std::list<int> one,two;
        one.push_back(1);one.push_back(2);one.push_back(4);one.push_back(3); //1,2,4,3
        two.push_back(3);two.push_back(6);two.push_back(7);two.push_back(5); //3,6,7,5
    /*Display*/for (auto i = one.begin(); i != one.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    /*Display*/for (auto i = two.begin(); i != two.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;

        /*one.merge(two);  // output : 1,2,3,4,3,6,7,5, */
        /* two.merge(one);     // output : 1,2,3,4,3,6,7,5, */
        
        
        one.sort();
        two.sort();
        //one.merge(two); //1,2,3,3,4,5,6,7,
        //two.merge(one); ////1,2,3,3,4,5,6,7,  //using defualt comparator 
        one.merge(two,compare); // using custime one 
        
    
        
        
    /*Display*/for (auto i = one.begin(); i != one.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
    /*Display*/for (auto i = two.begin(); i != two.end(); ++i) {std::cout << *i<<",";}std::cout << std::endl;
        std::cout<<"----------------MERGE[DONE]-----------------------"<<std::endl;
    }


    return 0;
}