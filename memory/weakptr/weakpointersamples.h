//
// Created by egl on 7/26/19.
//

#ifndef WORKBENCH_WEAKPOINTERSAMPLES_H
#define WORKBENCH_WEAKPOINTERSAMPLES_H

#include <iostream>
#include <memory>
#include <unordered_map>

namespace weakpointersamples {
    using WidgetID=int;
    class Widget{
        public:
            Widget(WidgetID wid):id{wid}{}
        private:
            WidgetID id;
    };

    void drive_weakpointersamples();
}


#endif //WORKBENCH_WEAKPOINTERSAMPLES_H
