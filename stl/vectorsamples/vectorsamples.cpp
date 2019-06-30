//
// Created by egl on 6/30/19.
//


#include "vectorsamples.h"

using namespace stl::vectorsamples;

void stl::vectorsamples::reading_letters_into_buff_keeping_track_of_word_boundaries(){
    std::vector<char> chars; // input "buffer" for characters
    constexpr int max = 20000;
    chars.reserve(max);
    std::vector<char*> words; // pointers to start of words
    bool in_word = false;
    for (char c; std::cin.get(c);) {
        if (isalpha(c)) {
            if (!in_word) { // found beginning of word
                in_word = true;
                chars.push_back(0); // end of previous word
                chars.push_back(c);
                words.push_back(&chars.back());
            }
            else
                chars.push_back(c);
        }
        else
            in_word = false;
    }
    if (in_word)
        chars.push_back(0); // terminate last word
    if (max<chars.size()) { // oops: chars grew beyond capacity; the words are invalid
        // ...
    }
    chars.shrink_to_fit(); // release any surplus capacity
}