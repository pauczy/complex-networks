#!/bin/bash
#uruchamianie skryptu liczącego średnią odległość dla sieci o różnych rozmiarach
#wyniki zapisane do pliku male_swiaty.txt

for i in 100 200 500 1000 2000 5000 10000 20000 50000
do
  root -q -b -l "male_swiaty.C($i)" > male_swiaty.log
done
