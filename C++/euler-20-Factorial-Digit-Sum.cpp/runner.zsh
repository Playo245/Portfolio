#!/bin/bash

[[ -z $TASK ]] && [[ -f $PWD:t ]] && TASK=$PWD:t
[[ -z $TASK  ]] && [[ -f $PWD:h:t ]] && TASK=$PWD:h:t

set -e

show-exec-command g++ -o ${TASK%.cpp} $TASK

for v in 5 45 93 100
do
  show-exec-command ./${TASK%.cpp} $v
done