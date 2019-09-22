//
// Created by egl on 9/18/19.
//

#include "langsteaufsteigendeteilfolge.h"
using namespace dynamicprogramming;

vector<int> dynamicprogramming::lese_folge(){
    ifstream is{"../dynamicprogramming/input"};
    if (is.is_open()) {
        istream_iterator<int> ii{is};
        istream_iterator<int> eos{};
        vector<int> folge{ii, eos};
        return folge;
    } else{
        throw runtime_error("Could not find file");
    }
}

vector<vector<int>>  dynamicprogramming::berechnen_alle_langste_aufsteigende_teilfolge(){
    auto folge = lese_folge();
    vector<int> a(folge.size(),1);
    vector<vector<int>> teilfolgen(folge.size());
    for(size_t i=0;i<folge.size();++i){
        if(teilfolgen[i].empty())
            teilfolgen[i]=vector<int>{folge[i]};
        for(size_t j=0;j<i;++j){
            if (folge[i]>folge[j]&& a[j]+1>a[i]) {
                a[i] = a[j] + 1;
                teilfolgen[i]=teilfolgen[j];
                teilfolgen[i].emplace_back(folge[i]);
            }
        }
    }
    return teilfolgen;
}

vector<int> dynamicprogramming::berechnen_langste_aufsteigende_teilfolge(){
    auto folge = lese_folge();
    vector<int> a(folge.size(),1);
    vector<int> vorganger(folge.size()+1, -1);
    vector<int> auf_stei_teil_folge{};
    int amax{-1};
    int amax_i{-1};
    for(size_t i=0;i<folge.size();++i){
        for(size_t j=0;j<i;++j){
            if (folge[i]>folge[j]&& a[j]+1>a[i]) {
                a[i] = a[j] + 1;
                if(amax<a[i]){
                    amax=a[i];
                    amax_i=i;
                }
                vorganger[i]=j;
            }
        }
    }


    auf_stei_teil_folge.emplace_back(folge[amax_i]);
    int index = vorganger[amax_i];
    while(index!=-1){
        auf_stei_teil_folge.emplace(auf_stei_teil_folge.begin(),folge[index]);
        index=vorganger[index];
    }

    return auf_stei_teil_folge;
}