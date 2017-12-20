#include "box_vertex_uv.h"

Box_Vertex_UV::Box_Vertex_UV()
{
    VertexUV  vert[] =
    {
        { 0.5f, -0.5f,  0.5f ,  /*1.0, 0.0, 0.0,*/ 0.0f, 0.0f  },
        { 0.5f, -0.5f, -0.5f ,  /*1.0, 0.0, 0.0,*/ 1.0f, 0.0f  },
        { 0.5f,  0.5f, -0.5f ,  /*1.0, 0.0, 0.0,*/ 1.0f, 1.0f  },

        { 0.5f,  0.5f, -0.5f ,  /*1.0, 0.0, 0.0,*/ 1.0f, 1.0f  },
        { 0.5f,  0.5f,  0.5f ,  /*1.0, 0.0, 0.0,*/ 0.0f, 1.0f  },
        { 0.5f, -0.5f,  0.5f ,  /*1.0, 0.0, 0.0,*/ 0.0f, 0.0f  },

        {-0.5f, -0.5f, -0.5f ,  /*-1.0, 0.0,0.0,*/ 0.0f, 0.0f  },
        {-0.5f, -0.5f,  0.5f ,  /*-1.0, 0.0,0.0,*/ 1.0f, 0.0f  },
        {-0.5f,  0.5f,  0.5f ,  /*-1.0, 0.0,0.0,*/ 1.0f, 1.0f  },

        {-0.5f,  0.5f,  0.5f ,  /*-1.0, 0.0,0.0,*/ 1.0f, 1.0f  },
        {-0.5f,  0.5f, -0.5f ,  /*-1.0, 0.0,0.0,*/ 0.0f, 1.0f  },
        {-0.5f, -0.5f, -0.5f ,  /*-1.0, 0.0,0.0,*/ 0.0f, 0.0f  },

        {-0.5f,  0.5f,  0.5f ,  /*-0.0, 1.0,0.0,*/ 0.0f, 0.0f  },
        { 0.5f,  0.5f,  0.5f ,  /*-0.0, 1.0,0.0,*/ 1.0f, 0.0f  },
        { 0.5f,  0.5f, -0.5f ,  /*-0.0, 1.0,0.0,*/ 1.0f, 1.0f  },

        { 0.5f,  0.5f, -0.5f ,  /*0.0, 1.0,0.0,*/ 1.0f, 1.0f   },
        {-0.5f,  0.5f, -0.5f ,  /*0.0, 1.0,0.0,*/ 0.0f, 1.0f   },
        {-0.5f,  0.5f,  0.5f ,  /*0.0, 1.0,0.0,*/ 0.0f, 0.0f   },

        {-0.5f, -0.5f, -0.5f ,  /*0.0, -1.0,0.0,*/ 0.0f, 0.0f  },
        { 0.5f, -0.5f, -0.5f ,  /*0.0, -1.0,0.0,*/ 1.0f, 0.0f  },
        { 0.5f, -0.5f,  0.5f ,  /*0.0, -1.0,0.0,*/ 1.0f, 1.0f  },

        { 0.5f, -0.5f,  0.5f ,  /*0.0, -1.0,0.0,*/ 1.0f, 1.0f  },
        {-0.5f, -0.5f,  0.5f ,  /*0.0, -1.0,0.0,*/ 0.0f, 1.0f  },
        {-0.5f, -0.5f, -0.5f ,  /*0.0, -1.0,0.0,*/ 0.0f, 0.0f  },

        {-0.5f, -0.5f,  0.5f,   /*0.0, 0.0, 1.0,*/  0.0f, 0.0f },
        { 0.5f, -0.5f,  0.5f,   /*0.0, 0.0, 1.0,*/  1.0f, 0.0f },
        { 0.5f,  0.5f,  0.5f,   /*0.0, 0.0, 1.0,*/  1.0f, 1.0f },

        { 0.5f,  0.5f,  0.5f,   /*0.0, 0.0, 1.0,*/  1.0f, 1.0f },
        {-0.5f,  0.5f,  0.5f,   /*0.0, 0.0, 1.0,*/  0.0f, 1.0f },
        {-0.5f, -0.5f,  0.5f,   /*0.0, 0.0, 1.0,*/  0.0f, 0.0f },

        { 0.5f, -0.5f, -0.5f,   /*0.0, 0.0,-1.0,*/  0.0f, 0.0f },
        {-0.5f, -0.5f, -0.5f,   /*0.0, 0.0,-1.0,*/  1.0f, 0.0f },
        {-0.5f,  0.5f, -0.5f,   /*0.0, 0.0,-1.0,*/  1.0f, 1.0f },

        {-0.5f,  0.5f, -0.5f,   /*0.0, 0.0,-1.0,*/  1.0f, 1.0  },
        { 0.5f,  0.5f, -0.5f,   /*0.0, 0.0,-1.0,*/  0.0f, 1.0  },
        { 0.5f, -0.5f, -0.5f,   /*0.0, 0.0,-1.0,*/  0.0f, 0.0  },
    };
    for(int i=0;i<36;i++)
    {
        verts[i].x = vert[i].x;
        verts[i].y = vert[i].y;
        verts[i].z = vert[i].z;
        verts[i].u = vert[i].u;
        verts[i].v = vert[i].v;
    }

}

void Box_Vertex_UV::initBox(CELL::float3 scale)
{
    _shaderBox.initialize();

    for(int i=0;i<36;i++)
    {
        verts[i].x *= scale.x;
        verts[i].y *= scale.y;
        verts[i].z *= scale.z;
    }
}

void Box_Vertex_UV::onRender(CELL::matrix4 mvp,CELL::matrix4 matTran)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,_textureBox._texId);

    CELL::matrix4 matMVP = mvp*matTran;
    _shaderBox.begin();
    {
        glUniformMatrix4fv(_shaderBox._MVP,1,false,matMVP.data());
        glUniform1i(_shaderBox._texture,0);/*
        glUniform4f(_shaderBox._color,1.0f,0.0f,1.0f,1.0f);*/
        glVertexAttribPointer(_shaderBox._position,3,GL_FLOAT,false,sizeof(VertexUV),&verts[0].x);
        glVertexAttribPointer(_shaderBox._uv,2,GL_FLOAT,false,sizeof(VertexUV),&verts[0].u);
        glDrawArrays(GL_TRIANGLES,0,36);

    }
    _shaderBox.end();
}
