//
// TestLayer.cpp
// slotMachine
//
// Created by ly on 15/3/26.
//
//

#include "TestLayer.h"
#include "SlotMachineNode.h"
TestLayer::TestLayer()
{
    
}

TestLayer::~TestLayer()
{
    
}

Scene* TestLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = TestLayer::create();
    scene->addChild(layer);
    return scene;
}

bool TestLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    initData();
    return true;
}

#pragma mark - initData
void TestLayer::initData()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // add your codes here...
    
    for (int i = 0 ; i < 1; i ++) {
    
        SlotMachineNode * slotMachine = SlotMachineNode::create();
        slotMachine->setPosition(100 + 50 * i, visibleSize.height / 2);
        slotMachine->setAlignStyle(SlotMachineNode::Align::DOWN);
        slotMachine->setShowSize(Size(1000,400));
        this->addChild(slotMachine);
        
        for (int i = 0 ; i < 11; i++) {
            Sprite * sp = Sprite::create("CloseNormal.png");
            char temp;
            sprintf(&temp, "%d",i);
            Label * label = Label::create();
            label->setString(&temp);
            label->setSystemFontSize(30);
            label->setAnchorPoint(Vec2::ZERO);
            sp->addChild(label);
            
            slotMachine->insertNode(sp) ;
        }
        
        slotMachine->setRewardItem(i);
        slotMachine->setRewardListener(CC_CALLBACK_0(TestLayer::reward, this));
        slotMachine->startTurn();
    }
    
//    SlotMachineManager::getInstance()->cleanAllUpdate();
    
}
void TestLayer::reward(){
    CCLOG("reward");
}

