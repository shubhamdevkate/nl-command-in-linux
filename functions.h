#include <stdio.h>
#include <errno.h>

/* when no file is given, read standard input */
void input() {
	char ip[64];
	int i;
	for(i = 0; i < 64; i++){
		scanf("%s", &ip[i]);
		printf("\n     %d  %s\n", i + 1, ip);
		i = -1;
	}
}

/* when only file is specified */
int nl_print1(char *file) {
	FILE *fp;
	int c, j = 1, len;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file");
		return errno;
	}

	printf("     %d  ",j++);
	do {	
		c = fgetc(fp);

		if(c != EOF)
			printf("%c", c);

		if(c == '\n'){
			c = fgetc(fp);
			if(c != EOF){
				printf("     ");
				printf("%d", j++);
				printf("  ");
				len = ftell(fp);
				fseek(fp, len - 1, SEEK_SET);				
			}
		}

	}while(c != EOF);

	fclose(fp);

}

/* nl -b t file */
int nl_print2(char *file) {
	FILE *fp;
	int c;
	int j = 1, flag = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file");
		return errno;
	}
	printf("     %d  ", j++);
	c = fgetc(fp);

	while(c != EOF){
		printf("%c", c);
		if(c == '\n'){
			c = fgetc(fp);
			if(c == '\n')
				printf("%c", c);
			else{
				if(c != EOF){
					printf("     %d  ", j++);                                           
					printf("%c", c);        
				}  
			}

		}

		c = fgetc(fp);
	}

	fclose(fp);
}

/* nl -b n file */
int nl_print3(char *file) {
	FILE *fp;
	int c;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file");
		return errno;
	}

	printf("       ");
	do {
		c = fgetc(fp);

		if(c != EOF)
			printf("%c", c);

		if(c == '\n'){
			printf("     ");
			printf("  ");
		}

	}while(c != EOF);

	fclose(fp);

}

/* nl -n ln file */
int nl_ln(char *file){
	FILE *fp;
	int c;
	int j = 1, flag = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file");
		return errno;
	}
	printf("%d     ", j++);
	c = fgetc(fp);
	while(c != EOF) {
		printf("%c", c);
		if(c == '\n'){
			c = fgetc(fp);
			if(c != '\n'){
				printf("%d     ", j++);
				printf("%c", c);
			}
			else if(c == '\n')
				printf("%c", c);

			else
				printf("%c", c);
		}
		c = fgetc(fp);
	}

	fclose(fp);
}

/* nl -n rz file */
int nl_rz(char *file) {
	FILE *fp;
	int c;
	int j = 1, flag = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file");
		return errno;
	}
	printf("00000%d  ", j++);
	c = fgetc(fp);
	while(c != EOF) {
		printf("%c", c);
		if(c == '\n'){
			c = fgetc(fp);
			if(c != '\n'){
				printf("00000%d  ", j++);
				printf("%c", c);
			}
			else if(c == '\n')
				printf("%c", c);
		}
		c = fgetc(fp);
	}

	fclose(fp);
}

/* nl -i NUMBER file */
int nl_i(int n, char *file) {
	FILE *fp;
	int c;
	int j = 1, flag = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file");
		return errno;
	}
	printf("     %d  ", j);
	c = fgetc(fp);
	while(c != EOF) {
		printf("%c", c);
		if(c == '\n'){
			c = fgetc(fp);
			if(c != '\n'){
				if(c != EOF){
					printf("     %d  ", 1 + (n * j++));
					printf("%c", c);
				}

			}
			else if(c == '\n') 
				printf("%c", c);
		}
		c = fgetc(fp);
	}

	fclose(fp);
}

