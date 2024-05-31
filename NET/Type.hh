#pragma once
#include <sys/socket.h>

namespace NET {
  class Type {
  public:
    static const int STREAM  = SOCK_STREAM;
    static const int DGRAM   = SOCK_DGRAM;
  };
}
