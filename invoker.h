#pragma once
#include "data.h"
#include <map>
#include <iostream>
#include <string>
#include <sstream>

class handler {
public:
	virtual void process(const data& _data);
};
class avg_handler : public handler {
public:
	virtual void process(const data& _data);
};


class invoker {
	std::map<int, handler *> handlers;
public:
	void add_handler(int id, handler* _handler);
	void invoke_handler(const data& _data);
};