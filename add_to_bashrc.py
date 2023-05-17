#!/usr/bin/env python3

import os

if __name__ == "__main__":
	path = os.environ.get("HOME") + "/.bashrc"
	
    # Read lines from ~/.bashrc
	fd = open(path, "r")
	lines = fd.readlines()
	fd.close()
	
	# Remove trailing newlines.
	for i in range(len(lines)):
		s = lines[i]
		if s[-2:] == '\r\n':
			lines[i] = s[:-2]
		elif s[-1] == '\r' or s[-1] == '\n':
			lines[i] = s[:-1]
	
	# Remove any lines matching the VAR we will EXPORT.
	lines = [x for x in lines if not x.startswith("export BADGESDK_PATH=")]
	
	# Add the VAR EXPORT line.
	lines.append("export BADGESDK_PATH=" + os.getenv("BADGESDK_PATH"))
	
	# Write it back.
	fd = open(path, "w")
	for line in lines:
		fd.write(line)
		fd.write('\n')
	fd.flush()
	fd.close()