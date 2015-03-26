//
//  SlotMachineNode.h
//  slotMachine
//
//  Created by ly on 15/3/26.
//
//

#ifndef __slotMachine__SlotMachineNode__
#define __slotMachine__SlotMachineNode__

#include "cocos2d.h"
#include <vector>
#include "SlotMachineManager.h"
USING_NS_CC;

class SlotMachineNode : public Node {
    
public:
    virtual bool init() override;
    
    CREATE_FUNC(SlotMachineNode);
    
    void updateMyself(float dt);
 
    /*!
     *  @author wuxingogo, 15-03-26 11:03:29
     *
     *  @brief  回调函数
     *
     *  @param std::function<void nil
     */
    void setRewardListener(const std::function<void ()> & listener);
    
    void setShowSize(Size size);
    
    void insertNode(Node *);
    
    void startTurn();
    
    enum Align{
        LEFT = 1,
        RIGHT = 2,
        UP = 3,
        DOWN = 4
    };

private:
    
    CC_SYNTHESIZE(Align, _align, AlignStyle);
    
    ClippingNode * _clipNode;
    
    CC_SYNTHESIZE(int, _currentItem, CurrentItem);
    
    /*!
     *  @author wuxingogo, 15-03-26 11:03:09
     *
     *  @brief  设置最后的奖励item
     */
    CC_SYNTHESIZE(int, _rewardItem, RewardItem);
    
    /*!
     *  @author wuxingogo, 15-03-26 11:03:21
     *
     *  @brief  真实的listView
     */
    CC_SYNTHESIZE(Node * , _container, ListView);
    
//    Vector<Node *> * _listView;
    
    std::vector<Node *> * _listView;
    
    /*!
     *  @author wuxingogo, 15-03-26 11:03:11
     *
     *  @brief  裁减区
     */
    Node * _showRect;
    
    /*!
     *  @author wuxingogo, 15-03-26 11:03:22
     *
     *  @brief  转动时间,加速减速总shijian
     */
    CC_SYNTHESIZE(float, _runTime, RunTime);
    
    CC_SYNTHESIZE(float, _currentTime, CurrentTime);
    
    /*!
     *  @author wuxingogo, 15-03-25 19:03:14
     *
     *  @brief  up is true, down is false
     */
    bool speedup;
    
    bool isTurn;
    
    
    std::function<void()> listener;
};

#endif /* defined(__slotMachine__SlotMachineNode__) */
