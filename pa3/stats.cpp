#include "stats.h"
#include "stats.h"
#include<cmath>

stats::stats(PNG & im){
    sumRed.resize(im.width(), vector<long>(im.height(), 0));
    sumGreen.resize(im.width(), vector<long>(im.height(), 0));
    sumBlue.resize(im.width(), vector<long>(im.height(), 0));
    sumsqRed.resize(im.width(), vector<long>(im.height(), 0));
    sumsqGreen.resize(im.width(), vector<long>(im.height(), 0));
    sumsqBlue.resize(im.width(), vector<long>(im.height(), 0));
    
    for (unsigned int y =0; y < im.height(); y++ ){
        for (unsigned int x = 0; x < im.width(); x++){
            RGBAPixel* pixel = im.getPixel(x, y);
            if (x != 0 && y != 0){
                sumRed[x][y] = pixel->r + sumRed[x][y-1] + sumRed[x-1][y] - sumRed[x-1][y-1];
                sumGreen[x][y] = pixel->g + sumGreen[x][y-1] + sumGreen[x-1][y] - sumGreen[x-1][y-1];
                sumBlue[x][y] = pixel->b + sumBlue[x][y-1] + sumBlue[x-1][y] - sumBlue[x-1][y-1];
                sumsqRed[x][y] = pow(pixel->r,2) + sumsqRed[x][y-1] + sumsqRed[x-1][y] - sumsqRed[x-1][y-1];
                sumsqGreen[x][y] = pow(pixel->g,2) + sumsqGreen[x][y-1] + sumsqGreen[x-1][y] - sumsqGreen[x-1][y-1];
                sumsqBlue[x][y] = pow(pixel->b, 2) + sumsqBlue[x][y-1] + sumsqBlue[x-1][y] - sumsqBlue[x-1][y-1];
            }
            else if (y != 0){ //i.e first horz. row, can just add linearly
                sumRed[x][y] = pixel->r + sumRed[x][y-1];
                sumGreen[x][y] = pixel->g + sumGreen[x][y-1];
                sumBlue[x][y] = pixel->b + sumBlue[x][y-1];
                sumsqRed[x][y] = pow(pixel->r,2) + sumsqRed[x][y-1];
                sumsqGreen[x][y] = pow(pixel->g,2) + sumsqGreen[x][y-1];
                sumsqBlue[x][y] = pow(pixel->b, 2) + sumsqBlue[x][y-1];
            }
            else if (x != 0){
                sumRed[x][y] = pixel->r + sumRed[x-1][y];
                sumGreen[x][y] = pixel->g + sumGreen[x-1][y];
                sumBlue[x][y] = pixel->b + sumBlue[x-1][y];
                sumsqRed[x][y] = pow(pixel->r,2) + sumsqRed[x-1][y];
                sumsqGreen[x][y] = pow(pixel->g,2) + sumsqGreen[x-1][y];
                sumsqBlue[x][y] = pow(pixel->b, 2) + sumsqBlue[x-1][y];
            } else if (x==0 && y ==0){
                sumRed[x][y] = pixel->r;
                sumGreen[x][y] = pixel->g;
                sumBlue[x][y] = pixel->b;
                sumsqRed[x][y] = pow(pixel->r,2);
                sumsqGreen[x][y] = pow(pixel->g,2);
                sumsqBlue[x][y] = pow(pixel->b, 2);
            } 
        }
    }
}


