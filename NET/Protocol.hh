#pragma once
#include <netinet/in.h>

namespace NET {
  class Proto {
  public:
    static const int TCP = IPPROTO_TCP;
    static const int UDP = IPPROTO_UDP;
  };
}
