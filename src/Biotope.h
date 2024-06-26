//
// Created by Heiko Kitscha on 07.04.24.
//

#ifndef GAMEOFLIFE_BIOTOPE_H
#define GAMEOFLIFE_BIOTOPE_H

#include<wx/dcmemory.h>
#include<vector>

namespace Biotope {

//! Enumeration with the implemented rules
enum Rules {
    STANDARD,    //! Standard rule of Conways Game of Life
    COUNTMOD2    //! Alternate rule "Count modulo 2"
};

//! Enumration with Styles
enum Style {
    PLANE,
    TOROID
}

} // End of namespace biotope


//! A class to hold the biotope, to calculate generations and draw on a wxMemoryDC
class Biotope {

private:
    //! Vector to hold the biotope
    std::vector<std::vector<int>> biotope(100, std::vector<int>(100, 0));
    std::vector<std::vector<int>> buffer (100, std::vector<int>(100, 0));
    int width = 100;
    int height = 100;
    //! PADDING: 1 = surrounded by sulfur acid, means plane biotope; 0 = toroid (last is neighbour of first)
    constexpr PADDING = 1;
    void calcConway();
    void calcCM2();
    int getNeighbourCount(int x, int y);

public:
    Biotope(int width, int height);
    ~Biotope();
    //! Calculates the nex generation with a given rule and returns the millis
    int calcNextGen(Rules rule);
    //! Function to get the value of a specific cell
    int getCell(int x, int y);
    //! Function to draw the actual biotope onto w wxMemoryDC    
    void draw(wxMemoryDC& dc);
    //! Erases all life in the actual biotope
    void clear();
    //! Fills the biotope with a pinch of cells
    /*! If cellCount > width x height, it is set to width x height */
    void randomize(int cellCount);
    //! Resizes the actual biotope
    void resize(int x, int y);    
    int getWidth();
    int getHeight();
};


#endif //GAMEOFLIFE_BIOTOPE_H
