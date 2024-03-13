#!/bin/bash

[[ -z $TASK ]] && [[ -f $PWD:t ]] && TASK=$PWD:t
[[ -z $TASK  ]] && [[ -f $PWD:h:t ]] && TASK=$PWD:h:t

set -e

for i in 7,7 4,11 4,63 6,99 2,298 3,1000
do
  one=${i%,*};
  two=${i#*,};
  show-exec-command go run $TASK $one $two
done