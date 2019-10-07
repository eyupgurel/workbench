//
// Created by egl on 10/2/19.
//

#include "booleanparenthesization.h"

using namespace dynamicprogramming;



template<size_t N>
int dynamicprogramming::count_ways(bool (&symbols)[N], char(&operations)[N-1]) {
    int true_ways[N][N]{0};
    int false_ways[N][N]{0};

    for(size_t i{0};i<N;++i){ // i means distance
        for(size_t j{0}; j<N; ++j) { // j means index into symbol array
            if(j+i>=N) continue;
            if (i==0) {
                true_ways[j][j] = symbols[j] ? 1 : 0;
                false_ways[j][j] = symbols[j] ? 0 : 1;
                continue;
            }
            int true_cases{0};
            int false_cases{0};
            for(auto k{j};k<j+i;++k){ // k means index into [j,j+i] subarray
                    switch(operations[k])
                    {
                        case '&':
                            true_cases+= true_ways[j][k] * true_ways[k+1][j+i];
                            false_cases+= false_ways[j][k] * false_ways[k+1][j+i] + false_ways[j][k]* true_ways[k+1][j+i] + true_ways[j][k]* false_ways[k+1][j+i];
                            break;
                        case '|':
                            true_cases+= true_ways[j][k] * true_ways[k+1][j+i] + false_ways[j][k] * true_ways[k+1][j+i] + true_ways[j][k]* false_ways[k+1][j+i];
                            false_cases+= false_ways[j][k] * false_ways[k+1][j+i];
                            break;
                        case '^':
                            true_cases+= false_ways[j][k] * true_ways[k+1][j+i] + true_ways[j][k]* false_ways[k+1][j+i];
                            false_cases+= true_ways[j][k] * true_ways[k+1][j+i] + false_ways[j][k] * false_ways[k+1][j+i];
                            break;
                        default:
                            throw runtime_error("unknown boolean operator!");
                    }
                }
            true_ways[j][j+i]=true_cases;
            false_ways[j][j+i]=false_cases;
        }
    }
    return true_ways[0][N-1];
}

void dynamicprogramming::drive_boolean_parenthesization(){
    bool trio_symbols[3]{true,false,true};
    char operations1[2]{'^', '&'};
    auto total_ways = count_ways<3>(trio_symbols, operations1);

    bool quatro_symbols[4]{true,true,false,true};
    char operations2[3]{'|','&', '^'};
    total_ways = count_ways<4>(quatro_symbols,operations2);
}

