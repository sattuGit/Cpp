pooC++ Compiler 
-----------------------------------
gcc --> C language compiler 
g++ --> C++ Language Compiler 
-----------------------------------
Steps:
Preprocessing :
	INPUT C/C++ user writen source code 
	* Remove COmments 
	* Include files into single source code 
	* Resolve Preprocess directive 
	OUTPUT 	:	Resolved C/C++ extended code 
	Command	:  	gcc -E {-l outPutFileName.l} filename.c
Compiling 
	INPUT : preprocessed source code 
	* Convert code into assembly language 
	OUTPUT : Object code (*.o in linux) 
	command: gcc -S {-o asssembly.asm} fileName.c   NOTE : default output is fileName.s
Linking :
	* link all object files and library and make single executable 
		* May use dynamic linking or stataic linking OR Compile time or RunTime binding 
	