.DEFAULT_GOAL := help

help:
	@echo "Type: make [rule]. Available options are:"
	@echo ""
	@echo "- help"
	@echo "- build"
	@echo "- run"
	@echo "- format"
	@echo ""
	@echo "Individual samples:"
	@echo "- run-01-simple"
	@echo "- run-02-fluentcpp"
	@echo ""

build:
	rm -rf out
	mkdir -p out
	cd out && \
		cmake ../ && \
		cmake --build . --config Release

run:
	@echo "> Running all samples..."
	@-make run-01-simple
	@-make run-02-fluentcpp

format:
	clang-format -style file -i 01-simple/src/main.cpp
	clang-format -style file -i 02-fluentcpp/src/main.cpp

run-01-simple:
	@echo "> Running 01-simple..."
	cd out/01-simple/ && time ./01-simple

run-02-fluentcpp:
	@echo "> Running 02-fluentcpp..."
	cd out/02-fluentcpp/ && time ./02-fluentcpp