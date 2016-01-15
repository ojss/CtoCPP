//
//  converter_helpers.c
//  cpp_converter
//
//  Created by Ojas Shirekar on 14/01/16.
//  Copyright © 2016 Ojas Shirekar. All rights reserved.
//

#include <string.h>
#include "converter_helpers.h"

int write_as_is(FILE *wp, const char *to_be_written){
    fprintf(wp, "%s", to_be_written);
    return 0;
}
