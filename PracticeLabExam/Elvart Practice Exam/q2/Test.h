#include <vector>
#include <iostream>
#include <sstream>
#include "Stack.h"

class Test
{

public:
	Test(std::ostream& os);
	void runTests();

private:

	bool test1();
	bool test2();
	bool test3();
	bool test4();
	bool test5();

	void testPopUntil();
	void loadStack(Stack<int>& s, const std::vector<int>& nums);

	inline void redirectOS();
	inline void restoreOS();

	std::ostream& os;
	std::stringstream ss_redirect;
	std::streambuf* os_rdbuf;


};
