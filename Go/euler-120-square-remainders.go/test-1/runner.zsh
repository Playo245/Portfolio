#!/bin/bash

[[ -z $TASK ]] && [[ -f $PWD:t ]] && TASK=$PWD:t
[[ -z $TASK  ]] && [[ -f $PWD:h:t ]] && TASK=$PWD:h:t

set -e

for i in 2,9 16,56 3two,98 53,4two3 62, "",""
do
  one=${i%,*};
  two=${i#*,};
  show-exec-command go run $TASK $one $two
done