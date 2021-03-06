
#include <iostream>
#include <cstring>
#include <ostream>
#include <limits>

#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/config/osconfig.h" 
#include <dcmtk/ofstd/oftypes.h>
#include <dcmtk/dcmimgle/dcmimage.h>

#include <tgmath.h>
#include <cmath>
#include <cstdlib>



#include "DATA.h"

using namespace std;

typedef std::numeric_limits< double > dbl;


//////////////get Data////////////////////

template <class T>
void DATA<T>::getData(int r, int c, int d){

    cout<< D3array[r][c][d]<<endl;

} 


////////////insert Data//////////////////

template <class T>
void DATA<T>::insertData( std::string filename , int slice ){

    DicomImage *image = new DicomImage(filename.c_str()); // read the .dcm file
    
    const DiPixel *diPixel;
    const void * ptr;
    
    EP_Representation rep; // pixels' representation
    
    
    if (image != NULL){
      
         if (image->getStatus() == EIS_Normal){
          
                 
            if (image->isMonochrome()){
                    
               
                     diPixel=image->getInterData();
                     
                     rep=diPixel->getRepresentation();                     


                  if(diPixel!=NULL){
                      
                      ptr=diPixel->getData();
                      
                     
                        if(ptr==NULL){
                           cout<<"null ptr"<<endl;
                           }
                     
                              if(rep == EPR_Uint8){ // pixels' representation is unsigned 8 bit

                                    Uint8 ** temp;
                                   
                                     temp= new Uint8 * [y];
                                         for(int i=0; i<y; i++){
                                           temp[i]= new Uint8 [x];
                                         }
                                         
                                          for(int rows=0; rows<x; rows++){
                                            for(int col=0; col<y; col++){
                                             temp[rows][col]=0;
                                           }
                                          }


                                            for(int i=0;i<y;i++){
                                               memcpy((void *)temp[i],((Uint8*)ptr)+i*x , x*sizeof(Uint8));
                                            }
                       
                                            for(int k=0;k<y;k++){
                                                for(int n=0;n<x;n++){
                                                    D3array[k][n][slice]=(T)temp[k][n];
                                                }
                                            }
                    
                                         ///de-allocation 2D temp///

                                            for(int j=0;j<y;j++){  
                                               delete [] temp[j];}
   
                                      delete [] temp;
                                    }

                                  else if (rep== EPR_Sint8){  // pixels' representation is signed 8 bit
                      
                                    Sint8 ** temp;
                                 
                                       temp= new Sint8 * [y];
                                          for(int i=0; i<y; i++){
                                            temp[i]= new Sint8 [x];
                                          }
                                          
                                           for(int rows=0; rows<x; rows++){
                                            for(int col=0; col<y; col++){
                                             temp[rows][col]=0;
                                           }
                                          }

                                             for(int i=0;i<y;i++){
                                                memcpy((void *)temp[i],((Sint8*)ptr)+i*x , x*sizeof(Sint8));
                                             }
                           
                                             for(int k=0;k<y;k++){
                                                 for(int n=0;n<x;n++){
                                                     D3array[k][n][slice]=(T)temp[k][n];
                                                 }
                                             }

                                      ///de-allocation 2D temp///
                                          for(int j=0;j<y;j++){  
                                            delete [] temp[j];}
   
                                  delete [] temp;
                                }

                                 
                           else  if(rep == EPR_Uint16){ // pixels' representation is unsigned 16 bit

                                    Uint16 ** temp;
                                   
                                     temp= new Uint16 * [y];
                                         for(int i=0; i<y; i++){
                                           temp[i]= new Uint16 [x];
                                         }
                                       
                                           for(int rows=0; rows<x; rows++){
                                            for(int col=0; col<y; col++){
                                             temp[rows][col]=0;
                                           }
                                          }

                                            for(int i=0;i<y;i++){
                                               memcpy((void *)temp[i],((Uint16*)ptr)+i*x , x*sizeof(Uint16));
                                            }
                       
                                            for(int k=0;k<y;k++){
                                                for(int n=0;n<x;n++){
                                                    D3array[k][n][slice]=(T)temp[k][n];
                                                }
                                            }
                    
                                         ///de-allocation 2D temp///

                                            for(int j=0;j<y;j++){  
                                               delete [] temp[j];}
   
                                      delete [] temp;
                                    }
                     
                              else if (rep== EPR_Sint16){ // pixels' representation is signed 16 bit
                      
                                    Sint16 ** temp;
                                 
                                       temp= new Sint16 * [y];
                                          for(int i=0; i<y; i++){
                                            temp[i]= new Sint16 [x];
                                          }
                                           
                                           for(int rows=0; rows<x; rows++){
                                            for(int col=0; col<y; col++){
                                             temp[rows][col]=0;
                                           }
                                          }

                                             for(int i=0;i<y;i++){
                                                memcpy((void *)temp[i],((Sint16*)ptr)+i*x , x*sizeof(Sint16));
                                             }
                           
                                             for(int k=0;k<y;k++){
                                                 for(int n=0;n<x;n++){
                                                     D3array[k][n][slice]=(T)temp[k][n];
                                                 }
                                             }

                                      ///de-allocation 2D temp///
                                          for(int j=0;j<y;j++){  
                                            delete [] temp[j];}
   
                                  delete [] temp;
                                }
                   
                              else if(rep == EPR_Uint32){ // pixels' representation is unsigned 32 bit
                         
                                   Uint32 ** temp;
                                 
                                       temp= new Uint32 * [y];
                                          for(int i=0; i<y; i++){
                                            temp[i]= new Uint32 [x];
                                          }
   
                                          for(int rows=0; rows<x; rows++){
                                            for(int col=0; col<y; col++){
                                             temp[rows][col]=0;
                                           }
                                          }

                                            for(int i=0;i<y;i++){
                                              memcpy((void *)temp[i],((Uint32*)ptr)+i*x , x*sizeof(Uint32));
                                            }
                       
                                            for(int k=0;k<y;k++){
                                                for(int n=0;n<x;n++){
                                                    D3array[k][n][slice]=(T)temp[k][n];
                                                }
                                            }

                                       ///de-allocation 2D temp///
                                          for(int j=0;j<y;j++){  
                                            delete [] temp[j];}
                                     delete [] temp;
                                }
                      
                            else if (rep == EPR_Sint32){  // pixels' representation is signed 32 bit
                          
                                    Sint32 ** temp;
                                
                                    temp= new Sint32 * [y];
                                      for(int i=0; i<y; i++){
                                        temp[i]= new Sint32 [x];
                                    }

                                        for(int i=0;i<y;i++){
                                          memcpy((void *)temp[i],((Sint32*)ptr)+i*x , x*sizeof(Sint32));
                                        }
                                    
                                      for(int rows=0; rows<x; rows++){
                                            for(int col=0; col<y; col++){
                                             temp[rows][col]=0;
                                           }
                                          }
                       
                                        for(int k=0;k<y;k++){
                                           for(int n=0;n<x;n++){
                                               D3array[k][n][slice]=(T)temp[k][n];
                                            }
                                        }
                    
                                   ///de-allocation 2D temp///
                                      for(int j=0;j<y;j++){  
                                        delete [] temp[j];}
                                delete [] temp;
                        }
                       else{
                         
                         cout<<"Image pixel representation:unknown"<<endl;
                        }             
                 
                }
            else{
                   
                cout<<"diPixel NULL"<<endl;
                
              }           
                          
                 
           }
     
        }
     
    }
    

    else{
    cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << endl;
    }

delete image;
 
}//end insertData


