#include "design_pattern/factory_method_design.hpp"

#include <iostream>

void Circle::draw() const {
    std::cout << "Drawing a Circle" << std::endl;
}

void Rectangle::draw() const {
    std::cout << "Drawing a Rectangle" << std::endl;
}

void Triangle::draw() const {
    std::cout << "Drawing a Triangle" << std::endl;
}

std::unique_ptr<Shape> CircleFactory::createShape() const {
    return std::make_unique<Circle>();
}

std::unique_ptr<Shape> RectangleFactory::createShape() const {
    return std::make_unique<Rectangle>();
}

std::unique_ptr<Shape> TriangleFactory::createShape() const {
    return std::make_unique<Triangle>();
}
