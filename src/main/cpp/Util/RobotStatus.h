#pragma once

#include "Event.h"
#include "EventArgs.h"

namespace Util{

    enum RobotState{
        Teleop,
        Auton,
        Test,
        Disabled
    };

    class RobotStatus{
        public:
            static RobotStatus& GetInstance(){
                static RobotStatus instance;
                return instance;
            }
            Event RobotStatusChanged;
            void NotifyState(RobotState state){
                // cout << "NOTIFYSTATE" << endl;
                CurrentRobotState = state;
                RobotStatusChanged(new TEventArgs<RobotState,RobotStatus*>(CurrentRobotState,this));
            }
        private:
            RobotStatus(){}
            RobotState CurrentRobotState;
        public:
            RobotStatus(RobotStatus const&) = delete;
            void operator=(RobotStatus const&) = delete;
    };
}