/// Implementation of the Box Countng Method 
////////////////////BoxCountingMethod/////////////////////////

template <class T>
void DATA<T>::boxCountingMethod(){

 
int boxsize,boxsize_i,boxsize_j,boxsize_z;
 
int ni,nj,ki,kj,kz,nz;
 
 int counter=0;
 int mult=0;
 
 int maxx=x;
 int minx=0;
 
 int maxy=y;
 int miny=0;
 
 int minz=0;
 int maxz=z;
 
 T sumbox;

 ofstream out_Data("BCMoutput_file.dat");
 
double * results;

results=new double[50];

for(int w=0; w<50; w++){
results[w]=0;
}

 for(boxsize=1;boxsize<=50;boxsize++){
       
     boxsize_i=(maxx-minx)/boxsize;     
     boxsize_j=(maxy-miny)/boxsize;
     boxsize_z=(maxz-minz)/boxsize;
     
         for(nz=0;nz<boxsize_z;nz++){
             for(ni=0; ni<boxsize_i;ni++){
                 for(nj=0; nj<boxsize_j;nj++){
                     sumbox=0;
                     for(kz=nz*boxsize; kz<(nz*boxsize)+boxsize; kz++){
                          for(ki=ni*boxsize; ki<(ni*boxsize)+boxsize; ki++){
                              for(kj=nj*boxsize;kj<(nj*boxsize)+boxsize;kj++){
                                  
                                    if(D3array[ki][kj][kz]>0){
                                  
                                         sumbox=sumbox+D3array[ki][kj][kz];}                                  
                             
                              }// kj
                          
                           }// for ki
                      
                      }// for  kz 
             
                     if(sumbox>0){
                       counter++;  
                     }
                 
                 }//for nj             
             
             }//for ni
         
         }//for nz
 
     
     
     mult=boxsize_i*boxsize_j*boxsize_z*boxsize*boxsize*boxsize;
     results[boxsize-1]=(double)counter/(double)mult;
     out_Data.precision(dbl::digits10);     
     out_Data<<boxsize<<" "<<std::fixed<< results[boxsize-1]<<endl;
     
     counter=0;
     

}//for boxsize
 

delete[]  results; 

}

