//
//  SlotMachineManager.cpp
//  slotMachine
//
//  Created by ly on 15/3/26.
//
//

#include "SlotMachineManager.h"


SlotMachineManager * SlotMachineManager::_instance = NULL;

SlotMachineManager * SlotMachineManager::getInstance(){
    if (_instance == NULL) {
        _instance = new SlotMachineManager();
    }
    return _instance;
}

void SlotMachineManager::insertSlot(SlotMachineNode * item){
    allSlotMachine->push_back(item);
    removeFromParentAndCleanup(false);
    item->addChild(this);
}

SlotMachineManager::SlotMachineManager(){
    allSlotMachine = new std::vector<SlotMachineNode*>();
    startTimer();
}

void SlotMachineManager::startTimer(){
    this->scheduleUpdate();
    
}
void SlotMachineManager::cleanAllUpdate(){
    this->unscheduleUpdate();
}

void SlotMachineManager::update(float dt){
    std::vector<SlotMachineNode *>::iterator pos3;
    for(pos3 = allSlotMachine->begin(); pos3 != allSlotMachine->end(); ++pos3){
        SlotMachineNode * node = * pos3;
        node->updateMyself(dt);
    }
}