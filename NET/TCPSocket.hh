#pragma once
#include "Socket.hh"

namespace NET {
  class TCPSocket :public Socket {
  public:
    TCPSocket (void);
    void  listen_on (int backlog, int listen_port) override;
  };
}
