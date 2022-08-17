    //Luna Dana 260857641 
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    int main(int argc, char* argv[])  {
        /////////////If SHOW
            if(argc<2){
                    puts("Your did not provide any arguments. Please enter: ./database CMD OPT1 OPT2 OPT3 OPT4");
                    return -1; }

           char *a = argv[1];
           char *b = "SHOW";
           char *c = "DELETE";
           char *d = "ADD";
            if(strcmp(a,b)!=0 && strcmp(a,c)!=0 && strcmp(a,d)!=0){
                    puts("The command you requested in invalid. Please select from one of these: SHOW, DELETE, ADD");
                    return -8; }

            if(strcmp(a,b)==0){
            char buffer[1000];
            FILE *p = fopen("database.csv","r");
            
            if(p == NULL){
                return -1;
            }

            
            char NAME[250], AGE[250], ID[250], GPA[250];
            int age, id;
            float gpa;

            int o = 1;
            
            fgets(buffer, 999, p);
            while(!feof(p)){

                if(strcmp(buffer,"\n")==0||strcmp(buffer,"\r")==0||strcmp(buffer,"\0")==0){
                    continue;
                }

                int i = 0;
                int j;

                for(j=0; j<250 && buffer[i]!=',';i++) {
                    if(buffer[i] != ' ' || buffer[i] != '\n') {
                        ID[j] = buffer[i];
                        j++;
                    }
                }
                ID[j] = '\0';
                i++;
                id = atoi(ID);
                
                 for(j=0;j<250 && buffer[i]!=',';i++){
                    if (buffer[i] != ' ' || buffer[i] != '\n') {
                        NAME[j] = buffer[i];
                        j++;
                      }  
                }
                 NAME[j] = '\0';
                 i++;

                 for(j=0;j<250 && buffer[i]!=',';i++){
                    if (buffer[i] != ' ' || buffer[i] != '\n') {
                        AGE[j] = buffer[i];
                        j++;
                    }
                }
                AGE[j] = '\0';
                i++;
                age = atoi(AGE);


                for(j=0;j<250 && buffer[i]!=',';i++){
                    if (buffer[i] != ' '|| buffer[i] != '\n') {
                        GPA[j] = buffer[i];
                        j++;
                    }
                }
                GPA[j] = '\0';
                gpa = atof(GPA);

                printf("Record %d : ID= %d\tNAME= %s\tAGE= %d\tGPA= %.1f\n",o,id,NAME,age,gpa);
                  o++;
                  fgets(buffer, 999, p);
                          } 
                fclose(p);
                  return 0; 
                            }

     ///////IF DELETE                       
                if(strcmp(a,c)==0){
                        if(argc<3){
                            puts("Name of record to delete is missing");
                            return -1; }


                FILE *f = fopen("database.csv","r");
                FILE *destination = fopen("database.temp","wt");
                
                char buffer[1000];
                char ID[1000];

                int id;
                int idToDelete = atoi(argv[2]);

                if(f == NULL){
                return -1;
                }

                int record = 0;
                int j;


                while(!feof(f)){
                fgets(buffer, 999, f);
                
                int i = 0;
                for(j=0; j<1000 && buffer[i]!=',';i++) {
                    if(buffer[i] != ' ') {
                        ID[j] = buffer[i];
                        j++;
                    }
                }
                ID[j] = '\0';
                i++;
                
                id = atoi(ID);
                

                if(id == idToDelete && record == 0){
                    record++;
                }else{
                    fputs(buffer,destination);
                }

                }
                if(record == 0){
                    printf("Sorry, that user was not found, nothing was deleted\n");
                    return -1;
                }
                system("rm database.csv");
                system("mv database.temp database.csv");

                                    }
////////IF ADD
if(strcmp(a,d)==0){
if(argc < 6){
    printf("Missing ID, NAME, AGE, and GPA arguments");
}
FILE *f = fopen("database.csv","at");

int id = atoi(argv[2]);
char* name = argv[3];
int age = atoi(argv[4]);
float gpa = atof(argv[5]);

char string[500];
snprintf(string, 500, "%d, %s, %d, %.1f\n",id,name,age,gpa);
fputs(string, f);

}


    } 