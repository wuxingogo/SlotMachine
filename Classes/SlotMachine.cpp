//
// SlotMachine.cpp
// TestSpine
//
// Created by ly on 15/3/25.
//
//

#include "SlotMachine.h"

SlotMachine::SlotMachine()
{
    
}

SlotMachine::~SlotMachine()
{
    
}

Scene* SlotMachine::createScene()
{
    auto scene = Scene::create();
    auto layer = SlotMachine::create();
    scene->addChild(layer);
    return scene;
}

bool SlotMachine::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    initData();
    return true;
}

#pragma mark - initData
void SlotMachine::initData()
{
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(SlotMachine::toReward, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    listView = Node::create();
    listView->setPosition(visibleSize / 2);
    
    LayerColor * clipLayer = LayerColor::create(Color4B::RED,200,200);
    clipLayer->setPosition(visibleSize.width / 2.3, visibleSize.height / 4);
    
    ClippingNode * clip = ClippingNode::create(clipLayer);
    clip->setInverted(false);
    this->addChild(clip,10);
    clip->addChild(listView);
    
    for (int i = 0; i < 10; i++) {
        listViewSp[i] = Sprite::create("CloseNormal.png");
        listViewSp[i]->setTag(i);
        listView->addChild(listViewSp[i]);
        listViewSp[i]->setPositionY(i * -50);
        char temp;
        sprintf(&temp, "%d",i);
        Label * label = Label::create();
        label->setString(&temp);
        label->setSystemFontSize(30);
        label->setAnchorPoint(Vec2::ZERO);
        listViewSp[i]->addChild(label);
    }
    
    myTag = 0;
    
    startTime = 0;
    
    speedup = true;
}


void SlotMachine::toReward(cocos2d::Ref* pSender){
    this->scheduleUpdate();
    speedup = true;
    startTime = 0;
}

void SlotMachine::update(float dt){
    
    if (speedup) {
        startTime += dt;
        if (startTime > 5) {
            speedup = false;
        }
    }else{
        startTime -= dt;
        if (startTime < 0) {
            this->unscheduleUpdate();
            CCLOG("myTag is %d",myTag);
        }
    }
    for ( int i = 0; i < 10; i++) {
        listViewSp[i]->setPositionY(listViewSp[i]->getPositionY() + startTime * 5);
        if (listViewSp[i]->getPositionY() > 0) {
            myTag = myTag >= 9 ? 0 : myTag + 1 ;
            CCLOG("%d",myTag);
            float detal = listViewSp[i]->getPositionY();
            listViewSp[i]->setPositionY(-450 + detal);
        }
    }
}
