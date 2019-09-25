//
// Created by egl on 9/25/19.
//

#include "setsofnumbersthataddup.h"

using namespace dynamicprogramming;

template<int N>
bool dynamicprogramming::find_sets_of_numbers_that_addup_to_N(vector<int> &set, bitset<N>& subset, int i, int n, int& r, vector<bitset<N>>& match_set, map<pair<int,int>,bool>& history) {

  //  auto pair = make_pair(i,n);
    //cout << i << " " << n << endl;
   // if(history.find(pair)!=history.end()){
      //  return history[pair];
    //}
    bool match;
    if (set[i]>n || i==set.size()-1){
        match = false;
    } else{
        if(set[i]==n) {
            r++;
            subset.set(N - 1 - i);
            cout << "______________" << endl;
            cout << subset << endl;
            cout << "______________" << endl;
            match_set.emplace_back(subset);
            match = true;
        }
        //There are two alternatives
        subset.set(N-1-i);
        cout << subset << endl;
        auto b1 = find_sets_of_numbers_that_addup_to_N<N>(set, subset, i+1, n-set[i],r,match_set,history); //include current number
        subset.set(N-1-i,0);
        cout << subset << endl;
        auto b2 = find_sets_of_numbers_that_addup_to_N<N>(set, subset, i+1, n,r,match_set,history); //exclude current number
        match = b1 || b2;
    }
    //history[pair]=match;
    return match;
}

void dynamicprogramming::drive_to_find_sets_of_numbers() {
    vector<int> set{16,9,7};
    bitset<3> subset;
    cout << subset << endl;
    int r = 0;
    map<pair<int,int>,bool> history;

    vector<bitset<3>> match_set;

    auto b1= find_sets_of_numbers_that_addup_to_N<3>(set,subset,0,16,r,match_set,history);



}