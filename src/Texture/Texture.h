#pragma once

#include "Renderer/Renderer.h"

class Texture {
private:
    uint m_RendererID;
    std::string m_Filepath;
    uchar* m_LocalBuffer;
    int m_Width;
    int m_Height;
    // BPP - bits per pixel
    int m_BPP;
public:
    Texture(const std::string& path);
    ~Texture();

    void Bind(uint slot = 0) const;
    void Unbind() const;

    inline int GetWidth() const { return m_Width; }
    inline int GetHeight() const { return m_Height; }
};