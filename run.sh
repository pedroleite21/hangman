#!/bin/bash
make clean
make
cd src
../bin/hangman
cd ..
make clean