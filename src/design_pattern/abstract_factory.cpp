#include "design_pattern/abstract_factory.hpp"

#include <iostream>

void WindowsButton::render() const {
    std::cout << "Rendering Windows Button\n";
}

void WindowsCheckbox::render() const {
    std::cout << "Rendering Windows Checkbox\n";
}

std::unique_ptr<Button> WindowsFactory::createButton() const {
    return std::make_unique<WindowsButton>();
}

std::unique_ptr<Checkbox> WindowsFactory::createCheckbox() const {
    return std::make_unique<WindowsCheckbox>();
}

void MacButton::render() const {
    std::cout << "Rendering Mac Button\n";
}

void MacCheckbox::render() const {
    std::cout << "Rendering Mac Checkbox\n";
}

std::unique_ptr<Button> MacFactory::createButton() const {
    return std::make_unique<MacButton>();
}

std::unique_ptr<Checkbox> MacFactory::createCheckbox() const {
    return std::make_unique<MacCheckbox>();
}
