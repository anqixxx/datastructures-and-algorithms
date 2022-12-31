/**
 * @file HSLAPixel.cpp
 * Implementation of a simple HSLAPixel class
 *
 * @author Anqi Xu, CS 221: Data Structures
 */

#include <iostream>
#include <string>
#include <algorithm>
#include "lodepng/lodepng.h"
#include "HSLAPixel.h"

 // What does :: do in C++?
 // 

namespace cs221util {
  HSLAPixel::HSLAPixel() {
    h = 0;
    s = 0;
    l = 1.0;
    a = 1.0;
  }

  HSLAPixel::HSLAPixel(double hue, double sat, double lum) {
    h = hue;
    s = sat;
    l = lum;
    a = 1.0;
  }

  HSLAPixel::HSLAPixel(double hue, double sat, double lum, double alp) {
    h = hue;
    s = sat;
    l = lum;
    a = alp;
  }
}
