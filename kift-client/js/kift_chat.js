// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   kift_chat.js                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/06/18 02:47:07 by jaleman           #+#    #+#             //
//   Updated: 2017/06/18 02:47:08 by jaleman          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// Put a message into the chat.
function putMessage(name, image, message) {
    var targetElement = document.getElementById("showMessage");
    var newElement = document.createElement('span');
    newElement.innerHTML = '<div class="' + name + '"><img src="' +
        image + '" width=32 height=32 /><div class="message"><p>' +
        message + '</p></div></div>';
    targetElement.appendChild(newElement);
}

// Copies the functionality of the sleep() function
function sleep(ms) {
    var unixtime_ms = new Date().getTime();
    while (new Date().getTime() < unixtime_ms + ms) {}
}

// Parse the data into the chat.
function parseChat(data) {
    var userMessage = data[0];
    var kevinMessage = data[1];

    if (kevinMessage == "name missing\n")
        return;
    putMessage("user", "images/avatar.png", userMessage);
    putMessage("kevin", "images/logo-icon.png", kevinMessage);
    responseVoice(kevinMessage);
    //sleep(2000);
	    //startRecord();
}
