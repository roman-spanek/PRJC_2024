#include "invoker.h"

void handler::process(const data& _data) {
	std::cout << " default handler - just printing values..." << std::endl;
    for (double * val : _data.get_values()) {
        std::cout << "value: " << *val << std::endl;
    }
}

void avg_handler::process(const data& _data) {
	std::cout << " computing mean of values ..." << std::endl;
    for (double* val : _data.get_values()) {
        std::cout << "value: " << *val << std::endl;
    }
}


void invoker::add_handler(int id, handler* _handler) {

    if (handlers.find(id) != handlers.end()) {
        std::stringstream output;
        output << " Handler for key " << id << " already exists " << std::endl;;
        std::cout << output.str();
    }
    handlers[id] = _handler;

}
void invoker::invoke_handler(const data& _data) {
    if (handlers.find(_data.get_id()) == handlers.end()) {
        throw std::invalid_argument("Handler for key " + std::to_string(_data.get_id()) + " does not exist \n");
    }
    handlers[_data.get_id()]->process(_data);
}