#ifndef QMYWIDGET_H
#define QMYWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "tool/CELLMath.hpp"
#include "qmytexture.h"
#include "qmyopengl.h"
#include "shader/qmyshader_p2uv.h"
//#include "player/qmyplayer.h"
#include "camera/camerabase.h"
#include "home/ground.h"
#include "box_vertex_uv.h"

class QMyWidget : public QMyOpengl
{
public:
    QMyWidget(QWidget *parent = 0);

    float offset;
    QString mousePos;
public:
    QMyShader_P2UV  _shader;
    QMyTexture      _texture;
//    QMyPlayer       _player;
    CameraBase      _camera;
    Ground          _ground;

    //只有顶点和纹理坐标的正方体
    Box_Vertex_UV   _boxDrink;

    //设置黑色地面砖,0大阳台,1餐厅,2走廊,3厕所门口,4厕所旁客房,5客房,6主卧,7主厕,8小阳台
    Box_Vertex_UV   _boxFloor[9];

    //!设置墙,0酒柜后面的墙,1电视墙,2鞋柜墙,3沙发墙,4厕所与小房间的墙,5小房间和走廊墙,
    //!6衣柜墙,7主卧与小房间墙,8(650)厕所小墙,9隔户墙,10主厕和客房的墙,11餐厅与厨房墙
    //!12油烟机墙,13小阳台和厨房墙,14小阳台门与厨房门之间的墙,15客房墙(1),16客房墙(2)
    //!17主厕窗左墙,18主厕窗右墙,19主厕隔户墙,20主厕与主卧间隔户墙
    //!21客房1左墙,22客房1右墙,23厨房窗左墙柱子,24厨房窗左墙,25厨房窗右墙,26厨房窗右墙柱子
    Box_Vertex_UV   _boxWall[27];

    //!窗台墙:
    //! 0小阳台(宽),1小阳台(窄),2厕所,3主厕,4客房1,5大阳台左矮墙,6大阳台矮墙,7大阳台右矮墙
    Box_Vertex_UV   _boxWindowWall[8];

    //!玻璃窗户:
    //! 0厨房窗户,1小阳台窗户大,2小阳台窗户小,3厕所窗户,4主厕窗户,5客房1窗户
    //! 6小阳台玻璃门,7客房2落地窗,8主卧落地窗,9客厅玻璃门
    //! 10大阳台左窗户,11大阳台大窗户,12大阳台右窗户
    Box_Vertex_UV   _boxWindow[13];


    //!ice,0橱柜(洗碗池),1橱柜(灶台),2鞋柜
    Box_Vertex_UV   _boxIce;
    Box_Vertex_UV   _boxCupboard[3];

    //!门:
    //! 0厨房门,1厕所门,2客房2门,3主卧门,4主厕门,5客房1门   
    Box_Vertex_UV   _boxDoor[6];


    CELL::int2    _posOrg;
public:
    virtual bool init();
    virtual void onRender();
    void drawImage();


    bool eventFilter(QObject *target, QEvent *event);

    virtual void mouseMoveEvent(QMouseEvent *ev);
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // QMYWIDGET_H
