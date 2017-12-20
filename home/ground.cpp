#include "ground.h"

Ground::Ground()
{

}

void Ground::initilize(int w, int h)
{
    _width  = w;
    _height = h;
    _pos    = CELL::float3(0.0,0.0,0.0);

    //地面纹理
    _texture._texId  = _texture.loadTexture("../image/1.png");
    //+Z轴方向纹理
    _textureZ._texId = _textureZ.loadTexture("../image/red.png");
    //+X轴方向纹理
    _textureX._texId = _textureX.loadTexture("../image/green.png");
    //地面纹理
    //_textureG._texId = _textureX.loadTexture("../image/black.png");

    _shader.initialize();
}

void Ground::onRender(CELL::matrix4 proj,CELL::matrix4 view)
{
    struct Vertex
    {
        float x,y,z;
        float u,v;
    };


    CELL::float2    halfSz  =   getSize() * 0.5f;

    CELL::float3    vMin    =   -CELL::float3(halfSz.x,halfSz.y,0);
    CELL::float3    vMax    = CELL::float3(halfSz.x,halfSz.y,0);
    Vertex vert[]   =
    {//地面纹理
       {   vMin.x,0.0,vMin.y,    0,0},
       {   vMax.x,0.0,vMin.y,    20,0},
       {   vMin.x,0.0,vMax.y,    0,20},
       {   vMax.x,0.0,vMax.y,    20,20},
   };

    Vertex lineZ[] =
    {//+Z轴方向纹理
        {    400, 1.0,0,      0,0},
        {    400, 1.0,10000,  1,0},
        {   -400, 1.0,0, 0,1},
        {   -400, 1.0,10000,     1,1},
    };

    Vertex lineX[] =
    {//+X轴方向纹理
        {   0    ,  1.0,-400,    0,0},
        {  -10000,  1.0,-400,    1,0},
        {   0    ,  1.0, 400,    0,1},
        {  -10000,  1.0, 400,    1,1},
    };

//    Vertex lineG[] =
//    {//大阳台黑色瓷砖
//        {   5450 ,-1.0,-4000,    0,0},
//        {   5450 ,-1.0,-8000,    1,0},
//        {   5750 ,-1.0,-4000,    0,1},
//        {   5750 ,-1.0,-8000,    1,1},
//    };
//    Vertex lineH[] =
//    {//餐厅黑色瓷砖
//        {   720 ,-1.0,-4000,    0,0},
//        {   720 ,-1.0,-8000,    1,0},
//        {   800 ,-1.0,-4000,    0,1},
//        {   800 ,-1.0,-8000,    1,1},
//    };

//    Vertex lineJ[] =
//    {//走廊黑色瓷砖
//        {   2400,-1.0,-4000,    0,0},
//        {   2400,-1.0,-3800,    1,0},
//        {   800 ,-1.0,-4000,    0,1},
//        {   800 ,-1.0,-3800,    1,1},
//    };

    CELL::matrix4 mvp = proj *view * _matModel;
    _shader.begin();
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,_texture._texId);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,_textureZ._texId);

        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D,_textureX._texId);

        //glActiveTexture(GL_TEXTURE3);
        //glBindTexture(GL_TEXTURE_2D,_textureG._texId);

        {//+Z轴方向纹理
            glUniform1i(_shader._texture,1);
            glUniformMatrix4fv(_shader._MVP, 1, false, mvp.data());
            glUniform4f(_shader._color,1.0f,0.0f,0.0f,0.5f);
            glVertexAttribPointer(_shader._position,3,GL_FLOAT,false,sizeof(Vertex),&lineZ[0].x);
            glVertexAttribPointer(_shader._uv,2,GL_FLOAT,false,sizeof(Vertex),&lineZ[0].u);
            glDrawArrays(GL_TRIANGLE_STRIP,0,4);
        }

        {//+X轴方向纹理
            glUniform1i(_shader._texture,2);
            glUniformMatrix4fv(_shader._MVP, 1, false, mvp.data());
            glUniform4f(_shader._color,1.0f,0.0f,0.0f,0.5f);
            glVertexAttribPointer(_shader._position,3,GL_FLOAT,false,sizeof(Vertex),&lineX[0].x);
            glVertexAttribPointer(_shader._uv,2,GL_FLOAT,false,sizeof(Vertex),&lineX[0].u);
            glDrawArrays(GL_TRIANGLE_STRIP,0,4);
        }

        {//地面纹理
            glUniform1i(_shader._texture,0);
            glUniformMatrix4fv(_shader._MVP, 1, false, mvp.data());
            glUniform4f(_shader._color,0.0f,1.0f,1.0f,0.5f);
            glVertexAttribPointer(_shader._position,3,GL_FLOAT,false,sizeof(Vertex),&vert[0].x);
            glVertexAttribPointer(_shader._uv,2,GL_FLOAT,false,sizeof(Vertex),&vert[0].u);
            glDrawArrays(GL_TRIANGLE_STRIP,0,4);
        }

        {//大阳台黑色瓷砖
            //glUniform1i(_shader._texture,3);
            //glUniform4f(_shader._color,1.0f,0.0f,0.0f,0.5f);
            //glVertexAttribPointer(_shader._position,3,GL_FLOAT,false,sizeof(Vertex),&lineG[0].x);
            //glVertexAttribPointer(_shader._uv,2,GL_FLOAT,false,sizeof(Vertex),&lineG[0].u);
            //glDrawArrays(GL_TRIANGLE_STRIP,0,4);
        }

        {//餐厅黑色瓷砖
           //glUniform1i(_shader._texture,3);
           //glUniform4f(_shader._color,1.0f,0.0f,0.0f,0.5f);
           //glVertexAttribPointer(_shader._position,3,GL_FLOAT,false,sizeof(Vertex),&lineH[0].x);
           //glVertexAttribPointer(_shader._uv,2,GL_FLOAT,false,sizeof(Vertex),&lineH[0].u);
           //glDrawArrays(GL_TRIANGLE_STRIP,0,4);
        }
        {//走廊黑色瓷砖
            //glUniform1i(_shader._texture,3);
            //glUniform4f(_shader._color,1.0f,0.0f,0.0f,0.5f);
            //glVertexAttribPointer(_shader._position,3,GL_FLOAT,false,sizeof(Vertex),&lineJ[0].x);
            //glVertexAttribPointer(_shader._uv,2,GL_FLOAT,false,sizeof(Vertex),&lineJ[0].u);
            //glDrawArrays(GL_TRIANGLE_STRIP,0,4);
        }
    _shader.end();
}
