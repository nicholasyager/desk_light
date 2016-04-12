#!/bin/bash

COUNTER=0
while [  $COUNTER -lt 15 ]; do
  for LIGHT in `seq 0 2`; do
    ./desk_light.py $LIGHT $1 $2 $3 ;
  done
  sleep 0.2
  for LIGHT in `seq 0 2`; do
    ./desk_light.py $LIGHT 0 0 0;
  done
  let COUNTER=$COUNTER+1
done;
for LIGHT in `seq 0 2`; do
   ./desk_light.py $LIGHT $1 $2 $3  none;
done;
