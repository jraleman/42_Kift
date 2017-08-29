// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   kift_client.js                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/06/15 02:11:03 by jaleman           #+#    #+#             //
//   Updated: 2017/06/15 02:11:04 by jaleman          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// Module declarations.
var net = require('net');
var globalStatus = true;

// Define port number, ip address, and timeout.
var PORT = 8080;
var HOST = '127.0.0.1';
var TIMEOUT = 1000;

// Creates a new socket.
var client = new net.Socket();

// Logs the ip address and port number when there's a connection.
client.connect(PORT, HOST, function() {
    console.log('Connected to: ' + HOST + ':' + PORT);
    startRecord();
});

// If there's an error, retry connecting back to the server every few seconds,
// defined by TIMEOUT.
client.on('error', function(e) {
    if (e.code == 'ECONNREFUSED') {
        console.log('Is the server running at port ' + PORT + '?');
        client.setTimeout(TIMEOUT, function() {
            client.connect(PORT, HOST, function() {
                console.log('Connected to: ' + HOST + ':' + PORT);
            });
        });
        console.log('Trying again in ' + (TIMEOUT / 1000) + ' seconds...');
    }
});

// Gets the data received from the server.
client.on('data', function(data) {
    parseChat(String(data).split(";"));
    startRecord();
});

// Shows a message when the connection is closed.
client.on('close', function() {
    console.log('Connetion ded x_x');
});
