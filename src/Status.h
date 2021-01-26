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

#include <iostream>

/** @brief This class could be modified if the current set of possible status
 *  is not enough to implement a distributed algorithm. Take care about the
 *  values assigned to each item. Do not forget 
 *  @author A.G. Medrano-Chavez
*/
class Status {
private:
  /** @brief A variable holding the node status */
  int status;
  /** @brief Overloaded constructor taking values from the static variables 
   *  from this class */
  Status(int s) : status(s) { }
public:
  /** @brief Status associated to the node that starting a protocol */
  static const Status UNSPECIFIED;
  /** @brief Status associated to the node that starting a protocol */
  static const Status INITIATOR;
  /** @brief Status associated to nodes that have not received any message */
  static const Status IDLE;
  /** @brief Status associated to nodes waiting for a message */
  static const Status ACTIVE;
  /** @brief Status associated to nodes unactive nodes */
  static const Status SLEEP;
  /** @brief Status associated to nodes that do not have any actions to do */
  static const Status DONE;
  /** @brief Default constructor */
  Status() : status(-1) { }
  /** @brief Overloaded constructor taking values from the static variables 
   *  from this class */
  Status(const Status& s) : status(s.status) { }
  /** @brief Assings a possible status of this set*/
  virtual Status& operator=(const Status& s) {
    status = s.status; 
    return *this; 
  }
  /** @brief Assings a possible status of this set*/
  virtual bool operator==(const Status& s) {
    return status == s.status; 
  }
  /** @brief Returns a c-style string containing the name of the status */
  virtual const char* str() const {
    switch (status) {
    case 0:  return "INITIATOR";
    case 1:  return "IDLE";     
    case 2:  return "ACTIVE";   
    case 3:  return "SLEEP";    
    case 4:  return "DONE";     
    default: return "UNDEFINED";
    }
  }
  friend std::ostream& operator<<(std::ostream& os, const Status& s) {
    return os << s.str();
  }
};

#endif // STATUS_H
