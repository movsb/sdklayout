#!/bin/sh
echo Start cloning tinyxml2...
git clone https://github.com/leethomason/tinyxml2.git
cp tinyxml2/tinyxml2.cpp .
cp tinyxml2/tinyxml2.h .
rm -rf tinyxml2/
