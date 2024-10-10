#!/bin/bash

if [ $# -ne 2 ]; then
    echo "$# argument(s) provided."
    echo "Provide the file directory and search string as two command line arguments."
    exit 1
fi

filesdir=$1
searchstr=$2

if [ -d $filesdir ]; then
    Y=$(grep -ro $searchstr $filesdir | wc -l)
    X=$(find $filesdir -type f | wc -l)
    echo "The number of files are $X and the number of matching lines are $Y"
else
    echo "enter valid filesdir"
    exit 1
fi
