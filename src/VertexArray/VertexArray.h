#pragma once

#include "Types.h"
#include "VertexBuffer/VertexBuffer.h"
#include "VertexBufferLayout/VertexBufferLayout.h"

class VertexArray {
private:
    uint m_RendererID;
public:
    VertexArray();

    ~VertexArray();

    void AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout);
    void Bind() const;
    void Unbind() const;
};
