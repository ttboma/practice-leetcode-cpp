/// ## 🧩 Problem: Cross-Platform UI Factory
///
/// ### **Scenario**
///
/// You are designing a GUI framework that can support multiple operating systems — for now, **Windows** and **macOS**.
/// Each OS provides its own look and feel for **Buttons** and **Checkboxes**.
///
/// Your task is to implement an **Abstract Factory** pattern that allows creating UI elements for either platform
/// **without modifying client code** when a new OS is added.
///
/// ---
///
/// ### **Requirements**
///
/// 1. Define **abstract product interfaces** for:
///
///    * `Button`
///    * `Checkbox`
///
/// 2. Define **concrete product classes** for:
///
///    * `WindowsButton`, `MacButton`
///    * `WindowsCheckbox`, `MacCheckbox`
///
/// 3. Define an **abstract factory interface** `GUIFactory` with:
///
///    * `createButton()`
///    * `createCheckbox()`
///
/// 4. Implement **two concrete factories**:
///
///    * `WindowsFactory`
///    * `MacFactory`
///
/// 5. Implement a **client class** `Application` that:
///
///    * Receives a `GUIFactory*` in its constructor.
///    * Uses it to create the UI elements.
///    * Calls `render()` on them.
///
/// 6. Add a simple **demo main()**:
///
///    * Ask user to enter `"windows"` or `"mac"`.
///    * Instantiate the appropriate factory and run the app.
///
/// ---
///
/// ### **Expected Output**
///
/// ```
/// Enter OS (windows/mac): windows
/// Rendering Windows Button
/// Rendering Windows Checkbox
/// ```
///
/// or
///
/// ```
/// Enter OS (windows/mac): mac
/// Rendering Mac Button
/// Rendering Mac Checkbox
/// ```
///
/// ---
///
/// ### **Reference Solution**
///
/// ```cpp
/// #include <iostream>
/// #include <memory>
/// #include <string>
///
/// // ----- Abstract Product Interfaces -----
/// struct Button {
///     virtual void render() const = 0;
///     virtual ~Button() = default;
/// };
///
/// struct Checkbox {
///     virtual void render() const = 0;
///     virtual ~Checkbox() = default;
/// };
///
/// // ----- Concrete Products (Windows) -----
/// struct WindowsButton : Button {
///     void render() const override { std::cout << "Rendering Windows Button\n"; }
/// };
///
/// struct WindowsCheckbox : Checkbox {
///     void render() const override { std::cout << "Rendering Windows Checkbox\n"; }
/// };
///
/// // ----- Concrete Products (Mac) -----
/// struct MacButton : Button {
///     void render() const override { std::cout << "Rendering Mac Button\n"; }
/// };
///
/// struct MacCheckbox : Checkbox {
///     void render() const override { std::cout << "Rendering Mac Checkbox\n"; }
/// };
///
/// // ----- Abstract Factory -----
/// struct GUIFactory {
///     virtual std::unique_ptr<Button> createButton() const = 0;
///     virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
///     virtual ~GUIFactory() = default;
/// };
///
/// // ----- Concrete Factories -----
/// struct WindowsFactory : GUIFactory {
///     std::unique_ptr<Button> createButton() const override {
///         return std::make_unique<WindowsButton>();
///     }
///     std::unique_ptr<Checkbox> createCheckbox() const override {
///         return std::make_unique<WindowsCheckbox>();
///     }
/// };
///
/// struct MacFactory : GUIFactory {
///     std::unique_ptr<Button> createButton() const override {
///         return std::make_unique<MacButton>();
///     }
///     std::unique_ptr<Checkbox> createCheckbox() const override {
///         return std::make_unique<MacCheckbox>();
///     }
/// };
///
/// // ----- Client Code -----
/// class Application {
///     std::unique_ptr<Button> button;
///     std::unique_ptr<Checkbox> checkbox;
///
/// public:
///     Application(const GUIFactory& factory) {
///         button = factory.createButton();
///         checkbox = factory.createCheckbox();
///     }
///
///     void renderUI() const {
///         button->render();
///         checkbox->render();
///     }
/// };
///
/// // ----- Demo -----
/// int main() {
///     std::string os;
///     std::cout << "Enter OS (windows/mac): ";
///     std::cin >> os;
///
///     std::unique_ptr<GUIFactory> factory;
///
///     if (os == "windows")
///         factory = std::make_unique<WindowsFactory>();
///     else if (os == "mac")
///         factory = std::make_unique<MacFactory>();
///     else {
///         std::cerr << "Unknown OS\n";
///         return 1;
///     }
///
///     Application app(*factory);
///     app.renderUI();
/// }
/// ```
///
/// ---
///
/// ### 💡 Interview Discussion Points
///
/// * **What problem does Abstract Factory solve?**
///
///   * Decouples object creation from client code, supporting families of related objects.
/// * **Difference from Factory Method?**
///
///   * Abstract Factory creates *families* of related objects; Factory Method creates *one type*.
/// * **How to extend for Linux or mobile platforms?**
///
///   * Add new concrete product classes and a `LinuxFactory`, without touching client code.

#include <memory>

class Button {
public:
    virtual void render() const = 0;
    virtual ~Button() = default;
};

class Checkbox {
public:
    virtual void render() const = 0;
    virtual ~Checkbox() = default;
};

class GUIFactory {
public:
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
    virtual ~GUIFactory() = default;
};

class WindowsButton : public Button {
public:
    void render() const override;
    ~WindowsButton() override = default;
};

class WindowsCheckbox : public Checkbox {
public:
    void render() const override;
    ~WindowsCheckbox() override = default;
};

class WindowsFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override;
    std::unique_ptr<Checkbox> createCheckbox() const override;
    ~WindowsFactory() override = default;
};

class MacButton : public Button {
public:
    void render() const override;
    ~MacButton() override = default;
};

class MacCheckbox : public Checkbox {
public:
    void render() const override;
    ~MacCheckbox() override = default;
};

class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override;
    std::unique_ptr<Checkbox> createCheckbox() const override;
    ~MacFactory() override = default;
};
