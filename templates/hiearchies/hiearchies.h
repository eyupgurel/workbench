//
// Created by egl on 6/7/19.
//

#ifndef WORKBENCH_HIEARCHIES_H
#define WORKBENCH_HIEARCHIES_H

namespace templates{

    struct Red_black_balancer{

    };


    template<typename N, typename Balancer>
    struct Node_base: Balancer{
        N* left_child;
        N* right_child;
        Node_base():left_child{nullptr},right_child{nullptr}{}
        N* left(){return left_child;}
        N* right(){return right_child;}

    };

    template<typename Val, typename Balancer>
    struct Node: public Node_base<Node<Val,Balancer>,Balancer>{
        Val v;
        Node(Val vv):v{vv}{}
    };


    template<typename T>
    using Rbnode = Node<T,Red_black_balancer>;

    Rbnode<double> myroot{3.2};




}
#endif //WORKBENCH_HIEARCHIES_H
