#!/bin/bash

[[ -z $TASK ]] && [[ -f $PWD:t ]] && TASK=$PWD:t
[[ -z $TASK  ]] && [[ -f $PWD:h:t ]] && TASK=$PWD:h:t

set -e

show-exec-command g++ -o ${TASK%.cpp} $TASK

for v in 150 two3 ten ""
do
  show-exec-command ./${TASK%.cpp} $v
done