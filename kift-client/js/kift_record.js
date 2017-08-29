// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   kift_record.js                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/06/15 02:11:03 by jaleman           #+#    #+#             //
//   Updated: 2017/06/15 02:11:04 by jaleman          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// Module declarations.
var fs = require('fs');
var record = require('node-record-lpcm16');

// Filename of the record
var filename = "record.wav";

// Saves and sends a .wav file to the server.
function sendRecord() {
    stats = fs.statSync(filename).size;
    client.write(stats.toString());
    var readStream = fs.createReadStream(filename);
    readStream.pipe(client);
}

// Create an empty .wav file, starts recording audio.
function startRecord() {
    var file = fs.createWriteStream(filename, {
        encoding: 'binary'
    });
    record.start({
            sampleRate: 16000,
            verbose: true
        })
        .on('close', () => {
            sendRecord();
        })
        .pipe(file);
}
