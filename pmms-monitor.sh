#!/bin/bash

gcc -o pmms pmms.c && ./pmms &
PARENT_PID=$!
echo "Started PMMS with PID $PARENT_PID"

running=true
while $running; do
    echo "
[1] View Status
[2] Pause/Resume Process
[3] Kill Process
[4] Kill All
[5] View Log
[6] Exit"

    read -p ">> " choice

    if ! ps -p $PARENT_PID > /dev/null; then
        echo "PMMS has terminated"
        exit
    fi

    case $choice in
        1) ps -f | grep -E "PID|$PARENT_PID" ;;
        2) read -p "PID: " pid && kill -SIGUSR1 $pid ;;
        3) read -p "PID: " pid && kill -SIGTERM $pid ;;
        4) kill -SIGINT $PARENT_PID && exit ;;
        5) [ -f "pmms.log" ] && tail pmms.log || echo "No log file" ;;
        6) kill -SIGINT $PARENT_PID && running=false ;;
        *) echo "Invalid choice" ;;
    esac
done
