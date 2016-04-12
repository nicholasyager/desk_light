#!/bin/bash

for LIGHT in `seq 0 2`; do
   ./desk_light.py $LIGHT 255 0 0;
done
./desk_light.py 0 255 0 0 alarm;
