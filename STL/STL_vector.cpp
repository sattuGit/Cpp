/*

*/

#include<iostream>
#include<vector>

int main(){
    auto x =10;
    
    /*Declare vector */
    std::vector<int> vc1;
    
    
    /*========================================[SPACE/SIZE]=====================================*/
    
    /*size  : current element count 
    capacity    : current memory allocated 
    maxsize     : maximum memor that may avaialble 
    empty       : check empty or not (size==0)
    */
    if (vc1.empty()){ //true is size==0 ie no element 
        std::cout<<"Vector vc1 is empty with size ["<<vc1.size()<<"] capacity ["<<vc1.capacity();
        std::cout<<"] Max size allowed :"<<vc1.max_size()<<std::endl;
    } 
    
    /* We are requesting to reserve some memory, as we know that is going to be use 
        used in performance  :: reserve()
        ## Reserver will reserve memory but won't add in vectory 
    */
    size_t reqSpace=10;
    vc1.reserve(reqSpace);
        std::cout<<"Vector vc1 is "<<const_cast<char*>(vc1.empty()?"empty":"non_empty")  <<" with size ["<<vc1.size()<<"] capacity ["<<vc1.capacity();
        std::cout<<"] Max size allowed :"<<vc1.max_size()<<std::endl;
        
    /*Display*/
    for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
    
    /*Request to update memory, resize increase vector size , but reserver only allocate  
    if current size is n , resize (m) , adding new (m-n) elements with defaut values 
    */
    reqSpace+=12;  //10+12
    vc1.resize(reqSpace);
        std::cout<<"Vector vc1 is "<<const_cast<char*>(vc1.empty()?"empty":"non_empty")  <<" with size ["<<vc1.size()<<"] capacity ["<<vc1.capacity();
        std::cout<<"] Max size allowed :"<<vc1.max_size()<<std::endl;
            
    /*Display*/
    for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
    
    /* Test shrink_to_fit, 
    A : increaes capacity by 3 , from 22 to 25 , vector having 22 elements 
    B : request shrink_to_fit, it will release all aloocated memory which is not in use ie. 22
    */
    vc1.reserve(25);
        std::cout<<"Vector vc1 is "<<const_cast<char*>(vc1.empty()?"empty":"non_empty")  <<" with size ["<<vc1.size()<<"] capacity ["<<vc1.capacity();
        std::cout<<"] Max size allowed :"<<vc1.max_size()<<std::endl;

    vc1.shrink_to_fit();
        std::cout<<"Vector vc1 is "<<const_cast<char*>(vc1.empty()?"empty":"non_empty")  <<" with size ["<<vc1.size()<<"] capacity ["<<vc1.capacity();
        std::cout<<"] Max size allowed :"<<vc1.max_size()<<std::endl;

    vc1.clear(); // destroy all elements, size become zero , no capacity changes 
        std::cout<<"Vector vc1 is "<<const_cast<char*>(vc1.empty()?"empty":"non_empty")  <<" with size ["<<vc1.size()<<"] capacity ["<<vc1.capacity();
        std::cout<<"] Max size allowed :"<<vc1.max_size()<<std::endl;
    
    /*================================[Loop]===================================*/
    for (int i = 0; i < 10; i++) {vc1.push_back(i);} // feed data into vector 

    
    std::vector<int>::iterator itStart = vc1.begin();
    std::vector<int>::iterator itEnd = vc1.end();
    while(itStart!=itEnd){ 
        std::cout<<*itStart<<",";
        ++itStart;
    }
    std::cout<<std::endl;
    
    //Style B  , cost is high due to vc1.end() each time (witout optimization)
    for (auto i = vc1.begin(); i != vc1.end(); ++i) {
        std::cout<<*i<<",";
    }    
    std::cout<<std::endl;
    
    //Reverse 
    for (auto i = vc1.rbegin(); i != vc1.rend(); ++i) {
        std::cout<<*i<<",";
    }    
    std::cout<<std::endl;
    
    //using index 
    itStart = vc1.begin();
    for (auto i = 0; i < vc1.size(); ++i) {
        std::cout<<*itStart+i<<","<<itStart[i]<<","<<vc1.at(i)<<"|";
    }    
    
    std::cout<<std::endl;
    
    /*NOTE : cbegin or cend , crbegin crend  gives constant itrator , we can't modify values using it*/    
    
    
    /*================================[CRUD elements]===================================*/
    /* assign(size n, elements d)
            reset vectory , replace old values , n elements with value d
    */
    
    //A
    vc1.assign(3,99);
    /*Display*/
    for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
    
    //B
    vc1.clear();    //clean all elements
    
    //C push_back append elements at last 
    for (int i = 0; i < 10; i++) {vc1.push_back(i);} // feed data into vector 
    
    //D  modifying using itrator
    std::vector<int>::iterator eof = vc1.end();
    for(auto i= vc1.begin();i!=eof;++i){*i+=1;}
    /*Display*/
    for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
    
    //E pop_back remove elements at the end   , no return type 
    vc1.pop_back();
    vc1.pop_back();
    /*Display*/
    for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
    
    //E instert (position(iterator), data)
    try{
        std::cout<<"FLAS A ..."<<*vc1.end()<<","<<*vc1.begin()<<std::endl;  
        auto i = vc1.end(); //end represent last +1 
        vc1.insert(i,9);
        
        vc1.insert(++i,10);
        vc1.insert(vc1.begin()+1,11);
        /*Display*/
        for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
        
        vc1.erase(vc1.begin()+3); //vc1.begin() represent  first , first+ n = n+1th elements
        /*Display*/
        for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
        
        vc1.erase(vc1.begin()+3,vc1.end()-3); // 4th to (end -3 )-1 , last pointing elements won't delete
        /*Display*/
        for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
    }catch(...){
        std::cout<<"Exception ..."<<std::endl;    
    }
    
    // at(n) return refrence , we can access/modify value via refrence
    vc1.at(2)=17;
    /*Display*/
        for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
    
                /*swap*/
    std::vector<int> vc3;
    vc3.resize(4);
    std::cout<<"Before Swap" <<std::endl;
    /*Display*/
        for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
        for (auto i = vc3.begin(); i !=vc3.end(); )std::cout << *i++<<",";std::cout<< std::endl;
    
    vc3.swap(vc1);
    std::cout<<"After Swap" <<std::endl;
    /*Display*/
        for (auto i = vc1.begin(); i !=vc1.end(); )std::cout << *i++<<",";std::cout<< std::endl;
        for (auto i = vc3.begin(); i !=vc3.end(); )std::cout << *i++<<",";std::cout<< std::endl;
    
    std::cout<<"front:"<<vc3.front()<<" back:"<<vc3.back() <<std::endl;
    
    /*get Raw pointer*/
    int *pVcr = vc3.data();
    for(int i= 0 ;i<vc3.size();++i){
    std::cout<<*(pVcr+i)<<"," ;}std::cout<<std::endl;
    
    /*performance*/
    struct Foo
    {
        int _n;
        double _x;
        Foo(int n, double x):_n{n},_x{x}{}
        void display(){std::cout<<_n<<","<<_x<<std::endl;}
    };


    std::vector<Foo> v;
    Foo *o1 = new Foo(1,1.1);
    Foo o2(2,2.1);
    v.push_back(*o1);
    v.push_back(o2);
    
    v.emplace(v.begin(), 42, 3.1416);  // having less cost in case of objeict elements 
    v.insert(v.begin(), Foo(42, 3.1416));
     for(auto i= v.begin();i!=v.end();++i)
     i->display();
     
    return 0;
}