#include "design_pattern/factoryMethodDesign.hpp"

#include <gtest/gtest.h>

void usingFactoryMethodDesign(ShapeFactory& factory) {
    auto shape = factory.createShape();
    shape->draw();
}

TEST(FactoryMethodDesign, CreateCircle) {
    testing::internal::CaptureStdout();

    CircleFactory circleFactory;
    usingFactoryMethodDesign(circleFactory);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Drawing a Circle\n");
}

TEST(FactoryMethodDesign, CreateRectangle) {
    testing::internal::CaptureStdout();
    RectangleFactory rectangleFactory;

    usingFactoryMethodDesign(rectangleFactory);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Drawing a Rectangle\n");
}

TEST(FactoryMethodDesign, CreateTriangle) {
    testing::internal::CaptureStdout();
    TriangleFactory triangleFactory;

    usingFactoryMethodDesign(triangleFactory);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Drawing a Triangle\n");
}
