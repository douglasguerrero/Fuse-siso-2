#include <stdlib.h>
#include <stdio.h>
#include "device.h"

static const char *device_path;
static FILE *f;

int device_open(const char *path) 
{
    device_path = path;
    f = fopen(path, "r+");
	if(f == NULL){

	create_new_device(path);
	}
	
    return (f != NULL);
}

void create_new_device(const char *path){

	int fileSize = 1024;
	f = fopen("floppyB.img", "w");
	fseek(f, fileSize , SEEK_SET);
        fputc('\0', f);

	unsigned char fileArray[fileSize];

	for (int i = 0; i < fileSize; ++i){
        	fileArray[i] = 0x46;
	}

	
	device_write_sector(fileArray, 0);
}

void device_close()
{
    fflush(f);
    fclose(f);
}

int device_read_sector(unsigned char buffer[], int sector) 
{
    fseek(f, sector*SECTOR_SIZE, SEEK_SET);
	
    return ( fread(buffer, 1, SECTOR_SIZE, f) == SECTOR_SIZE );
}

int device_write_sector(unsigned char buffer[], int sector) 
{
    fseek(f, sector*SECTOR_SIZE, SEEK_SET);
	
    return ( fwrite(buffer, 1, SECTOR_SIZE, f) == SECTOR_SIZE );
}

void device_flush()
{
    fflush(f);
}
