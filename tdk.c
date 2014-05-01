#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <signal.h>

int main(int argc, char * argv[]) {
        signal(SIGINT, SIG_IGN);
        setvbuf(stdout, NULL, _IONBF, 0);
        char buf[512];
        char tmbuf[64];

        FILE * fp = fopen("/etc/jaja_z_tdk/dmesg.txt", "r");
        FILE * logfile = fopen("/etc/jaja_z_tdk/log.txt", "a");
        if (!logfile) {
                printf("Failed to open shell file\n");
                return 1;
        }

        srand(time(NULL));

        if (fp) {
                while(!feof(fp)) {
                        if (!fgets(buf, sizeof(buf), fp))
                                continue;
                        printf("%s", buf);
                        usleep((rand() % 10) * 2000);
                }
                fclose(fp);
        }


        printf("Starting shell...\n\n");
        sleep(2);
        system("ponysay 'Witaj root!!!'");
        sleep(2);
        while(1) {
                memset(buf, 0, sizeof(buf));
                printf("root@shell ~ # ");
                fgets(buf, sizeof(buf), stdin);

                time_t now;
                struct tm * timeinfo;

                time(&now);
                timeinfo = localtime (&now);
                strftime(tmbuf, sizeof(tmbuf), "%H:%M:%S %d-%m-%Y", timeinfo);

                fprintf(logfile, "%s %s", tmbuf, buf);



                if (buf[0] == '\0') {
                        printf("exit\n");
                        break;
                }
                else if (buf[0] == '\n') {
                        continue;
                }
                else if (!strncmp("exit", buf, 4)) {
                        break;
                }
		else if (!strncmp("ls", buf, 2)) {
                        printf(".  ..  .bash_history  .bash_logout  .bash_profile  .bashrc  .ssh\n");
                }
		else if (!strncmp("touch", buf, 5)) {
			printf("http://www.youtube.com/watch?v=otCpCn0l4Wo&feature=kp");
                }
                else if ((!strncmp("cd", buf, 2)) || (!strncmp("pwd", buf, 3))) {
                        printf("Current directory is /home/tdk8gb\n");
                }
                else {
                        buf[strlen(buf) - 1] = '\0';
                        printf("%s: command not found\n", buf);
                }
        }
        fclose(logfile);
        printf("Logout.\n");
        return 0;
}
