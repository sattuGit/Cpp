/*
What we can't over load : dot(.) ::  ?: sizeof

*/


#include<iostream>
class Complex{
    private :
        
    public:
        int _real,_img;
        Complex(int argReal=0, int argImg=0 ):_real{argReal},_img{argImg}{
            
        }
    
    
        Complex operator + (Complex const &obj){
            Complex tmp;
            tmp._real = obj._real + _real;
            tmp._img = obj._img  + _img;
            return tmp;
        }
        
friend Complex operator * (Complex const &obj1, Complex const &obj2);
        
};

Complex operator * (Complex const &obj1, Complex const &obj2){
    return Complex(obj1._real * obj2._real, obj1._img * obj2._img );
}

Complex operator - (Complex const &obj1, Complex const &obj2){
    return Complex(obj1._real - obj2._real, obj1._img - obj2._img );
}


int main(){
    Complex one(3,4);
    Complex two(1,2);
    Complex three(one._real + two._real, one._img+two._img);
    std::cout<<three._real<<","<<three._img<<std::endl;
    
    Complex four = three + two;
    
    std::cout<<four._real<<","<<four._img<<std::endl;
    
    
    Complex five = four - two;
    std::cout<<five._real<<","<<five._img<<std::endl;
    Complex six = five * Complex(9,9);
    std::cout<<six._real<<","<<six._img<<std::endl;
    return 0;
}