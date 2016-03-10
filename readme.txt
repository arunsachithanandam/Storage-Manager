		**Assignment 1: Storage Manager**
****************************************************

					

CONTENTS
*********
1)Instructions to run the code
2)Description of functions used
3)Additional Test Cases
4)Implementation

*****************************************************************

1)Instructions to run the code
*******************************

a)For executing mandatory test cases:

1) In the terminal,navigate to the assignment directory.

2) Type: 
	make -f makefile1

3) ./assign1

b) For executing additional test cases:

1) In the terminal,navigate to the assignment directory.

2) Type: 
	make -f makefile2

3) ./assign2




*****************************************************************


2)Description of functions used
********************************

	Function : CreatePageFile
	-------------------------
		
1)Check for file existence.If the file exists,throw an error message that the file is already present.


2)If the file does not exist,create the file and fill the first page with null bytes.

	Function : OpenPageFile
	------------------------
	
1) Check if the file with the provided file name exists and also the acess for that particular file.

2) If it does not exist, throw an error.

3) If opening the file is successful,then the fields of this file handle are initialized with the information about the opened file.

4) The file pointer is stored for book keeping i.e. in mgmtInfo 

	Function : ClosePageFile
	-----------------------------
1) Close the file and return a success message upon success.

2) Upon failure, return an appropriate error message.


	Function : DestroyPageFile
	------------------------------
	
1) If the file is present, remove the file.

2) Upon success, return a success message.

3) Upon failure, return a failure message.


	Function : readBlock
	---------------------
1)Check if the file handler has been initialzed and if the page exists.

2)Seek the file descriptors position to the page requested.

3)Read the content of the page and load it to the memory which is specified in mempage.


	Function : getBlockPos
	-----------------------

1)Check if the file handler has been initialzed. 

2)If initialized,return position of the page in file.

	Function : readFirstBlock
	-------------------------

1)Check if the file handler has been initialzed. 

2)Seek the file pointer to the first page of the file.

3)Read the content to mempage.


	Function : readPreviousBlock
	----------------------------
1)Check if the file handler has been initialzed.
 
2)Check if we are trying to access non existing page in the file.

3)Seek the file pointer to the previous block.

4)Read the content to mempage.
 

	Function : readCurrentBlock
	---------------------------
1)Check if the file handler has been initialzed.

2)If we are reading a non existing page ,then throw an error.

3)Read the content of the current page position to mempage.


	Function : readNextBlock
	------------------------

1)Check if the file handler has been initialzed.

2)Check if we are trying to access a non existing page in the file.

3)Seek the file pointer to the next block.

4)Read the content to mempage. 


	Function : readLastBlock
	------------------------

1)Check if the file handler has been initialzed.

2)Move the file file pointer to the last page of the file.

3)Read the content to mempage.


	Function: writeBlock
	---------------------
	
1)Check if the file handler has been initialzed.

2)Get the current Position of the file.
	
3)Write Contents to the file. If failed,throw an error message. 


	Function: writeCurrentBlock
	----------------------------
	
1)Check if the file handler has been initialzed.

2)Check if we are trying to access a non existing page in the file.

3)Seek the file pointer to the number of pages passed.

4)Write Contents to the file. If failed,throw an error message. 


	Function : appendEmptyBlock
	-------------------------------
	
1)Check if the file handler has been initialzed.

2.Check for the total number of pages and update the total number of pages.

3.Seek the file pointerto the lat page and  print'\0' for PAGE_SIZE bytes.



	Function : ensureCapacity
	-----------------------------
	
1) Get the size of the page block.

2) Check if the size of the page block is greater than the number of pages.If true,then the capacity has been ensured.

3) Else,print'\0' for the remaining pages.


3) Additional Test Cases
------------------------

We have included additional test cases for executing the following functions.


-GetBlockPosition

-ReadCurrentBlock

-ReadPreviousBlock

-ReadNextBlock

-WriteCurrentBlock

-ReadLastBlock

-EnsureCapacity


4) Implementation
-----------------

Before the actual coding of the project was done,we figured out the cause and effect of the problem,which made the implementation more systematic.

We then split the project into 3 modules and worked on the modules.
 
The modules being:
 
a)Functions pertaning to open,close,destroy a page file.

b)Functions pertaining to read operations.

c)Functions pertaining to write operation.

then,the code was integrated using GitHub.

The implementation versions with the descriptions are as follows.

Version 	   Date 	   Description				
----------    --------   ------------
version 1.0  9/25/2014   Initial code had logical and syntax 					   errors

version 1.1  9/26/2014   Errors had been rectified and makefile 					   was created

version 1.2  9/27/2014   Changes in ensure capacity were   				              incorporated     

version 1.3  10/02/2014  All test cases were sucessfully 					  	   implemented and additional test cases 					   were added

version 1.4  10/03/2014  makefile was updated and comments were 
(FINAL)			   added to improve readability of the 					   code.
 



----------------------------------------------------------------------------------------------------------------------------------
 


