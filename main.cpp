
#include "stdafx.h"

/*  Compare time duration of copy in files*/
void compareCopyTime(){

	pmap_context map_context= create_map_context(L"./temp1.txt",512*1024*1024);
	// create file using mmio 
	close_map_context(map_context);
	// close mmio context

	StopWatch stopWatch2;
	stopWatch2.Start(); // mmio time clock start

	if(file_copy_using_memory_map(L"./temp1.txt",L"./temp2.txt"))
	{
		printf("Using mmio Success\n");
	} // file copy using mmio

	stopWatch2.Stop(); // mmio time clock stop
	
	printf("%d\n",stopWatch2.GetDurationSecond()); //print mmio duration

	StopWatch stopWatch3;
	stopWatch3.Start(); // read write clock start

	if(file_copy_using_read_write(L"./temp1.txt",L"./temp3.txt"))
	{
		printf("Using read Success \n");
	} //  file copy using read_write

	stopWatch3.Stop(); // read write clock end

	printf("%d\n",stopWatch3.GetDurationSecond()); //print rw duration

}
/* A File create , the size of file larger than 4GB , using FileIOHelperClass */ 
void createBigFile(){

	FileIoHelper fileIoHelper;
	LARGE_INTEGER sizeofFile;

	sizeofFile.LowPart=0x40000000;
	sizeofFile.HighPart=0x1; // file size 5GB
	//sizeofFile.QuadPart = 1024 * 1024 * 1024;
	
	const wchar_t *filePath = L"./bob.txt";
	

	if(sizeofFile.HighPart>0){ 
		// Large file, larger than 4GByte file

		LARGE_INTEGER offset;
		DWORD bufSize = 1024;
		PUCHAR buf = new unsigned char[bufSize];

		offset.QuadPart=0;
		
		fileIoHelper.FIOCreateFile(filePath,sizeofFile);

		while(0 < sizeofFile.QuadPart){

			if((sizeofFile.QuadPart=sizeofFile.QuadPart-bufSize)<0){
				// bufsize change 
				bufSize = sizeofFile.QuadPart;
			} //else buf size 1024

			if(!fileIoHelper.FIOWriteToFile(offset,bufSize,buf)){
				printf("The file create Success, size of file larger than 4GB size ");
				// file write fail
			} 

			offset.QuadPart += bufSize;
			// offset += bufsize
		}

		fileIoHelper.FIOClose();
		
	}else{
		// Small file, smaller than 4GByte file
		if(!create_very_big_file(filePath,sizeofFile.LowPart)){
			printf("The file create fail, size of file smaller than 4GB size ");
		}
	}
	
	

}

int _tmain(int argc, _TCHAR* argv[])
{

	compareCopyTime();
	
	createBigFile();

	return 0;
}


