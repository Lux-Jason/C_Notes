//#include<stdio.h>
//// fgetc--Read a character from a stream (fgetc, fgetwc) or stdin (_fgetchar, _fgetwchar).
////int fgetc( FILE *stream );
///* FGETC.C: This program uses getc to read the first
// * 80 input characters (or until the end of input)
// * and place them into a string named buffer.
// */
//#include <stdio.h>
//#include <stdlib.h>
//void main(void)
//{
//    FILE* stream;
//    char buffer[81];
//    int  i, ch;
//
//    /* Open file to read line from: */
//    if ((stream = fopen("fgetc.c", "r")) == NULL)
//        exit(0);
//
//    /* Read in first 80 characters and place them in "buffer": */
//    ch = fgetc(stream);
//    for (i = 0; (i < 80) && (feof(stream) == 0); i++)
//    {
//        buffer[i] = (char)ch;
//        ch = fgetc(stream);
//    }
//
//    /* Add null to end string */
//    buffer[i] = '\0';
//    printf("%s\n", buffer);
//    fclose(stream);
//}
//
//
//// fgets--Get a string from a stream.
////char *fgets( char *string, int n, FILE *stream );
///* FGETS.C: This program uses fgets to display
//   a line from a file on the screen.
// */
//
//#include <stdio.h>
//
//void main(void)
//{
//    FILE* stream;
//    char line[100];
//
//    if ((stream = fopen("fgets.c", "r")) != NULL)
//    {
//        if (fgets(line, 100, stream) == NULL)
//            printf("fgets error\n");
//        else
//            printf("%s", line);
//        fclose(stream);
//    }
//}
//
//// fopen--Open a file.
////FILE *fopen( const char *filename, const char *mode );
///* FOPEN.C: This program opens files named "data"
// * and "data2".It  uses fclose to close "data" and
// * _fcloseall to close all remaining files.
// */
//#include <stdio.h>
//FILE* stream, * stream2;
//void main(void)
//{
//    int numclosed;
//
//    /* Open for read (will fail if file "data" does not exist) */
//    if ((stream = fopen("data", "r")) == NULL)
//        printf("The file 'data' was not opened\n");
//    else
//        printf("The file 'data' was opened\n");
//
//    /* Open for write */
//    if ((stream2 = fopen("data2", "w+")) == NULL)
//        printf("The file 'data2' was not opened\n");
//    else
//        printf("The file 'data2' was opened\n");
//
//    /* Close stream */
//    if (fclose(stream))
//        printf("The file 'data' was not closed\n");
//
//    /* All other files are closed: */
//    numclosed = _fcloseall();
//    printf("Number of files closed by _fcloseall: %u\n", numclosed);
//}
//
//// fputc--Writes a character to a stream (fputc, fputwc) or to stdout (_fputchar, _fputwchar).
////int fputc( int c, FILE *stream );
///* FPUTC.C: This program uses fputc and _fputchar
// * to send a character array to stdout.
// */
//#include <stdio.h>
//void main(void)
//{
//    char strptr1[] = "This is a test of fputc!!\n";
//    char strptr2[] = "This is a test of _fputchar!!\n";
//    char* p;
//
//    /* Print line to stream using fputc. */
//    p = strptr1;
//    while ((*p != '\0') && fputc(*(p++), stdout) != EOF);
//
//    /* Print line to stream using _fputchar. */
//    p = strptr2;
//    while ((*p != '\0') && _fputchar(*(p++)) != EOF)
//        ;
//}
//
//// fputs--Write a string to a stream.
////int fputs( const char *string, FILE *stream );
///* FPUTS.C: This program uses fputs to write
// * a single line to the stdout stream.
// */
//
//#include <stdio.h>
//
//void main(void)
//{
//    fputs("Hello world from fputs.\n", stdout);
//}
//
//// fclose--Closes a stream (fclose) or closes all open streams (_fcloseall).
////int fclose( FILE *stream );
///* FOPEN.C: This program opens files named "data"
// * and "data2".It  uses fclose to close "data" and
// * _fcloseall to close all remaining files.
// */
//#include <stdio.h>
//FILE* stream, * stream2;
//void main(void)
//{
//    int numclosed;
//
//    /* Open for read (will fail if file "data" does not exist) */
//    if ((stream = fopen("data", "r")) == NULL)
//        printf("The file 'data' was not opened\n");
//    else
//        printf("The file 'data' was opened\n");
//
//    /* Open for write */
//    if ((stream2 = fopen("data2", "w+")) == NULL)
//        printf("The file 'data2' was not opened\n");
//    else
//        printf("The file 'data2' was opened\n");
//
//    /* Close stream */
//    if (fclose(stream))
//        printf("The file 'data' was not closed\n");
//
//    /* All other files are closed: */
//    numclosed = _fcloseall();
//    printf("Number of files closed by _fcloseall: %u\n", numclosed);
//}
//
//// fscanf--Read formatted data from a stream.
////int fscanf( FILE *stream, const char *format [, argument ]... );
///* FSCANF.C: This program writes formatted
// * data to a file. It then uses fscanf to
// * read the various data back from the file.
// */
//#include <stdio.h>
//FILE* stream;
//void main(void)
//{
//    long l;
//    float fp;
//    char s[81];
//    char c;
//
//    stream = fopen("fscanf.out", "w+");
//    if (stream == NULL)
//        printf("The file fscanf.out was not opened\n");
//    else
//    {
//        fprintf(stream, "%s %ld %f%c", "a-string",
//            65000, 3.14159, 'x');
//
//        /* Set pointer to beginning of file: */
//        fseek(stream, 0L, SEEK_SET);
//
//        /* Read data back from file: */
//        fscanf(stream, "%s", s);
//        fscanf(stream, "%ld", &l);
//
//        fscanf(stream, "%f", &fp);
//        fscanf(stream, "%c", &c);
//
//        /* Output data read: */
//        printf("%s\n", s);
//        printf("%ld\n", l);
//        printf("%f\n", fp);
//        printf("%c\n", c);
//
//        fclose(stream);
//    }
//}
//
//// fprintf--Print formatted data to a stream.
////int fprintf( FILE *stream, const char *format [, argument ]...);
///* FPRINTF.C: This program uses fprintf to format various
// * data and print it to the file named FPRINTF.OUT. It
// * then displays FPRINTF.OUT on the screen using the system
// * function to invoke the operating-system TYPE command.
// */
//#include <stdio.h>
//#include <process.h>
//FILE* stream;
//void main(void)
//{
//    int    i = 10;
//    double fp = 1.5;
//    char   s[] = "this is a string";
//    char   c = '\n';
//
//    stream = fopen("fprintf.out", "w");
//    /*fprintf returns the number of bytes written. */
//    fprintf(stream, "%s%c", s, c);
//    fprintf(stream, "%d\n", i);
//    fprintf(stream, "%f\n", fp);
//    fclose(stream);
//    system("type fprintf.out");
//}
///*fprintf formats and prints a series of characters and values to the output stream.
//Each function argument (if any) is converted and output according to the corresponding format specification in format. 
//For fprintf, the format argument has the same syntax and use that it has in printf.
//*/
//
//
//
//// fread--Reads data from a stream.
////size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
///* FREAD.C: This program opens a file named FREAD.OUT and
// * writes 25 characters to the file. It then tries to open
// * FREAD.OUT and read in 25 characters. If the attempt succeeds,
// * the program displays the number of actual items read.
// */
//#include <stdio.h>
//void main(void)
//{
//    FILE* stream;
//    char list[30];
//    int  i, numread, numwritten;
//
//    /* Open file in text mode: */
//    if ((stream = fopen("fread.out", "w+t")) != NULL)
//    {
//        for (i = 0; i < 25; i++)
//            list[i] = (char)('z' - i);
//        /* Write 25 characters to stream */
//        numwritten = fwrite(list, sizeof(char), 25, stream);
//        printf("Wrote %d items\n", numwritten);
//        fclose(stream);
//
//    }
//    else
//        printf("Problem opening the file\n");
//
//    if ((stream = fopen("fread.out", "r+t")) != NULL)
//    {
//        /* Attempt to read in 25 characters */
//        numread = fread(list, sizeof(char), 25, stream);
//        /*fread returns the number of full items actually read,
//        which may be less than count if an error occurs or if the end of the file is encountered before reaching count. 
//        Use the feof or ferror function to distinguish a read error from an end-of-file condition. 
//        If size or count is 0, fread returns 0 and the buffer contents are unchanged.*/
//
//
//        printf("Number of items read = %d\n", numread);
//        printf("Contents of buffer = %.25s\n", list);
//        fclose(stream);
//    }
//    else
//        printf("File could not be opened\n");
//}
//
//
//// fwrite--Writes data to a stream.
////size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
///* FREAD.C: This program opens a file named FREAD.OUT and
// * writes 25 characters to the file. It then tries to open
// * FREAD.OUT and read in 25 characters. If the attempt succeeds,
// * the program displays the number of actual items read.
// */
//#include <stdio.h>
//void main(void)
//{
//    FILE* stream;
//    char list[30];
//    int  i, numread, numwritten;
//
//    /* Open file in text mode: */
//    if ((stream = fopen("fread.out", "w+t")) != NULL)
//    {
//        for (i = 0; i < 25; i++)
//            list[i] = (char)('z' - i);
//        /* Write 25 characters to stream */
//        numwritten = fwrite(list, sizeof(char), 25, stream);
//        printf("Wrote %d items\n", numwritten);
//        fclose(stream);
//
//    }
//    else
//        printf("Problem opening the file\n");
//
//    if ((stream = fopen("fread.out", "r+t")) != NULL)
//    {
//        /* Attempt to read in 25 characters */
//        numread = fread(list, sizeof(char), 25, stream);
//        printf("Number of items read = %d\n", numread);
//        printf("Contents of buffer = %.25s\n", list);
//        fclose(stream);
//    }
//    else
//        printf("File could not be opened\n");
//}
///*The fwrite function writes up to count items, of size length each, from buffer to the output stream. 
//The file pointer associated with stream (if there is one) is incremented by the number of bytes actually written. 
//If stream is opened in text mode, each carriage return is replaced with a carriage-return ¨C linefeed pair. 
//The replacement has no effect on the return value.
//*/
//
//
//// fseek--Moves the file pointer to a specified location.
////int fseek( FILE *stream, long offset, int origin );
///*Beginning of file
//
//You can use fseek to reposition the pointer anywhere in a file.
//The pointer can also be positioned beyond the end of the file.
//fseek clears the end-of-file indicator and negates the effect of any prior ungetc calls against stream.
//
//When a file is opened for appending data,
//the current file position is determined by the last I/O operation,not by where the next write would occur.
//If no I/O operation has yet occurred on a file opened for appending, the file position is the start of the file. 
//
//For streams opened in text mode, fseek has limited use, because carriage return¨Clinefeed translations can cause fseek to produce unexpected results.
//The only fseek operations guaranteed to work on streams opened in text mode are: 
//Seeking with an offset of 0 relative to any of the origin values.
//Seeking from the beginning of the file with an offset value returned from a call to ftell. 
//Also in text mode, CTRL+Z is interpreted as an end-of-file character on input. 
//In files opened for reading/writing, fopen and all related routines check for a CTRL+Z at the end of the file and remove it if possible.
//This is done because using fseek and ftell to move within a file that ends with a CTRL+Z may cause fseek to behave improperly near the end of the file. 
//*/
//
///* FSEEK.C: This program opens the file FSEEK.OUT and
// * moves the pointer to the file's beginning.
// */
//
//#include <stdio.h>
//
//void main(void)
//{
//    FILE* stream;
//    char line[81];
//    int  result;
//
//    stream = fopen("fseek.out", "w+");
//    if (stream == NULL)
//        printf("The file fseek.out was not opened\n");
//    else
//    {
//        fprintf(stream, "The fseek begins here: "
//            "This is the file 'fseek.out'.\n");
//        result = fseek(stream, 23L, SEEK_SET);
//        if (result)
//            perror("Fseek failed");
//        else
//        {
//            printf("File pointer is set to middle of first line.\n");
//            fgets(line, 80, stream);
//            printf("%s", line);
//
//        }
//        fclose(stream);
//    }
//}
///*The fseek function moves the file pointer (if any) associated with stream to a new location that is offset bytes from origin.
//The next operation on the stream takes place at the new location.
//On a stream open for update, the next operation can be either a read or a write.
//The argument origin must be one of the following constants, defined in STDIO.H:
//*/
