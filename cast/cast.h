//
// Created by egl on 5/22/19.
//

#ifndef WORKBENCH_CAST_H
#define WORKBENCH_CAST_H
#include <string>

using namespace std;
namespace cast{
    struct Storable //persistent storage
    {
     virtual string get_file() = 0;
     virtual void read() = 0;
     virtual void write() = 0;
     virtual ~Storable() { }
    };

    class Component: public virtual Storable {
        int cv1;
        double cv2;
    };

    class Receiver: public Component {
        int rv1;
        double rv2;
    };

    class Transmitter: public Component {
        int tv1;
        double tv2;
    };

    class Radio: public Receiver, public Transmitter {
        string get_file() override{return "component.file";};
        void read()override{}
        void write()override{}
        int rv1;
        double rv2;
    };

    void drive_cast();
}


#endif //WORKBENCH_CAST_H
