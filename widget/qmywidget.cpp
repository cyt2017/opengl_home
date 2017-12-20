#include "qmywidget.h"

QMyWidget::QMyWidget(QWidget *parent):QMyOpengl(parent)
{

}
bool QMyWidget::init()
{
    QMyOpengl::init();
    printf("QMyDevice::init\n");

    _camera.setEye(CELL::float3(0.0,500.0,0.0));
    _camera.setTarget(CELL::float3(0.0,0.0,0.0));
    _camera.setUp(CELL::float3(0.0,0.0,1.0));
    _camera.calcDir();
    _camera.update();

    CELL::float3 pos(0.0,0.0,0.0);
    CELL::quatr  quat(0.0,0.0,0.0,1.0);
    CELL::float3 scale(1.0,1.0,1.0);
    _ground.initilize(16000.0,16000.0);
    _ground.setPosition(pos);
    _ground.setQuatr(quat);
    _ground.setScale(scale);
    _ground.setSize(16000.0,16000.0);
    _ground.upDate();

    //酒柜 矩形数据
    CELL::float3 scal(1700,2100,340);
    _boxDrink.initBox(scal);
    _boxDrink._textureBox._texId = _boxDrink._textureBox.loadTexture("../image/jiuGui.png");

    {//!初始化黑色地面砖,
     //!0大阳台,1餐厅,2走廊,3厕所门口,4厕所旁客房,5客房,6主卧,7主厕,8小阳台
        CELL::float3 floor(300,50,4000);
        _boxFloor[0].initBox(floor);
        _boxFloor[0]._textureBox._texId = _boxFloor[0]._textureBox.loadTexture("../image/black.jpg");

        CELL::float3 floor1(80,50,4000);    //1餐厅 黑色地面砖
        _boxFloor[1].initBox(floor1);
        _boxFloor[1]._textureBox._texId = _boxFloor[0]._textureBox._texId;

        CELL::float3 floor2(1600,50,200);   //2走廊 黑色地面砖
        _boxFloor[2].initBox(floor2);
        _boxFloor[2]._textureBox._texId = _boxFloor[0]._textureBox._texId;

        CELL::float3 floor3(200,50,750);    //3厕所门口 黑色地面砖
        _boxFloor[3].initBox(floor3);
        _boxFloor[3]._textureBox._texId = _boxFloor[0]._textureBox._texId;

        CELL::float3 floor4(200,50,1020);    //4厕所旁客房 黑色地面砖
        _boxFloor[4].initBox(floor4);
        _boxFloor[4]._textureBox._texId = _boxFloor[0]._textureBox._texId;

        CELL::float3 floor5(200,50,980);    //5客房 黑色地面砖
        _boxFloor[5].initBox(floor5);
        _boxFloor[5]._textureBox._texId = _boxFloor[0]._textureBox._texId;

        CELL::float3 floor6(2000,50,200);    //6主卧 黑色地面砖
        _boxFloor[6].initBox(floor6);
        _boxFloor[6]._textureBox._texId = _boxFloor[0]._textureBox._texId;

        CELL::float3 floor7(200,50,1000);    //7主厕 黑色地面砖
        _boxFloor[7].initBox(floor7);
        _boxFloor[7]._textureBox._texId = _boxFloor[0]._textureBox._texId;

        CELL::float3 floor8(200,50,2150);    //8小阳台 黑色地面砖
        _boxFloor[8].initBox(floor8);
        _boxFloor[8]._textureBox._texId = _boxFloor[0]._textureBox._texId;
    }

    {//!初始化墙,
     //!0酒柜后面的墙,1电视墙,2鞋柜墙,3沙发墙,4厕所与客房2的墙,5客房1和走廊墙,6衣柜墙,
     //!7主卧与客房2墙,8(650)厕所小墙,9隔户墙,10主厕和客房的墙,11餐厅与厨房墙,12油烟机墙,13小阳台和厨房墙
     //!14小阳台门与厨房门之间的墙,15客房窗边墙(1),16客房窗边墙(2),17主厕窗左墙,18主厕窗右墙,19主厕隔户墙
     //!20主厕与主卧间隔户墙,21客房1左墙,22客房1右墙,23厨房窗左墙柱子,24厨房窗左墙,25厨房窗右墙,26厨房窗右墙柱子
        CELL::float3 wall0(2840,3000,200);
        _boxWall[0].initBox(wall0);
        _boxWall[0]._textureBox._texId = _boxWall[0]._textureBox.loadTexture("../image/qiangBi.png");

        CELL::float3 wall1(2800,3000,200);//1电视墙
        _boxWall[1].initBox(wall1);
        _boxWall[1]._textureBox._texId = _boxWall[0]._textureBox._texId;

        CELL::float3 wall2(4400,3000,400);//2鞋柜墙
        _boxWall[2].initBox(wall2);
        _boxWall[2]._textureBox._texId = _boxWall[0]._textureBox._texId;

        CELL::float3 wall3(2800,3000,200);//3沙发墙
        _boxWall[3].initBox(wall3);
        _boxWall[3]._textureBox._texId = _boxWall[0]._textureBox._texId;

        CELL::float3 wall4(2840,3000,200);//4厕所与客房2的墙
        _boxWall[4].initBox(wall4);
        _boxWall[4]._textureBox._texId = _boxWall[0]._textureBox._texId;

        CELL::float3 wall5(200,3000,1750);//5客房1和走廊墙
        _boxWall[5].initBox(wall5);
        _boxWall[5]._textureBox._texId = _boxWall[0]._textureBox._texId;

        CELL::float3 wall6(2800,3000,200);//6衣柜墙
        _boxWall[6].initBox(wall6);
        _boxWall[6]._textureBox._texId = _boxWall[0]._textureBox._texId;

        CELL::float3 wall7(200,3000,3350);//7主卧与客房2墙
        _boxWall[7].initBox(wall7);
        _boxWall[7]._textureBox._texId = _boxWall[0]._textureBox._texId;

        CELL::float3 wall8(200,3000,650);//8(650)厕所小墙
        _boxWall[8].initBox(wall8);
        _boxWall[8]._textureBox._texId = _boxWall[0]._textureBox._texId;

        CELL::float3 wall9(4400,3000,200);//9隔户墙
        _boxWall[9].initBox(wall9);
        _boxWall[9]._textureBox._texId = _boxWall[0]._textureBox._texId;

        CELL::float3 wall10(2700,3000,200);//10主厕和客房的墙
        _boxWall[10].initBox(wall10);
        _boxWall[10]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //11餐厅与厨房墙
        CELL::float3 wall11(200,3000,2000);
        _boxWall[11].initBox(wall11);
        _boxWall[11]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //12油烟机墙
        CELL::float3 wall12(1830,3000,200);
        _boxWall[12].initBox(wall12);
        _boxWall[12]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //13小阳台和厨房墙
        CELL::float3 wall13(2000,3000,200);
        _boxWall[13].initBox(wall13);
        _boxWall[13]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //14小阳台门与厨房门之间的墙
        CELL::float3 wall14(200,3000,450);
        _boxWall[14].initBox(wall14);
        _boxWall[14]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //15客房2窗边墙(1),
        CELL::float3 wall15(600,3000,650);
        _boxWall[15].initBox(wall15);
        _boxWall[15]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //16客房2窗边墙(2)
        CELL::float3 wall16(600,3000,540);
        _boxWall[16].initBox(wall16);
        _boxWall[16]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //17主厕窗左墙,
        CELL::float3 wall17(200,3000,600);
        _boxWall[17].initBox(wall17);
        _boxWall[17]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //18主厕窗右墙,
        CELL::float3 wall18(200,3000,800);
        _boxWall[18].initBox(wall18);
        _boxWall[18]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //19主厕隔户墙
        CELL::float3 wall19(2950,3000,200);
        _boxWall[19].initBox(wall19);
        _boxWall[19]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //20主厕与主卧间隔户墙
        CELL::float3 wall20(200,3000,700);
        _boxWall[20].initBox(wall20);
        _boxWall[20]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //21客房1左墙,
        CELL::float3 wall21(200,3000,600);
        _boxWall[21].initBox(wall21);
        _boxWall[21]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //22客房1右墙
        CELL::float3 wall22(200,3000,600);
        _boxWall[22].initBox(wall22);
        _boxWall[22]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //23厨房窗左墙柱子
        CELL::float3 wall23(270,3000,300);
        _boxWall[23].initBox(wall23);
        _boxWall[23]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //24厨房窗左墙
        CELL::float3 wall24(200,3000,660);
        _boxWall[24].initBox(wall24);
        _boxWall[24]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //25厨房窗右墙
        CELL::float3 wall25(200,3000,540);
        _boxWall[25].initBox(wall25);
        _boxWall[25]._textureBox._texId = _boxWall[0]._textureBox._texId;

        //26厨房窗右墙柱子
        CELL::float3 wall26(330,3000,270);
        _boxWall[26].initBox(wall26);
        _boxWall[26]._textureBox._texId = _boxWall[0]._textureBox._texId;
    }

    {//!初始化窗台墙:
        //!0小阳台(宽),1小阳台(窄),2厕所,3主厕,4客房1,5大阳台左矮墙,6大阳台矮墙,7大阳台右矮墙
        CELL::float3 wall[8];

        wall[0] = CELL::float3(200,650,2800);
        _boxWindowWall[0].initBox(wall[0]);
        _boxWindowWall[0]._textureBox._texId = _boxWall[0]._textureBox._texId;

        wall[1] = CELL::float3(2050,650,200);
        _boxWindowWall[1].initBox(wall[1]);
        _boxWindowWall[1]._textureBox._texId = _boxWindowWall[0]._textureBox._texId;

        //2厕所 窗台墙
        wall[2] = CELL::float3(200,880,1400);
        _boxWindowWall[2].initBox(wall[2]);
        _boxWindowWall[2]._textureBox._texId = _boxWindowWall[0]._textureBox._texId;

        //3主厕 窗台墙
        wall[3] = CELL::float3(200,880,1000);
        _boxWindowWall[3].initBox(wall[3]);
        _boxWindowWall[3]._textureBox._texId = _boxWindowWall[0]._textureBox._texId;

        //4客房1 窗台墙
        wall[4] = CELL::float3(200,880,1800);
        _boxWindowWall[4].initBox(wall[4]);
        _boxWindowWall[4]._textureBox._texId = _boxWindowWall[0]._textureBox._texId;

        //5大阳台左矮墙,窗台墙
        wall[5] = CELL::float3(2500,650,200);
        _boxWindowWall[5].initBox(wall[5]);
        _boxWindowWall[5]._textureBox._texId = _boxWindowWall[0]._textureBox._texId;

        //6大阳台矮墙,窗台墙
        wall[6] = CELL::float3(200,650,4200);
        _boxWindowWall[6].initBox(wall[6]);
        _boxWindowWall[6]._textureBox._texId = _boxWindowWall[0]._textureBox._texId;

        //7大阳台右矮墙,窗台墙
        wall[7] = CELL::float3(2500,650,200);
        _boxWindowWall[7].initBox(wall[7]);
        _boxWindowWall[7]._textureBox._texId = _boxWindowWall[0]._textureBox._texId;
    }

    {//!初始化玻璃窗户:
        //! 0厨房窗户,1小阳台窗户大,2小阳台窗户小,3厕所窗户,4主厕窗户,5客房1窗户
        //! 6小阳台玻璃门,7客房2落地窗,8主卧落地窗,9客厅玻璃门
        //! 10大阳台左窗户,11大阳台大窗户,12大阳台右窗户
        CELL::float3 window[13];

        window[0] = CELL::float3(200,2000,1000);
        _boxWindow[0].initBox(window[0]);
        _boxWindow[0]._textureBox._texId = _boxWindow[0]._textureBox.loadTexture("../image/chuang1.png");

        //1小阳台窗户大
        window[1] = CELL::float3(200,2000,2400);
        _boxWindow[1].initBox(window[1]);
        _boxWindow[1]._textureBox._texId = _boxWindow[0]._textureBox._texId;

        //2小阳台窗户小
        window[2] = CELL::float3(2050,2000,200);
        _boxWindow[2].initBox(window[2]);
        _boxWindow[2]._textureBox._texId = _boxWindow[0]._textureBox._texId;

        //3厕所窗户
        window[3] = CELL::float3(200,2000,1600);
        _boxWindow[3].initBox(window[3]);
        _boxWindow[3]._textureBox._texId = _boxWindow[0]._textureBox._texId;

        //4主厕窗户
        window[4] = CELL::float3(200,2000,1000);
        _boxWindow[4].initBox(window[4]);
        _boxWindow[4]._textureBox._texId = _boxWindow[0]._textureBox._texId;

        //5客房1窗户
        window[5] = CELL::float3(200,2000,1450);
        _boxWindow[5].initBox(window[5]);
        _boxWindow[5]._textureBox._texId = _boxWindow[0]._textureBox._texId;

        //6小阳台玻璃门,7客房2落地窗,8主卧落地窗,9客厅玻璃门
        window[6] = CELL::float3(200,3000,2200);
        _boxWindow[6].initBox(window[6]);
        _boxWindow[6]._textureBox._texId = _boxWindow[6]._textureBox.loadTexture("../image/men2.png");

        window[7] = CELL::float3(200,3000,2300);
        _boxWindow[7].initBox(window[7]);
        _boxWindow[7]._textureBox._texId = _boxWindow[6]._textureBox._texId;

        window[8] = CELL::float3(200,3000,4000);
        _boxWindow[8].initBox(window[8]);
        _boxWindow[8]._textureBox._texId = _boxWindow[6]._textureBox._texId;

        window[9] = CELL::float3(200,3000,4100);
        _boxWindow[9].initBox(window[9]);
        _boxWindow[9]._textureBox._texId = _boxWindow[6]._textureBox._texId;

        //10大阳台左窗户,11大阳台大窗户,12大阳台右窗户
        window[10] = CELL::float3(2500,2000,200);
        _boxWindow[10].initBox(window[10]);
        _boxWindow[10]._textureBox._texId = _boxWindow[10]._textureBox.loadTexture("../image/men1.png");

        window[11] = CELL::float3(200,2000,4200);
        _boxWindow[11].initBox(window[11]);
        _boxWindow[11]._textureBox._texId = _boxWindow[10]._textureBox._texId;

        window[12] = CELL::float3(2500,2000,200);
        _boxWindow[12].initBox(window[12]);
        _boxWindow[12]._textureBox._texId = _boxWindow[10]._textureBox._texId;
    }

    {//!初始化柜子
        //ice
        CELL::float3 ice(540,1730,580);
        _boxIce.initBox(ice);
        _boxIce._textureBox._texId = _boxIce._textureBox.loadTexture("../image/iceBox.png");

        //0橱柜(洗碗池),1橱柜(灶台),2鞋柜
        CELL::float3 cupboard[3];
        cupboard[0] = CELL::float3(580,800,2800);
        _boxCupboard[0].initBox(cupboard[0]);
        _boxCupboard[0]._textureBox._texId = _boxCupboard[0]._textureBox.loadTexture("../image/iceBox.png");
        //1橱柜(灶台)
        cupboard[1] = CELL::float3(1630,800,600);
        _boxCupboard[1].initBox(cupboard[1]);
        _boxCupboard[1]._textureBox._texId = _boxCupboard[0]._textureBox._texId;

        //2鞋柜
        cupboard[2] = CELL::float3(1500,1100,340);
        _boxCupboard[2].initBox(cupboard[2]);
        _boxCupboard[2]._textureBox._texId = _boxCupboard[0]._textureBox.loadTexture("../image/xiegui.png");
    }

    {//!初始化门:
        //! 0厨房门,1厕所门,2客房2门,3主卧门,4主厕门,5客房1门,
        CELL::float3 door[6];

        door[0] = CELL::float3(200,2000,900);
        _boxDoor[0].initBox(door[0]);
        _boxDoor[0]._textureBox._texId = _boxDoor[0]._textureBox.loadTexture("../image/men.png");

        //1厕所门
        door[1] = CELL::float3(200,2000,800);
        _boxDoor[1].initBox(door[1]);
        _boxDoor[1]._textureBox._texId = _boxDoor[0]._textureBox._texId;

        //2客房2门
        door[2] = CELL::float3(200,2000,1000);
        _boxDoor[2].initBox(door[2]);
        _boxDoor[2]._textureBox._texId = _boxDoor[0]._textureBox._texId;

        //3主卧门
        door[3] = CELL::float3(1600,2000,200);
        _boxDoor[3].initBox(door[3]);
        _boxDoor[3]._textureBox._texId = _boxDoor[0]._textureBox._texId;

        //4主厕门
        door[4] = CELL::float3(200,2000,870);
        _boxDoor[4].initBox(door[4]);
        _boxDoor[4]._textureBox._texId = _boxDoor[0]._textureBox._texId;

        //5客房1门
        door[5] = CELL::float3(200,2000,1000);
        _boxDoor[5].initBox(door[5]);
        _boxDoor[5]._textureBox._texId = _boxDoor[0]._textureBox._texId;

    }

    glEnable(GL_DEPTH_TEST);
}

