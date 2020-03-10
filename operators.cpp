#include<iostream>

using namespace std;

int main(){
	int x;
	int y = 2+(x=5);
	cout<<(x=5)<<endl;
	cout<<y<<x<<endl;
}