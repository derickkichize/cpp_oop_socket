#pragma once
#include <netinet/in.h>
#include <sys/socket.h>
#include "SocketContract.hh"
#include "Binder.hh"
#include "Listener.hh"

namespace NET {
  namespace Sockets {
    class Socket: public SocketContract  {
    private:
      int socket_descriptor;
      int socket_domain;
      int socket_type;
      int socket_protocol;
      int create (void);
    public:
      void    startListen (int listen_port, std::string listen_target, uint32_t backlog);
      Socket  (int domain, int type, int protocol);
      ~Socket (void) override;
    };
  }
}
