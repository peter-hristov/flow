all:
	clang++ -Wc++11-extensions -std=c++14 ./src/cpp/* -o ./bin/run

clang:
	clang++ -Wc++11-extensions -std=c++14 ./src/cpp/* -o ./bin/run

gcc:
	g++ -std=c++14 -fdiagnostics-color src/cpp/* -o bin/run

analyze:
	clang++ --analyze -Xanalyzer -analyzer-output=text -Wc++11-extensions -std=c++14 ./src/cpp/*

