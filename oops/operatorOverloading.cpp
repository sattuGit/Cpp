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

        /*uniory operator overloading*/        
        Complex operator - (){
            return Complex(_real*-1,_img*-1);
        }
        Complex operator ++ (){
            return Complex(++_real,++_img);
        }
        
        /*Post increment uses a dummy int arg, to diffreciate pre and post incremet  */
        Complex operator ++ (int){
            return Complex(++(++_real),++(++_img));
        }
        
        friend Complex operator * (Complex const &obj1, Complex const &obj2);
        
        /*over load conversion 
        * it should not have return type otherwise it will trow compilation error 
        */
        /*float*/ operator float()const {
            return float(_real)/_img;
        }      
        
        void display(){
            std::cout << "["<<_real<<","<<_img<<"]" << std::endl;
        }
        
        /*stream out */
        friend std::ostream& operator << (std::ostream &out, const Complex &d);
        
        
        
};

std::ostream& operator<<(std::ostream &out,const Complex &d){
    out<<d._real<<","<<d._img;
    return out;
}

Complex operator * (Complex const &obj1, Complex const &obj2){
    return Complex(obj1._real * obj2._real, obj1._img * obj2._img );
}

Complex operator - (Complex const &obj1, Complex const &obj2){
    return Complex(obj1._real - obj2._real, obj1._img - obj2._img );
}


class conversion{
    int *data, *data2;
    public:
    void display(){std::cout << *data<<","<<*data2 << std::endl;}
    conversion(int arg=0,int arg2=0):data{new int(arg)},data2{new int(arg2)}{}
};

bool test(){
    conversion x =1 ;
    x.display();
    
    conversion y = x;
    y.display();
    
    y=2;
    y.display();
}

int main(){
    test();
    return 0;
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
    
    /*Test conversion*/
    float value  = six;
    std::cout << value << std::endl;
    
    six.display();
    six = -six;
    six.display();
    
    ++six;
    six.display();
    six++;
    six.display();
    std::cout<<six;
    return 0;
}
