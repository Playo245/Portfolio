#!/bin/bash

[[ -z $TASK ]] && [[ -f $PWD:t ]] && TASK=$PWD:t
[[ -z $TASK  ]] && [[ -f $PWD:h:t ]] && TASK=$PWD:h:t

set -e

for i in 5,10000000d 5two,100000000 44, "",""
do
    one=${i%,*};
    two=${i#*,};
    show-exec-command runghc $TASK $one $two
done