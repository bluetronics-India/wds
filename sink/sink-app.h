/*
 * This file is part of Wireless Display Software for Linux OS
 *
 * Copyright (C) 2014 Intel Corporation.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef SINK_APP_H
#define SINK_APP_H

#include <memory>

#include "sink.h"
#include "connman-client.h"

class SinkApp: public P2P::Client::Observer, public P2P::Peer::Observer {
 public:
  SinkApp();
  SinkApp(const std::string& hostname, int port);
  ~SinkApp();

  Sink& sink() { return *sink_; }

  void on_peer_added(P2P::Client *client, std::shared_ptr<P2P::Peer> peer) override;
  void on_peer_removed(P2P::Client *client, std::shared_ptr<P2P::Peer> peer) override;
  void on_availability_changed(P2P::Client *client) override {};

  void on_availability_changed(P2P::Peer *peer) override;
  void on_initialized(P2P::Peer *peer) override {};

 private:
  std::unique_ptr<P2P::Client> p2p_client_;
  std::unique_ptr<Sink> sink_;
  P2P::Peer *peer_;
};

#endif // SINK_APP_H
