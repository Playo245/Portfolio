#!/bin/bash

[[ -z $TASK ]] && [[ -f $PWD:t ]] && TASK=$PWD:t
[[ -z $TASK  ]] && [[ -f $PWD:h:t ]] && TASK=$PWD:h:t

set -e

for i in 5 10 50
do
  show-exec-command runghc $TASK $i
done