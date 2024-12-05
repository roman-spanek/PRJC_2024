#include "chain_of_atributes.h"

input_atr_chain::input_atr_chain() : next(nullptr) { ; }

void input_atr_chain::get_value(std::string& input) {
	modify_atr(input);
	if (next != nullptr) { next->get_value(input); }
	else return;
};
void input_atr_chain::set_next(input_atr_chain* _next) {
	this->next = _next;
}
input_atr_chain* input_atr_chain::get_next() {
	return this->next;
}

value_atr_chain::value_atr_chain(std::string _value) : value(_value) {}
void value_atr_chain::modify_atr(std::string& input) {
	input.append(" value=\"" + value + "\" " );
}
class_atr_chain::class_atr_chain(std::string _value) : value(_value) {}
void class_atr_chain::modify_atr(std::string& input) {
	input.append(" class=\"" + value + "\" ");
}

input_chain::input_chain(input_atr_chain* _atr) : atr(_atr){ ; }

std::string input_chain::get_html() {
	atr->get_value(this->html_value);
	return this->html_value + "/>";
}

void input_chain::delete_me(input_atr_chain* atr) {
	if (atr == nullptr) {
		return; // Base case: reached the end of the list
	}
	delete_me(atr->get_next());
	std::cout << "Deleting atr {" << atr << "}" << std::endl;
	delete atr;
}

input_chain::~input_chain() {
	std::cout << std::endl << "clearing atributes" << std::endl;
	delete_me(atr);
}

bool test_chain() {
	bool passed = true;
	//test full
	value_atr_chain* t1 = new value_atr_chain("test value");
	class_atr_chain* t2 = new class_atr_chain("RED");
	t1->set_next(t2);
	input_chain i1(t1);
	std::string tmp = i1.get_html();
	std::string expected = "<input value=\"test value\"  class=\"RED\"/>";
	if (tmp.compare(expected) != 0) {
		std::cout << "test full input failed, expected: [" + expected + "]  but got : " + tmp;
		passed = false;
	}

	return passed;
}

