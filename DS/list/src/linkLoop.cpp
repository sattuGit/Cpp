/*
 * LinkLoop.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: satendra
 */

#include "linkLoop.h"

#include "../../base/nodes.h"

LinkLoop::LinkLoop() {
	// TODO Auto-generated constructor stub
	headLinkLoop=nullptr;
}

LinkLoop::~LinkLoop() {
	// TODO Auto-generated destructor stub
	LoopNode *tmp=nullptr;
	while(headLinkLoop){
		tmp = headLinkLoop ;
		headLinkLoop = headLinkLoop->getNext();
		delete tmp;
	}
}
LoopNode * LinkLoop::getNode(void* addressData){
	return new (std::nothrow)  LoopNode(addressData);
}
bool LinkLoop::addUnique(void* argData){
	LoopNode *newNode = getNode(argData);
	if(!newNode) {cout<<"Memory Resource ERROR\n";return false;}
	LoopNode *tmp = headLinkLoop ;
	if(!tmp){headLinkLoop=newNode;return true;}
	while(tmp)
	{

		if(argData == tmp->getData())return false;

		if(argData > tmp->getData())/*maximum value put in top*/
		{
			newNode->setNext(headLinkLoop);
			headLinkLoop=newNode;
			return true;	/*No conflict ,new value added at top*/
		}
		else	/* not maximum */
		{
			if (tmp->getNext())		/*next is available */
			{
				if(tmp->getNext()->getData()==argData)return false;// N-1 is conflict

				if(tmp->getNext()->getData() > argData)	/*value lies b/w N and N-1*/
				{
					newNode->setNext(tmp->getNext());
					tmp->setNext(newNode);
					return true ;	// noconflict added between N and N-1 , i,e at N-1
				}
				else
				{
					/* No conflict in N and N-1 (AND) value is less then N and N-1
					 * going to test next postion value */
					tmp=tmp->getNext();
				}
			}
			else {
				/*we are last node */
				tmp->setNext(newNode);
				return true;
			}
		}
	}/*End While*/

	return false;
}

