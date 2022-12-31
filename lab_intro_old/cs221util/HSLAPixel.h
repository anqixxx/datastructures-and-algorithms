/**
 * @file HSLAPixel.h
 *
 * @author Anqi Xu, CS 221: Data Structures
 */


#ifndef CS221UTIL_HSLAPixel_H
// Do we need this in this file, what does this do?
// Include guards?
#define CS221UTIL_HSLAPixel_H

#include <string>
#include <vector>

using namespace std;

namespace cs221util {
  class HSLAPixel{
  public:

    /**
      * Default constructor
      * Sets the default pixel to white
      * (a pixel with any hue, saturation 0,
      * luminance 1.0, and alpha 1.0)
      */
    HSLAPixel();

   /**
      * Three argument constructor
      * Parameters used to set hue, saturation,
      * and luminance
      */
    // can I use the same variable names for arguements as local variables?
    HSLAPixel(double hue, double sat, double lum);

   /**
      * Four argument constructor
      * Parameters used to set hue, saturation,
      * luminance, and alpha
      */
    HSLAPixel(double hue, double sat, double lum, double alp);


    
    /**
        * h represents hue
        * s represents saturation
        * l represents luminance
        * a represents alpha (transparency value)
        */
    public:
        double h;
        double s;
        double l;
        double a;

  };

}

#endif
