#include <stdio.h>
#include <string.h>


int main(int argc, const char* argv[]) {

	FILE *fp = fopen("Z:/SecondContribution/Cuckoo/CuckooCleanRansomwareNew/1/reports/report.json", "r");
	FILE *fpp = fopen("Z:/SecondContribution/Cuckoo/CuckooCleanRansomwareNew/1/reports/report_replace.json", "w");
	const char *api[] = {"\"", "a", "p", "i", "\""};
	const char *time[] = {"\"", "t","i", "m", "e", "\""};
	char str[2];
	int bracket_count = 0;
	int api_index = 0;
	int time_index = 0;

	api_index=0;
	time_index=0;

	if(fp == NULL) {
		printf("Error");
		perror("Error opening file");
		return(-1);
	}

	if(fpp == NULL) {
		printf("Error");
		perror("Error opening file");
		return(-1);
	}
	fputs("{\n", fpp);



	while(fgets (str, 2, fp)!=NULL ) {
		if (strcmp(str, "\"") == 0){
			api_index = 0;
			time_index = 0;
			fgets (str, 2, fp);
			if (strcmp(str, "a") == 0) {
				api_index = 2;
				while(api_index < 5) {
					fgets (str, 2, fp);
					if (strcmp(str, api[api_index]) != 0) {
						api_index = 10;
					}
					api_index+=1;
				}

			}
			if (strcmp(str, "t") == 0) {
				time_index = 2;
				while(time_index < 6) {
					fgets (str, 2, fp);
					if (strcmp(str, time[time_index]) != 0) {
						time_index = 10;
					}
					time_index+=1;
				}
			}

			if (api_index == 5) {
				fputs("\"api\"", fpp);
				while (strcmp(str, ",") != 0) {
					fgets(str, 2, fp);
					fputs(str, fpp);
				}
				fputs("\n", fpp);
			}
			if (time_index == 6) {
				fputs("\"time\"", fpp);
				while (strcmp(str, ",") != 0) {
					fgets(str, 2, fp);
					fputs(str, fpp);
				}
				fputs("\n", fpp);
			}

		}
	}

}