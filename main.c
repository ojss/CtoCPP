//
//  main.c
//  CtoCPP
//
//  Created by Ojas Shirekar on 14/01/16.
//  Copyright © 2016 Ojas Shirekar. All rights reserved.
//

#include <stdio.h>
#include <string.h>


int main(int argc, const char * argv[]) {
    char str[100], *rets, new_str[100];
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

        // skipping main

        rets = strtok(str, "(");
        if (strcmp("int main", rets) == 0) {
          fprintf(wp, "%s%s\n", rets,"()");
          continue;
        }
    }
    printf("%s\n",rets );
    fclose(fp);
    fclose(wp);
    return 0;
}
