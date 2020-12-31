#pragma once

#include "Types.h"

class VertexBuffer {
private:
    uint m_RendererID;
public:
    VertexBuffer(const void *data, uint size);

    ~VertexBuffer();

    void Bind() const;

    void Unbind() const;
};
