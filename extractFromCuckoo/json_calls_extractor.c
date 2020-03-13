#include <stdio.h>
#include <string.h>

//First argument is source, second is destination
int main(int argc, const char* argv[]) {
	//printf(argv[1]);
	//printf(argv[2]);
	//D:/SecondContribution/CuckooNewCleanRansomware2/469/reports/report.json
	FILE *fp = fopen("Z:/SecondContribution/Cuckoo/CuckooCleanRansomwareNew/1/reports/report.json", "r");
	//FILE *fp = fopen("D:/SecondContribution/SecondContributionRansomwareCuckoo/10/reports/report.json", "r");
	//FILE *fp = fopen("D:/SecondContribution/CuckooNewCleanRansomware2/469/reports/report.json", "r");
	//D:/SecondContribution/CuckooNewCleanRansomware2/469/reports/report_replace.json
	FILE *fpp = fopen("Z:/SecondContribution/Cuckoo/CuckooCleanRansomwareNew/1/reports/report_replace.json", "w");
	//FILE *fpp = fopen("D:/SecondContribution/SecondContributionRansomwareCuckoo/10/reports/report_new.json", "w");
	//FILE *fpp = fopen("D:/SecondContribution/CuckooNewCleanRansomware2/469/reports/report_new.json", "w");
	
	//FILE *fp = fopen(argv[1], "r");
	//FILE *fpp = fopen(argv[2], "w");
	int target_done = 0;
	char str[2];
	char str_big[3];
	char str_prev[3];
	char str_prev_prev[3];
	char str_prev_prev_prev[3];
	const char *target[] = {"\"","p", "r", "o", "c", "e", "s", "s", "e", "s", "\"", ":"};
	const char *ignore[] = {"\"","a", "r", "g", "u"};
	char left[6];
	int target_index = 0;
	int match = 0;
	int bracket_count = 0;
	int ig_bracket_count = 0;
	int job_done = 0;
	int quotations = 0;
	int ignore_index = 0;
	int dont_break = 0;
	int use_left = 0;
	int index = 0;
	printf(target[0]);
	/* opening file for reading */
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
		target_index=0;
		if (strcmp(str, "\"") == 0){
			target_index+=1;
			match = 1;
			while (match == 1){
				if (target_index < 12) {
					if (fgets (str, 2, fp)!=NULL ) {
						if (strcmp(str, target[target_index]) == 0){
							target_index+=1;
						} else {
							match=0;
						}
					}
					else {
						match=0;
					}
				} else {
					fputs("\"processes\"", fpp);
					while(strcmp(str, "[") != 0) {
						fputs(str, fpp);
						fgets (str, 2, fp);

					}
					fputs(str, fpp);
					bracket_count +=1;
					strncpy(str_prev, str, 2);
					//printf("%s\n", str);
					while (bracket_count != 0) {
						fgets (str, 2, fp);
						//printf("%d", bracket_count);
						//printf("%s\n", str);
						if(strcmp(str, "\"") == 0) {
							dont_break=1;
							ignore_index=0;
							use_left=0;
							job_done=0;
							memset(left, 0, 6);
							left[ignore_index] = str[0];
							ig_bracket_count = 0;

							while(dont_break == 1){
								ignore_index+=1;
								if (ignore_index == 5) {
									ignore_index =0;
									job_done=1;
									
									fgets (str_big, 3, fp);
									while (strcmp(str_big, "},") != 0){
										fgets (str_big, 3, fp);
										//printf("I stuck\n");
										//printf("%s\n", str_big);
									}
									fgets(str, 2, fp);
									while (strcmp(str, "\n") != 0) {
										//while (strcmp(str_big, "},") != 0){
										//	fgets (str_big, 3, fp);
										//printf("I stuck\n");
										//printf("%s\n", str_big);
										//}
										fgets(str, 2, fp);
									}
									
									//fputs("\"time\"", fpp);									
									
									//Tries to match with time
									/*
									fgets (str_big, 7, fp);
									while (strcmp(str_big, "\"time\"") != 0){
										fgets (str_big, 7, fp);
										//printf("I stuck\n");
										//printf("%s\n", str_big);
									}
									//printf("I not stuck\n");
									fputs("\"time\"", fpp);
									*/

									//Tries to match with curly brackets
									/*
									while (strcmp(str, "{") != 0){
										fgets (str, 2, fp);
										//printf("%s\n", str_big);
									}
									ig_bracket_count +=1;
									while (ig_bracket_count != 0){
										fgets (str, 2, fp);
										if (strcmp(str, "{") == 0) {
											ig_bracket_count+=1;
										}
										if (strcmp(str, "}") == 0) {
											ig_bracket_count-=1;
										}
										//printf("%s\n", str_big);
									}
									*/
									//fgets(str, 2, fp);
									dont_break=0;
								}
								fgets (str, 2, fp);
								left[ignore_index] = str[0];
								if ((strcmp(str, ignore[ignore_index]) != 0) && (job_done ==0)) {
									dont_break=0;
									use_left=1;
									//printf("%s\n", left);
									memset(&(left[ignore_index]), 0, 6 - ignore_index);
									for (index =0; index<ignore_index; index++) {
										fputs(&(left[index]), fpp);
									}
								}
							}

						}
						fputs(str, fpp);
						
						if (((strcmp(str, "\"") == 0) && (strcmp(str_prev, "\\") == 0) && (strcmp(str_prev_prev, "\\") == 0) && (strcmp(str_prev_prev_prev, "\\") != 0)) || ((strcmp(str, "\"") == 0) && (strcmp(str_prev, "\\") != 0))) {
							if (quotations == 0) {
								//printf("quotations is 0\n");
								//fputs("\n1\n", fpp);
								quotations+=1;
							}
							else {
								//fputs("\n0\n", fpp);
								quotations -=1;
							}
						}
						if (quotations == 0) {
							if (strcmp(str, "[") == 0) {
								bracket_count+=1;
							}
							if (strcmp(str, "]") == 0) {
								bracket_count-=1;
							}
						}
						strncpy(str_prev_prev_prev, str_prev_prev, 2);
						strncpy(str_prev_prev, str_prev, 2);
						strncpy(str_prev, str, 2);
					}
					
					target_index=0;
					match=0;
				}
			}

		}
	}
	fputs("\n}\n", fpp);
	fclose(fp);
	fclose(fpp);

	return(0);
}
