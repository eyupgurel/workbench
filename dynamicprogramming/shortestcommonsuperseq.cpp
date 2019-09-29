//
// Created by egl on 9/24/19.
//

#include "shortestcommonsuperseq.h"

using namespace dynamicprogramming;
using namespace slab;

/*int dynamicprogramming::find_shortest_common_superseq2(string& a, string& b, vector<pair<int,int>>& history,
        int pa, int pb){
    if(pa==a.length() && pb==b.length()){
        return 0;
    } else if(pa==a.length() && pb!=b.length()){
        history.emplace_back(pair<int,int>{pa,pb+1});
        return 1+find_shortest_common_superseq2(a,b,history,pa,pb+1);
    } else if(pa!=a.length() && pb==b.length()){
        history.emplace_back(pair<int,int>{pa+1,pb});
        return 1+find_shortest_common_superseq2(a,b,history,pa+1,pb);
    }

    if(a[pa]==b[pb]){
       history.emplace_back(pair<int,int>{pa+1,pb+1});
       return 1+find_shortest_common_superseq2(a,b,history,pa+1,pb+1);
    } else{
        auto r1 = find_shortest_common_superseq2(a,b,history,pa+1,pb);
        auto r2 = find_shortest_common_superseq2(a,b,history,pa,pb+1);
        if(r1<r2){
            history.emplace_back(pair<int,int>{pa+1,pb});
            return r1;
        } else{
            history.emplace_back(pair<int,int>{pa,pb+1});
            return r2;
        }

    }
}
*/
string dynamicprogramming::find_shortest_common_superseq(string a, string b) {
    if(a.empty()) return b;
    if(b.empty()) return a;

    if(a.front()==b.front()){
        string scs;
        scs.push_back(a.front());
        a.erase(a.begin(),a.begin()+1);
        b.erase(b.begin(), b.begin()+1);
        return scs + find_shortest_common_superseq(a,b);
    } else{
        string ca = a;
        ca.erase(ca.begin(),ca.begin()+1);
        string scs1;
        scs1.push_back(a.front());
        scs1 += find_shortest_common_superseq(ca,b);

        string cb = b;
        cb.erase(cb.begin(),cb.begin()+1);
        string scs2;
        scs2.push_back((b.front()));
        scs2 += find_shortest_common_superseq(a,cb);
        return scs1.length() < scs2.length() ? scs1 : scs2;
    }

}

void dynamicprogramming::drive_to_find_shortest_common_super_seq() {
     string a{"ABCBDAB"};
     string b{"BDCABA"};
    //string a{"AB"};
    //string b{"BA"};
    //vector<pair<int,int>> history;
    //int r = find_shortest_common_superseq2(a,b,history,0,0);

     string scs=find_shortest_common_superseq(a,b);
}

string dynamicprogramming::find_shortest_common_superseq_by_back_tracking(string& lhs, string& rhs) {
    Matrix<int,2> matrix(lhs.length()+1,rhs.length()+1);
    for(size_t i=1;i<=lhs.length();++i){
        for(size_t j=1;j<=rhs.length();++j){
            if(lhs[i-1]==rhs[j-1]){
                matrix(i,j)= matrix[i-1][j-1]+1;
            } else{
                matrix(i,j) = matrix[i][j-1] > matrix[i-1][j] ? matrix[i][j-1] : matrix[i-1][j];
            }
        }
    }
    cout << matrix << endl;
    auto i=lhs.length();
    auto j= rhs.length();
    string res;
    while(i!=0 && j!=0){
        if(lhs[i-1]==rhs[j-1]){
            res.insert(res.begin(),lhs[i-1]);
            --i;
            --j;
        } else{
            if(matrix(i,j-1) > matrix(i-1,j)){
                res.insert(res.begin(),rhs[j-1]);
                --j;
            } else{
                res.insert(res.begin(),lhs[i-1]);
                --i;
            }
        }
    }
    while(i!=0){
        res.insert(res.begin(),lhs[i-1]);
        --i;
    }
    while(j!=0){
        res.insert(res.begin(),rhs[j-1]);
        --j;
    }
    return res;
}

void dynamicprogramming::drive_to_find_shortest_common_superseq_by_back_tracking() {
    string lhs{"CABCA"};
    string rhs{"ACABAD"};
    auto scs = find_shortest_common_superseq_by_back_tracking(lhs,rhs);

    lhs="ABCBDAB";
    rhs="BDCABA";
    scs = find_shortest_common_superseq_by_back_tracking(lhs,rhs);

    lhs="GXTXAYB";
    rhs="AGGTAB";
    scs = find_shortest_common_superseq_by_back_tracking(lhs,rhs);
}