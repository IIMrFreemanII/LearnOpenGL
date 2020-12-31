#include "GLDebug.h"
#include "Types.h"

#include <iostream>
#include <GL/glew.h>

void GLClearError() {
    while (glGetError() != GLEW_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
    while (uint error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << std::endl;
        return false;
    }

    return true;
}
