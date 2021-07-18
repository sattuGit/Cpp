#include<thread>
#include<iostream>
#include<string>
#include<chrono>

//https://www.bogotobogo.com/cplusplus/C11/1_C11_creating_thread.php
//auto _f = [](std::string &s)->void {s.append("done"); std::cout<<"_"<<s<<"_"<<std::endl;};
void _f(std::string &s){
    s.append("done"); 
    std::cout<<"_"<<s<<"_"<<std::endl;
    //std::this_thread::sleep_for (std::chrono::seconds(10));
    std::cout<<"_********************_"<<std::endl;
}
int main(){
    std::string s("This is test string ");
    
    std::cout<<"_"<<s<<"_"<<std::endl;
 
    //std::thread t_p1(_f,s); compile error 
    std::thread t_p1(_f,std::ref(s)); //string s will pass as refrence , std::ref will create wrepper around s and then pass it to thread 
    
    /* How to copy one thread into another */
    std::thread t_p2;
    //t_p2 = t_p1; compile error copy thread is not allowed, you can move ownership 
    t_p2 = move(t_p1); 
    
    
    /*getting thread id  */
    std::cout << "This "<<std::this_thread::get_id() << std::endl;
    std::cout << "This "<<t_p2.get_id() << std::endl;  /* Note if thread is not executing it will throw error */
    
    t_p2.join();
    std::cout << "This "<<t_p2.get_id() << std::endl;  /* Note if thread is not executing it will throw error */
    
    std::cout<<"_"<<s<<"_"<<std::endl;
    
	
	/*getid for detached thread */
	std::thread t_p3(
	    [](){
	        std::this_thread::sleep_for(std::chrono::seconds(10));});
	t_p3.detach();
	std::thread::id tp3Id = t_p3.get_id(); 
	std::cout << "This "<<tp3Id << std::endl; 
	
	
	return 0;
}