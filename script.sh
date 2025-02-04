#!/bin/bash
#SBATCH --job-name=myjob
#SBATCH --partition=Centaurus
#SBATCH --time=01:00:00

./program 10
./program 100
./program 1000
./program 10000
./program 100000
./program 1000000
./program 10000000
./program 100000000
./program 1000000000
