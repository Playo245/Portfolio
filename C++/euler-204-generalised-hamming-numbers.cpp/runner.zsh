#!/bin/bash

[[ -z $TASK ]] && [[ -f $PWD:t ]] && TASK=$PWD:t
[[ -z $TASK  ]] && [[ -f $PWD:h:t ]] && TASK=$PWD:h:t

set -e

show-exec-command g++ -o ${TASK%.cpp} $TASK

for i in 5,100000000 15,10000000 11,10000000 24,10000000 65,100000000 100,1000000000
do
  one=${i%,*};
  two=${i#*,};
  show-exec-command ./${TASK%.cpp} $one $two
done