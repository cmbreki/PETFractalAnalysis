#include <string>
#include <iostream>
#include <dcmtk/dcmimgle/dcmimage.h>

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"


#include "SPECS.h"

using namespace std;

/////set specifications/////

int SPECS::set_specs(string filename){

    const DiPixel *diPixel;
    EP_Representation rep;
    int var;
    
     DicomImage *image = new DicomImage(filename.c_str());
      
   if (image != NULL)
   {
        if (image->getStatus() == EIS_Normal)
          {
             if (image->isMonochrome())
                 {
            
                   width=image->getWidth();
                   cout<<"Image Width:"<<width<<endl;
                   
                   height=image->getHeight();
                   cout<<"Image Height"<<height<<endl;
                   
                   diPixel=image->getInterData();
                   rep=diPixel->getRepresentation();
                   
                   
                     if(rep == EPR_Uint8){
                       category=1;
                       cout<<"Image pixel representation:EPR_Uint8 "<<endl;
                     }
              
                     else if (rep == EPR_Sint8){
                       category=2;
                       cout<<"Image pixel representation:EPR_Sint8 "<< endl;             
                     }
                   
                     else if(rep == EPR_Uint16){
                       category=1;
                       cout<<"Image pixel representation:EPR_Uint16 "<<endl;
                   
                      }
                   
                      else if (rep== EPR_Sint16){
                       category=2;
                       cout<<"Image pixel representation:EPR_Sint16"<<endl;
                     
                       }
                   
                       else if(rep == EPR_Uint32){
                         category=1;
                         cout<<"Image pixel representation:EPR_Uint32"<<endl;
                        }
                      
                       else if (rep == EPR_Sint32){
                         category=2;
                         cout<<"Image pixel representation:EPR_Sint32"<<endl;
                   
                        }
                       else{
                         category=-1;
                         cout<<"Image pixel representation:unknown"<<endl;
             
                        }
                 var=1;
                    }//if Monochrome

                 }//getStatus
             
         }
        else{
            
            cout<<"Image:Null"<<endl;
            var=0;        
        }

        delete image;
        return var;        
} //endset_specs     



// counts the number of images in each representation category
void SPECS::lookUp(string filename){
    
    const DiPixel *diPixel;
    EP_Representation rep;
    int var;
    
     DicomImage *image = new DicomImage(filename.c_str());
      
   if (image != NULL)
   {
        if (image->getStatus() == EIS_Normal)
          {
             if (image->isMonochrome())
                 {
                   
                   diPixel=image->getInterData();
                   rep=diPixel->getRepresentation();
                   
                   
                     if(rep == EPR_Uint8){
                         counter[1]++;
                     }
              
                     else if (rep == EPR_Sint8){
                       counter[2]++;            
                     }
                   
                     else if(rep == EPR_Uint16){
                       counter[3]++;
                   
                      }
                   
                      else if (rep== EPR_Sint16){
                       counter[4]++;
                     
                       }
                   
                       else if(rep == EPR_Uint32){
                        counter[5]++;
                        cout<<filename<<endl;
                        }
                      
                       else if (rep == EPR_Sint32){
                         counter[6]++;
                   
                        }
                       else{
                         counter[7]++;
             
                        }
                 
                    }//if Monochrome

                 }//getStatus
             
         }
        else{
            
            cout<<"Image:Null"<<endl;
                  
        }

        delete image;
        

}

void SPECS::printCounter(){
        
    for(int i=0;i<7;i++){
           cout<<counter[i]<<" ";
    }

}

unsigned long SPECS::getWidth(){
  
    return width;

}

unsigned long SPECS::getHeight(){
    
    return height;
}


int SPECS::getCategory(){
   
    return category;

}



SPECS::SPECS() {
    
    try{
     
        counter= new int [7];
        for(int i=0;i<7;i++){
            counter[i]=0;
        }
    
      cout<<"A SPECS created"<<endl;
    
    }
     catch(std::bad_alloc& exc){
         cout<<"No successful memory allocation SPECS"<<endl;
     }
    

}


SPECS::SPECS(const SPECS& orig){
    
 width=orig.width;
 height=orig.height;
 category=orig.category;
  
 cout<< "Copy constructor for SPECS"<<endl;
}


SPECS::~SPECS() {
    
    delete [] counter;
    
    cout<<"A SPECS destroyed"<<endl;
}

