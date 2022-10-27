#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


int main(int argc, char **argv, char **envp)
{

    //falls keine gefilterte Suche
    if(argc <= 1){
        while(*envp!=NULL) {
            printf("%s\n", *envp);
            envp++;
        }
    }

    //gefilterte Suche ohne weitere Parameter
    if(argc == 2){
        while (*envp != NULL){
        
            if(strstr(*envp,argv[1]) != NULL){
                printf("%s\n", *envp);
                envp++;
            }else{
                envp++;
            }
        }
    }
 

    //gefilterte Suche mit "-n"
    if(argc == 3 && strstr(argv[1],"-n") != NULL){
        while(*envp != NULL){
            if(strstr(*envp,argv[2]) != NULL)
            {
            char* temp;
            char* ptr;

            temp = *envp;
            ptr = strchr(temp,'=');
                 if(ptr != NULL){
                     *ptr = '\0';
                 }
                printf("%s\n", temp);

                envp++;
                    
            }
            else{
                envp++;
            }
        }
    
    }

    //gefilterte Suche mit "-i"
     if(argc == 3 && strstr(argv[1],"-i") != NULL){
        while(*envp != NULL){
            
            char* temp = argv[2];
            int j = 0;
            while(temp[j]){
                temp[j] = toupper(temp[j]);
                j++;
            }

            if (strstr(*envp,temp) != NULL)
            {
                printf("%s\n",*envp);
                envp++;
            }
            else envp++;
        }
    
    }


    //gefilterte Suche mit "-n" unf "-i"
    if(argc == 4 && strstr(argv[1], "-n") !=NULL && strstr(argv[2],"-i") !=NULL|| argc == 4 && strstr(argv[1], "-i") !=NULL && strstr(argv[2],"-n")!=NULL){
         while(*envp != NULL){

            char* temp = argv[3];
            int j = 0;
            while(temp[j]){
                temp[j] = toupper(temp[j]);
                j++;
            }
            //
             if(strstr(*envp,temp) != NULL){

                char* envtemp;
                char* ptr;

                envtemp = *envp;
                ptr = strchr(envtemp,'=');
                if(ptr != NULL){
                     *ptr = '\0';
                 }
                 printf("%s\n", envtemp);
                 envp++;

             }
             else envp++;
            

        }
    }

    return 0;
  
}
    
    



