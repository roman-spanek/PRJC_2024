#pragma once
#include <iostream>
#include <string>

class input_chain;

class input_atr_chain {
	input_atr_chain* next;
public:
	input_atr_chain();
	virtual void modify_atr(std::string& input) = 0;
	virtual void get_value(std::string& input);
	void set_next(input_atr_chain* _next);
	input_atr_chain* get_next();
};

class value_atr_chain : public input_atr_chain {
	std::string value;
public:
	value_atr_chain(std::string _value);
	virtual void modify_atr(std::string& input);
};

class class_atr_chain : public input_atr_chain {
	std::string value;
public:
	class_atr_chain(std::string _value);
	virtual void modify_atr(std::string& input);
};

class input_chain {
	std::string html_value = "<input";
	input_atr_chain* atr;
	void delete_me(input_atr_chain* atr);
public:
	input_chain(input_atr_chain* _atr);
	std::string get_html();

	~input_chain();
};

bool test_chain(void);