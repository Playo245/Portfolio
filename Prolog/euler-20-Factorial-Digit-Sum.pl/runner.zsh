#!/bin/bash

[[ -z $TASK ]] && [[ -f $PWD:t ]] && TASK=$PWD:t
[[ -z $TASK  ]] && [[ -f $PWD:h:t ]] && TASK=$PWD:h:t

set -e

for i in 5 10 100
do
  show-exec-command swipl -s euler-20-Factorial-Digit-Sum.pl -- $i
done