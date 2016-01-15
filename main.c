//
//  main.c
//  CtoCPP
//
//  Created by Ojas Shirekar on 14/01/16.
//  Copyright © 2016 Ojas Shirekar. All rights reserved.
//

// TODO Finish working on printf scanning.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char str[100], *rets = NULL, new_str[100], *rets_two;
    FILE *fp = fopen("test.dat", "r");
    FILE *wp = fopen("toC.cpp", "w+");
    while (!feof(fp)) {
        fgets(str, 100, fp);
        //changing headers
        strcpy(new_str, str);
        rets = strtok(str, "<");

        if(strcmp("#include",rets) == 0){
            fprintf(wp, "%s", rets );
            // now extracting the header name
            rets = strtok(NULL, ">");
            if(strcmp("stdio.h", rets) == 0){
                fprintf(wp, "%s\n", "<iostream>");
            }
            continue;
        }

        // skipping main, as in keeping it the same

        rets = strtok(str, "(");
        if (strcmp("int main", rets) == 0) {
            printf("1\n");
            fprintf(wp, "%s%s\n", rets,"(){");
            continue;
        }
        else if (strcmp("printf", rets) == 0) {
            printf("2\n");
            fprintf(wp, "%s", "cout<<");
            rets = strtok(NULL, ",");
            rets = strtok(rets, ")");

            rets_two = strtok(new_str, ",");
            rets_two = strtok(NULL, ")");
            if (rets_two != NULL) {
                fprintf(wp, "%s%s\n",rets_two,";");
            }
            else{
                fprintf(wp, "%s%s\n", rets,";");
            }
            continue;
        }
    }
    printf("%s\n",rets );
    fclose(fp);
    fclose(wp);
    return 0;
}
