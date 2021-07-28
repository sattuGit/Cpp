#include<iostream>
#include<filesystem>
#include<dirent.h>
#include<sys/stat.h>
#include<string>
#include<cstring>

bool isPathExist(const std::string &_path){
    struct stat buffer ; // from sys/stat.h 
    if(stat(_path.c_str(), &buffer ) != 0){
        return false;   //stat call fail , no inode found 
    }
    else if(buffer.st_mode & S_IFDIR){
        return true;    //is file mode bit is DIR bit 
    }
    else{return  false;}
        
    /*
    Ref : https://pubs.opengroup.org/onlinepubs/7908799/xsh/sysstat.h.html
    https://en.wikipedia.org/wiki/Stat_(system_call)

     */
     return false ;
}

/*coding game Question for nasdaq*/
bool isFileExistRSearch(const std::string& _path,const std::string& _fname){
    if (!isPathExist(_path)) return false;
    DIR *dir;
    struct dirent *ent;
    if ((dir =  opendir(_path.c_str()))!=NULL){
        /*process all file/directory*/
        while((ent = readdir(dir))!=NULL){
             if ( !strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..") ){
                 continue; 
             }
             else if (!strcmp(ent->d_name,_fname.c_str())){
                 std::cout<<"File found "<<ent->d_name<<std::endl;
                 closedir(dir);
                 return true ;
             }
             std::string tmpFname(_path);
             tmpFname.append("/").append(ent->d_name);
                //std::cout<<"DIR to test "<<tmpFname<<std::endl;        
             if(isPathExist(tmpFname)){
                std::cout<<"DIR "<<ent->d_name<<std::endl;        
                if (isFileExistRSearch(tmpFname,_fname)) return true;
            }
            //std::cout<<"???Normal "<<ent->d_name<<std::endl;
            

        }
        closedir(dir);
        return false;
        
    }


    /*C++17 onwards 
    namespace fs = std::filesystem;
    const fs::path path{_path.length()==0 ? fs::current_path() : _path.c_str()}; 
    for(const auto& entry : fs::directory_iterator(path)){
        const auto filenameStr = entry.path().filename().string();
        if (!filenameStr.compare(_fname)) return true ;
        if(entry.is_directory()){
            if( isFileExistRSearch(filenameStr,_fname)) return true ;
        }
    }
    */

    return false ;
}