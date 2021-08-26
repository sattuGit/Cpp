#include<iostream>
#include "testMidLinkList.hpp"
#include "palindrome.h"
#include "deciBin.h"

int main(){
   //testMidNodeLinkList();  TO-DO , segmantation fault  need to fix 
   std::cout<<std::boolalpha;
   std::cout<<"ABCCBA" <<palindrome("ABCCBA")<<std::endl;
   std::cout<< "ABDCBA"<<palindrome("ABDCBA")<<std::endl;
   std::cout<< ""<<palindrome(01234210)<<std::endl;
   std::cout<< ""<<palindrome(1234321)<<std::endl;
   //dec2bin(10);
   //const int i=10;
   std::cout<<dec2bin(10)<<std::endl;
   std::cout<<dec2bin(4)<<std::endl;
   std::cout<<dec2bin(7)<<std::endl;
return 0;}
