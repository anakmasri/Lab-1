#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void anak(){
	char name[20];
	printf("Please enter child name: ");
	scanf("%20s", name);
	printf("Child name is %s\n", name);
}

void makpak(){
	wait(NULL);
	printf("Job is done.\n\n");
}

int main(void){
	for(int i=1; i<5; i++){
		pid_t pid = fork();

		if(pid == 0){
			anak();
			exit(0);
		}
		else{
			makpak();
		}
	}

	return EXIT_SUCCESS;
}

