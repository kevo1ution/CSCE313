
#ifndef _FIFOreqchannel_H_
#define _FIFOreqchannel_H_

#include "common.h"
#include "RequestChannel.h"

class FIFORequestChannel : public RequestChannel
{	
private:
	/*  The current implementation uses named pipes. */
	int wfd;
	int rfd;
	
	string pipe1, pipe2;
	int open_pipe(string _pipe_name, int mode);

	
public:
	FIFORequestChannel(const string _name, const Side _side, int _bs);

	~FIFORequestChannel();

	char* cread(int *len=NULL);

	int cwrite(char *msg, int msglen);
};

#endif
