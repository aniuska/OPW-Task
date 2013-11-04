#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char MinVersion[] = "8.4";
char MaxVersion[] = "9.1";

int power(int base, unsigned int exp) 
{
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
 }

/*
   1)Convert version strings in numbers in the follow way:

   strversion = "9.1.4"
   intversion = 9 * 1000 + 1 * 100 + 4 * 10 =  9140

   2) Compare numeric versions to see if it is between Minversion
      and Max version
   3) Return 1 Minversion <= Cversion <= Maxversion
      return 0 otehr case

*/

int version_cmp(const char Version[], const char MinVersion[], const char MaxVersion[])
{

       char *strMinVersion, *strMaxVersion, *strVersion;
       char *digitv[7], *digitmi[7], *digitmx[7];
       int i = 0, j;
       int len;
       int intVersion = 0, intMinVersion = 0, intMaxVersion = 0;
/*
       strMinVersion = strdpa(MinVersion);
       strMaxVersion =  strdpa(MaxVersion);
       strVersion =  strdpa(Version);
*/
       strMinVersion = (char *) malloc(sizeof(MinVersion)* sizeof(char));
       strMaxVersion =  (char *) malloc(sizeof(MaxVersion)* sizeof(char));
       strVersion =  (char *) malloc(sizeof(Version)* sizeof(char));

       strcpy(strMinVersion,MinVersion);
       strcpy(strMaxVersion, MaxVersion);
       strcpy(strVersion,Version);

        digitv[i] = strtok(strVersion,".");

        while(digitv[i]!=NULL)
        {
           digitv[++i] = strtok(NULL,".");

        }
        len = i;
        
        for (i=0,j=len; i< len; i++, j--) 
        {
        intVersion +=  atoi(digitv[i])  * power(10, j);

        }

        i=0;
        digitmi[i] = strtok(strMinVersion,".");

        while(digitmi[i]!=NULL)
        {
           digitmi[++i] = strtok(NULL,".");
        }

        len = i;

        for (i=0,j=len; i< len; i++, j--) 
        {

        intMinVersion += atoi(digitmi[i])  * power(10, j);


        }

        i=0;
        digitmx[i] = strtok(strMaxVersion,".");

        while(digitmx[i]!=NULL)
        {
           digitmx[++i] = strtok(NULL,".");
        }

        len = i;      

        for (i=0,j=len; i< len; i++, j--) 
        {

            intMaxVersion +=  atoi(digitmx[i])  * power(10, j);

        }

        free(strMinVersion);
        free(strMaxVersion);
        free(strVersion);

        if( !(intVersion < intMinVersion || intVersion > intMaxVersion) )
        {
            return 1;
        }

        return 0;
            
}

int main(void)
{
   
   printf("Min version=%s\nMax version=%s\n\n", MinVersion, MaxVersion);
   printf("Curent version=%s result=%d\n","10.1",version_cmp("10.1", MinVersion, MaxVersion));
   printf("Curent version=%s result=%d\n","8.1",version_cmp("8.1", MinVersion, MaxVersion));
   printf("Curent version=%s result=%d\n","8.5",version_cmp("8.5", MinVersion, MaxVersion));
   printf("Curent version=%s result=%d\n","8.2.1",version_cmp("8.2.1", MinVersion, MaxVersion));
   printf("Curent version=%s result=%d\n","8.4",version_cmp("8.4", MinVersion, MaxVersion));
   printf("Curent version=%s result=%d\n","9.1.2",version_cmp("9.1.2", MinVersion, MaxVersion));
   printf("Curent version=%s result=%d\n","9.1.a",version_cmp("9.1.a", MinVersion, MaxVersion));
   printf("Curent version=%s result=%d\n","9.1",version_cmp("9.1", MinVersion, MaxVersion));
}
