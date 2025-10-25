#include <gtest/gtest.h>

#include "design_pattern/abstract_factory.hpp"

// ----- Client Code -----
class Application {
    std::unique_ptr<Button> button;
    std::unique_ptr<Checkbox> checkbox;

public:
    Application(const GUIFactory& factory) {
        button = factory.createButton();
        checkbox = factory.createCheckbox();
    }

    void renderUI() const {
        button->render();
        checkbox->render();
    }
};

// ----- Unit Tests -----
TEST(AbstractFactoryTest, WindowsFactoryRendersCorrectly) {
    WindowsFactory factory;
    Application app(factory);

    testing::internal::CaptureStdout();
    app.renderUI();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Rendering Windows Button"), std::string::npos);
    EXPECT_NE(output.find("Rendering Windows Checkbox"), std::string::npos);
}

TEST(AbstractFactoryTest, MacFactoryRendersCorrectly) {
    MacFactory factory;
    Application app(factory);

    testing::internal::CaptureStdout();
    app.renderUI();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Rendering Mac Button"), std::string::npos);
    EXPECT_NE(output.find("Rendering Mac Checkbox"), std::string::npos);
}
