//
// Created by Никита Ефимов on 02.12.2021.
//

#ifndef MVC_MVP_AMOUNTOFOBJECTS_HPP
#define MVC_MVP_AMOUNTOFOBJECTS_HPP
template<int A, int W, int D>
class AmountOfObjects{
public:
    int returnArchers(){return A;}
    int returnWorms(){return W;}
    int returnDragons(){return D;}
};
#endif //MVC_MVP_AMOUNTOFOBJECTS_HPP
