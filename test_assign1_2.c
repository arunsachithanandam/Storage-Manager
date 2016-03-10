#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "storage_mgr.h"
#include "dberror.h"
#include "test_helper.h"

// test name
char *testName;

/* test output files */
#define TESTPF "test_pagefile_2.bin"

/* prototypes for test functions */
static void testCreateOpenClose(void);
static void testMultiPageContent(void);

/* main function running all tests */
int
main (void)
{
  testName = "";
  
  initStorageManager();

//  testCreateOpenClose();
  testMultiPageContent();

  return 0;
}


/* check a return code. If it is not RC_OK then output a message, error description, and exit */
/* Try to create, open, and close a page file */
void testMultiPageContent(void)
{
  SM_FileHandle fh;
  SM_PageHandle ph;
  int i;

  testName = "test Multi page content";

  ph = (SM_PageHandle) malloc(PAGE_SIZE);

  // create a new page file
  TEST_CHECK(createPageFile (TESTPF));
  TEST_CHECK(openPageFile (TESTPF, &fh));
  printf("created and opened file\n");
  
  // read first page into handle
  TEST_CHECK(readFirstBlock (&fh, ph));
  // the page should be empty (zero bytes)
  for (i=0; i < PAGE_SIZE; i++)
    ASSERT_TRUE((ph[i] == 0), "expected zero byte in first page of freshly initialized page");
  printf("first block was empty\n");
    
  // change ph to be a string and write that one to disk
  for (i=0; i < PAGE_SIZE; i++)
    ph[i] = (i % 10) + '0';
  //TEST_CHECK(getBlockPos(&fh));
  TEST_CHECK(writeBlock (0, &fh, ph));
  printf("writing first block\n");

  // read back the page containing the string and check that it is correct
  // Read current BLock
  TEST_CHECK(readCurrentBlock (&fh, ph));
  
  printf("\nReading Current block Done");
  //Get Block POsition
  printf("\nCurrent BLock Position is :%d",getBlockPos(&fh));
  //Write block 2
  TEST_CHECK(writeBlock(1,&fh,ph));
  printf ("\nWrote page 2 with same content");
  printf("\nNow current Block is:%d",getBlockPos(&fh));
  // Reading 0th Block now
  printf("\nReading previous Block");
  TEST_CHECK(readPreviousBlock(&fh,ph));
  printf ("\nTo check we are reading previous block. Printing block position.And it is:%d",getBlockPos(&fh));
  TEST_CHECK(readNextBlock(&fh,ph));
  printf("\n To check we are reading next block. Printing block Position .And it is:%d",getBlockPos(&fh));
  // Read First block
  TEST_CHECK(readFirstBlock(&fh,ph));
  printf("\nAgain reading Block %d",getBlockPos(&fh));
  // Testing write Current Block
  for(i=PAGE_SIZE; i<1 ; i--)
  ph [i] = (i%10) + '0'; 
  TEST_CHECK(writeCurrentBlock(&fh,ph));
  printf("Wrote this thing just now to current block:%s",ph);  
  // Reading Last Block
  TEST_CHECK(readLastBlock(&fh,ph));
  printf("\nReading Last block Done.And it is:%d",getBlockPos(&fh));
  // Ensurring we are good with 3 pages
  TEST_CHECK(ensureCapacity(3,&fh));
  // Writing 2nd block for that
  TEST_CHECK(writeBlock(2,&fh,ph));
  printf("NOw we are in %d block",getBlockPos(&fh));
  // destroy new page file
  TEST_CHECK(destroyPageFile (TESTPF));  
   
  TEST_DONE();
}
