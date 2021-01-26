#include "BaseNode.h"

Define_Module(BaseNode);

omnetpp::cMessage* BaseNode::localBroadcast(omnetpp::cMessage* msg) {
  if (msg) {
    int n = gateSize("port$o");
    for (int i = 0; i < n-1; i++)
      send(msg->dup(), "port$o", i);
    send(msg, "port$o", n-1);
  }
  return msg;
}

omnetpp::cMessage* BaseNode::localFlooding(
  omnetpp::cMessage* msg, int senderID
) {
  if (msg) {
    int n = gateSize("port$o");
    for (int i = 0; i < n; i++)
      if (i != senderID)
        send(msg->dup(), "port$o", i);
    delete msg;
    msg = nullptr;
  }
  return msg;
}

omnetpp::cMessage* BaseNode::localMulticast(
  omnetpp::cMessage* msg,
  const std::vector<int>& destination
) {
  if (msg) {
    int n = gateSize("port$o");
    for (int i = 0; i < destination.size() - 1; i++)
      send(msg->dup(), "port$o", destination[i]);
    send(msg, "port$o", destination.back());
  }
  return msg;
}
