#pragma once
#include <iostream>
#include <string>

namespace NET {
  namespace Sockets {
    class SocketContract {
    public:
      virtual int  create      (void) = 0;
      virtual void startListen (int         listen_port,
				std::string listen_target,
				uint32_t    backlog) = 0;
    
      virtual ~SocketContract (void) = default;
    };
  }
};
