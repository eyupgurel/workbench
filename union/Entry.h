//
// Created by egl on 3/9/19.
//

#ifndef WORKBENCH_ENTRY_H
#define WORKBENCH_ENTRY_H

#include <string>

using namespace std;

namespace  unions{

    class Entry{
    private:
        enum class Tag {number, text};
        Tag type;
        union{
            int i;
            string s;
        };
    public:
        struct Bad_entry:exception{};
        string name;
        ~Entry();
        Entry(const Entry& entry);
        Entry(string t);
        Entry(int i);
        Entry& operator=(const Entry& entry);


        int number() const;
        string text() const;

        void set_number(const int n);
        void set_text(const string& s);
    };

};




#endif //WORKBENCH_ENTRY_H
