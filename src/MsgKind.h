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

class MsgKind {
public:
  /** @brief A generic message */
  static const int MSG       = 0;
  /** @brief A common message sent to ask for something */
  static const int QUERY     = 1;
  /** @brief A common message sent to answer a query */
  static const int REPLY     = 2;
  /** @brief An affirmative response */
  static const int YES       = 3;
  /** @brief An negative response */
  static const int NO        = 4;
  /** @brief An acknowlegdement */
  static const int ACK       = 5;
  /** @brief A negative acknowlegdement */
  static const int NACK      = 6;
  /** @brief A token */
  static const int TOKEN     = 7;
  /** @brief A timer implemented as a self-message */
  static const int TIMER     = 8;
  /** @brief An announcement to inform a task is completed */
  static const int CHECK     = 9;
  /** @brief An message to inform global termination */
  static const int TERMINATE = 10;
};