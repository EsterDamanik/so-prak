/*
Shell
=====
Shell adalah program yang membuat proses child untuk menjalankan string perintah yang diberikan.
Shell berupa infinite looping yang berisi siklus fork--exec--wait.
Lengkapilah kode berikut ini untuk membuat program shell sederhana!
Contoh masukan dan keluaran
---------------------------
    $ date
    Tue Dec  9 13:34:17 WIB 2014
    $ whoami
    auriza
    $ exit
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// pecah string per kata
void split_words(char *string, char **words)
{
    int i;
    words[0] = strtok(string, " \n");
    for (i = 0; words[i]; i++)
        words[i+1] = strtok(NULL, " \n");
}


int main()
{
    char cmd[80];                           //  string perintah
    char *args[20];                         //  argumen string perintah

    while (1)
    {
        //  cetak prompt "$ "
        printf("$ ");

        //  baca string perintah
        fgets(cmd, 80, stdin);
		
        //  pecah string perintah per argumen
		split_words(cmd, args);
		
        //  jika perintah = "exit"
        //      break
        if (strcmp(args[0], "exit") == 0)
			break;

        //  jika perintah = "cd"
        //      ganti direktori pakai chdir
        //      continue
		if(strcmp(args[0], "cd") == 0){
			if (args[1]){
				chdir(args[1]);
				printf("Anda sudah berada di direktori yang benar hehe\n");
			}
			continue;
		}
		
   
         //  buat proses child:
        pid_t pid = fork();
        
        if (pid == 0){
			execvp(args[0], args); //      exec string perintah
			perror(args[0]);	//      cetak pesan error
			return -1;			//      keluar dengan kode -1
		} else if (pid > 0){
			wait(NULL);			//  tunggu child selesai
		} else{
			perror("Fork Failed");
			return -1;
		}
    }

    return 0;
}
