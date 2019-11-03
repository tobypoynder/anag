/* - anag.c - print out all the possible anagrams of a word */

char id[] = "@(#) anag v1.1  Print permutations of a word Author Toby Poynder";

#define MAXLENGTH 12

main(argc,argv)
int argc;
char **argv;
{
     char array[MAXLENGTH];
     void perms();
     char *swap();
     char *gets();
     void perm();
     int n = 0;
     int length;


     length = strlen(argv[1]);

     perms(argv[1],n,length);
}
char *swap(string,pos_1,pos_2)
char string[MAXLENGTH];
int pos_1,pos_2;
{
     char temp;

     temp = string[pos_1];
     string[pos_1] = string[pos_2];
     string[pos_2] = temp;

     return(string);
}
void perms(string,stage,length)
char string[MAXLENGTH];
int stage,length;
{
	char temp[MAXLENGTH];
	int i;

	if (length - stage == 2) {
		strcpy(temp,string);
		printf("%s\n",temp);
		swap(temp,length-1,length-2);
		printf("%s\n",temp);
	} else {
		strcpy(temp,string);
		for (i = stage; i < length; ++i) {
			swap(temp,stage,i);
			perms(temp,stage+1,length);
		}
	}
	return;
}


