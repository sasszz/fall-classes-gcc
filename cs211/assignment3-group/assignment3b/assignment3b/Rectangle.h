//
//  Rectangle.h
//  assignment3b
//
//  Created by Lucie Chevreuil on 9/20/23.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle();
    void setDimensions(double length, double width);
    double getLength() const;
    double getWidth() const;
    double calculateArea() const;
    double calculatePerimeter() const;
};

#endif