/* nl -w NUMBER file */
int nl_w(int n, char *file){
	FILE *fp;
	int c, k, j = 1, i = 0;
	k = n % 8;
	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file:");
		return errno;	
	}

	switch(k){
		case 0:
			c = fgetc(fp);
			while(++i <= (n / 8))
				printf("       ");
			printf("%d", j++);
			printf("        ");

			while(c != EOF){
				printf("%c", c);
				if(c == '\n'){
					c = fgetc(fp);
					if(c == '\n')
						printf("%c", c);
					else{
						if(c != EOF){
							i = 0;
							while(++i <= (n / 8))
								printf("       ");
							printf("%d", j++);
							printf("        ");

							printf("%c", c);
						}
					}

				}
				c = fgetc(fp);
			}
			fclose(fp);
			break;

		case 1:
			c = fgetc(fp);
			i = 0;
			while(++i <= (n / 8))
				printf("        ");
			printf("%d        ", j++);

			while(c != EOF){
				printf("%c", c);
				if(c == '\n'){
					c = fgetc(fp);
					if(c == '\n')
						printf("%c", c);
					else{
						if(c != EOF){
							i = 0;
							while(++i <= (n / 8))
								printf("        ");
							printf("%d", j++);
							printf("        ");

							printf("%c", c);
						}
					}

				}	
				c = fgetc(fp);		
			}
			fclose(fp);
			break;

		case 2:
			printf(" ");
			c = fgetc(fp);
			i = 0;
			while(++i <= (n / 8))
				printf("        ");
			printf("%d      ", j++);

			while(c != EOF){
				printf("%c", c);
				if(c == '\n'){
					c = fgetc(fp);
					if(c == '\n')
						printf("%c", c);
					else{   
						if(c != EOF){
							i = 0;
							printf(" ");
							while(++i <= (n / 8))
								printf("        ");
							printf("%d", j++);
							printf("      ");

							printf("%c", c);
						}
					}

				}
				c = fgetc(fp);
			}
			fclose(fp);
			break;
		case 3:
			printf("  ");
			c = fgetc(fp);
			i = 0;
			while(++i <= (n / 8))
				printf("        ");
			printf("%d     ", j++);

			while(c != EOF){
				printf("%c", c);
				if(c == '\n'){
					c = fgetc(fp);
					if(c == '\n')
						printf("%c", c);
					else{
						if(c != EOF){
							i = 0;
							printf("  ");
							while(++i <= (n / 8))
								printf("        ");
							printf("%d", j++);
							printf("     ");

							printf("%c", c);
						}
					}

				}
				c = fgetc(fp);
			}
			fclose(fp);
			break; 

		case 4:
			printf("   ");
			c = fgetc(fp);
			i = 0;
			while(++i <= (n / 8))
				printf("        ");
			printf("%d    ", j++);

			while(c != EOF){
				printf("%c", c);
				if(c == '\n'){
					c = fgetc(fp);
					if(c == '\n')
						printf("%c", c);
					else{
						if(c != EOF){
							i = 0;
							printf("   ");
							while(++i <= (n / 8))
								printf("        ");
							printf("%d", j++);
							printf("    ");

							printf("%c", c);
						}
					}

				} 
				c = fgetc(fp);
			}
			fclose(fp);
			break;

		case 5:
			printf("    ");
			c = fgetc(fp);
			i = 0;
			while(++i <= (n / 8))
				printf("        ");
			printf("%d   ", j++);

			while(c != EOF){
				printf("%c", c);
				if(c == '\n'){
					c = fgetc(fp);
					if(c == '\n')
						printf("%c", c);
					else{
						if(c != EOF){
							i = 0;
							printf("    ");
							while(++i <= (n / 8))
								printf("        ");
							printf("%d", j++);
							printf("   ");

							printf("%c", c);
						}
					}

				}
				c = fgetc(fp);
			}
			fclose(fp);     
			break;

		case 6:
			printf("     ");
			c = fgetc(fp);
			i = 0;
			while(++i <= (n / 8))
				printf("        ");
			printf("%d  ", j++);

			while(c != EOF){
				printf("%c", c);
				if(c == '\n'){
					c = fgetc(fp);
					if(c == '\n')
						printf("%c", c);
					else{
						if(c != EOF){
							i = 0;
							printf("     "); 
							while(++i <= (n / 8))
								printf("        ");
							printf("%d", j++);
							printf("  ");

							printf("%c", c);
						}
					}

				}
				c = fgetc(fp);
			}
			fclose(fp);
			break;

		case 7:
			printf("      ");
			c = fgetc(fp);
			i = 0;
			while(++i <= (n / 8))
				printf("        ");
			printf("%d ", j++);

			while(c != EOF){
				printf("%c", c);
				if(c == '\n'){
					c = fgetc(fp);
					if(c == '\n')
						printf("%c", c);
					else{
						if(c != EOF){
							i = 0;
							printf("      ");
							while(++i <= (n / 8))
								printf("        ");
							printf("%d", j++);
							printf(" ");

							printf("%c", c);
						}
					}

				}
				c = fgetc(fp);
			}
			fclose(fp);
			break;



		default:
			printf("hi");
	} 


}

int nl_s(char *str, char *file){
	FILE *fp;
	int c;
	int j = 1, flag = 0;

	fp = fopen(file, "r");
	if(fp == NULL){
		perror("Can't open file");
		return errno;
	}
	printf("     %d%s", j++, str);
	c = fgetc(fp);

	while(c != EOF){
		printf("%c", c);
		if(c == '\n'){
			c = fgetc(fp);
			if(c == '\n')
				printf("%c", c);
			else{
				if(c != EOF){
					printf("     %d%s", j++, str);
					printf("%c", c);
				}
			}

		}

		c = fgetc(fp);
	}

	fclose(fp);	
}

int help(){
	FILE *fp;
	int c;

	fp = fopen("nl_help", "r");
	if(fp == NULL){
		perror("can't open wc_help file: ");
		return errno;
	}

	while((c = fgetc(fp)) != EOF)
		printf("%c", c);

}

