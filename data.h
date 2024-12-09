#pragma once
#include "vector"
#include <stdexcept>

class data {
	int id;
	long timestamp;
	std::vector<double*> values;
public:
	data(int _id, long _timestamp);
	//lets use a method/constructor with variable number of parameters 
	data(int _id, long _timestamp, std::initializer_list<double*> values);

	int get_id() const;
	long get_timestamp() const;
	std::vector<double*> get_values() const;

	double operator[] (const int index) const;
};