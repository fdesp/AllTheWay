#include "Status.h"

const Status Status::UNSPECIFIED(-1);
const Status Status::INITIATOR(0);
const Status Status::IDLE(1);
const Status Status::ACTIVE(2);
const Status Status::SLEEP(3);
const Status Status::DONE(4);
const Status Status::LEADER(5);
const Status Status::FOLLOWER(6);
const Status Status::SATURATED(7);
const Status Status::PROCESSING(8);