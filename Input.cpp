#include "input.h"

std::string password_type::get_type() {
	return "type=\"password\"";
}

std::string text_type::get_type() {
	return "type=\"text\"";
}

std::string hidden_type::get_type() {
	return "type=\"hidden\"";
}

value_atr::value_atr(std::string _value) :value(_value) { ; }
std::string value_atr::get_value() {
	return "value=";
}

class_atr::class_atr(std::string _value) :value(_value) { ; }

std::string class_atr::get_value() {
	return "class=\""+value+ "\"";
}

height_atr::height_atr(int _value) :value(_value) { ; }
std::string height_atr::get_value() {
	return "height=" + std::to_string(value);
}


weight_atr::weight_atr(int _value) :value(_value) { ; }
std::string weight_atr::get_value() {
	return "weigth=" + std::to_string(value);
}


input_classic::input_classic(itype* _type) : type(_type) { ;  }

std::string input_classic::get_html() {
	std::string complete_input = "<input " + type->get_type();
	for (input_atr * atribute: atrs) {
		complete_input.append( " " + atribute->get_value());
	}
	return complete_input.append(" />\n");
}

void input_classic::add_atribute(input_atr* atr) {
	atrs.push_back(atr);
}

input_classic::~input_classic() {
	std::cout << std::endl << "clearing atributes" << std::endl;
	for (input_atr* atribute : atrs) {			
		delete atribute;
	}
	delete type;
}

bool test() {
	bool passed = true;
	//test full
	input_classic i1(new password_type());
	i1.add_atribute(new class_atr("red"));
	i1.add_atribute(new weight_atr(10));
	i1.add_atribute(new height_atr(20));
	i1.add_atribute(new value_atr("test"));
	std::string tmp = i1.get_html();
	std::string expected = "<input type = \"password\" class=\"red\" weigth=10 height=20 value=\"test\" />\n";
	if (tmp.compare(expected) != 0) {
		std::cout << "test full input failed, expected: [" + expected + "]  but got : " + tmp;
		passed = false;
	}
	//text_type test
	input_classic i2(new text_type());
	tmp = i2.get_html();
	expected = "<input type=\"text\" />\n";
	if (tmp.compare(expected) != 0) {
		std::cout << "test type text input failed, expected: [" + expected + "]  but got : " + tmp;
		passed = false;
	}
	return passed;
}