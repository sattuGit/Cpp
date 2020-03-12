/*
 *  This is to demostrate dynamic memory in c/C++
 * http://man7.org/linux/man-pages/man3/malloc.3.html
 * https://stackoverflow.com/questions/20094394/why-do-we-cast-return-value-of-malloc
 * https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
 */
 
 #include<iostream>
 #include<cstring> //for memset
 //#include<stdlib.h>   /*For dynamic memory C-Style needed in C compiler */
 using namespace std;
 int main()
 {
     /*C-Style Dynamic memory memory */
      
    /*-----------malloc---------  
    void* malloc(byte-size);
    */
    
    int     *pDMemory   =   nullptr ,
            *pDMemory_2 =   nullptr ,
            *pTmp       =   nullptr ,
            *pTmp2      =   NULL    ; 
      
      /* This line will work only in C compiler not in C++ Compiler 
         malloc returns a void pointer (void *), which indicates that it is a pointer to a region of unknown data type. 
         The use of casting is required in C++ due to the strong type system, whereas this is not the case in C 
    pDMemory  = malloc(100*sizeof(int)); */
    
    
    /* mallco will return allocated undefined dataType memory chunk without initilization , 
        in case if failure it will return NULL
        To handle memory allocation exception  in more deep, we can use 
            * M_CHECK_ACTION 
            * https://stackoverflow.com/questions/27451220/how-can-i-correctly-handle-malloc-failure-in-c-especially-when-there-is-more-th
    */
    if (nullptr == (pDMemory= (int*)malloc(100*sizeof(int)) )) cout <<"return NULL by malloc\n";        
    cout<<"Pointer is "<<pDMemory<<endl;
    
    
    /* For Zero memory request, malloc may return NULL or an unique valid pointer (depennding on compiler, its version and implementation */
    if (NULL == (pDMemory_2= (int*)malloc(0) )) cout <<"return NULL by malloc\n";
    cout<<"Pointer is "<<pDMemory_2<<endl;  //in this case valid memory pointer pointing to no memory but valid entry under symbol table 
    cout<<pTmp<<endl;
    cout<<pTmp2<<endl;
    
    
    /*-----------calloc---------  
    contignous memory allocation 
    void* malloc(N-elements, each_elemnt_size); total memory allocated is N*sizeof(each) in contignous memory 
    after allocating memory its initilize momory with 0, becouse of this additional task, cost of calloc > cost of malloc
    */
    int     *pDMemCalloc    =   nullptr ,
            *pDMemCalloc2    =   nullptr ,
            *pDMemMelloc    =   nullptr ;
    
    pDMemCalloc = (int*) calloc(10,sizeof(int));
    pDMemMelloc = (int*) malloc(10*sizeof(int));
    pDMemCalloc2 = (int*) calloc(0,sizeof(int));
    
    cout<<pDMemCalloc<<":"<<pDMemMelloc<<":"<<pDMemCalloc2<<endl;
    for(int t=0;t<10;++t){ cout<<"["<<*(pDMemCalloc+t)<<":"<<*(pDMemMelloc+t)<<"]";}
    for(int t=0;t<10;++t){ cout<<"["<<pDMemCalloc[t]<<":"<<pDMemMelloc[t]<<"]";}
    
    
    /*-------memset---------
        memset(memoryAddress, 0, offset);
        memset is memory initilization utility, its set memory byte by bite to numeric zero ASCII 
    */
    int *pTmpMemSet = (int*) malloc(10*sizeof(10));
    if(pTmpMemSet==nullptr) {cout<<"memory failure\n"; exit(0);}
    for(int i=0;i<10;++i) *(pTmpMemSet+i)= i+1;
    cout<<"\n-----------------------------------------------------**\n";
    for(int i=0;i<10;++i) cout<<*(pTmpMemSet+i)<<",";
    cout<<"\n-----------------------------------------------------**\n";
    memset(pTmpMemSet,9,10*sizeof(int));
    for(int i=0;i<10;++i) cout<<*(pTmpMemSet+i)<<",";
    cout<<"\n-----------------------------------------------------**\n";
    
    
    
    
    /*-----------realloc----------------
    * ptr = realloc(ptr, newSize);
    * realloc  = free(old)+allocate(new)
    * realloc wont do memory initilization
    * during realloc , weather system is using same memory block by adding more contignous memory or allocated all togather new memory block , is unpredictable as its depand on 
    * runtime environmnet and OS
    */
    int     *tDM_req1   =   nullptr ,
            *tDM_req2   =   nullptr;
    cout<<"\n"<<tDM_req1<<":"<<tDM_req2<<endl;
    tDM_req1    =   (int*) malloc(10*sizeof(int));
    cout<<"\nFirst Request Address "<<tDM_req1<<endl;
    tDM_req2    = (int*)  realloc(tDM_req1, 10*sizeof(20));        
    cout<<"Second Request Address "<<tDM_req2<<endl;
    
    tDM_req1=nullptr; // See below message 
    /*
        Special case :  In Genral we allways use same pointer in realloc , but to demostrate I am using two diffrent pointers to mmeory 
                        It may possible in  compiler on scenarios, OS will return same memory block will new size 
                        on that case tDM_req1 and tDM_req2 both will point to same memory Address, that's why we are setting old pointer as null explicit
                        
    */
        
    /* ---------------------Free----------------
    the most common way to store size of memory so that free() knows the size of memory to be deallocated.
    When memory allocation is done, the actual heap space allocated is one word larger than the requested memory. 
    The extra word is used to store the size of the allocation and is later used by free( )
    
    * C is unable to handle free memory twice, {for example : *** Error in `./a.out': double free or corruption (fasttop): 0x0000000001478e90 ***}
        there is no defined behaviour for this, so its always good to set null to memory pointer after free, 
        as no action will perform if pointer is null
    * 
    */
    
    int *pTestFree = (int*)malloc(sizeof(int));
    cout<<"Allocation :"<<pTestFree<<endl;
    free(pTestFree);
    cout<<"Allocation after free :"<<pTestFree<<endl;
    pTestFree =nullptr;
    free(pTestFree);
    cout<<"Allocation after 2nd free :"<<pTestFree<<endl;
    

    /*Free malloc example's  memmory */
    free(pDMemory)  ;   pDMemory=nullptr;
    free(pDMemory_2);   pDMemory_2=nullptr;
    free(pTmp);
    free(pTmp2);
    /*Free calloc example's  memmory */
    free(pDMemCalloc );pDMemCalloc =nullptr;
    free(pDMemCalloc2);pDMemCalloc2=nullptr;
    free(pDMemMelloc );pDMemMelloc =nullptr;
    /*Free realloc example's  memmory */
    free(tDM_req1);tDM_req1=nullptr;
    free(tDM_req2);tDM_req2=nullptr;
    
    /*--------------------------------------------------------------------------------------------------------------------------*/

    return 0;
 }
