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

#if !defined(STATUS_H)
#define STATUS_H

/** @brief This class could be extended if the current set of possible status
 *  is not enough to implement a distributed algorithm. Take care about the
 *  valuces assigned to each item.
 *  @author A.G. Medrano-Chavez
*/
class Status {
public:
  /** @brief Status associated to the node that starting a protocol */
  static const int INITIATOR = 0;
  /** @brief Status associated to nodes that have not received any message */
  static const int IDLE = 1;
  /** @brief Status associated to nodes that have received a message, at least*/
  static const int ACTIVE = 2;
  /** @brief Status associated to nodes that do not have any actions to do */
  static const int DONE = 3;
};

#endif // STATUS_H
