#!/usr/bin/env python

import subprocess
import time

folder = "/home/peter/Documents/FileTransfer/watch.py"
command_to_run = "make clean && make && ./ftransfer"

def get_drlist():
	return subprocess.check_output(["ls", folder]).decode('utf-8').strip().split("\n")

while True:
	drlist1 = get_drlist()
	time.sleep(2)
	drlist2 = get_drlist()
	if len(drlist2) > len(drlist1):
		subprocess.Popen(["/bin/bash", "-c",command_to_run])
