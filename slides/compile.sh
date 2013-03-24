#!/bin/bash

if [[ ! "$VIRTUAL_ENV" ]]; then
    source $HOME/.virtualenvs/slides/bin/activate
fi

landslide "$@"
