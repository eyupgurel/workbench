//
// Created by egl on 7/26/19.
//

#include "weakpointersamples.h"
using namespace weakpointersamples;
std::weak_ptr<int> gw;

std::unique_ptr<const Widget> loadWidget(WidgetID id){
    return std::make_unique<Widget>(id);
}

std::shared_ptr<const Widget> fastLoadWidget(WidgetID id)
{
    static std::unordered_map<WidgetID,std::weak_ptr<const Widget>> cache;
    auto objPtr = cache[id].lock(); // objPtr is std::shared_ptr
                                    // to cached object (or null
                                    // if object's not in cache)
    if (!objPtr) {// if not in cache,
        objPtr = loadWidget(id);// load it
        cache[id] = objPtr;// cache it
    }
    return objPtr;
}

void observe()
{
    std::cout << "use_count == " << gw.use_count() << ": ";
    if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
        std::cout << *spt << "\n";
    }
    else {
        std::cout << "gw is expired\n";
    }
}
void weakpointersamples::drive_weakpointersamples() {
    {
        auto sfw = fastLoadWidget(123);
        std::cout << sfw.use_count() << std::endl;
        auto sfw1 = fastLoadWidget(123);
        std::cout << sfw.use_count() << std::endl;

        sfw1= nullptr;
        std::cout << sfw.use_count() << std::endl;
        sfw=nullptr;
        std::cout << sfw.use_count() << std::endl;

        auto sfw2 = fastLoadWidget(123);
        std::cout << sfw.use_count() << std::endl;
        std::cout << sfw2.use_count() << std::endl;

        auto sp = std::make_shared<int>(42);
        std::cout << sp.use_count() << std::endl;
        std::weak_ptr<int> wpt=sp;
        std::cout << sp.use_count() << std::endl;
        auto sp2=wpt.lock();
        std::cout << sp.use_count() << std::endl;
        std::cout << sp2.use_count() << std::endl;

        sp=nullptr;
        std::cout << sp.use_count() << std::endl;
        std::cout << sp2.use_count() << std::endl;
        sp2=nullptr;
        std::cout << sp.use_count() << std::endl;
        std::cout << sp2.use_count() << std::endl;

        sp = std::make_shared<int>(42);

        gw = sp;
        observe();
    }
    observe();

}



