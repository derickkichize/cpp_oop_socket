#pragma once
#include "Socket.hh"

namespace NET {
  namespace Sockets {
    class TCPSocket :public Socket {
    public:
      TCPSocket         (void);
      void  startListen (int listen_port,
			 std::string listern_target,
			 uint32_t backlog) override;
    };
  }
}
  
