/* Main file, this fill will call subsequent functions*/

#include<iostream>
#include<cstdlib>
#include<cassert>
#include<string.h>
#include<string>
#include<dirent.h>
using namespace std;

/* Functions Def */
int processRequest(int, char**);
void crash(int);
void init(char *);

int main(int argc, char **argv)
{
	int status = 0;

	switch (argc) {
		case 1:
			cout<<"Welcome to JCM\nUse \"jcm help\" for more info.\n";
			break;
		case 2:
		case 3:
		case 4:
			status = processRequest(argc, argv);
			break;
		default:
			cout<<"0 arguments, how did you do it?";
			break;
	}
	return 0;
}

/**/
int processRequest(int count, char **arguments)
{
	if(strncmp("init",*(arguments+1),4)==0) {
		cout<<"INIT Called\n";
		init(*(arguments+2));
	} else {
		cout<<*arguments<<"\n";
	}
	
	return 0;
}

void init(char *directory) 
{
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (directory)) != NULL) {
	/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) {
			cout<<ent->d_name<<"\n";
			if(opendir(ent->d_name)!=NULL) {
				init(ent->d_name);
			}
		}
		closedir (dir);
	} else {
		/* could not open directory */
	        crash(1);
	}
}
/* This Code will crash the program intentionally when some unwanted conditions occur */
void crash(int status)
{
	switch (status) {
		case 1:
			cout<<"Directory Not Found\n";
			break;
		default:
			cout<<"Undefined error:"<<status<<"\n";
			break;
	}
	assert(false);
}


