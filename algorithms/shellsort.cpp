//
// Created by egl on 4/9/19.
//



#include "shellsort.h"
using namespace algorithms;
    void algorithms::ssort(void* base, size_t n, size_t sz, CFT cmp){
        for(int gap=n/2; 0<gap;gap/=2){
            for(int i=gap; i<n; ++i){
                for(int j=i-gap; j>=0; j-=gap){
                    char* b = static_cast<char*>(base);
                    char* pj = b+j*sz;
                    char* pjg = b+(j+gap)*sz;
                    if(cmp(pjg,pj)<0){
                        for(int k=0; k<sz; ++k){
                            char tmp = *(pj+k);
                            *(pj+k) = *(pjg+k);
                            *(pjg+k) = tmp;
                        }
                    }
                }
            }
        }
    }

    struct User{
        const char* name;
        const char* id;
        int dept;
    };
    void print_users(const vector<User>& v){
        for(auto& u:v)
            cout<<"name:" << '\t' << u.name << '\t' << "id:" << '\t' << u.id
                << '\t' << "dept:" << '\t' << u.dept << '\n';
    }
    int cmpName(const void* p, const void* q){
        return strcmp(static_cast<const User*>(p)->name, static_cast<const User*>(q)->name);
    }
    int cmpDept(const void* p, const void* q){
        return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept;
    }
    void algorithms::test_shell_sort(){
        vector<User>heads={
                {"Ritchie D.M.", "dmr", 11271},
                {"Sethi R.", "ravi", 11272},
                {"Szymanski T.G.", "tgs",11273},
                {"Schr yer N.L.", "nls",11274},
                {"Schr yer N.L.", "nls",11275},
                {"Kernighan B.W.", "bwk",11276}
        };

        cout << "Heads unsorted" << endl;
        print_users(heads);
        cout << "Heads in alphabetical order" << endl;
        ssort(heads.data(),heads.size(),sizeof(User),cmpName);

        print_users(heads);


        cout << "Heads in order of department number:\n";
        ssort(heads.data(),6,sizeof(User),cmpDept);
        print_users(heads);
    }
