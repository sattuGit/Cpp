CC=g++
FLAG=-g
FLAG+= -std=gnu++11
TARGET= lambada
OBJECTS= 1_simpleVectorElementProcess.cpp
OOBJECTS+= 2_DoingSamleOpertionUsingFunction.cpp  
OOBJECTS+= 3_replaceFunctionWith_lambda_function.cpp
OOBJECTS+= 4_Yes_we_can_give_name_lembda_fun.cpp
OOBJECTS+= 5_lembada_usingCaptureClause.cpp
all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) -o 1_simpleVectorElementProcess 1_simpleVectorElementProcess.cpp 
	$(CC) -o 2_DoingSamleOpertionUsingFunction 2_DoingSamleOpertionUsingFunction.cpp 
	$(CC) -o 3_replaceFunctionWith_lambda_function 3_replaceFunctionWith_lambda_function.cpp 
	$(CC) -o 4_Yes_we_can_give_name_lembda_fun 4_Yes_we_can_give_name_lembda_fun.cpp 
	$(CC) -o 5_lembada_usingCaptureClause 5_lembada_usingCaptureClause.cpp 
.PHONY: clean
clean:
	rm -f  1_simpleVectorElementProcess 2_DoingSamleOpertionUsingFunction 3_replaceFunctionWith_lambda_function 4_Yes_we_can_give_name_lembda_fun  5_lembada_usingCaptureClause
