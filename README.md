# Overview
This program is a tool to automatically sort files from a source folder into designated folders.

## Set up
The directories currently in the `mydirectories.h` header should be changed to match desired directories.

Compile with `make` and clean with `make clean`.

## How to use
Save files with suffixes that match suffixes in the `mydirectories.h` header. Suffixes must begin with a hyphen in order
to be properly read.

There must be 5 directories. If unused, change the suffix to `-NULL` and the path to an empty string.

Files must be saved to the designated source folder. Run the program and files will be sorted to corresponding folders based on their suffixes.

## Running in the background
The file `watch.py` can be executed to check for new files every 10 seconds and
can be ran in the background. This requires python to be installed. I am not
sure which version is required but I reccomend the most recent version as I am
using 3.7.

To run on startup, add `python3.7 path/to/file/watch.py` to your startup thing
you have going on for your system.

For example, I am using i3wm and i have `exec_always
python3.7/home/peter/Documents/FileTransfer/watch.py` in my i3 config file.


