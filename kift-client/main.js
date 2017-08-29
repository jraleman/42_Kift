// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.js                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/06/15 17:02:43 by jaleman           #+#    #+#             //
//   Updated: 2017/06/15 17:02:44 by jaleman          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

const url = require('url')
const path = require('path')
const {app, BrowserWindow} = require('electron')

let win

function createWindow() {
   win = new BrowserWindow({width: 560, height: 720})
   win.loadURL(url.format({
      pathname: path.join(__dirname, 'index.html'),
      protocol: 'file:',
      slashes: true
   }))
}

app.on('ready', createWindow)
