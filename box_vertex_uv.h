#ifndef BOX_VERTEX_UV_H
#define BOX_VERTEX_UV_H

#include "shader/qmyshader_p2uv.h"
#include "widget/qmytexture.h"
#include "tool/CELLMath.hpp"

class Box_Vertex_UV
{
public:
    Box_Vertex_UV();

public:
    struct VertexUV
    {
        float x,y,z;
        float u,v;
    };
    QMyShader_P2UV  _shaderBox;
    QMyTexture      _textureBox;
    VertexUV        verts[36];

public:
    virtual void initBox(CELL::float3 scale);
    virtual void onRender(CELL::matrix4 mvp, CELL::matrix4 matTran);
};

#endif // BOX_VERTEX_UV_H
