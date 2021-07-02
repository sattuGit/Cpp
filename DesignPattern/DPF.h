#ifndef _DPFACTORY_
#define _DPFACTORY_
#include<iostream>
#include<memory>
class Pizza{
    public:
    ~Pizza(){std::cout << "Distructor :: Pizza" << std::endl;}
    Pizza(){std::cout << "Constructor  :: Pizza" << std::endl;}
    void setDough(const std::string dough){_dough=dough;}
    void setSauce(const std::string sauce){_sauce=sauce;}
    void setTopping(const std::string topping){_topping=topping;}
    
    void display(){
        std::cout << "The Pizz Have :" << 
        _dough<<" Dough,"<<_sauce<<" Sauce,"<<
        _topping<<" topping "<<std::endl;
    }
  private:
    std::string _dough;
    std::string _sauce;
    std::string _topping;
};

class PizzaBuilder{
    public:
        virtual ~PizzaBuilder(){delete _pizza;} 
        void createNewPizza(){
            //if (_pizza != nullptr){
            _pizza = new Pizza();//std::make_unique<Pizza>();
            //}
        }
        PizzaBuilder():_pizza{nullptr}{}
        Pizza* getPizz(){
            return _pizza;//_pizza.release();
        }
        /*Abstract*/
        virtual void BuikdDough()=0;
        virtual void BuikdSauce()=0;
        virtual void BuikdToppings()=0;
    protected:
        Pizza *_pizza;
};

class Domnio: public PizzaBuilder{
    public:
        //~ Domnio() override = default;
        ~Domnio(){std::cout << "Domnio Distructors" << std::endl;}
        void BuikdDough()override{_pizza->setDough("Domino_dough");}
        void BuikdSauce()override{_pizza->setSauce("Domino_sauce");}
        void BuikdToppings()override{_pizza->setTopping("Domino_topping");} 

};

class PapaJ: public PizzaBuilder{
    public:
        //~ PapaJ() override = default;
         ~PapaJ(){std::cout << "PapaJ Distructors" << std::endl;}
        void BuikdDough()override{_pizza->setDough("PapaJ_dough");}
        void BuikdSauce()override{_pizza->setSauce("PapaJ_sauce");}
        void BuikdToppings()override{_pizza->setTopping("PapaJ_topping");} 
};

class Cook{
  public:
    void display(){
        _pizzaBuilder->getPizz()->display();
    }
    Cook():_pizzaBuilder{nullptr}{}
    
    void createPizz(PizzaBuilder* pPizzaBuilder ){
        //if(_pizzaBuilder != nullptr){
        //   delete _pizzaBuilder;
        //}
        _pizzaBuilder = pPizzaBuilder;
        _pizzaBuilder->createNewPizza();
        _pizzaBuilder->BuikdDough();
        _pizzaBuilder->BuikdSauce();
        _pizzaBuilder->BuikdToppings();
    }
  private:
    PizzaBuilder* _pizzaBuilder;
};
#endif 