struct input{
	char *host;
	int start;
	int end;
};

struct output{
	int total;
	int portno[100];
};

typedef struct input in;
typedef struct output out;

program PORT{
version PORTVER{
	out getports(in)=1;
}=1;
}=44;
