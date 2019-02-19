# Overview
This program is a tool to automatically sort files from a source folder into designated folders.

## Set up
The directories currently in the `mydirectories.h` header should be changed to match desired directories.

Compile with `make` and clean with `make clean`.

## How to use
Save files with suffixes that match suffixes in the `mydirectories.h` header. Suffixes must begin with a hyphen in order
to be properly read.

There must be 5 directories. If unused, change the suffix to "-null" and the path to an empty string.

Files must be saved to the designated source folder. Run the program and files will be sorted to corresponding folders based
on their suffixes.
