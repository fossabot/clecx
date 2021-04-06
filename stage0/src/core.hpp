#pragma once


#include <string>
#include <fstream>
#include <iostream>
#include "utils.hpp"
#include <sys/stat.h>


#define LOG(x) std::cout << x << std::endl;
#define ERR(x) std::cout << "error: " << x << std::endl;

inline bool file_exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

