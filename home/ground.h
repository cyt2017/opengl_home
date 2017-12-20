#ifndef GROUND_H
#define GROUND_H

#include <tool/CELLMath.hpp>
#include <widget/qmytexture.h>
#include <home/qmynodematrix.h>
#include <shader/qmyshader_p2uv.h>

class Ground:public QMyNodeMatrix
{
public:
    Ground();

public:
    int             _width;
    int             _height;
    QMyTexture      _texture;
    QMyTexture      _textureZ;
    QMyTexture      _textureX;
    //QMyTexture      _textureG;
    QMyShader_P2UV  _shader;
public:
    CELL::float3    _pos;

    virtual void initilize(int w, int h);
    virtual void onRender(CELL::matrix4 proj, CELL::matrix4 view);
};

#endif // GROUND_H