// Implementation of the Box Counting Method considering the physical dimensions
////////////////////////boxCountDim///////////////////////////////


template <class T>
void DATA<T>::boxCountDim(){

 
int boxsize,boxsize_i,boxsize_j,boxsize_z;

 
int ni,nj,ki,kj,kz,nz;
 
 int counter=0;

 int mult=0;
 
 int maxx=x;
 int minx=0;
 
 int maxy=y;
 int miny=0;
 
 int minz=0;
 int maxz=z;
 
 T sumbox;

ofstream out_Data("BCMdim_output_file.dat");
 
double * results;


 
 results=new double[50];

for(int w=0; w<50; w++){
results[w]=0;}

 for(boxsize=1;boxsize<=50;boxsize++){
       
     boxsize_i=(maxx-minx)/(2*boxsize);     
     boxsize_j=(maxy-miny)/(2*boxsize);
     boxsize_z=(maxz-minz)/boxsize;
     
         for(nz=0;nz<boxsize_z;nz++){
             for(ni=0; ni<boxsize_i;ni++){
                 for(nj=0; nj<boxsize_j;nj++){
                     sumbox=0;
                     for(kz=nz*boxsize; kz<(nz*boxsize)+boxsize; kz++){
                          for(ki=ni*2*boxsize; ki<(ni*2*boxsize)+2*boxsize; ki++){
                              for(kj=nj*2*boxsize;kj<(nj*2*boxsize)+2*boxsize;kj++){
                                  
                                    if(D3array[ki][kj][kz]>0){
                                  
                                         sumbox=sumbox+D3array[ki][kj][kz];}
                                    
                                   
                                   
                             
                              }// kj
                          
                           }// for ki
                      
                      }// for  kz 
                     
                     if(sumbox>0){
                       counter++;}                   
                 
                 }//for nj             
             
             }//for ni
         
         }//for nz
 
     
    
     mult=boxsize_i*boxsize_j*boxsize_z*(4*boxsize)*(4*boxsize)*(4*boxsize);
     results[boxsize-1]=(double)counter/(double)mult;
     out_Data.precision(dbl::digits10);     
     out_Data<<boxsize*4<<" "<<std::fixed<<results[boxsize-1]<<endl;

     counter=0;
   

}//for boxsize
 

delete[]  results; 

}


/////////////////// sum Computation /////////////////////////////////

template <class T>
unsigned long long int DATA<T>::sumComputation(int boxsize){


int boxsize_i,boxsize_j,boxsize_z;

 
int ni,nj,ki,kj,kz,nz;
 
 int counter=0;

 int mult=0;
 
 int maxx=x;
 int minx=0;
 
 int maxy=y;
 int miny=0;
 
 int minz=0;
 int maxz=z;
 
unsigned long long int sumbox=0;

 boxsize_i=(maxx-minx)/(2*boxsize);     
 boxsize_j=(maxy-miny)/(2*boxsize);
 boxsize_z=(maxz-minz)/boxsize;
     
         for(nz=0;nz<boxsize_z;nz++){
             for(ni=0; ni<boxsize_i;ni++){
                 for(nj=0; nj<boxsize_j;nj++){
                     
                     for(kz=nz*boxsize; kz<(nz*boxsize)+boxsize; kz++){
                          for(ki=ni*2*boxsize; ki<(ni*2*boxsize)+2*boxsize; ki++){
                              for(kj=nj*2*boxsize;kj<(nj*2*boxsize)+2*boxsize;kj++){
                                  
                                    if(D3array[ki][kj][kz]>0){
                                         
                                         sumbox=sumbox+D3array[ki][kj][kz];}
                                    
                                                 
                             
                              }// kj
                          
                           }// for ki
                      
                      }// for  kz  
                   
                 }//for nj             
             
             }//for ni
         
         }//for nz

    cout<<sumbox;
    return sumbox;
}



