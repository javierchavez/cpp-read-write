#Very Fast Write in C++
Currently testing for write speeds

iterated through 19048576 times (4GB file produced)

	//My string
	const string mys = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111\n";
	
	//buffer
	const std::size_t buf_size = 32768;
	char my_buffer[buf_size];
	
	out.rdbuf()->pubsetbuf(my_buffer, buf_size);

###First off Windows

stream:

	out.write(mys.c_str(), mys.length()); 

Write speed: 48.211772mb/sec 
Write speed: 62.732423mb/sec (increased buffer size)

stream:
	
	out << mys.c_str(); 

Write speed: 46.67032mb/sec
Write speed: 42.0012mb/sec

stream:

			//out << "11111111111111111111111111111111111111111111111111111111111111\n"; 

Write speed: 50.406844mb/sec (increased buffer size)

### Next Mac

stream:
	
		out.write(mys.c_str(), mys.length());

Write speed: 194.81867mb/sec Unix with buffer

fastest Write speed: 237.17066mb/sec

**ALSO** switched to Macbook air 2012 i7 2.0ghz

Elapsed time: 10.100016s	File Size: 3506.0648mb

Write speed: 347.12816mb/sec

***32% write speed inscrease!***


more to come...