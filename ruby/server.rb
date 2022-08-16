#!/usr/bin/env ruby

require 'socket'

server = TCPServer.new('localhost', 3000)
client = server.accept
client.write('Hello!\r\n')
