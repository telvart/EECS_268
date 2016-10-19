#include "Test.h"

Test::Test(std::ostream& os) : os(os)
{
}


void Test::redirectOS()
{
	os_rdbuf = os.rdbuf(ss_redirect.rdbuf());
}


void Test::restoreOS()
{
	os.rdbuf(os_rdbuf);
}

void Test::loadStack(Stack<int>& s, const std::vector<int>& nums)
{
	for (std::size_t i = 0; i < nums.size(); i++)
		s.push(nums[i]);
}

void Test::runTests()
{
	int score = 0;


	std::cerr << "===============" << std::endl;
	std::cerr << "Running Tests" << std::endl;
	std::cerr << "==============="<< std::endl;

	score += test1() ? 30 : 0;
	score += test2() ? 30 : 0;
	score += test3() ? 5 : 0;
	score += test4() ? 15 : 0;
	score += test5() ? 20 : 0;

	std::cerr << "===============" << std::endl;
	std::cerr << "Score: " << score << "/100" << std::endl;
	std::cerr << "NOTES:" << std::endl;
	std::cerr << "\t*Each question is graded on a 100 point scale!" << std::endl;
	std::cerr << "\t*The remaining 10pts is a check for memory leaks (just leaks, not errors)" << std::endl;	
	std::cerr << "\t*The test suite on the actual exam will provide more verbose output" << std::endl;
	std::cerr << "==============="<< std::endl;
}

bool Test::test1()
{
	// test 1 
	Stack<int> s1;
	std::vector<int> t1 = {2, 8, 3, 5, 6};
	loadStack(s1, t1);
	s1.popUntil(8);
	std::vector<int> r1;

	std::cerr << "Test 1: pop until on a populated stack : ";
	while (!s1.isEmpty())
	{
		r1.push_back(s1.peek());
		s1.pop();
	}

	bool PASS = (r1.size()==2) && (r1[0]==8) && (r1[1]==2);

	if (PASS) std::cout << "PASS\n";
	else std::cout << "FAILED\n";

	return(PASS);
}

bool Test::test2()
{
	Stack<int> s2;
	std::vector<int> t2 = {2, 8, 3, 5, 6};
	loadStack(s2, t2);
	s2.popUntil(99);
	std::vector<int> r2;

	std::cerr << "Test 2: pop until when value not in stack : ";
	while (!s2.isEmpty())
	{
		r2.push_back(s2.peek());
		s2.pop();
	}

	bool PASS = (r2.size()==0);

	if (PASS) std::cout << "PASS\n";
	else std::cout << "FAILED\n";

	return(PASS);
}

bool Test::test3()
{
	Stack<int> s;

	std::cerr << "Test 3: pop until on empty stack : ";
	s.popUntil(99);
	bool PASS = (s.size()==0);

	if (PASS) std::cout << "PASS\n";
	else std::cout << "FAILED\n";

	return(PASS);
}

bool Test::test4()
{
	Stack<int> s;

	std::cout << "Test 4: printStack an empty list : ";

	// this test only tries to trigger a seg fault

    	redirectOS();
	ss_redirect.clear();
	s.printStack();
	restoreOS();

	std::cout << "PASS" << std::endl;

	return true;
}


bool Test::test5()
{
	Stack<int> s;
	bool printResult = true;	


	std::cout << "Test 5: printStack on populated stack : ";
	
	s.push(3);	
	s.push(2);
	
	redirectOS();
	ss_redirect.clear();
	s.printStack();
	restoreOS();
	
	for(int i = 2; i <= 3; ++i){
		int num;
		ss_redirect >> num;
		if( num != i)
			printResult = false;
	}
	
	//Check to make sure a print leaves the stack in a valid state.
	//Or in other words, can we still use the stack after printing?
	s.push(1);
	s.push(0);

	redirectOS();
	ss_redirect.clear();
	s.printStack();
	restoreOS();

	for(int i = 0; i <= 3; ++i){
		int num;
		ss_redirect >> num;
		if( num != i)
			printResult = false;
	}


	if(printResult)
		std::cout << "PASS" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	return printResult;
}
