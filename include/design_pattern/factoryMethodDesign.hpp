/// ### 💡 **C++ Factory Method Design Question**
///
/// **Title:**
/// *Design a Factory Method Pattern for Creating Different Types of Shapes*
///
/// ---
///
/// #### **Problem Description**
///
/// You are asked to implement a small drawing framework that supports creating different geometric shapes using the
/// **Factory Method design pattern**.
///
/// The system should support three types of shapes:
///
/// * `Circle`
/// * `Rectangle`
/// * `Triangle`
///
/// Each shape has:
///
/// * A `draw()` method that prints a short text description (e.g., `"Drawing a Circle"`)
/// * A virtual destructor.
///
/// Your goal:
///
/// 1. Design an abstract base class `Shape` that defines the interface.
/// 2. Create concrete subclasses for each shape.
/// 3. Design an abstract factory class `ShapeFactory` that defines the factory method:
///
///    ```cpp
///    virtual std::unique_ptr<Shape> createShape() const = 0;
///    ```
/// 4. Implement concrete factories (`CircleFactory`, `RectangleFactory`, `TriangleFactory`) that override this method.
/// 5. Write a simple test function that demonstrates:
///
///    * Creating different shapes using their corresponding factories.
///    * Calling `draw()` on each created shape.
///
/// ---
///
/// #### **Example Output**
///
/// ```
/// Drawing a Circle
/// Drawing a Rectangle
/// Drawing a Triangle
/// ```
///
/// ---
///
/// #### **Requirements**
///
/// * Use **Factory Method Pattern** — not a simple switch-based factory.
/// * Use **polymorphism** and **smart pointers (`std::unique_ptr`)**.
/// * Avoid using `if` or `switch` statements to decide which shape to create.
///
/// ---
///
/// #### **Follow-Up Discussion**
///
/// 1. How would you extend the system to support new shapes (e.g., `Polygon`) without modifying existing code?
/// 2. Compare this pattern with the **Abstract Factory** pattern.
/// 3. What are the trade-offs between using **Factory Method** vs **Static Factory Function**?

#include <memory>

// Define the abstract product class
class Shape {
   public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// TODO: Define concrete product classes
class Circle : public Shape {
   public:
    void draw() const override;
    ~Circle() override = default;
};

class Rectangle : public Shape {
   public:
    void draw() const override;
    ~Rectangle() override = default;
};

class Triangle : public Shape {
   public:
    void draw() const override;
    ~Triangle() override = default;
};

// Define the abstract creator
class ShapeFactory {
   public:
    virtual std::unique_ptr<Shape> createShape() const = 0;
    virtual ~ShapeFactory() = default;
};

// TODO: Define concrete creators
class CircleFactory : public ShapeFactory {
   public:
    std::unique_ptr<Shape> createShape() const override;
    ~CircleFactory() override = default;
};

class RectangleFactory : public ShapeFactory {
   public:
    std::unique_ptr<Shape> createShape() const override;
    ~RectangleFactory() override = default;
};

class TriangleFactory : public ShapeFactory {
   public:
    std::unique_ptr<Shape> createShape() const override;
    ~TriangleFactory() override = default;
};