////////////////////Generalized Dimensions///////////////////////

template<class T>
void DATA<T>:: multiFractal(int boxsize, unsigned long long int totalSum){

ofstream out_Data("multifractal_output_file.dat");

long long int sum=0;

long double result,athroisma,sum_pn=0;
long double  * sum_array;
long double Dq;
double epsilon;

 int q,k=0;

int  boxsize_i,boxsize_j,boxsize_z;
int ni,nj,ki,kj,kz,nz;
 int maxx=x;
 int minx=0;
 
 int maxy=y;
 int miny=0;
 
 int minz=0;
 int maxz=z;

athroisma=0;
  
cout<<"Total sum is:"<<totalSum<<endl;

     boxsize_i=(maxx-minx)/(2*boxsize);     
     boxsize_j=(maxy-miny)/(2*boxsize);
     boxsize_z=(maxz-minz)/boxsize;

epsilon=((1/(double)boxsize_i)+(1/(double)boxsize_j)+(1/(double)boxsize_z))/3;

cout<<"e is:"<<epsilon<<endl;

 sum_array= new long double[boxsize_i*boxsize_j*boxsize_z];  

for(int w=0; w<boxsize_i*boxsize_j*boxsize_z; w++){
   sum_array[w]=0;
}

   for( nz=0;nz<boxsize_z;nz++){
     
       for(ni=0; ni<boxsize_i;ni++){
         
         for(nj=0; nj<boxsize_j;nj++){
           
           sum=0;
           result=0;
            
            for(kz=nz*boxsize; kz<(nz*boxsize)+boxsize; kz++){
                   
              for(ki=ni*2*boxsize; ki<(ni*2*boxsize)+2*boxsize; ki++){
                  
                 for(kj=nj*2*boxsize;kj<(nj*2*boxsize)+2*boxsize;kj++){
                    
                     sum=sum+D3array[ki][kj][kz];
                  }
                 
                }
              }
              
             if(sum>0){
              sum_array[k]=(long double)sum/totalSum;
              athroisma=athroisma+sum_array[k];
              k++;
              } //end if
              
         }
     
      }     
   
   }  
   
  for(q=-20 ; q<=20 ; q++){
  
        sum_pn=0;
        Dq=0;  
     
    if(q!=1){

         for(int count=0; count<k; count++){
           sum_pn=sum_pn+pow(sum_array[count],q);
         }// count for

          Dq=(1/(double)(q-1))*(1/(double)log(epsilon))*(log(sum_pn));
          out_Data.precision(dbl::digits10);
          out_Data<<q<<" "<<Dq<<endl;
     }// end if q
    else{
          
        for(int count=0; count<k; count++){
          
          sum_pn=sum_pn+(sum_array[count]*log(sum_array[count]));
          }// count for
       
           
           Dq=(1/(double)log(epsilon))*sum_pn;
           out_Data.precision(dbl::digits10);
           out_Data<<q<<" "<<Dq<<endl;

     }// end else 

}//end q for



delete [] sum_array;


}



/////////////memory allocation///////////////////

template <class T>
int DATA<T>::memoryAllocation(){
    
    try{
     D3array= new T ** [y];
      
      for(int i=0; i<y; i++){
          D3array[i]= new T * [x];
            for(int j=0; j< x ; j++){
              D3array[i][j]=new T [z];
            }
       }     

          for(int i=0; i<x; i++){
           for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
              D3array[i][j][k]=0;
            }
           }
          }

    
      cout<<"MemoryAllocation:Success"<<endl;
      return 1;
    
    }
     catch(std::bad_alloc& exc){
         cout<<"No successful memory allocation"<<endl;
         return 0;
     }

}



//////////////print function////////////////

template <class T>
void DATA<T>::printDim(){

    cout<<x<<endl<<y<<endl<<z<<endl;
}


//////////constructor/////////////

template <class T>
DATA<T>::DATA(unsigned long w, unsigned long h, int d) {
    
    x=w;
    y=h;
    z=d;
    D3array=NULL;

}




///////////destructor//////////////

template <class T>
DATA<T>::~DATA() {
    
   for (int i = 0; i < y; ++i) {
    
       for (int j = 0; j < x; ++j){
         delete [] D3array[i][j];}

    delete [] D3array[i];
  }
  delete [] D3array;
  
  cout<<"DATA Destructor"<<endl;


}

