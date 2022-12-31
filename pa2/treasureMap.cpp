#include "treasureMap.h"
#include "queue.h"
#include <string> 
using namespace std;

treasureMap::treasureMap(const PNG & baseim, const PNG & mazeim, pair<int,int> s)
{
    base = baseim;
    maze = mazeim;
    start = s;
}

void treasureMap::setGrey(PNG & im, pair<int,int> loc){

/* YOUR CODE HERE */
    RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
    pixel->r = (unsigned char) 2*(pixel->r/4);
    pixel->g = (unsigned char) 2*(pixel->g/4);
    pixel->b = (unsigned char) 2*(pixel->b/4);
}

void treasureMap::setLOB(PNG & im, pair<int,int> loc, int d){

/* YOUR CODE HERE */
    RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
    pixel->r = (unsigned char) dencode(pixel->r, d%64, {0,1});
    pixel->g = (unsigned char) dencode(pixel->g, d%64, {2,3});
    pixel->b = (unsigned char) dencode(pixel->b, d%64, {4,5});
}

PNG treasureMap::renderMap(){

/* YOUR CODE HERE */

}


PNG treasureMap::renderMaze(){

/* YOUR CODE HERE */

}

    // tests next, a neighbor (adjacent vertex) of curr to see if it is 
    // 1. within the image, 2. unvisited, and 3. the same colour as curr in
    // the maze image (member var).  An entry in table v is true if a cell 
    // has previously been visited, and false, otherwise. Colour sameness is
    // measured using the == operator on RGBAPixel values.
bool treasureMap::good(vector<vector<bool>> & v, pair<int,int> curr, pair<int,int> next){

/* YOUR CODE HERE */

}

    // builds a vector containing the locations of the 
    // four vertices adjacent to curr:
    // left, below, right, above. 
    // does not pay any attention to whether or not the neighbors are 
    // valid (in the image, previously visited, or the right colour).
vector<pair<int,int>> treasureMap::neighbors(pair<int,int> curr) {

/* YOUR CODE HERE */

}

int dencode(int higherorder, int change, pair<int,int> index){
    string change_s = to_string(change);
    string higherorder_s = to_string(higherorder);
    string result = higherorder_s.substr(0,5)+change_s[index.first]+change_s[index.second];
    return( stoi(result));
}
