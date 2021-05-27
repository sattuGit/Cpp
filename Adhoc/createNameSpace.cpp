#include<iostream>
//using namespace std;  /*We can directly access std name space without making it default via std:: */

//creating namespace
namespace myspace
{
  int data = 500;
    int copy(bool flag){
        int data = 99;
        if(flag){
            return data;
        }else{
            return myspace::data;
        }
    }
}
int copy (bool flag){
	int data = 88;
	if(flag){
		return data;
	}else{
		return myspace::data;
	}
}
//Global variable
int data = 100;

int main ()
{
  std::cout << "namespace understanding" << std::endl;
  int data = 200;
  std::cout << "Value of data " << data << std::endl;           /* default namespace, by default accessing global name insted of local version */
  std::cout << "Value of data " << myspace::data << std::endl;  /* accessing namespace "myspace", accessing namespace's members */
  std::cout << "Value of data " <<::data << std::endl;          /* default namespace, by default accessing local copy of variable */
  std::cout << "Value of data " << myspace::copy(true) << std::endl;  /* accessing namespace "myspace", reuring myspace copy functoin's local copy */
  std::cout << "Value of data " << myspace::copy(false) << std::endl;  /* accessing namespace "myspace", reuring myspace global copy */
  std::cout << "Value of data " << copy(true) << std::endl;  /* accessing namespace "myspace", reuring myspace copy functoin's local copy */
  std::cout << "Value of data " << copy(false) << std::endl;  /* accessing namespace "myspace", reuring myspace global copy */

return 0;

}
