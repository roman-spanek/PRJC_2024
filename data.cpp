#include "data.h"

data::data(int _id, long _timestamp) : id(_id), timestamp(_timestamp) { ; }

data::data(int _id, long _timestamp, std::initializer_list<double*> _values) : data(_id, _timestamp) {
	for (auto* val : _values) {
		values.push_back(val);
	}		
}
int data::get_id() const {
	return id;
}
long data::get_timestamp() const {
	return timestamp;
}
std::vector<double*> data::get_values() const {
	return values;
}

double data::operator[] (const int index) const {
	if (index < 0) throw std::invalid_argument("index cannot be nagative...");
	if (index > values.size()) throw std::invalid_argument("index cannot be over " + values.size());

	return *values[index];
}