all:
	g++-7 -std=c++11 -O3 fm_train.cpp src/Frame/pc_frame.cpp src/Utils/utils.cpp -I . -std=c++11 -o bin/fm_train -lpthread
	g++-7 -std=c++11 -O3 fm_predict.cpp src/Frame/pc_frame.cpp src/Utils/utils.cpp -I . -std=c++11 -o bin/fm_predict -lpthread
	g++-7 -std=c++11 -O3 model_bin_tool.cpp src/Utils/utils.cpp -I . -std=c++11 -o bin/model_bin_tool
