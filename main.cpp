/*
Name Javier Chavez
email jchavez589@cnm.edu
oct 31,2012
*/


#include <iostream>
#include <fstream>
#include "Timer.h"
#include <math.h>

//#include "hr_time.h"

using namespace std;


int main()
{
	//19048576
	Timer timer;

	const int TOTAL=19048576;
	const string mys = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n";
	streampos  begin = 0;
	streampos end = 0;
	const std::size_t buf_size = 32768;
	char my_buffer[buf_size];
	//CStopWatch s;
	ofstream out;
	
	out.open("test.txt");
	begin = out.tellp();
	//streampos mid[6];
	//s.startTimer();
	timer.start();
	out.rdbuf()->pubsetbuf(my_buffer, buf_size);
	for(unsigned i = 0; i<=TOTAL; i++)
	{
		//out.write(mys.c_str(), mys.length());
		//out << mys.c_str(); 
		//out << "11111111111111111111111111111111111111111111111111111111111111\n"; 
		out.write(mys.c_str(), mys.length());
		//out << "1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n"; 1.6gb


		//if(i == ceil(TOTAL*.12))
		//	mid[0] = (out.tellp() - begin)/1048576.00;

		//if(i == ceil(TOTAL*.25))
		//	mid[1] = (out.tellp() - begin)/1048576.00;

		// if(i == ceil(TOTAL*.50)){
		// 	mid[2] = (out.tellp() - begin)/1048576.00;
		// 	cout << timer.getElapsedTime();			
		// }

		//if(i == ceil(TOTAL*.75))
		//	mid[3] = (out.tellp() - begin)/1048576.00;

		//if(i == ceil(TOTAL*.85))
		//	mid[4] = (out.tellp() - begin)/1048576.00;

		//if(i == ceil(TOTAL*.99))
		//	mid[5] = (out.tellp() - begin)/1048576.00;
	}	
	//s.stopTimer();
	timer.stop();
	end = out.tellp();
	out.close();


	// bytes to 
	// kb 1024
	// mb 1048576

	cout.unsetf(ios::floatfield);  
	cout.precision(8);
	cout << "Elapsed time: " << timer.getElapsedTime()  << "s\tFile Size: " << (end-begin)/1048576.00 << "mb\n\n\n\n";

	long double speed = ((end-begin)/1048576)/timer.getElapsedTime();
	
	cout << "Write speed: " << speed << "mb/sec\n\n";

	cout << "\n\n\n" << mys.length();

	// for(int i = 0; i<6; i++){

	// 	cout << mid[i] << " - mark: " << i << "\n\n";
	// }
	return 0;
}