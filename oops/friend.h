#ifndef _SATTU_FRIEND_H_
#define _SATTU_FRIEND_H_

/*Class declartion*/
class DemoFriend;
class DemoFriend_base;
class DemoFriendClass;
class DemoFriednClassBase;

/*method declartion*/
bool testFriendFun();
void accessData(DemoFriend&);
void synchData(DemoFriend_base&,DemoFriend&);

#endif