long stats::getSum(char channel, pair<int,int> ul, int w, int h){
    long sum = 0; int x = ul.first; int y = ul.second;

    if (x != 0 && y != 0){
        if (channel == 'r') sum = sumRed[x+w-1][y+h-1] - sumRed[x-1][y+h-1] - sumRed[x+w-1][y-1] + sumRed[x-1][y-1];
        if (channel == 'g') sum = sumGreen[x+w-1][y+h-1] - sumGreen[x-1][y+h-1] - sumGreen[x+w-1][y-1] + sumGreen[x-1][y-1];
        if (channel == 'b') sum = sumBlue[x+w-1][y+h-1] - sumBlue[x-1][y+h-1] - sumBlue[x+w-1][y-1] + sumBlue[x-1][y-1];
    }
    else if (y != 0){
        if (channel == 'r') sum = sumRed[w-1][y+h-1] - sumRed[w-1][y-1];
        if (channel == 'g') sum = sumGreen[w-1][y+h-1] - sumGreen[w-1][y-1];
        if (channel == 'b') sum = sumBlue[w-1][y+h-1] - sumBlue[w-1][y-1];
    }
    else if (x != 0){
        if (channel == 'r') sum = sumRed[x+w-1][h-1] -sumRed[x-1][h-1];
        if (channel == 'g') sum = sumGreen[x+w-1][h-1] -sumGreen[x-1][h-1];
        if (channel == 'b') sum = sumBlue[x+w-1][h-1] -sumBlue[x-1][h-1];
    }
    else if (x==0 && y ==0){
        if (channel == 'r') sum = sumRed[w-1][h-1];
        if (channel == 'g') sum = sumGreen[w-1][h-1];
        if (channel == 'b') sum = sumBlue[w-1][h-1];
    }
    
    return sum;

}

long stats::getSumSq(char channel, pair<int,int> ul, int w, int h){    
    long sum = 0; int x = ul.first; int y = ul.second;

    if (x != 0 && y != 0){
        if (channel == 'r') sum = sumsqRed[x+w-1][y+h-1] - sumsqRed[x-1][y+h-1] - sumsqRed[x+w-1][y-1] + sumsqRed[x-1][y-1];
        if (channel == 'g') sum = sumsqGreen[x+w-1][y+h-1] - sumsqGreen[x-1][y+h-1] - sumsqGreen[x+w-1][y-1] + sumsqGreen[x-1][y-1];
        if (channel == 'b') sum = sumsqBlue[x+w-1][y+h-1] - sumsqBlue[x-1][y+h-1] - sumsqBlue[x+w-1][y-1] + sumsqBlue[x-1][y-1];
    }
    else if (y != 0){
        if (channel == 'r') sum = sumsqRed[w-1][y+h-1] - sumsqRed[w-1][y-1];
        if (channel == 'g') sum = sumsqGreen[w-1][y+h-1] - sumsqGreen[w-1][y-1];
        if (channel == 'b') sum = sumsqBlue[w-1][y+h-1] - sumsqBlue[w-1][y-1];
    }
    else if (x != 0){
        if (channel == 'r') sum = sumsqRed[x+w-1][h-1] -sumsqRed[x-1][h-1];
        if (channel == 'g') sum = sumsqGreen[x+w-1][h-1] -sumsqGreen[x-1][h-1];
        if (channel == 'b') sum = sumsqBlue[x+w-1][h-1] -sumsqBlue[x-1][h-1];
    }
    else if (x==0 && y ==0){
        if (channel == 'r') sum = sumsqRed[w-1][h-1];
        if (channel == 'g') sum = sumsqGreen[w-1][h-1];
        if (channel == 'b') sum = sumsqBlue[w-1][h-1];
    }

    return sum;
}

// given a rectangle, compute its sum of squared deviations from mean, over all color channels.
// see written specification for a description of this function.
double stats::getVar(pair<int,int> ul, int w, int h){
    double area = w*h;
    if (area == 0) return 0.0;

    long red = getSum('r', ul, w, h);
    long green = getSum('g', ul, w, h);
    long blue = getSum('b', ul, w, h);
    long redSq = getSumSq('r', ul, w, h);
    long greenSq = getSumSq('g', ul, w, h);
    long blueSq = getSumSq('b', ul, w, h);

    double varRed = redSq - (red*red)/area;
    double varGreen = greenSq - (green*green)/area;
    double varBlue = blueSq - (blue*blue)/area;
    
    return (varRed + varGreen + varBlue);
}
		
RGBAPixel stats::getAvg(pair<int,int> ul, int w, int h){
    long area = w*h;
    RGBAPixel pixel;
    if (area != 0){    
        pixel.r = getSum('r', ul, w, h)/area;
        pixel.g = getSum('g', ul, w, h)/area; 
        pixel.b = getSum('b', ul, w, h)/area;
    } 
    return pixel;
}
