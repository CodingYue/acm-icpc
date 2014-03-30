#!/bin/python
import os
import re
import pdb

def dfs(curdir) :
	print curdir
	for name in os.listdir(curdir) :
		fullname = curdir + '/' + name
		if re.match(r'.*dSYM', name) != None :
			#print curdir + name
			#os.system('rm -rf %s' %(curdir + name))
			continue
		if os.path.isdir(fullname) :
			dfs(fullname)
dfs(os.getcwd())
