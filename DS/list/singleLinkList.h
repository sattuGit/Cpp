#ifndef NODES_LINK_LIST_
#define NODES_LINK_LIST_

#include "../base/nodes.h"

using namespace std;
class SLList{
	public 	:
		SLList(){
			head = nullptr;
			nodeCount=0;
		}
		~SLList(){
			/* free memory node by node */
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
		bool del(int);
		void rev();
		void testLoop();
		void testAndRepairLoop();
		void findMid();
		void makeLoop();
		unsigned int getListCount(){return nodeCount;}
	private :
		unsigned int nodeCount;
		Node * getNode(int);
		Node *head;
};


#endif
