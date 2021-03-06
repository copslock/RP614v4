#include "globals.h"
#ifdef SUPPORT_ASP
#define ERROR -1
#define FAILED -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

#define MAX_QUERY_TEMP_VAL_SIZE 2048
#define	T(s)	s



typedef int (*asp_funcptr)(request * req,  int argc, char **argv);
typedef void (*form_funcptr)(request * req, char* path, char* query);

typedef struct asp_name_s
{
	char *pagename;
	asp_funcptr function;
	struct asp_name_s *next;
} asp_name_t;

typedef struct form_name_s
{
	char *pagename;
	form_funcptr function;
	struct form_name_s *next;
} form_name_t;

typedef struct temp_mem_s
{
	char *str;
	struct temp_mem_s *next;
} temp_mem_t;


int websWriteBlock(request *req, char *buf, int nChars);
#define websWrite(req,format, arg...)  {	char temp[1024]; snprintf(temp, sizeof(temp), format, ##arg); websWriteBlock(req, temp, strlen(temp));}

#endif

