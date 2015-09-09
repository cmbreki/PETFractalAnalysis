#ifndef SPECS_H
#define	SPECS_H

#include <sys/types.h>
#include <string>
#include <stdint.h>



class SPECS {
public:
    
    unsigned long getWidth();
    unsigned long getHeight();
    int getCategory();
    
    int set_specs(std::string );
    void set_category();
    void lookUp(std::string);
    void printCounter();
    
    SPECS();
    
    SPECS(const SPECS& orig);
    
    virtual ~SPECS();



private:    
    
    unsigned long width;
    unsigned long height;
    int category;
    int * counter;
};

#endif	/* SPECS_H */

