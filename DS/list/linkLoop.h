/*
 * LinkLoop.h
 *
 *  Created on: Apr 3, 2020
 *      Author: satendra
 */

#ifndef LINKLOOP_H_
#define LINKLOOP_H_
#include "../base/nodes.h"
class LinkLoop {
public:
	LinkLoop();
	~LinkLoop();
	bool addUnique(void*);
private:
	LoopNode * getNode(void*);
	LoopNode  *headLinkLoop;
};



#endif /* LINKLOOP_H_ */
