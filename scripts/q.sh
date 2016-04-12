#!/bin/bash

COUNTER=0
./desk_light.py 1 0 0 0 ;
while [  $COUNTER -lt 15 ]; do

    ./desk_light.py 0 255 0 0 ;
    ./desk_light.py 2 0 0 255 ;
    sleep 0.2
    ./desk_light.py 0 0 0 255 ;
    ./desk_light.py 2 255 0 0 ;
    sleep 0.2
    let COUNTER=$COUNTER+1
done;
for LIGHT in `seq 0 2`; do
   ./desk_light.py $LIGHT 0 0 0 none;
done;
