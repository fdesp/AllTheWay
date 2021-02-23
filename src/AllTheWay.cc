//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "AllTheWay.h"

Define_Module(AllTheWay);

AllTheWay::AllTheWay()    
    : id(-1)
    , minimum(-1)
    , msgCnt(0)
    , ringSize(0)
{ }

void AllTheWay::initialize(){
    if(par("initiator").boolValue()){
        timer = new omnetpp::cMessage("timer", MsgKind::TIMER);
        scheduleAt(par("startTime"), timer);
    }
    status = Status::IDLE;
    id = getIndex();
}

void AllTheWay::handleMessage(omnetpp::cMessage* recvMsg){
    if (status == Status::IDLE){
        if (recvMsg->getKind() == MsgKind::TIMER){ // A1
            setState();
            status = Status::PROCESSING;
            delete recvMsg;
        }
        else if (recvMsg->getKind() == MsgKind::ELECTION){ // A2
            setState();
            auto electMsg = dynamic_cast<AllTheWayMsg*>(recvMsg);
            electMsg->setHops(electMsg->getHops() + 1);
            int other = (recvMsg->getArrivalGate()->getIndex() == 0) ? 1 : 0;
            send(electMsg, "port$o", other);
            minimum = std::min(minimum, electMsg->getId());
            msgCnt++;
            status = Status::PROCESSING;
        }
        else 
            nil(recvMsg);
    }
    else if (status == Status::PROCESSING){
        if (recvMsg->getKind() == MsgKind::ELECTION){ // A3
            auto electMsg = dynamic_cast<AllTheWayMsg*>(recvMsg);
            if(electMsg->getId() != id){
                electMsg->setHops(electMsg->getHops() + 1);
                int other = (recvMsg->getArrivalGate()->getIndex() == 0) ? 1 : 0;
                send(electMsg, "port$o", other);
                minimum = std::min(minimum, electMsg->getId());
                msgCnt++;
                if(ringSize > 0)
                    check();
            }
            else{
                msgCnt++;
                ringSize = electMsg->getHops();
                check();
            }
        }
        else 
            nil(recvMsg);
    }
}

void AllTheWay::setState(){
    msgCnt = 0;
    ringSize = 0;
    minimum = id;
    auto electionMsg = new AllTheWayMsg("election", MsgKind::ELECTION);
    electionMsg->setId(id);
    electionMsg->setHops(1);
    send(electionMsg, "port$o", 1);
}


void AllTheWay::check(){
    if(msgCnt == ringSize){
        if(minimum == id)
            status = Status::LEADER;
        else
            status = Status::FOLLOWER;
    }
}

void AllTheWay::refreshDisplay() const{
    std::string info = status.str();
    getDisplayString().setTagArg("t", 0, info.c_str());
    if(info == "LEADER"){
        getDisplayString().setTagArg("t", 2, "red");
    }
}

