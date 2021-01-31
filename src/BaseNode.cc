#include "BaseNode.h"

Register_Abstract_Class(BaseNode);

omnetpp::cMessage* BaseNode::localBroadcast(omnetpp::cMessage* msg) {
  if (msg) {
    int n = gateSize("port$o");
    for (int i = 0; i < n -1; i++)
      send(msg->dup(), "port$o", i);
    send(msg, "port$o", n-1);
  }
  return msg;
}

omnetpp::cMessage* BaseNode::localFlooding(omnetpp::cMessage* msg) {
  int senderID = msg->getArrivalGate()->getIndex();
  if (msg) {
    int n = gateSize("port$o");
    for (int i = 0; i < n; i++)
      if (i != senderID)
        send(msg->dup(), "port$o", i);
    delete msg;
  }
  return msg;
}

omnetpp::cMessage* BaseNode::localMulticast(
  omnetpp::cMessage* msg,
  const std::vector<int>& destination
) {
  if (msg) {
    for (auto&& port : destination)
      send(msg->dup(), "port$o", port);
    delete msg;
  }
  return msg;
}
