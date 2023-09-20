//
//  main.cpp
//  assignment3b
//
//  Created by Lucie Chevreuil on 9/20/23.
//
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    Rectangle myRectangle;

    myRectangle.setDimensions(5.0, 3.0);

    double length = myRectangle.getLength();
    double width = myRectangle.getWidth();
    double area = myRectangle.calculateArea();
    double perimeter = myRectangle.calculatePerimeter();

    cout << "Rectangle Dimensions:" << endl;
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Area: " << area << endl;
    cout << "Perimeter: " << perimeter << endl;

    return 0;
}
