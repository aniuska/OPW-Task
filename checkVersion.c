#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char lowerVersion[] = "8.4";
char upperVersion[] = "9.1";

int version_cmp(const char Version[], const char MinVersion[], const char MaxVersion[])
{

       char *strMinVersion, *strMaxVersion, *strVersion;
       char *digitv[7], *digitmi[7], *digitmx[7];
       int i = 0, j;
       int len;
       long int intVersion, rangeVersion, subVersion=0;
       char *p1, *p2, *strp1;
       

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
        len =i;
      
        i=0;
        digitmi[i] = strtok(strMinVersion,".");

        while(digitmi[i]!=NULL)
        {
           digitmi[++i] = strtok(NULL,".");
        }
        
        if ( len < i) len = i; 
        i=0;
        digitmx[i] = strtok(strMaxVersion,".");

        while(digitmx[i]!=NULL)
        {
           digitmx[++i] = strtok(NULL,".");
        }
        if ( len < i) len = i; 

        //check lower limit
        
        for (i=0; i< len; i++)
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
            
            p1 = digitv[i];
            p2 = digitmi[i];

           if (p1 && p2) {
                intVersion = atoi(p1);
                rangeVersion = atoi(p2);

                if ( intVersion && rangeVersion) //is number
                {
                       if (intVersion < rangeVersion)
                         return 0;
                       if ( intVersion > rangeVersion )
                                 break;
              
                       
                } else { //alphanumeric or null
                   
                   if ( i == 0 || *p1 == 'r' ) {
                      //extract numbers and compare numbers
                      strp1 = p1;
                      while (*strp1) {
                          
                          if ( isdigit(*strp1) ) {
                             
                             subVersion = strtol(strp1,&strp1,10);
                             break;
                          }
                          else
                             strp1++;
                     }
                          
                          if (subVersion < rangeVersion ) return 0;
                          
                          if ( subVersion > rangeVersion ) break;
                   } else {//alpha or beta
                       return 0;
                       
                   }
                }
               
            } else { //one is null
                
                if (!p1 && !p2) break;
                if (!p1) return 0;
                if (!p2) break;
            }
        }
        

       //check upper limit
       for (i=0; i< len; i++)
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
            
            p1 = digitv[i];
            p2 = digitmx[i];

           if (p1 && p2) {
                intVersion = atoi(p1);
                rangeVersion = atoi(p2);

                if ( intVersion && rangeVersion) //is number
                {
                       if (intVersion > rangeVersion)
                         return 0;
                       else if ( intVersion < rangeVersion )
                                 break;
                       
                       
                } else { //alphanumeric
                   
                   if ( i == 0 || *p1 == 'r' ) {
                      //extract numbers and compare numbers

                      strp1 = p1;
                      while (*strp1) {
                                                    
                          if ( isdigit(*strp1) ) {
                             
                             subVersion = strtol(strp1,&strp1,10);
                             break;
                          }
                          else
                             strp1++;
                     }
                          
                          if (subVersion > rangeVersion ) return 0;
                          
                          if ( subVersion < rangeVersion ) break;
                   } else {//alpha or beta
                       return 1;
                       
                   }
                }
               
            } else { //one is null
                
                if (!p1 && !p2) break;
                if (!p1) return 1;
                if (!p2) break;
            }
        }

        free(strMinVersion);
        free(strMaxVersion);
        free(strVersion);

       

        return 1;
            
}

int main(void)
{
   
   printf("Min version=%s\nMax version=%s\n\n", lowerVersion, upperVersion);

   printf("Legend: \nresult=1 means good version\nresult=0 means bad version");

   printf("\n\nCurent version=%s result=%d\n","8.4.5",version_cmp("8.4.5", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","8.1",version_cmp("8.1", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","8.5",version_cmp("8.5", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","8.2.1",version_cmp("8.2.1", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","8.4",version_cmp("8.4", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","8.4.4",version_cmp("8.4.4", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","9.1.2",version_cmp("9.1.2", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","9.1.a",version_cmp("9.1.a", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","9.1",version_cmp("9.1", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","10.1",version_cmp("10.1", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","8.r",version_cmp("8.r", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","8.r1",version_cmp("8.r1", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","v10.1",version_cmp("v10.1", lowerVersion, upperVersion));
   printf("Curent version=%s result=%d\n","v9.1",version_cmp("v9.1", lowerVersion, upperVersion));  
  
}