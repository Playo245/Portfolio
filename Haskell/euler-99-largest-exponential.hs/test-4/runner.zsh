#!/bin/bash

# The TASK environment  variable will be set automatically in the Einstein execution
# environment.
#
# For testing, try to set the TASK environment variable...
#
[ -z "$TASK" ] && [ -f "$PWD:t" ] && TASK="$PWD:t"
[ -z "$TASK" ] && [ -f "$PWD:h:t" ] && TASK="$PWD:h:t"

# Fail (exit) immediately if any of the following commands fail.

set -e

filename="numbers.txt"
filename2="numbers-2.txt"

show-exec-command runghc $TASK $filename $filename2