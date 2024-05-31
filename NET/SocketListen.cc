#include <cstdlib>
#include <sys/socket.h>
#include "SocketListen.hh"

namespace NET {
  SocketListen::SocketListen (int listen_backlog)
    :backlog(listen_backlog) {}

  void
  SocketListen::listen_socket (int socket_descriptor)
  {
    return (listen (socket_descriptor, backlog) == -1) ?
      EXIT_FAILURE : socket_descriptor;
  }
}
