/*  NewNet - A networking framework in C++
    Copyright (C) 2006-2007 Ingmar K. Steen (iksteen@gmail.com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 */

#include "nnunixclientsocket.h"
#include "nnlog.h"
#include "platform.h"
#include <iostream>

void
NewNet::UnixClientSocket::connect(const std::string & path)
{
  // TODO: Make the UnixClientSocket class a bit more functional
  assert((descriptor() == -1) || (socketState() == SocketUninitialized));

  setSocketState(SocketConnecting);

  if(path.length() >= UNIX_PATH_MAX)
  {
    NNLOG("newnet.net.warn", "Unix socket path too long: '%s'.", path.c_str());
    setSocketError(ErrorInvalidPath);
    cannotConnectEvent(this);
    return;
  }

  struct sockaddr_un address;
  memset(&address, 0, sizeof(address));
  address.sun_family = AF_UNIX;
  memcpy(address.sun_path, path.c_str(), path.length()+1);

  NNLOG("newnet.net.debug", "Connecting to unix socket '%s'.", path.c_str());

  int sock = socket(PF_UNIX, SOCK_STREAM, 0);
  fcntl(sock, F_SETFL, O_NONBLOCK);
  setDescriptor(sock);

  if(::connect(sock, (struct sockaddr *)&address, sizeof(struct sockaddr_un)) == 0)
  {
    NNLOG("newnet.net.debug", "Connected to unix socket '%s'.", path.c_str());
    setDescriptor(sock);
    setSocketState(SocketConnected);
    connectedEvent(this);
    return;
  }
  else if(errno != EINPROGRESS)
  {
    NNLOG("newnet.net.warn", "Cannot connect to unix socket '%s', error: %i.", path.c_str(), errno);
    closesocket(sock);
    setSocketError(ErrorCannotConnect);
    cannotConnectEvent(this);
    return;
  }
  setDescriptor(sock);
}
