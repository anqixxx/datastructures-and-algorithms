/**
 * @file RGBAPixel.h
 *
 * @author CS 221: Data Structures
 */

#ifndef CS221UTIL_RGBAPIXEL_H
#define CS221UTIL_RGBAPIXEL_H

#include <string>
#include <vector>

using namespace std;

namespace cs221util {
  class RGBAPixel {
  public:
    /**
      * Creates an default RGBA pixel
      * White,  a pixel with the maximum 
      * contribution on all visible colour 
      * channels, and alpha 1.0
      */
    RGBAPixel();

    /**
     * Creates a RGBA Pixel with set red, green and blue values
     * and full opacity
     * @param red the red value
     * @param gre the green value
     * @param blu the blue value
     */
    RGBAPixel(unsigned char red, unsigned char gre, unsigned char blu);

    /**
     * Creates a RGBA Pixel with set red, green and blue values
     * and a set opacity (alpha) value
     * @param red the red value
     * @param gre the green value
     * @param blu the blue value
     * @param alpha the opacity value
     */
    RGBAPixel(unsigned char red, unsigned char gre, unsigned char blu, double alpha);

    // r,g, b ranges from 255
    unsigned char r;
    unsigned char g;
    unsigned char b;
    double a; // Range from 0 to 1.0
  };
}

#endif
