#!/bin/bash

#rm -rf AppRTCMobile.xcodeproj && xcake make && pod install

rm -rf WebRTC/WebRTC.xcodeproj AppRTCMobile.xcodeproj && \
cd WebRTC && xcake make && cd .. && xcake make
