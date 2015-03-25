//
// SlotMachine.h
// TestSpine
//
// Created by ly on 15/3/25.
//
//

#ifndef __TestSpine__SlotMachine__
#define __TestSpine__SlotMachine__

#include "cocos2d.h"
USING_NS_CC;


/**
 *　　　　　　　　┏┓　┏┓+ +
 *　　　　　　　┏┛┻━━━┛┻┓ + +
 *　　　　　　　┃　　　　　　　┃
 *　　　　　　　┃　　　━　　　┃ ++ + + +
 *　　　　　　 ████━████ ┃+
 *　　　　　　　┃　　　　　　　┃ +
 *　　　　　　　┃　　　┻　　　┃
 *　　　　　　　┃　　　　　　　┃ + +
 *　　　　　　　┗━┓　　　┏━┛
 *　　　　　　　　　┃　　　┃
 *　　　　　　　　　┃　　　┃ + + + +
 *　　　　　　　　　┃　　　┃　　　　Code is far away from bug with the animal protecting
 *　　　　　　　　　┃　　　┃ + 　　　　神兽保佑,代码无bug
 *　　　　　　　　　┃　　　┃
 *　　　　　　　　　┃　　　┃　　+
 *　　　　　　　　　┃　 　　┗━━━┓ + +
 *　　　　　　　　　┃ 　　　　　　　┣┓
 *　　　　　　　　　┃ 　　　　　　　┏┛
 *　　　　　　　　　┗┓┓┏━┳┓┏┛ + + + +
 *　　　　　　　　　　┃┫┫　┃┫┫
 *　　　　　　　　　　┗┻┛　┗┻┛+ + + +
 */

class SlotMachine : public Layer
{
public:
    SlotMachine();
    ~SlotMachine();
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(SlotMachine);
    
    Sprite * listViewSp[10];
    
    Node * listView;
    
    void toReward(cocos2d::Ref* pSender);
    void update(float dt);
    
    float startTime;
    
    /*!
     *  @author wuxingogo, 15-03-25 19:03:14
     *
     *  @brief  up is true, down is false
     */
    bool speedup;
    
    int myTag;
private:
    void initData();
};

#endif /* defined(__TestSpine__SlotMachine__) */