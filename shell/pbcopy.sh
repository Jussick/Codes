#!/bin/bash

set -euo pipefail

t=$(cat <&0 | base64 --wrap=0)
if [ ! -z ${STY+x} ]; then
    echo -ne "\eP\e]52;c;$t\a\e\\"
elif [ ! -z ${TMUX+x} ]; then
    echo -ne "\ePtmux;\e\e]52;c;$t\a\e\\"
else
    echo -ne "\e]52;c;$t\a"
fi
