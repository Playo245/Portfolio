#!/bin/bash

[[ -z $TASK ]] && [[ -f $PWD:t ]] && TASK=$PWD:t
[[ -z $TASK  ]] && [[ -f $PWD:h:t ]] && TASK=$PWD:h:t

set -e

for i in 3,5 7,11 2,43 9,78 6,223 7,785
do
  one=${i%,*};
  two=${i#*,};
  show-exec-command swipl -s euler-120-square-remainders.pl -- $one $two
done