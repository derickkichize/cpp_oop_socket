#include <cstdlib>
#include <sys/socket.h>
#include "Listener.hh"

namespace NET {
  namespace Sockets {
    Listener::Listener (int listen_backlog)
      :backlog(listen_backlog) {}

    int
    Listener::listen_socket (int socket_descriptor)
    {
      return (listen (socket_descriptor, backlog) == -1) ?
	EXIT_FAILURE : socket_descriptor;
    }
  }
}
