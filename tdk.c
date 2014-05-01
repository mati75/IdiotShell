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
                else if ((!strncmp("cd", buf, 2)) || (!strncmp("pwd", buf, 3))) {
                        printf("Current directory is /home/tdk8gb\n");
                }
                else if (!strncmp("touch", buf, 5)) {
                        printf("U Can't Touch This!\nhttp://www.youtube.com/watch?v=otCpCn0l4Wo\n");
                }
                else if (!strncmp("passwd", buf, 6)) {
                        system("/usr/local/bin/roll.sh");
                }

                else if (!strncmp("ping", buf, 4)) {
                        printf("PONG!\n");
                }
                else if (!strncmp("dir", buf, 4)) {
                        printf("What did you mean by: Directory?\n Directory may refer to:\n Directory (computing), or folder, a file system structure in which to store computer files\n Directory service, a software application for organizing information about a computer network's users and resources\n Directory (political), a small group of influential states that is said to 'direct' the agenda\n  French Directory, the government in revolutionary France from 1795 to 1799\n Business directory, a listing of information about suppliers and manufacturers\n Telephone directory, a book which allows telephone numbers to be found given the subscriber's name\n Web directory, an organized collection of links to websites");
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
