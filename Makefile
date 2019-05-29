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
	@echo ""

build:
	rm -rf out
	mkdir -p out
	cd out && \
		cmake ../ && \
		cmake --build . --config Release

run:
	@echo "> Running simple..."
	make br-01-simple

format:
	clang-format -style file -i 01-simple/src/main.cpp

run-01-simple:
	@echo "> Running 01-simple..."
	cd out/01-simple/ && time ./01-simple