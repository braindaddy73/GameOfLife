//
// Created by Heiko Kitscha on 07.04.24.
//

#ifndef GAMEOFLIFE_BIOTOPE_H
#define GAMEOFLIFE_BIOTOPE_H


class Biotope {
private:
    std::vector<std::vector<unsigned char>> biotope;

public:
    Biotope();
    ~Biotope();

    calcNextGen();
    unsigned char getCell(int x, int y);
};


#endif //GAMEOFLIFE_BIOTOPE_H
