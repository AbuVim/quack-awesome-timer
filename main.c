#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
	
int h_in_secs = 0;
int m_in_secs = 0;
int seconds = 0;

void usage(void);

int main(int argc, char *argv[]) 
{
	if (argc < 3)
	{
		usage();
		return 1;
	}
	
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "h") == 0) 
		{
			int hours = atoi(argv[i + 1]);
			h_in_secs = hours * 3600;	
			i += 1;
		}

		else if (strcmp(argv[i], "m") == 0)
		{
			int minutes = atoi(argv[i + 1]);
			m_in_secs = minutes * 60;
			i += 1;
		}

		else if (strcmp(argv[i], "s") == 0)
		{
			seconds = atoi(argv[i + 1]);
			i += 1;
		}
		else 
		{
			usage();
			return 1;
		}
	}
	
	int length = h_in_secs + m_in_secs + seconds;
		
	for(int i = length; i >= 0; i--)
	{			
	    	int h = i / 3600;
	        int m = (i % 3600) / 60;
	    	int s = i % 60;
		
	
	    	printf("\r%02d:%02d:%02d", h, m, s);
	    
	    	fflush(stdout);
	    	sleep(1);
	}	

	system("mpv --loop sound.mp3");

	return EXIT_SUCCESS;
}

void usage(void)
{
	printf("Usage: qal OPTION TIME\n");
}