void QMyWidget::onRender()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glViewport(0,0,_width,_height);


        //! 创建一个投影矩阵

    float aspect = float(_width)/float(_height);
    //CELL::matrix4   screenProj  =   CELL::ortho<float>(-8000.f,8000.f,-8000.f/aspect,8000.f/aspect,-10.0f,10);
    CELL::matrix4   screenProj  =   CELL::perspective<float>(45.0f,aspect,1,100000);
    _camera.setProject(screenProj);
    _ground.onRender(screenProj,_camera.getView());

    CELL::matrix4 mvp = screenProj * (_camera.getView());
    {//酒柜1800
        CELL::matrix4 matTran;
        matTran.translate(0,1050,-4100);
        _boxDrink.onRender(mvp,matTran);
    }

    { //!设置黑色地面砖,0大阳台,1餐厅,2走廊,3厕所门口,4厕所旁客房,5客房,6主卧,7主厕,8小阳台
        CELL::matrix4 mat0;             //0大阳台
        mat0.translate(-5600, 25,-6000);
        _boxFloor[0].onRender(mvp,mat0);

        CELL::matrix4 mat1;             //1餐厅
        mat1.translate(-800, 25,-6000);
        _boxFloor[1].onRender(mvp,mat1);

        CELL::matrix4 mat2;             //2走廊
        mat2.translate(-2000, 25,-3920);
        _boxFloor[2].onRender(mvp,mat2);

        CELL::matrix4 mat3;             //3厕所门口
        mat3.translate(-1090, 25,-2800);
        _boxFloor[3].onRender(mvp,mat3);

        CELL::matrix4 mat4;             //4厕所旁客房
        mat4.translate(-1090, 25,-1725);
        _boxFloor[4].onRender(mvp,mat4);

        CELL::matrix4 mat5;             //5客房
        mat5.translate(-2900, 25,-1700);
        _boxFloor[5].onRender(mvp,mat5);

        CELL::matrix4 mat6;             //6主卧
        mat6.translate(-2000, 25,-1130);
        _boxFloor[6].onRender(mvp,mat6);

        CELL::matrix4 mat7;             //7主厕
        mat7.translate(-1100, 25, 2600);
        _boxFloor[7].onRender(mvp,mat7);

        CELL::matrix4 mat8;             //8小阳台
        mat8.translate(1670, 25, -5130);
        _boxFloor[8].onRender(mvp,mat8);
    }
    {//!设置墙,0酒柜后面的墙,1电视墙,2鞋柜墙,3沙发墙,4厕所与小房间的墙,5小房间和走廊墙,6衣柜墙,
     //!7主卧与小房间墙,8(650)厕所小墙,9隔户墙,10主厕和客房的墙,11餐厅与厨房墙,12油烟机墙,13小阳台和厨房墙
     //!14小阳台门与厨房门之间的墙,15客房窗边墙(1),16客房窗边墙(2),17主厕窗左墙,18主厕窗右墙,19主厕隔户墙
     //!20主厕与主卧间隔户墙,21客房1左墙,22客房1右墙,23厨房窗左墙柱子,24厨房窗左墙,25厨房窗右墙,26厨房窗右墙柱子
        CELL::matrix4 matWall;
        matWall.translate(230, 1500,-3930);
        _boxWall[0].onRender(mvp,matWall);

        CELL::matrix4 matWall1;//1电视墙
        matWall1.translate(-4200, 1500,-3930);
        _boxWall[1].onRender(mvp,matWall1);

        CELL::matrix4 matWall2;//2鞋柜墙,
        matWall2.translate(-570, 1500,-8000);
        _boxWall[2].onRender(mvp,matWall2);

        CELL::matrix4 matWall3;//3沙发墙,
        matWall3.translate(-4200, 1500,-8280);
        _boxWall[3].onRender(mvp,matWall3);

        CELL::matrix4 matWall4;//4厕所与小房间的墙,
        matWall4.translate(230, 1500,-2330);
        _boxWall[4].onRender(mvp,matWall4);

        CELL::matrix4 matWall5;//5小房间和走廊墙,
        matWall5.translate(-2900, 1500,-3060);
        _boxWall[5].onRender(mvp,matWall5);

        CELL::matrix4 matWall6;//6衣柜墙,
        matWall6.translate(-4200, 1500,-1130);
        _boxWall[6].onRender(mvp,matWall6);

        CELL::matrix4 matWall7;//7主卧与小房间墙,
        matWall7.translate(-1100, 1500,440);
        _boxWall[7].onRender(mvp,matWall7);

        CELL::matrix4 matWall8;//8(650)厕所小墙,
        matWall8.translate(-1090, 1500,-3500);
        _boxWall[8].onRender(mvp,matWall8);

        CELL::matrix4 matWall9;//9隔户墙
        matWall9.translate(-3400, 1500,3000);
        _boxWall[9].onRender(mvp,matWall9);

        CELL::matrix4 matWall10;//10主厕和客房的墙
        matWall10.translate(250, 1500,1330);
        _boxWall[10].onRender(mvp,matWall10);

        //11餐厅与厨房墙
        CELL::matrix4 matWall11;
        matWall11.translate(1670, 1500,-8500);
        _boxWall[11].onRender(mvp,matWall11);

        //12油烟机墙
        CELL::matrix4 matWall12;
        matWall12.translate(2685, 1500,-9500);
        _boxWall[12].onRender(mvp,matWall12);

        //13小阳台和厨房墙
        CELL::matrix4 matWall13;
        matWall13.translate(2685, 1500,-6500);
        _boxWall[13].onRender(mvp,matWall13);

        //14小阳台门与厨房门之间的墙
        CELL::matrix4 matWall14;
        matWall14.translate(1670, 1500,-6400);
        _boxWall[14].onRender(mvp,matWall14);

        //15客房2窗边墙(1),
        CELL::matrix4 matWall15;
        matWall15.translate(1930, 1500,-1905);
        _boxWall[15].onRender(mvp,matWall15);

        //16客房2窗边墙(2)
        CELL::matrix4 matWall16;
        matWall16.translate(1930, 1500,960);
        _boxWall[16].onRender(mvp,matWall16);

        //17主厕窗左墙,
        CELL::matrix4 matWall17;
        matWall17.translate(1670, 1500,1730);
        _boxWall[17].onRender(mvp,matWall17);

        // 18主厕窗右墙,
        CELL::matrix4 matWall18;
        matWall18.translate(1670, 1500,3400);
        _boxWall[18].onRender(mvp,matWall18);

        // 19主厕隔户墙
        CELL::matrix4 matWall19;
        matWall19.translate(250, 1500,3900);
        _boxWall[19].onRender(mvp,matWall19);

        //20主厕与主卧间隔户墙
        CELL::matrix4 matWall20;
        matWall20.translate(-1300, 1500,3450);
        _boxWall[20].onRender(mvp,matWall20);

        //21客房1左墙,
        CELL::matrix4 matWall21;
        matWall21.translate(-5700, 1500,-1530);
        _boxWall[21].onRender(mvp,matWall21);

        //22客房1右墙
        CELL::matrix4 matWall22;
        matWall22.translate(-5700, 1500,-3530);
        _boxWall[22].onRender(mvp,matWall22);

        //23厨房窗左墙柱子,
        CELL::matrix4 matWall23;
        matWall23.translate(3735, 1500,-9250);
        _boxWall[23].onRender(mvp,matWall23);

        //24厨房窗左墙,
        CELL::matrix4 matWall24;
        matWall24.translate(3970, 1500,-8770);
        _boxWall[24].onRender(mvp,matWall24);

        //25厨房窗右墙,
        CELL::matrix4 matWall25;
        matWall25.translate(3970, 1500,-7150);
        _boxWall[25].onRender(mvp,matWall25);

        //26厨房窗右墙柱子
        CELL::matrix4 matWall26;
        matWall26.translate(3850, 1500,-6735);
        _boxWall[26].onRender(mvp,matWall26);
    }

    {//窗台墙:
        //!0小阳台(宽),1小阳台(窄),2厕所,3主厕,4客房1,5大阳台左矮墙,6大阳台矮墙,7大阳台右矮墙
        CELL::matrix4 matWall[8];

        matWall[0].translate(3485, 325,-5400);
        _boxWindowWall[0].onRender(mvp,matWall[0]);

        matWall[1].translate(2585, 325,-3930);
        _boxWindowWall[1].onRender(mvp,matWall[1]);

        //2厕所 窗台墙
        matWall[2].translate(1670, 440,-3130);
        _boxWindowWall[2].onRender(mvp,matWall[2]);

        //3主厕 窗台墙
        matWall[3].translate(1670, 440,2500);
        _boxWindowWall[3].onRender(mvp,matWall[3]);

        //4客房1 窗台墙
        matWall[4].translate(-5700, 440,-2330);
        _boxWindowWall[4].onRender(mvp,matWall[4]);

        //5大阳台左矮墙,
        matWall[5].translate(-6850, 325,-3930);
        _boxWindowWall[5].onRender(mvp,matWall[5]);

        //6大阳台矮墙,
        matWall[6].translate(-8200, 325,-6130);
        _boxWindowWall[6].onRender(mvp,matWall[6]);

        //7大阳台右矮墙
        matWall[7].translate(-6850, 325,-8280);
        _boxWindowWall[7].onRender(mvp,matWall[7]);
    }

    {//!玻璃窗户:
        //! 0厨房窗户,1小阳台窗户大,2小阳台窗户小,3厕所窗户,4主厕窗户,5客房1窗户,
        //! 6小阳台玻璃门,7客房2落地窗,8主卧落地窗,9客厅玻璃门
        //! 10大阳台左窗户,11大阳台大窗户,12大阳台右窗户
        CELL::matrix4 matWindow[13];

        matWindow[0].translate(3970, 1800,-7930);
        _boxWindow[0].onRender(mvp,matWindow[0]);

        //1小阳台窗户大
        matWindow[1].translate(3485, 1650,-5200);
        _boxWindow[1].onRender(mvp,matWindow[1]);

        //2小阳台窗户小
        matWindow[2].translate(2585, 1650,-3930);
        _boxWindow[2].onRender(mvp,matWindow[2]);

        //3厕所窗户
        matWindow[3].translate(1670, 1880,-3130);
        _boxWindow[3].onRender(mvp,matWindow[3]);

        //4主厕窗户
        matWindow[4].translate(1670, 1880,2500);
        _boxWindow[4].onRender(mvp,matWindow[4]);

        //5客房1窗户
        matWindow[5].translate(-5700, 1880,-2550);
        _boxWindow[5].onRender(mvp,matWindow[5]);

        //6小阳台玻璃门,
        matWindow[6].translate(1670, 1550,-5125);
        _boxWindow[6].onRender(mvp,matWindow[6]);

        //7客房2落地窗,
        matWindow[7].translate(2330, 1500,-420);
        _boxWindow[7].onRender(mvp,matWindow[7]);

        //8主卧落地窗,
        matWindow[8].translate(-5700, 1500,900);
        _boxWindow[8].onRender(mvp,matWindow[8]);

        //9客厅玻璃门
        matWindow[9].translate(-5600, 1550,-6100);
        _boxWindow[9].onRender(mvp,matWindow[9]);

        //10大阳台左窗户,11大阳台大窗户,12大阳台右窗户
        matWindow[10].translate(-6850, 1650,-3930);
        _boxWindow[10].onRender(mvp,matWindow[10]);

        matWindow[11].translate(-8200, 1650,-6130);
        _boxWindow[11].onRender(mvp,matWindow[11]);

        matWindow[12].translate(-6850, 1650,-8280);
        _boxWindow[12].onRender(mvp,matWindow[12]);
    }

    {//!柜子
        //ice
        CELL::matrix4 ice;
        ice.translate(1300, 865,-4300);
        _boxIce.onRender(mvp,ice);

        //0橱柜(洗碗池),1橱柜(灶台)
        CELL::matrix4 matcup[3];
        matcup[0].translate(3600, 400,-8000);
        _boxCupboard[0].onRender(mvp,matcup[0]);

        matcup[1].translate(2535, 400,-9100);
        _boxCupboard[1].onRender(mvp,matcup[1]);

        //2鞋柜
        matcup[2].translate(0, 550,-7730);
        _boxCupboard[2].onRender(mvp,matcup[2]);
    }

    {//!门:
        //! 0厨房门,1厕所门,2客房2门,3主卧门,4主厕门,5客房1门
        CELL::matrix4 matDoor[6];

        matDoor[0].translate(1670, 1000,-7070);
        _boxDoor[0].onRender(mvp,matDoor[0]);

        matDoor[1].translate(-1090, 1050,-2775);
        _boxDoor[1].onRender(mvp,matDoor[1]);

        //2客房2门
        matDoor[2].translate(-1090, 1050,-1730);
        _boxDoor[2].onRender(mvp,matDoor[2]);

        //3主卧门
        matDoor[3].translate(-2000, 1050,-1130);
        _boxDoor[3].onRender(mvp,matDoor[3]);

        //4主厕门
        matDoor[4].translate(-1090, 1050,2515);
        _boxDoor[4].onRender(mvp,matDoor[4]);

        //5客房1门
        matDoor[5].translate(-2900, 1050,-1685);
        _boxDoor[5].onRender(mvp,matDoor[5]);
    }
}

