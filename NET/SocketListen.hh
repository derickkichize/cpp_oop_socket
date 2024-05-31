#pragma once

namespace NET {
  class SocketListen {
  private:
    uint32_t backlog;
  public:
    SocketListen       (int listen_backlog);
    void listen_socket (int socket_descriptor);
  };
}
