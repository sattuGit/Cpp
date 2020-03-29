#include<iostream>
using namespace std;
struct Node{
	public :
		Node(int argData=0){
			nextNode = nullptr;
			data = argData;
		}
		~Node(){
			cout<<"Node is going to vanish with data "<<getData()<<endl;
		}
		int getData(){
			return data;
		}
		void setData(int arg){
			data=arg;
		}
		void setLink(Node *pNode){
			nextNode=pNode;
		}
		Node * getLink(){
			return nextNode;
		}
	private:
		int data;	
		Node *nextNode;
};

class SLList{
	public 	:
		SLList(){
			head = nullptr;
			nodeCount=0;
		}
		~SLList(){
			cout<<"distructer SSList"<<endl;
			// need to delete memory by trversing  
			Node *tmp=nullptr;
			while (head){
				tmp=head->getLink();
				delete head ;
				head = tmp;
			}
		}
		bool addNodex(int arg);
		bool addNode(int arg, int pos=1);
		void display();
		unsigned int getListCount(){return nodeCount;}
	private :
		unsigned int nodeCount;
		Node * getNode(int);
		Node *head;
};
void SLList::display(){
	Node *tmpHead = head;
	while(tmpHead){
		cout<<"["<<tmpHead->getData()<<"]->";
		tmpHead=tmpHead->getLink();
	}
	cout<<"NULL\n";	
}

bool SLList::addNode(int arg, int pos){
	cout<<"arg "<<arg<<" pos "<<pos<<endl;
	if((pos>getListCount()+1) || pos<1) return false;	//BoundChecking
	Node *newNode = getNode(arg);
	if(!newNode){
		cout<<"Insufficient memory\n";
		return false;
	}
	//cout<<"we have node ready \n";
	Node 	*tmp 	= 	head,
			*tmp2	=	nullptr;
	for(int i=0;i<(pos-1);++i){
		//cout<<"serching for netx node of "<<i+1<<endl;	
		if (!tmp)tmp=tmp->getLink();	
	}
	//cout<<"flag A \n";
	if(head==nullptr){
		//cout<<"vargin list\n";
		head =newNode;
	}else{
		//cout<<"will put after "<<tmp->getData()<<endl;
		newNode->setLink(tmp->getLink());
		if(tmp==head){
			//cout<<"tmp==head\n";
			newNode->setLink(tmp);
			head = newNode;	
		}else{
			tmp->setLink(newNode);	
		}
	}
	++nodeCount;
	return true ;
}
bool SLList::addNodex(int arg){
	Node *newNode = getNode(arg);
	if(!newNode){
		cout<<"Insufficient memory\n";
		return false;
	}
	if(head!=nullptr){
		newNode->setLink(head);
	}
	head=newNode;
	++nodeCount;
	return true;
}

Node * SLList::getNode(int arg){
	Node *tmp = new (std::nothrow) Node(arg);
	return tmp;
}
int main(){
	SLList *sl= new SLList();
	sl->display();
	sl->addNode(1);
	sl->display();
	sl->addNode(2);
	sl->display();
	sl->addNode(3);
	sl->display();
	sl->addNode(4);
	sl->display();
	cout<<sl->getListCount()<<endl;
	sl->addNode(5,5);
	sl->display();
	sl->addNode(6,2);
sl->display();
	sl->addNode(7);sl->display();
	
	
	delete sl;
	return 0;
}