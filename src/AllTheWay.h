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

#if !defined(ALLTHEWAY_H)
#define ALLTHEWAY_H

#include "BaseNode.h"
#include "AllTheWayMsg_m.h"
#include <algorithm>


class AllTheWay : public BaseNode{

protected: 
    /** @brief Unique identifier of the node **/
    int id;

    /** @brief Minimum seen by the node **/
    int minimum;

    /** @brief Counter of messages recieved by the node **/
    size_t msgCnt;

    /** @brief Size of the ring n **/
    size_t ringSize;

    protected:     
    /** @brief configure node state */
    virtual void setState(); 

    /** @brief Verify state based on mensagges recieved */
    virtual void check(); 

    /** @brief Prints the node starts in the simulation canvas */
    virtual void refreshDisplay() const override;

    public:
        AllTheWay();

        /** @brief Assings the initial node status: idle or initiator **/
        virtual void initialize() override;

        /** @brief Assings the initial node status: idle or initiator **/
        virtual void handleMessage(omnetpp::cMessage*);
};

#endif