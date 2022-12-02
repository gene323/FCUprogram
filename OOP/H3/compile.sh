#!/bin/bash

PROJECT_FOLDER="/home/gene/code/FCUprogram/OOP/H3"
SOURCE_FOLDER="$PROJECT_FOLDER/src"
DEST_FOLDER="$PROJECT_FOLDER/bin"

FILES="$SOURCE_FOLDER/*.*"
EXEC_FILE=$(basename -- $1 .${1#*.})

if [ ! -d "$DEST_FOLDER" ]; then
    eval mkdir "$DEST_FOLDER"
fi

eval cd $PROJECT_FOLDER
eval javac -cp $SOURCE_FOLDER -d $DEST_FOLDER $FILES
eval cd $DEST_FOLDER
eval java $EXEC_FILE
