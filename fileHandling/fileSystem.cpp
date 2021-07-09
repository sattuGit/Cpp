/*
struct stat {
	dev_t st_dev;
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
	dev_t st_rdev;
	off_t st_size;
	time_t st_atime;
	time_t st_mtime;
	time_t st_ctime;
	blksize_t st_blksize;
	blkcnt_t st_blocks;
	mode_t st_attr;
}; 
*/
#include<sys/stat.h>
bool isPathExist(const std::string &_path){
    struct stat buffer ; // from sys/stat.h 
    stat(s.c_str(),&buffer);// == o ? true : false;
    cout << buffer.st_dev << endl;
     cout << buffer.st_ino << endl;
     cout << buffer.st_mode << endl;
     cout << buffer.st_nlink << endl;
     cout << buffer.st_uid << endl;
     cout << buffer.st_gid << endl;
     cout << buffer.st_rdev << endl;
     cout << buffer.st_size << endl;
     cout << buffer.st_blksize << endl;
     cout << buffer.st_blocks << endl;
     cout << buffer.st_atime << endl;
     cout << buffer.st_mtime << endl;
     cout << buffer.st_ctime << endl;
     return false ;
}