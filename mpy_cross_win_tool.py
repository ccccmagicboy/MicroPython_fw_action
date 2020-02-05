import fileinput
import sys
import os

def replaceAll(file,searchExp,replaceExp):
    for line in fileinput.input(file, inplace=1):
        if searchExp in line:
            line = line.replace(searchExp,replaceExp)
        sys.stdout.write(line)
        
def main():
    print(os.environ['PATH'])
    print(os.getcwd())
    mk_path = os.path.join(os.getcwd(), 'my_micropython', 'mpy-cross', 'Makefile')
    print(mk_path)
    replaceAll(mk_path, "PROG = mpy-cross","PROG = mpy-cross.exe")
    print("ok finished!")
    
def get_ver():
    command = 'cd my_micropython\mpy-cross && mpy-cross.exe --version'
    print(command)
    result = os.popen(command).read()
    print(result)
    return result

if __name__ == "__main__":
    # execute only if run as a script
    main()

