#pragma once

#include <string>
#include <unordered_map>
#include "Types.h"
#include "glm/glm.hpp"

struct ShaderProgramSource {
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader {
private:
    std::string m_Filepath;
    uint m_RendererID;
    std::unordered_map<std::string, int> m_UniformLocationCache;
public:
    Shader(const std::string &filepath);

    ~Shader();

    void Bind() const;

    void Unbind() const;

    void SetUniform1i(const std::string& name, int value);
    void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
    void SetUniform1f(const std::string &name, float v0);
    void SetUniformMat4f(const std::string &name, const glm::mat4& matrix);

private:
    ShaderProgramSource ParseShader(const std::string &filePath);

    uint CompileShader(uint type, const std::string &source);

    uint CreateShader(const std::string &vertexShader, const std::string &fragmentShader);

    int GetUniformLocation(const std::string &name);
};