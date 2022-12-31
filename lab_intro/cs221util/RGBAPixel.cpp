/**
 * @file RGBAPixel.cpp
 * Implementation of a simple RGBAPixel class
 *
 * @author CS 221: Data Structures
 */

#include <iostream>
#include <string>
#include <algorithm>
#include "lodepng/lodepng.h"
#include "RGBAPixel.h"

namespace cs221util {
//means the function is part of the PNG class
  RGBAPixel::RGBAPixel() {
    r =  255;
    g = 255;
    b = 255;
    a = 1.0;
  }
  
  RGBAPixel::RGBAPixel(unsigned char red,unsigned char gre,unsigned char blu){
    r =  red;
    g = gre;
    b = blu;
    a = 1.0;
  }
  
  RGBAPixel::RGBAPixel(unsigned char red, unsigned char gre,unsigned char blu, double alpha){
    r =  red;
    g = gre;
    b = blu;
    a = alpha;
  }
}
