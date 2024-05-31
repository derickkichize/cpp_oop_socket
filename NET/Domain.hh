#pragma once
#include <sys/socket.h>

namespace NET {
  class Domain {
  public:
    static const int INET  = AF_INET;
    static const int INET6 = AF_INET6;
  };
}
