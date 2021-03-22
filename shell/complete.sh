#!/bin/bash

function _foo() {
    local cur prev opts

    COMPREPLY=()

    cur="${COMP_WORDS[COMP_CWORD]}"
    prev="${COMP_WORDS[COMP_CWORD-1]}"
    opts="-h --help -f --file -o --output"

    if [[ ${cur} == -* ]] ; then
        COMPREPLY=( $(compgen -W "${opts}" -- ${cur}) )
        return 0
    fi
}

case "${prev}" in
    -f|--file)
        COMPREPLY=( $(compgen -o filenames -W "`ls *.sh`" -- ${cur}) )
        ;;
esac

_foo
