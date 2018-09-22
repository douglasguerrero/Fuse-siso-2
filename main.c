#include "sfs.h"

#include <fuse.h>
#include <stdio.h>

struct fuse_operations sfs_oper;

int main(int argc, char *argv[]) {

	printf("mounting file system...\n");
	
	/*for(i = 1; i < argc && (argv[i][0] == '-'); i++) {
		if(i == argc) {
			return (-1);
		}
	}*/

	//realpath(...) returns the canonicalized absolute pathname
	if (!device_open(realpath(argv[1], NULL)) ) {
	    printf("Cannot open device file %s\n", argv[1]);
	    return 1;
	}

	/*for(; i < argc; i++) {
		argv[i] = argv[i+1];
	}
	argc--;*/

	//fuse_stat = fuse_main(argc, argv, &sfs_oper, NULL);

    	device_close();

	return 0;
}


