#ifndef DATA_H
#define	DATA_H

#include <string>

template <class T> class DATA {
  
public:
    
    
    void getData(int,int,int);
    int memoryAllocation();
    void insertData(std::string, int);
    void printDim();
    void boxCountingMethod();
    void boxCountDim();
    unsigned long long int sumComputation(int );
    void multiFractal(int boxsize, unsigned long long int totalSum);
    
    
    DATA(unsigned long, unsigned long, int);
    
    DATA(const DATA& orig);
    
    
    virtual ~DATA();


private:
    unsigned long x;
    unsigned long y;
             int  z;
    
    T *** D3array;

};

#endif	/* DATAS_H */

