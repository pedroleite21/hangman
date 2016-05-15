#!/bin/bash
make clean
make
cd src
../bin/hangman
make clean