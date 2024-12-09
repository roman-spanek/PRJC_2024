#include "invoker.h"
#include "data.h"


int main() {
	data d1(1, 1000l, { new double(10.23), new double(40.4), new double(34.5) });
	data d2(2, 1000l, { new double(1.23), new double(4.4), new double(3.5) });
	data d3(3, 1000l, { new double(1.23), new double(4.4), new double(3.5) });
	invoker in;
	handler default_handler;
	avg_handler avg_handler;

	in.add_handler(1, &default_handler);
	in.add_handler(2, &avg_handler);
	try {
		in.invoke_handler(d1);
		in.invoke_handler(d2);
		in.invoke_handler(d3);
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}