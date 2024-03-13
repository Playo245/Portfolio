#!/bin/bash

[[ -z $TASK ]] && [[ -f $PWD:t ]] && TASK=$PWD:t
[[ -z $TASK  ]] && [[ -f $PWD:h:t ]] && TASK=$PWD:h:t

set -e

show-exec-command g++ -o ${TASK%.cpp} $TASK

for i in 5,10000000d 5two,100000000 44, "",""
do
  one=${i%,*};
  two=${i#*,};
  show-exec-command ./${TASK%.cpp} $one $two
done