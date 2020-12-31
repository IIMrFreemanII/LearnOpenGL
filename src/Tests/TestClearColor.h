#pragma once

#include "Tests/Test.h"

namespace Test {
    class TestClearColor : public Test {
    public:
        TestClearColor();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void OnImGuiRender() override;

    private:
        float m_ClearColor[4];
    };
}