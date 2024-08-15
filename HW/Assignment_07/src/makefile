all: clean compile run

compile: test.java
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@javac test.java
	
run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	java test
	@echo "================================================================================="
	@echo "Completed tests...."
	
clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.class
