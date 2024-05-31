#pragma once

namespace NET {
  class SocketContract {
  public:
    virtual int create      (void) = 0;
    virtual int startListen (void) = 0;
    virtual ~SocketContract (void) = default;
  };
}
