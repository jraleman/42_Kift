#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    build.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/18 18:10:25 by jaleman           #+#    #+#              #
#    Updated: 2017/06/18 18:10:26 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

brew update &&
brew install sox &&
brew install node &&
brew tap watsonbox/cmu-sphinx &&
brew install --HEAD watsonbox/cmu-sphinx/cmu-sphinxbase &&
brew install --HEAD watsonbox/cmu-sphinx/cmu-pocketsphinx &&
npm install --prefix kift-client electron --save &&
npm install --prefix kift-client node-record-lpcm16 --save &&
npm install --prefix kift-client electron-packager --save &&
make &&
npm run --prefix kift-client build &&
mv kift-client/release-builds/Kevin\ Kift-darwin-x64/ ./
