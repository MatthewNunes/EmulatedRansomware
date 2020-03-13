#include <stdio.h>
#include <string.h>

//First argument is source, second is destination
int main(int argc, const char* argv[]) {
	//printf(argv[1]);
	//printf(argv[2]);
	//D:/SecondContribution/CuckooNewCleanRansomware2/469/reports/report.json
	//FILE *fp = fopen("Z:/SecondContribution/Cuckoo/CuckooCleanRansomwareNew/1/reports/report.json", "r");
	//FILE *fp = fopen("D:/SecondContribution/CuckooNewCleanRansomware2/469/reports/report.json", "r");
	//D:/SecondContribution/CuckooNewCleanRansomware2/469/reports/report_replace.json
	//FILE *fpp = fopen("Z:/SecondContribution/Cuckoo/CuckooCleanRansomwareNew/1/reports/report_replace.json", "w");
	//FILE *fpp = fopen("D:/SecondContribution/CuckooNewCleanRansomware2/469/reports/report_replace.json", "w");
	FILE *fp = fopen(argv[1], "r");
	FILE *fpp = fopen(argv[2], "w");
	int target_done = 0;
	char str[2];
	int first = 0;
	int second = 0;
	int third = 0;
	int forth = 0;
	int fifth = 0;
	int sixth = 0;
	int bracket_count = 0;
	int start_brackets = 0;
	int first_time = 0;

	//lets match "target"
	int name_first = 0;
	int name_second = 0;
	int name_third = 0;
	int name_forth = 0;
	int name_fifth = 0;
	int name_sixth = 0;
	int name_seventh = 0;
	int name_eigth = 0;
	int name_bracket_count = 0;
	int name_start_brackets = 0;
	int name_first_time = 0;

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
	  	/* writing content to stdout */
	  	/*
		if (sixth == 1) {
			if (strcmp(str, "{") == 0){
				start_brackets =1;
				bracket_count +=1;
			}
			fputs(str, fpp);

		}

		if (name_eigth == 1) {
			if (strcmp(str, "{") == 0){
				name_start_brackets =1;
				name_bracket_count +=1;
			}
			fputs(str, fpp);

		}

		if (sixth == 1) {
			if (strcmp(str, "}") == 0){
				bracket_count -=1;
			}			
		}

		if (name_eigth == 1) {
			if (strcmp(str, "}") == 0){
				name_bracket_count -=1;
			}			
		}

		if ((start_brackets==1) && (bracket_count == 0)){
			fputs("\n}\n", fpp);
			fclose(fpp);
			fclose(fp);
			sixth = 0;
			bracket_count = -1;
			return 0;
		}
		if ((name_start_brackets==1) && (name_bracket_count == 0)){
			//fclose(fpp);
			//fputs("\n\0", fpp);
			name_eigth = -1;
			name_first = 0;
			name_second = 0;
			name_third = 0;
			name_forth = 0;
			name_fifth = 0;
			name_sixth = 0;
			name_seventh = 0;
			name_bracket_count = -1;
			//return 0;
		}


		if ((fifth == 1) && (sixth==0)) {
			if (strcmp(str, "a") == 0){
				sixth = 1;
				//puts(str);
			}
			if (first_time == 0) {
				fputs(",\n\0", fpp);
				fputs("\"apista\0", fpp);
				first_time=1;
			}
		}

		if ((forth == 1) && (fifth == 0)) {
			if (strcmp(str, "t") == 0){
				fifth = 1;
			}
			else {
				first = 0;
				second = 0;
				third = 0;
				forth = 0;
			}
		}

		if ((name_seventh == 1) && (name_eigth == 0)) {
			if (strcmp(str, "\"") == 0){
				name_eigth = 1;
			}
			if (name_first_time == 0) {
				fputs("\"target\"\0", fpp);
				name_first_time=1;
			}
		}

		if ((name_sixth == 1) && (name_seventh == 0)) {
			if (strcmp(str, "t") == 0){
				name_seventh = 1;
			}
			else {
				name_first = 0;
				name_second = 0;
				name_third = 0;
				name_forth = 0;
				name_fifth = 0;
				name_sixth = 0;
			}
		}

		if ((name_fifth == 1) && (name_sixth == 0)) {
			if (strcmp(str, "e") == 0){
				name_sixth = 1;
			}
			else {
				name_first = 0;
				name_second = 0;
				name_third = 0;
				name_forth = 0;
				name_fifth = 0;
			}
		}

		if ((name_forth == 1) && (name_fifth == 0)) {
			if (strcmp(str, "g") == 0){
				name_fifth = 1;
			}
			else {
				name_first = 0;
				name_second = 0;
				name_third = 0;
				name_forth = 0;
			}
		}

		if ((third == 1) && (forth == 0)) {
			if (strcmp(str, "s") == 0){
				forth = 1;
			}
			else {
				first = 0;
				second = 0;
				third = 0;
			}
		}
		if ((name_third == 1) && (name_forth == 0)) {
			if (strcmp(str, "r") == 0){
				name_forth = 1;
			}
			else {
				name_first = 0;
				name_second = 0;
				name_third = 0;
			}
		}


		if ((second == 1) && (third == 0)) {
			if (strcmp(str, "i") == 0){
				third = 1;
			}
			else {
				first = 0;
				second = 0;
			}
		}
		if ((name_second == 1) && (name_third == 0)) {
			if (strcmp(str, "a") == 0){
				name_third = 1;
			}
			else {
				name_first = 0;
				name_second = 0;
			}
		}

		if ((first == 1) && (second == 0)) {
			if (strcmp(str, "p") == 0){
				second = 1;
			}
			else {
				first = 0;
			}
		}
		if ((name_first == 1) && (name_second == 0)) {
			if (strcmp(str, "t") == 0){
				name_second = 1;
			}
			else {
				name_first = 0;
			}
		}
	*/
		if (target_done == 0) {
			if (strcmp(str, "\"") == 0){
				if (fgets (str, 2, fp)!=NULL ) {
					if (strcmp(str, "t") == 0) {
						if (fgets (str, 2, fp)!=NULL ) {
							if (strcmp(str, "a") == 0) {
								if (fgets (str, 2, fp)!=NULL ) {
									if (strcmp(str, "r") == 0) {
										if (fgets (str, 2, fp)!=NULL ) {
											if (strcmp(str, "g") == 0) {
												if (fgets (str, 2, fp)!=NULL ) {
													if (strcmp(str, "e") == 0) {
														if (fgets (str, 2, fp)!=NULL ) {
															if (strcmp(str, "t") == 0) {
																if (fgets (str, 2, fp)!=NULL ) {
																	if (strcmp(str, "\"") == 0) {
																		fputs("\"target\0", fpp);
																		while(strcmp(str, "{") != 0) {
																			fputs(str, fpp);
																			fgets (str, 2, fp);
																		}
																		fputs(str, fpp);
																		bracket_count +=1;
																		while (bracket_count != 0) {
																			fgets (str, 2, fp);
																			fputs(str, fpp);
																			if (strcmp(str, "{") == 0) {
																				bracket_count+=1;
																			}
																			if (strcmp(str, "}") == 0) {
																				bracket_count-=1;
																			}
																		}
																		target_done = 1;

																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (strcmp(str, "a") == 0){
			if (fgets (str, 2, fp)!=NULL ) {
				if (strcmp(str, "p") == 0) {
					if (fgets (str, 2, fp)!=NULL ) {
						if (strcmp(str, "i") == 0) {
							if (fgets (str, 2, fp)!=NULL ) {
								if (strcmp(str, "s") == 0) {
									if (fgets (str, 2, fp)!=NULL ) {
										if (strcmp(str, "t") == 0) {
											if (fgets (str, 2, fp)!=NULL ) {
												if (strcmp(str, "a") == 0) {
													if (fgets (str, 2, fp)!=NULL ) {
														if (strcmp(str, "t") == 0) {
															if (target_done == 1){
																fputs(",\n\0", fpp);
															}
															fputs("\"apista\0", fpp);
															while(strcmp(str, "{") != 0) {
																fputs(str, fpp);
																fgets (str, 2, fp);
															}
															fputs(str, fpp);
															bracket_count +=1;
															while (bracket_count != 0) {
																fgets (str, 2, fp);
																fputs(str, fpp);
																if (strcmp(str, "{") == 0) {
																	bracket_count+=1;
																}
																if (strcmp(str, "}") == 0) {
																	bracket_count-=1;
																}
															}
															fputs("\n}\n", fpp);
															fclose(fp);
															fclose(fpp);
															return(0);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		/*
		if (strcmp(str, "\"") == 0) {
			name_first = 1;

		}
		*/
	}
	fputs("\n}\n", fpp);
	fclose(fp);
	fclose(fpp);

	return(0);
}
