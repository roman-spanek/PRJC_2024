#pragma once
#include <iostream>
#include <string>
#include <vector>

class itype {
public:
	virtual std::string get_type() = 0;
};
class password_type : public itype {
public:
	virtual std::string get_type();
};
class text_type : public itype {
public:
	virtual std::string get_type();
};
class hidden_type : public itype {
public:
	virtual std::string get_type();
};

class input_atr {
public:
	virtual std::string  get_value() = 0;
};

class value_atr : public input_atr {
	std::string value;
public:
	value_atr(std::string _value);
	virtual std::string get_value();
};

class class_atr : public input_atr {
	std::string value;
public:
	class_atr(std::string _value);
	virtual std::string get_value();
};

class height_atr : public input_atr {
	int value;
public:
	height_atr(int _value);
	virtual std::string get_value();
};

class weight_atr : public input_atr {
	int value;
public:
	weight_atr(int _value);
	virtual std::string get_value();
};

class input_classic {
	std::vector<input_atr*> atrs;
	itype* type;
public:
	input_classic(itype* _type);
	std::string get_html();
	void add_atribute(input_atr* atr);
	~input_classic();
};


bool test();