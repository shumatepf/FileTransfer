#!/usr/bin/env python

import subprocess
import time

folder = "/home/peter/Documents/FileTransfer/SRC"
command_to_run = "make clean && make && ./ftransfer"

def get_drlist():
	return subprocess.check_output(["ls", folder]).decode('utf-8').strip().split("\n")

while True:
	drlist = get_drlist()
	print(drlist)
	time.sleep(2)
	if len(drlist) > 1:
		subprocess.Popen(["/bin/bash", "-c",command_to_run])