void QMyWidget::drawImage()
{
    onRender();
    eglSwapBuffers(_display,_surface);
}

bool QMyWidget::eventFilter(QObject *target, QEvent *event)
{
    if( target == parent )
     {
         if( event->type() == QEvent::KeyPress )
         {
             QKeyEvent *ke = (QKeyEvent *) event;
             keyPressEvent(ke);
          }
         if( event->type() == QEvent::MouseTrackingChange )
         {
             QMouseEvent *mouse = (QMouseEvent *) event;
             mouseMoveEvent(mouse);
             mousePressEvent(mouse);
             mouseReleaseEvent(mouse);
             QWheelEvent *wheel = (QWheelEvent *) event;
             wheelEvent(wheel);
         }
     }
    return false;
}

void QMyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    mousePos.sprintf("pos:[%d,%d]",ev->pos().x(),ev->pos().y());
    //printf("%s\n",mousePos.toLatin1().data());
    fflush(NULL);
    if(ev->buttons() & Qt::RightButton)
    {
        _camera.reciveMouseEvent(CameraBase::MOUSEMODE::MOUSE_RIGHTDOWN,_posOrg,CELL::int2(ev->pos().x(),ev->pos().y()));
        _posOrg = CELL::int2(ev->pos().x(),ev->pos().y());
    }
    if(ev->buttons() & Qt::LeftButton)
    {
        _camera.reciveMouseEvent(CameraBase::MOUSEMODE::MOUSE_LEFTDOWN,_posOrg,CELL::int2(ev->pos().x(),ev->pos().y()));
        _posOrg = CELL::int2(ev->pos().x(),ev->pos().y());
    }

}

void QMyWidget::mousePressEvent(QMouseEvent *ev)
{
    mousePos.sprintf("pos:[%d,%d]",ev->pos().x(),ev->pos().y());

    if(ev->button() == Qt::RightButton)
    {
        _posOrg = CELL::int2(ev->pos().x(),ev->pos().y());
    }
    if(ev->button() == Qt::LeftButton)
    {
//        CELL::int2 point;
//        point           = CELL::int2(ev->x(),ev->y());
//        CELL::Ray ray   = _camera.createRayFromScreen(point.x,point.y);

//        CELL::float3 p  = ray.getOrigin();
//        float tm        = abs((p.x) /(ray.getDirection().x));
//        CELL::float3 pointEnd = ray.getPoint(tm);
//        //CELL::float3 target = ray.getDirection() * tm;
//        _posOrg = pointEnd;
        _posOrg = CELL::int2(ev->pos().x(),ev->pos().y());
    }
}

void QMyWidget::mouseReleaseEvent(QMouseEvent *ev)
{


}

void QMyWidget::wheelEvent(QWheelEvent *event)
{
    _camera.reciveWheelEvent(CameraBase::MOUSEMODE::MOUSE_WHEEL,event->delta(),CELL::int2(event->pos().x(),event->pos().y()));
}
