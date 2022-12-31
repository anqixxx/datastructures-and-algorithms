/**
 * @file word_counter.cpp
 * Implementation of the WordFreq class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Spring 2012
 */

using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
#include <iostream>
#include <algorithm>
#include <locale>
#include <functional>
#include <string>

template <template <class K, class V> class Dict>
WordFreq<Dict>::WordFreq(const string &infile)
    : dict(256), filename(infile)
{
    /* nothing */
}

template <template <class K, class V> class Dict>
vector<pair<string, int>> WordFreq<Dict>::getWords(int threshold)
{
    TextFile infile(filename);
    vector<pair<string, int>> ret;
    /**
     * @todo Implement this function.
     * @see char_counter.cpp if you're having trouble.
     */
    Dict<string, int> dict(100);

    while (infile.good()) {
        string word = infile.getNextWord();
        if(!dict.keyExists(word)){
            dict.insert(word, 1);
        }
        else{
            int count = dict.find(word);
            dict.remove(word);
            dict.insert(word, count+1);
        }
    }

    typename Dict<string, int>::iterator it;
    for (it = dict.begin(); it != dict.end(); it++) {
        if (it->second >= threshold)
            ret.push_back(*it);
    }
    return ret;
}
