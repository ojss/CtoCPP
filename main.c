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


int main(int argc, const char * argv[]) {
    char str[100], *rets, *rets_two, new_str[100];
    FILE *fp = fopen("test.dat", "r");
    FILE *wp = fopen("toC.cpp", "w+");
    while (!feof(fp)) {
        fgets(str, 100, fp);
        //changing headers
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
          fprintf(wp, "%s%s\n", rets,";");
          continue;
        }
    }
    printf("%s\n",rets );
    fclose(fp);
    fclose(wp);
    return 0;
}
