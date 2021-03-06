#include <cstdlib>
#include <iostream>
#include <dcmtk/ofstd/oftypes.h>

#include "DCM_READER.h"
#include "SPECS.h"
#include "DATA.h"
#include "DATA.cpp"

using namespace std;

int main(int argc, char** argv) {


    DCM_READER reader(argv[1]);
    SPECS specs;
    int result,cat;
    string filename;
    unsigned long long int sum=0;
    long long int sum2=0;
    
    
   //// create the image vectror////
   reader.readDir();
   reader.set_depth();

   
  
   /// set the specifications for this set of files 
   result=specs.set_specs(reader.get_imagesVector_item(0));
   
   
   if(result==1){  //file representation is known type
         
       cat=specs.getCategory();
       
       switch(cat){
                
           case 1:{
                  
                     DATA <Uint32> data(specs.getWidth(), specs.getHeight(),reader.get_depth());
                     data.printDim();
                     result=data.memoryAllocation();
                    if(result==1){  
                          for(int i=0; i<reader.get_depth(); i++){
                          data.insertData(reader.get_imagesVector_item(i),i);
                      } 
                       data.boxCountingMethod();
                       data.boxCountDim();
                       sum=data.sumComputation(1);
                       data.multiFractal(1,sum);
                      
                  }
   
                  break;
           }      
           case 2:{
                  DATA <Sint32> data2(specs.getWidth(), specs.getHeight(),reader.get_depth());
                  data2.printDim();
                  result=data2.memoryAllocation();
                  if(result==1){  
                      for(int i=0; i<reader.get_depth(); i++){
                          data2.insertData(reader.get_imagesVector_item(i),i);
                      } 
                    data2.boxCountingMethod();
                    data2.boxCountDim();
                    sum2=data2.sumComputation(1);
                    data2.multiFractal(1,sum2);
                    
                  }
                
                  break;
           }

       
      }//end switch

  
}//enf if result

    return 0;
}//end main

