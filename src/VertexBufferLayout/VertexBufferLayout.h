#pragma once

#include "Types.h"
#include "GLDebug/GLDebug.h"

#include "GL/glew.h"
#include <vector>

struct VertexBufferElement {
    uint type;
    uint count;
    uchar normalized;

    static uint GetSizeOfType(uint type) {
        switch (type) {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }

        ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    uint m_Stride;
public:
    VertexBufferLayout() : m_Stride(0) {}

    template<typename T>
    void Push(uint count) {
        static_assert(false);
    }

    template<>
    void Push<float>(uint count) {
        m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
    }

    template<>
    void Push<uint>(uint count) {
        m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
    }

    template<>
    void Push<uchar>(uint count) {
        m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
    }

    inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
    inline uint GetStride() const { return m_Stride; }
};
