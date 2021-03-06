#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <algorithm>


#include "DCM_READER.h"

using namespace std;


////// get imageVector item//////
string DCM_READER::get_imagesVector_item(int x){

    if (x > imagesVector.size()){
      cout<<"i out of vector limits"<<endl;   
      return " ";
    }
    
    else{
    
        return imagesVector[x];}
  }



//////set depth////

void DCM_READER::set_depth(){

    depth=imagesVector.size();
    cout<<"The imagesVector depth is:"<<depth<<endl;
}


/////get depth//////
int DCM_READER::get_depth(){
    
    return depth;

}



////////read and create the vector with image files' names//////

void DCM_READER::readDir(){
    
   string dir = string(directory_name);

 DIR *dp;
 struct dirent *dirp;
  
   if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
       // return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        
        if(strcmp(dirp->d_name,".")==0 || strcmp(dirp->d_name,"..")==0){      
             continue;            
         } 
        
        imagesVector.push_back(dir+"/"+string(dirp->d_name));
    }
  
   sort (imagesVector.begin(),imagesVector.end());
  
  closedir(dp);
  
}


void DCM_READER::printFiles(){
    
    for (int i = 0;i < imagesVector.size();i++) {
        
          cout << imagesVector[i] << endl;
    
    }
}



//////construstor///////
DCM_READER::DCM_READER(char * file) {
    
    directory_name= new char[strlen(file)+1];
    strcpy(directory_name,file);
     
    std::cout<<"I constracted a DCM_Reader"<< std::endl;
}

//////destructor////////

DCM_READER::~DCM_READER() {
    
     delete [] directory_name;
     std::cout<< "I destroy a DCM_Reader"<< std::endl;

}

