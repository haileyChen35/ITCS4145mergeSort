#!/bin/bash
#SBATCH --job-name=haileyC
#SBATCH --partition=Centaurus
#SBATCH --time=01:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --mem=16G

./program 10
./program 100
./program 1000
./program 10000
./program 100000
./program 1000000
./program 10000000
./program 100000000
./program 1000000000
