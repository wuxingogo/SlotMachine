//
//  SlotMachineManager.h
//  slotMachine
//
//  Created by ly on 15/3/26.
//
//

#ifndef __slotMachine__SlotMachineManager__
#define __slotMachine__SlotMachineManager__

#include "SlotMachineNode.h"
#include <iostream>
#include <vector>
using namespace std;

class SlotMachineNode;

class SlotMachineManager : public cocos2d::Node {
    
public:
    
    
    static SlotMachineManager * getInstance();
    
    static SlotMachineManager * _instance;
    
    std::vector<SlotMachineNode *> * allSlotMachine;
    
    void startTimer();
    
    void insertSlot(SlotMachineNode * );
    
    void update(float dt);
    
    void cleanAllUpdate();
private:
    SlotMachineManager();
};

#endif /* defined(__slotMachine__SlotMachineManager__) */
