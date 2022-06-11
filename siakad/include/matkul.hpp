#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__

#include <iostream>

class matkul{
    private:
        int bobotsks;
        std::string judul;

    public:
        matkul();
        matkul(int bobot, std::string judul);
        
        int getbobotsks();
        void setbobotsks(int bobotsks);

        std::string getjudul();
        void setjudul(std::string judul); 
};

#endif