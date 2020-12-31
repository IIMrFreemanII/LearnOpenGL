#pragma once

#include "Shader/Shader.h"
#include "IndexBuffer/IndexBuffer.h"
#include "VertexArray/VertexArray.h"

class Renderer {
public:
    void Clear() const;

    void Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const;
};
