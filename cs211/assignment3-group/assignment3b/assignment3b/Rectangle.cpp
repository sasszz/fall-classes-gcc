//
//  Rectangle.cpp
//  assignment3b
//
//  Created by Lucie Chevreuil on 9/20/23.
//

#include "Rectangle.h"

Rectangle::Rectangle() : length(0.0), width(0.0) {}

void Rectangle::setDimensions(double newLength, double newWidth) {
    length = newLength;
    width = newWidth;
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::calculateArea() const {
    return length * width;
}

double Rectangle::calculatePerimeter() const {
    return 2 * (length + width);
}

