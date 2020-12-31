#pragma once

#include "Tests/Test.h"
#include <VertexArray/VertexArray.h>
#include <IndexBuffer/IndexBuffer.h>
#include <Shader/Shader.h>
#include <Texture/Texture.h>
#include <memory>

namespace Test {
    class TestTexture2D : public Test {
    public:
        TestTexture2D();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void OnImGuiRender() override;

    private:
        std::unique_ptr<VertexArray> m_VAO;
        std::unique_ptr<IndexBuffer> m_IndexBuffer;
        std::unique_ptr<Shader> m_Shader;
        std::unique_ptr<Texture> m_Texture;
        std::unique_ptr<VertexBuffer> m_VertexBuffer;
        glm::vec3 m_TranslationA;
        glm::vec3 m_TranslationB;
        glm::mat4 m_Proj;
        glm::mat4 m_View;
    };
}