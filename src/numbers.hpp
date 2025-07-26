#include "sprite.hpp"

/* A number in a 4 by 5 grid,
    # # # #
    # # # #
    # # # #
    # # # #
    # # # #
*/
class Number : public Sprite {
    int num = 0;

    // number tiles
    void setTilesZero();
    void setTilesOne();
    void setTilesTwo();
    void setTilesThree();
    void setTilesFour();
    void setTilesFive();
    void setTilesSix();
    void setTilesSeven();
    void setTilesEight();
    void setTilesNine();
    public:
    void setNumber(int n);

    int getNumber();


};