#!/bin/bash

PROJECT_FOLDER="."
SOURCE_FOLDER="$PROJECT_FOLDER"
DEST_FOLDER="$PROJECT_FOLDER"
FILES="$SOURCE_FOLDER/*.java"
EXEC_FILE=$(basename -- $1 .${1#*.})

if [ ! -d "$DEST_FOLDER" ]
then
    echo "[INFO]mkdir bin folder"
    eval mkdir -p "$DEST_FOLDER"
fi

eval cd $PROJECT_FOLDER
eval javac -cp $SOURCE_FOLDER -d $DEST_FOLDER $FILES
eval cd $DEST_FOLDER
eval java $EXEC_FILE
