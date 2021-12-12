//
// Created by Никита Ефимов on 02.12.2021.
//

#ifndef MVC_MVP_AMOUNTOFOBJECTS_HPP
#define MVC_MVP_AMOUNTOFOBJECTS_HPP
template<int A, int W, int D, int HT, int PT, int SHT>
class AmountOfObjects{
public:
    int returnArchers(){return A;}
    int returnWorms(){return W;}
    int returnDragons(){return D;}
    int returnHealTools(){return HT;}
    int returnSupHealTool(){return SHT;}
    int returnPoisonTool(){return PT;}
};
#endif //MVC_MVP_AMOUNTOFOBJECTS_HPP
