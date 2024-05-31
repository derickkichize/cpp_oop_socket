#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "Socket.hh"

namespace NET {
  namespace Sockets {
    Socket::Socket (int domain, int type, int protocol)
      :socket_domain   (domain),
       socket_type     (type),
       socket_protocol (protocol)
    {
      if (create () == -1)
	{
	  std::cerr << "Failed to create socket" << std::endl;
	  std::exit (EXIT_FAILURE);
	}
    }

    void
    Socket::startListen (int listen_port, std::string listen_target, uint32_t backlog)
    {
      Sockets::Binder   socketBind   (socket_domain, listen_port, listen_target);
      Sockets::Listener socketListen (backlog);
	
      if (socketBind.bind_socket     (socket_descriptor) == EXIT_FAILURE)
	{
	  std::cerr << "Failed to bind socket" << std::endl;
	  std::exit (EXIT_FAILURE);
	}
	
      if (socketListen.listen_socket (socket_descriptor) == EXIT_FAILURE)
	{
	  std::cerr << "Failed to listen on socket" << std::endl;
	  std::exit (EXIT_FAILURE);
	}
	
      std::cout << "Server started to listen on port " << listen_port << std::endl;
    }
  
    int
    Socket::create (void)
    {
      socket_descriptor = socket(socket_domain, socket_type, socket_protocol);
      return (socket_descriptor == -1) ? EXIT_FAILURE : socket_descriptor;
    }

    Socket::~Socket (void)
    {
      close (socket_descriptor);
      std::cout << "Closing socket." << std::endl;
    }
  }
}
