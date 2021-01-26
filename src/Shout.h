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

#if !defined(SHOUT_H)
#define SHOUT_H

#include "BaseNode.h"
#include <vector>

class Shout : public BaseNode {
protected:
  /** @brief The ID of the node starting the experiment */
  int initiator;
  /** @brief the set of ports in T */
  std::vector<int> treeNeighborhood;
  /** @brief Register indicating if this node is the root of T */
  bool root;
  /** @brief Register indicating the port ID of the parent of this node */
  int parent;
  /** @brief The number of messages received from neighbors */
  unsigned counter;
protected:
  /** @brief Prints the node starts in the simulation canvas */
  virtual void refreshDisplay() const override;

public:
  /** @brief default constructor */
  Shout();
  /** @brief default destructor */
  virtual ~Shout() { }
  /** @brief Initializes the state of nodes according to their status. 
   *  The sole initiator parses the start time of the simulation and 
   *  schedules the execution of the rule (spontaneously, initiator) -> A1
   */
  virtual void initialize() override;
  /** @brief Manages the action of this node when an event happens */
  virtual void handleMessage(omnetpp::cMessage*) override;
};

#endif // SHOUT_H
