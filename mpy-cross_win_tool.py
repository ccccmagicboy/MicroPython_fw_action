import fileinput
import sys

def replaceAll(file,searchExp,replaceExp):
    for line in fileinput.input(file, inplace=1):
        if searchExp in line:
            line = line.replace(searchExp,replaceExp)
        sys.stdout.write(line)
        
import os
print(os.environ['PATH'])
print(os.getcwd())
mk_path = os.path.join(os.getcwd(), 'my_micropython', 'mpy-cross', 'Makefile')
print(mk_path)
replaceAll(mk_path, "PROG = mpy-cross","PROG = mpy-cross.exe")
print("ok finished!")


