#pragma once
#include <cstdint>

namespace NET {
  namespace Sockets {
    class Listener {
    private:
      uint32_t backlog;
    public:
      Listener          (int listen_backlog);
      int listen_socket (int socket_descriptor);
    };
  }
}
