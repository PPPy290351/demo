#include <stdio.h>
#include <string.h>

#define ARRNUM 13

char* dangerous[ARRNUM] = {
    "rm",
    "ssh",
    "curl",
    "rm -rf",
    "mv",
    "cp",
    "chown",
    "chmod",
    "mkdir",
    "sudo",
    "./",
    "wget"
    "apt"
};

int dangerCheck(char* checkCmd){
    if(checkCmd != NULL){
            for(int i=0; i<ARRNUM; i++){
                        char* verify = strstr(checkCmd, dangerous[i]);
                        if(verify != NULL) return 1;
                    }
        }
    return 0;
}
int main() {
    char buf[BUFSIZ];
    int stop = 12;
    fgets(buf, sizeof buf, stdin);
    while(buf != NULL && stop != 0){
            if(buf[strlen(buf)-1] == '\n') stop--;
            else stop = 0;
            if(dangerCheck(buf) == 1){
                        printf("danger found: %s\n", buf);
                    }
            if(stop != 0) fgets(buf, sizeof buf, stdin);
        }
    return 0;
}

