#!/bin/sh

# Add any build steps you need here
./precompute.rb

g++ level0.cc -std=c++11
mv a.out level0
