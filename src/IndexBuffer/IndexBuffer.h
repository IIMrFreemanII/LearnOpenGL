#pragma once

#include "GLDebug/GLDebug.h"
#include "Types.h"

class IndexBuffer
{
private:
    uint m_RendererID;
    uint m_Count;
public:
    IndexBuffer(const uint *data, uint count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline uint GetCount() const { return m_Count; }
};
