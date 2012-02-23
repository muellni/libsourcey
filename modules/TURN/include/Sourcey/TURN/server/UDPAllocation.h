//
// This software is copyright by Sourcey <mail@sourcey.com> and is distributed under a dual license:
// Copyright (C) 2002 Sourcey
//
// Non-Commercial Use:
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 
// Commercial Use:
// Please contact mail@sourcey.com
//


#ifndef SOURCEY_TURN_SERVER_UDPAllocation_H
#define SOURCEY_TURN_SERVER_UDPAllocation_H


#include "Sourcey/TURN/server/ServerAllocation.h"
#include "Sourcey/Net/UDPSocket.h"


namespace Sourcey {
namespace TURN {


class Server;
class IConnection;


class UDPAllocation: public ServerAllocation
{
public:
	UDPAllocation(
		Server& server,
		const FiveTuple& tuple, 
		const std::string& username, 
		const UInt32& lifetime);
	virtual ~UDPAllocation();

	void onPacketReceived(void* sender, DataPacket& packet);
		
	bool handleRequest(const Request& request);	
	void handleSendIndication(const Request& request);

	int send(const char* data, int size, const Net::Address& peerAddress);
	
	Net::Address relayedAddress() const;

private:
	Net::UDPSocket _relaySocket;
};


} } //  namespace Sourcey::TURN


#endif // SOURCEY_TURN_SERVER_UDPAllocation_H