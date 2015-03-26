//
//  SlotMachineNode.cpp
//  slotMachine
//
//  Created by ly on 15/3/26.
//
//

#include "SlotMachineNode.h"

bool SlotMachineNode::init(){
    if (Node::init()) {
        
        _container = Node::create();
        
        
        _clipNode = ClippingNode::create();
        _clipNode->addChild(_container);
        _clipNode->setInverted(false);
        this->addChild(_clipNode);
        
        /*!
         *  @author wuxingogo, 15-03-26 11:03:49
         *
         *  @brief  初始化转动时间是10s
         */
        _runTime = 10;
        _currentTime = 0;
        
        this->_showRect = Node::create();
        
        setShowSize(Size(200,200));
        
        _listView = new std::vector<Node*>();
        
        SlotMachineManager::getInstance()->insertSlot(this);
        
        this->setAlignStyle(SlotMachineNode::Align::DOWN);
        
        _currentItem = 0;
        
        return true;
    }
    return false;
}

void SlotMachineNode::insertNode(cocos2d::Node * item){
    
    
    if (_listView->size() > 0) {
        
        Node * pos = _listView->back();
        
        switch (_align) {
            case Align::LEFT:
                item->setPositionX(pos->getPositionX() + pos->getContentSize().width);
                break;
            case Align::RIGHT:
                item->setPositionX(pos->getPositionX() - pos->getContentSize().width);
                break;
            case Align::UP:
                item->setPositionY(pos->getPositionY() + pos->getContentSize().height);
                break;
            case Align::DOWN:
                item->setPositionY(pos->getPositionY() - pos->getContentSize().height);
                break;
                
            default:
                break;
        }
    }
    _listView->push_back(item);
    _container->addChild(item);
    
    
}

void SlotMachineNode::setRewardListener(const std::function<void ()> & listener){
    this->listener = listener;
}

void SlotMachineNode::setShowSize(cocos2d::Size size){
    
    
    LayerColor * layer = LayerColor::create(Color4B::RED, size.width, size.height);
    
    layer->ignoreAnchorPointForPosition(false);
    layer->setAnchorPoint(Vec2(0.5f,0.5f));
    layer->setPosition(Vec2::ZERO);
    
    this->_showRect->setContentSize(size);
    
    
    _clipNode->setStencil(layer);
}

void SlotMachineNode::startTurn(){
    speedup = true;
    _currentTime = 0;
    isTurn = true;
}

void SlotMachineNode::updateMyself(float dt){
    
    if (isTurn) {
        
        if (speedup) {
            _currentTime += dt;
            if (_currentTime > _runTime / 2) {
                speedup = false;
            }
        }else{
            if (_currentTime > 0.5) {
                _currentTime -= dt;
            }else if(_currentItem == _rewardItem){
                isTurn = false;
                this->runAction(CallFunc::create(listener));
                
            }
            
            
        }
        for ( int i = 0; i < _listView->size(); i++) {
            
            _listView->at(i)->setPositionY(_listView->at(i)->getPositionY() + _currentTime * 5);
            if (_listView->at(i)->getPositionY() > 0) {
                _currentItem = _currentItem >= _listView->size() - 1 ? 0 : _currentItem + 1 ;
                CCLOG("%d",_currentItem);
                float detal = _listView->at(i)->getPositionY();
                _listView->at(i)->setPositionY(-450 + detal);
            }
        }
    }
}




