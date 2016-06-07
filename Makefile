all:
	g++ -std=c++11 main.cpp bitcask.cpp -lboost_serialization -lboost_date_time
