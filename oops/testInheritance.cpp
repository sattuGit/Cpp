#include "inheritance.h"

#include <iostream>
using namespace std;
bool testDynamicBinding(){
    SimpleBase *base =  new SimpleBase(2);
    SimpleDerivePubic *derive = new SimpleDerivePubic(1,2);
    base->dynamicBind();
    derive->dynamicBind();

    base =  derive;
    base->dynamicBind();
    derive->dynamicBind();
    return true;
}
bool testInhritance()
{
    std::cout << "Inheritance Test Caes start ......" << std::endl;
 
    SimpleBase bobj(33);
    bobj.display();
    //bobj.data=9;  private in class compile error 
    bobj.pubData=8; //public data member 
    //bobj.proData=7; protacted in class , compile error
    bobj.display();
    std::cout << "--------------------------" << std::endl;

    SimpleDerive dr(2,3);
    dr.display();
    //dr.data=1;  private of base, not availbe in derive  
    //dr.pubData=2;   public in base, but inherited as private(default) so become private 
    //dr.protacted=3; protected in base , inherited as privare , become private in derive 
    dr.dupX=4;  //local base public 
    //dr.SimpleBase::dupX=5;  public in base , become private after private inhertance  
    dr.display();
    std::cout << "--------------------------" << std::endl;
    SimpleDerivePubic drp(2,3);
    drp.display();
    //drp.data=1;  private of base, not availbe in derive  
    drp.pubData=2;   //public in base, but inherited as public  
    //drp.protacted=3; protected in base , inherited as public , become protected in derive 
    drp.SimpleBase::dupX=4;  //public in base , still public as public inhertance
    drp.dupX=5;    // Deriven local 
    drp.display();
    std::cout << "--------------------------" << std::endl;
    return 0;
}