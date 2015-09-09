#ifndef DCM_READER_H
#define	DCM_READER_H

#include <vector>
#include <string>

class DCM_READER {
public:
    
    void set_depth();
    std::string get_imagesVector_item(int);
    int get_depth();
    
    
    void readDir();
    void printFiles();
    
    
    
    DCM_READER(char *);
    
   // DCM_READER(const DCM_READER& orig);
    
    virtual ~DCM_READER();


private:
    
    char * directory_name;
    std::vector<std::string> imagesVector;
    int depth;

};

#endif	/* DCM_READER_H */

