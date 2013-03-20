/* chselect.c
 * 
 * T. Hennessy
 *
 * Description: Control for homemade audio switching matrix made in a FPGA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define MAX_STR_LEN 20

int getNum ( void );

void reset ( void )
{
    digitalWrite ( 2, 0 );
    digitalWrite ( 3, 0 );
    digitalWrite ( 4, 0 );
    digitalWrite ( 17, 0 );
    digitalWrite ( 27, 0 );
    digitalWrite ( 22, 0 );
    digitalWrite ( 10, 0 );
    digitalWrite ( 9, 0 );
    digitalWrite ( 11, 0 );
}
int main(int argc, char *argv[])
{
    char input, output;
    int dummyRead;

    if (wiringPiSetupGpio () == -1)
        exit (1);

    pinMode ( 2, OUTPUT);   //enable
    pinMode ( 3, OUTPUT);   //1
    pinMode ( 4, OUTPUT);   //0
    pinMode ( 17, OUTPUT);  //3
    pinMode ( 27, OUTPUT);  //2
    pinMode ( 22, OUTPUT);  //5
    pinMode ( 10, OUTPUT);  //4
    pinMode ( 9, OUTPUT);   //7
    pinMode ( 11, OUTPUT);  //6

    reset();

    while ( 1 && output != '5' )
    {

        printf("Enter 5 to quit\n");
        printf("Choose output\n");

        output = getchar();

        dummyRead = getchar();

        if ( output != '5' && output != '6' )
        {
            printf("Choose input\n");

            input = getchar();

            dummyRead = getchar();
        }

        switch ( output )
        {
            case '1':
                switch ( input )
                {
                    case '2':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 3, 0 );
                        digitalWrite ( 4, 0 );
                        break;
                    case '1':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 3, 0 );
                        digitalWrite ( 4, 1 );
                        break;
                    case '3':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 3, 1 );
                        digitalWrite ( 4, 0 );
                        break;
                    case '4':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 3, 1 );
                        digitalWrite ( 4, 1 );
                        break;
                }
                break;
            case '2':
                switch ( input )
                {
                    case '2':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 17, 0 );
                        digitalWrite ( 27, 0 );
                        break;
                    case '1':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 17, 0 );
                        digitalWrite ( 27, 1 );
                        break;
                    case '3':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 17, 1 );
                        digitalWrite ( 27, 0 );
                        break;
                    case '4':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 17, 1 );
                        digitalWrite ( 27, 1 );
                        break;
                }
                break;
            case '3':
                switch ( input )
                {
                    case '2':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 22, 0 );
                        digitalWrite ( 10, 0 );
                        break;
                    case '1':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 22, 0 );
                        digitalWrite ( 10, 1 );
                        break;
                    case '3':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 22, 1 );
                        digitalWrite ( 10, 0 );
                        break;
                    case '4':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 22, 1 );
                        digitalWrite ( 10, 1 );
                        break;
                }
                break;
            case '4':
                switch ( input )
                {
                    case '2':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 9, 0 );
                        digitalWrite ( 11, 0 );
                        break;
                    case '1':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 9, 0 );
                        digitalWrite ( 11, 1 );
                        break;
                    case '3':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 9, 1 );
                        digitalWrite ( 11, 0 );
                        break;
                    case '4':
                        digitalWrite ( 2, 1 );
                        digitalWrite ( 9, 1 );
                        digitalWrite ( 11, 1 );
                        break;
                }
                break;          
            case '6':
                reset();
                break;
        }

        if ( output == '5' )
        {
            printf ( "Goodbye.\n\n" );
            reset();
        }
    }

    return 0;
}

int getNum ( void )
{
    char *in;
    in = malloc ( sizeof ( *in ) * MAX_STR_LEN );
    
    if ( in == NULL )
        printf("Error memory could not be allocated for input");

    memset ( in, 0, ( sizeof ( *in ) * MAX_STR_LEN ));

    int num;

    printf("\nInput a number ");
    fgets ( in, MAX_STR_LEN, stdin );

    if ( in [ strlen ( in ) - 1 ] == '\n' )
        in [ strlen ( in ) - 1 ] = '\0';

    num = atoi ( in );

    free ( in );

    return num;
}
