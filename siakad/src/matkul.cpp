#include <iostream>
#include "include/matkul.hpp"

matkul::matkul(){}
matkul::matkul(int bobot,std::string judul):bobotsks(bobot),judul(judul){}

int matkul::getbobotsks(){
    return this->bobotsks;
}

void matkul::setbobotsks(int bobotsks){
    this->bobotsks = bobotsks;
}

std::string matkul::getjudul(){
    return this->judul;
}

void matkul::setjudul(std::string judul){
    this->judul = judul;
}