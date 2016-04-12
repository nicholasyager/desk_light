#!/bin/bash

for LIGHT in `seq 0 2`; do
   ./desk_light.py $LIGHT $1 $2 $3 $4;
done
