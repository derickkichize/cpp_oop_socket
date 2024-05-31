#include "TCPSocket.hh"
#include "../Domain.hh"
#include "../Type.hh"
#include "../Protocol.hh"

namespace NET {
  namespace Sockets {
    TCPSocket::TCPSocket (void)
      : Socket
	(NET::Domain::INET, NET::Type::STREAM, NET::Proto::TCP) {}
    
    void
    TCPSocket::startListen  (int listen_port,
			     std::string listen_target,
			     uint32_t backlog)
    {
      Socket::startListen (listen_port, listen_target, backlog);
    }
  }
}
