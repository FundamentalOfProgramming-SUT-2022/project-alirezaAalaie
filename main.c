#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
void print_tab(int f,FILE* cptr);
FILE* crooshe_yab(FILE *fptr );
void file_name_of_addres(char*address,char *filename);
void copy_file(char *addres,FILE*fptr );
void neveshtan(FILE*cptr,FILE*str);
void input_addres(char *addres){
    scanf(" ");
    char end;
    scanf("%c",&end);

    if(end !='"'){
        end=' ';

    }

    int i=-1;
    do{
        i++;
        scanf("%c",addres+i);

    }while(addres[i]!=end);

    addres[i]='\0';


    char a[100]="/";

    if (addres[0]!='/'){
        strcat(a,addres);

        strcpy(addres,a);

    }

}
void input_str(){
     FILE*str;
    str=fopen("str.txt","w");
    scanf(" ");
    char end;
    scanf("%c",&end);


    if (end!='"'){
        fprintf(str,"%c",end);
        end=' ';
        char c;
        while((c=getchar())!=end){

            fprintf(str,"%c",c);

        }



    }else{
        char c=' ';
        char b;
        while(1){


            b=c;
            scanf("%c",&c);

            if (c=='"' && b!='\\'){

                break;
            }
            fprintf(str,"%c",c);
        }
    }
//fprintf(str,"%c",'^c');
fclose(str);


    //printf("%s\n",str);
    return;


}
long long int end_of_rc(int halat,FILE* fptr,long int size_of,long int current_byte ){
//long int i=0;
long int result;
if (halat==1){

    for (long int i=0;i<size_of;i++){
        char c= fgetc(fptr);
        //printf("%c*",c);

    }

}else{
for(int i=0;i<size_of;i++){
        fseek(fptr,-1,SEEK_CUR);
        char c= fgetc(fptr);
        if(c=='\n'){
            fseek(fptr,-2,SEEK_CUR);
            continue;
        }
        fseek(fptr,-1,SEEK_CUR);



}






}



result  =  ftell(fptr);
fseek(fptr,current_byte-result,SEEK_CUR);



    return result;
}


void create_file(){
            char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }

    char addres[101];
    input_addres(addres);
    char sar_addres[100];

    for(int i=0;i<strlen(addres);i++){
        sar_addres[i]=addres[i+1];
        if (sar_addres[i]=='/'){
            sar_addres[i]='\0';
            struct stat st = {0};
            if (stat(sar_addres, &st) == -1) {
                mkdir(sar_addres);
            }
            sar_addres[i]='/';
        }
        if(sar_addres[i]=='\0'){
            FILE*fptr=fopen(sar_addres,"r");
            if (fptr!=NULL){

                printf("file in this address existed: %s\n",addres);
                return;
            }
            fclose(fptr);
            fopen(sar_addres,"a");
            fclose(fptr);
            printf("file in this address created: %s\n",addres);
            return;

        }

    }
}


void insert_str(){

 char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }
    char addres[1001];
    input_addres(addres);
    char order_str[10];

    scanf("%s",order_str);
    if  (strcmp(order_str,"--str")!=0){

        return;
    }

    input_str();
    char order_pos[10];

    scanf("%s",order_pos);
    if  (strcmp(order_pos,"--pos")!=0){

        return;
    }

    int n,x;
    scanf("%d:%d",&n,&x);



char sar_addres[100];
for(int i=0;i<strlen(addres);i++){
    sar_addres[i]=addres[i+1];
    }
FILE*fptr=fopen(sar_addres,"r");
if (fptr==NULL){

            printf("file in this address is not existed: %s\n",addres);
            return;
            }


copy_file(sar_addres,fptr);
FILE*cptr=fopen("matn.txt","w");
int sn=1,sx=0;
char c;
int f=0;
while((c=fgetc(fptr))!=EOF){

    if(sn==n && f==0){

            for (;sx<x;++sx){

                if (c=='\n' ){
                        for(int i=0 ;i<x-sx;i++){
                            fprintf(cptr," ");
                        }


                        break;
                }
                fprintf(cptr,"%c",c);
                c=fgetc(fptr);

            }
            FILE*str=fopen("str.txt","r");
            neveshtan(cptr,str);
            fclose(str);
            f=1;
            //sn++;



    }
     if(c=='\n'){
        sn++;


    }

    fprintf(cptr,"%c",c);
}


if(f==0){

    if (sn<=n){

        for(int j=0;j<n-sn;j++){
        fprintf(cptr,"\n");
        }
        int a=x;
        if (sn==n){
            a=x-sx;
        }
        for(int i=0 ;i<a;i++){
                            fprintf(cptr," ");
                        }
        FILE*str=fopen("str.txt","r");
        neveshtan(cptr,str);
            fclose(str);
    }
    //printf("your line is empty!\n");

}
fclose(fptr);
fclose(cptr);
cptr=fopen("matn.txt","r");
fptr=fopen(sar_addres,"w");
c=' ';
for(long long int i=0;(c=fgetc(cptr))!=EOF;i++){

fprintf(fptr,"%c",c);
}
fclose(fptr);
fclose(cptr);
printf("your text added in this file: %s\n",addres);

}
void neveshtan(FILE*cptr,FILE*str){


char c;
while((c=fgetc(str))!=EOF){

        if (c=='\\'){
            c=fgetc(str);
            if (c=='n'){
                fprintf(cptr,"\n");
            }else{
            fprintf(cptr,"%c",c);
            }
            }else{

                fprintf(cptr,"%c",c);

            }

}
return;

}

void cat(){
     char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }
    char addres[1001];

    input_addres(addres);
    char sar_addres[1000];
    for(int i=0;i<strlen(addres);i++){
        sar_addres[i]=addres[i+1];
    }
    FILE*fptr=fopen(sar_addres,"r");
    if (fptr==NULL){

        printf("file in this address  is not existed: %s\n",addres);
        return;
    }

    printf("this is text of file: %s\n",addres);
    printf("******************************************************************\n");
    char c=' ';
    for(long long int i=0;(c=fgetc(fptr))!=EOF;i++){

        printf("%c",c);

    }
    printf("\n");
    printf("******************************************************************\n");
    fclose(fptr);


}
void remove_str(){
     char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }
    char addres[1001];
    input_addres(addres);

    char order_pos[10];
    scanf("%s",order_pos);
    if  (strcmp(order_pos,"--pos")!=0){

        return;
    }

    int n,x;
    scanf("%d:%d",&n,&x);
    char order_size[10];
    scanf(" %s",order_size);

    if  (strcmp(order_size,"-size")!=0){

        return;
    }
    int size_of_remove;
    char halat;
    scanf("%d",&size_of_remove);
    scanf(" -%c",&halat);

int halat_dahandeh=1;
if (halat=='b'){
    halat_dahandeh=-1;
}

char sar_addres[1000];
for(int i=0;i<strlen(addres);i++){
    sar_addres[i]=addres[i+1];
    }
FILE*fptr=fopen(sar_addres,"r");
if (fptr==NULL){

            printf("file in this address is not existed: %s\n",addres);
            return;
            }


copy_file(sar_addres,fptr);
FILE*cptr=fopen("matn.txt","w");
int sn=1,sx=0;
char c;
int sor,eor;
while((c=fgetc(fptr))!=EOF){
    if(sn==n){
            if (sx==x){
            if (halat_dahandeh==1){
            sor=ftell(fptr);
            eor=end_of_rc(halat_dahandeh,fptr,size_of_remove,sor);
            }
            else{

            eor=ftell(fptr);
            sor=end_of_rc(halat_dahandeh,fptr,size_of_remove,eor);


            }
            }
        sx++;



    }
     if(c=='\n'){
        sn++;


    }
    fprintf(cptr,"%c",c);
}

fclose(fptr);
fclose(cptr);


cptr=fopen("matn.txt","r");
fptr=fopen(sar_addres,"w");

for(long long int i=0;(c=fgetc(cptr))!=EOF;i++){
if (ftell(cptr)>=sor && ftell(cptr)<eor){
    continue;
}

fprintf(fptr,"%c",c);
}


fclose(fptr);
fclose(cptr);
printf("you are remove text from this file: %s\n",addres);

}

void copy_str(){
     char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }
    char addres[1001];
    input_addres(addres);

    char order_pos[10];
    scanf("%s",order_pos);
    if  (strcmp(order_pos,"--pos")!=0){

        return;
    }

    int n,x;
    scanf("%d:%d",&n,&x);
    char order_size[10];
    scanf(" %s",order_size);

    if  (strcmp(order_size,"-size")!=0){

        return;
    }
    int size_of_copy;
    char halat;
    scanf("%d",&size_of_copy);
    scanf(" -%c",&halat);

int halat_dahandeh=1;
if (halat=='b'){
    halat_dahandeh=-1;
}

char sar_addres[1000];
for(int i=0;i<strlen(addres);i++){
    sar_addres[i]=addres[i+1];
    }
FILE*fptr=fopen(sar_addres,"r");
if (fptr==NULL){

            printf("file in this address is not existed: %s\n",addres);
            return;
            }



int sn=1,sx=0;
char c;
int soc,eoc;
while((c=fgetc(fptr))!=EOF){
    if(sn==n){
            if (sx==x){
            if (halat_dahandeh==1){
            soc=ftell(fptr);
            eoc=end_of_rc(halat_dahandeh,fptr,size_of_copy,soc);
            }
            else{

            eoc=ftell(fptr);
            soc=end_of_rc(halat_dahandeh,fptr,size_of_copy,eoc);


            }
            break;
            }
        sx++;

    }
     if(c=='\n'){
        sn++;
    }

}

fclose(fptr);



FILE*cptr=fopen("clipboard.txt","w");

fptr=fopen(sar_addres,"r");

for(long long int i=0;(c=fgetc(fptr))!=EOF;i++){
if (ftell(fptr)>=soc && ftell(fptr)<eoc){
  fprintf(cptr,"%c",c);
}


}


fclose(fptr);
fclose(cptr);
printf("your text copied from this file: %s\n",addres);

}


void cut_str(){
     char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }
    char addres[1001];
    input_addres(addres);

    char order_pos[10];
    scanf("%s",order_pos);
    if  (strcmp(order_pos,"--pos")!=0){

        return;
    }

    int n,x;
    scanf("%d:%d",&n,&x);
    char order_size[10];
    scanf(" %s",order_size);

    if  (strcmp(order_size,"-size")!=0){

        return;
    }
    int size_of_cut;
    char halat;
    scanf("%d",&size_of_cut);
    scanf(" -%c",&halat);

int halat_dahandeh=1;
if (halat=='b'){
    halat_dahandeh=-1;
}

char sar_addres[1000];
for(int i=0;i<strlen(addres);i++){
    sar_addres[i]=addres[i+1];
    }
FILE*fptr=fopen(sar_addres,"r");
if (fptr==NULL){

            printf("file in this address is not existed: %s\n",addres);
            return;
            }

copy_file(sar_addres,fptr);

int sn=1,sx=0;
FILE *cptr=fopen("matn.txt","w");
char c;
int soc,eoc;
while((c=fgetc(fptr))!=EOF){
    if(sn==n){
            if (sx==x){
            if (halat_dahandeh==1){
            soc=ftell(fptr);
            eoc=end_of_rc(halat_dahandeh,fptr,size_of_cut,soc);
            }
            else{

            eoc=ftell(fptr);
            soc=end_of_rc(halat_dahandeh,fptr,size_of_cut,eoc);


            }

            }
        sx++;

    }
     if(c=='\n'){
        sn++;
    }


    fprintf(cptr,"%c",c);

}

fclose(cptr);
fclose(fptr);



FILE*tptr=fopen("clipboard.txt","w");
cptr=fopen("matn.txt","r");
fptr=fopen(sar_addres,"w");

for(long long int i=0;(c=fgetc(cptr))!=EOF;i++){
if (ftell(cptr)>=soc && ftell(cptr)<eoc){
  fprintf(tptr,"%c",c);
  continue;
}
fprintf(fptr,"%c",c);

}

fclose(tptr);
fclose(fptr);
fclose(cptr);
printf("your text cuted from this file: %s\n",addres);

}
void paste_str(){

 char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }
    char addres[1001];
    input_addres(addres);

    char order_pos[10];

    scanf("%s",order_pos);
    if  (strcmp(order_pos,"--pos")!=0){

        return;
    }

    int n,x;
    scanf("%d:%d",&n,&x);



char sar_addres[100];
for(int i=0;i<strlen(addres);i++){
    sar_addres[i]=addres[i+1];
    }
FILE*fptr=fopen(sar_addres,"r");
if (fptr==NULL){

            printf("file in this address is not existed: %s\n",addres);
            return;
            }
copy_file(sar_addres,fptr);
FILE*cptr=fopen("matn.txt","w");
int sn=1,sx=0;
char c;
int f=0;
while((c=fgetc(fptr))!=EOF){


    if(sn==n){

            for (;sx<x;++sx){

                if (c=='\n'){
                        for(int i=0 ;i<x-sx;i++){
                            fprintf(cptr," ");
                        }


                        break;
                }
                fprintf(cptr,"%c",c);
                c=fgetc(fptr);

            }
            FILE*str=fopen("clipboard.txt","r");
            neveshtan(cptr,str);
            fclose(str);
            f=1;
            sn++;



    }
     if(c=='\n'){
        sn++;


    }

    fprintf(cptr,"%c",c);
}

fclose(fptr);
fclose(cptr);
if(f==0){
    printf("your line is empty!\n");
    return;
}
cptr=fopen("matn.txt","r");
fptr=fopen(sar_addres,"w");
c=' ';
for(long long int i=0;(c=fgetc(cptr))!=EOF;i++){

fprintf(fptr,"%c",c);
}
fclose(fptr);
fclose(cptr);
printf("your clipboard pasted in this file: %s\n",addres);

}
void undo(){

 char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }
    char addres[1001];
    input_addres(addres);

char sar_addres[1000];
for(int i=0;i<strlen(addres);i++){
    sar_addres[i]=addres[i+1];
    }
FILE*fptr=fopen(sar_addres,"r");
if (fptr==NULL){

            printf("file in this address is not existed: %s\n",addres);
            return;
            }
FILE* cptr=fopen("matn.txt","w");
char c;
for(long long int i=0;(c=fgetc(fptr))!=EOF;i++){

fprintf(cptr,"%c",c);
}
fclose(cptr);
fseek(fptr,0,SEEK_SET);
char filename[1000];
file_name_of_addres(sar_addres,filename);
fclose(fptr);
FILE* uptr=fopen(filename,"r");
fptr=fopen(sar_addres,"w");

while((c=fgetc(uptr))!=EOF){
    fprintf(fptr,"%c",c);

}

fclose(uptr);
fclose(fptr);
cptr=fopen("matn.txt","r");
copy_file(sar_addres,cptr);
fclose(cptr);

        printf("your file is undo in this addres: %s\n",addres);

}

void copy_file(char *addres,FILE*fptr ){
char filename[1000];
file_name_of_addres(addres,filename);
fseek(fptr,0,SEEK_SET);
FILE* uptr=fopen(filename,"w");
char c;
while((c=fgetc(fptr))!=EOF){
    fprintf(uptr,"%c",c);

}

fclose(uptr);
fseek(fptr,0,SEEK_SET);

}

void file_name_of_addres(char*address,char *filename){
    int len=strlen(address);
    int i=len-1;
    for(;i>=0;i--){
        if(address[i]=='/'){
            break;
        }
    }
    i=i+1;
    filename[0]='c';
    for(int j=1;address[i]!='\0';j++,i++){

        filename[j]=address[i];
    }




}
void find_str(){
char order_str[10];

    scanf("%s",order_str);
    if  (strcmp(order_str,"--str")!=0){

        return;
    }

    input_str();

 char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }
    char addres[1001];
    input_addres(addres);
    char sar_addres[1000];
for(int i=0;i<strlen(addres);i++){
    sar_addres[i]=addres[i+1];
    }
FILE*fptr=fopen(sar_addres,"r");
if (fptr==NULL){

            printf("file in this address is not existed: %s\n",addres);
            return;
            }
fclose(fptr);
fptr=fopen(sar_addres,"r");
FILE*str=fopen("str.txt","r");
long long int ch_count=0;
char c;
char s;
long long int f_index;
int f;
int flag=0;
while((c=fgetc(fptr))!=EOF){
    ch_count++;
    f_index=ch_count;
    f=0;
    for(;(s=fgetc(str))!=EOF;){
          if (s=='*'){
            s=getc(str);
            if(s=='\n' || s==' ' || s==EOF){
                 for(; c!='\n' && c!=' ' && s!=EOF;){
                c=fgetc(fptr);
                ch_count++;
            }

          c=fgetc(fptr);
          ch_count++;
          continue;
            }else{
                long int bit=ftell(str);
                fseek(str,-3,SEEK_CUR);
                char a=fgetc(str);
                if(a==-1){
                 fseek(str,0,SEEK_SET);
                 fseek(str,bit,SEEK_CUR);
                }else{
                fseek(str,2,SEEK_CUR);

                }if (a==' ' || a=='\n'  || a==-1){

                    flag++;
                for(; c!=s ;)
                    {
                c=fgetc(fptr);
                if(c==EOF){
                    f_index=-1;
                    printf("this is character number: %lld\n",f_index);

                    return;
                }
                ch_count++;

                if ((c==' ' || c=='\n') && flag==1){
                    f_index=ch_count+1;
                }
            //printf("%d\n",f_index);
            }

          c=fgetc(fptr);
          ch_count++;
          //printf("JJ");
          continue;

                }else{

                for(; c!=s ;){
                c=fgetc(fptr);
                if(c==EOF || c=='\n' || c==' '){
                    f_index=-1;
                    printf("this is character number: %lld\n",f_index);
                    return;
                }

            c=fgetc(fptr);
          ch_count++;
          continue;


            }
            }


          }
          }
          if (s=='\\'){
             s=fgetc(str);
             if (s=='n'){
                s='\n';
             }


          }


        if(s!=c || c==EOF){
            f=1;

            break;
          }
        c=fgetc(fptr);
        ch_count++;
          }


if(f==0){

break;

}
fseek(str,0,SEEK_SET);


}
if (f==1) f_index=-1;
printf("this is character number: %lld\n",f_index);

}


void indent(){

 char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }
    char addres[1001];
    input_addres(addres);




char sar_addres[100];
for(int i=0;i<strlen(addres);i++){
    sar_addres[i]=addres[i+1];
    }
FILE*fptr=fopen(sar_addres,"r");
if (fptr==NULL){

            printf("file in this address is not existed: %s\n",addres);
            return;
            }


copy_file(sar_addres,fptr);
FILE*cptr=fopen("matn.txt","w");

char c;
int f=0;
int c_sp=0;
int ch_c=0;
char  s;
int flag=0;
while((c=fgetc(fptr))!=EOF){
    ch_c++;
    if (c=='{'){
        long int a=ftell(fptr);
        fptr=crooshe_yab(fptr);
        if (fptr!=NULL){

                fseek(fptr,a,SEEK_SET);
                fseek(fptr,-2,SEEK_CUR);
                c=fgetc(fptr);
                if (c!=' '  && c!='\t' && c!='\n' && c!=EOF && c!=NULL && s!=' '  && s!='\t' && s!='\n' && s!=EOF && s!=NULL && a!=1 ){
                    fprintf(cptr," {\n");
                        s=c;
                }else {
                fprintf(cptr,"{\n");
                s=c;
                }
                f++;

            fclose(fptr);
            fptr = fopen(sar_addres, "r");
            fseek(fptr, a, SEEK_SET);
                input_sefid(fptr);
                c= fgetc(fptr);

            if(c=='}'){
                c_sp=1;
            } else{
                print_tab(f,cptr);
                s=' ';
            }
            fseek(fptr,-1,SEEK_CUR);
        } else {
            fprintf(cptr,"{");
            s='{';
            fclose(fptr);
            fptr = fopen(sar_addres, "r");
            fseek(fptr, a, SEEK_SET);
        }



    }else if (c=='}'){
        f--;
        if (c_sp==0){
            fprintf(cptr,"\n");


        }
        c_sp=0;
        print_tab(f,cptr);
        fprintf(cptr,"}\n");

        input_sefid(fptr);
        s=' ';
        c= fgetc(fptr);
        if(c==EOF){
            break;
        }
        if(c=='}'){
            c_sp=1;
        } else{
            print_tab(f,cptr);
            s=' ';
        }
        fseek(fptr,-1,SEEK_CUR);



    }else if (c=='\n'){
        fprintf(cptr,"\n");
        print_tab(f,cptr);
        s=' ';

    }else{
    fprintf(cptr,"%c",c);
    s=c;
    }
}

fclose(fptr);
fclose(cptr);

cptr=fopen("matn.txt","r");
fptr=fopen(sar_addres,"w");
c=' ';
for(long long int i=0;(c=fgetc(cptr))!=EOF;i++){
fprintf(fptr,"%c",c);
}
fclose(fptr);
fclose(cptr);
printf("your text auto indented in this file: %s\n",addres);

}

FILE* crooshe_yab(FILE *fptr ){
    char c=' ';
    while(c!='}'){
        if (c==EOF){
            return NULL;
        }
        if (c=='{'){
            fptr=crooshe_yab(fptr);
        }

        if (fptr==NULL){
            break;
        }


        c=fgetc(fptr);
    }

return fptr;


}
void print_tab(int f,FILE* cptr){
for(int i=0;i<f;i++){
                fprintf(cptr,"    ");
            }


}
void input_sefid(FILE*fptr){
    char c=' ';
    while(c==' ' || c=='\n' || c=='\t'){
        c=fgetc(fptr);
    }
    if(c== EOF){
        return;
    }
    fseek(fptr,-1,SEEK_CUR);
    return;


}







void grep_str(){
    enum option{NON_OPTION,C,L};
    enum option halat;
    char order_option[10];
    scanf("%s",order_option);
    if  (strcmp(order_option,"-c")!=0 && strcmp(order_option,"-l")!=0 && strcmp(order_option,"--str")!=0 ){

        return;
    }
    char order_str[10];
    if  (strcmp(order_option,"-c")==0 || strcmp(order_option,"-l")==0  ){
        if (order_option[1]=='c'){
            halat=C;
        }else{

        halat=L;
        }
    scanf("%s",order_str);
    if  (strcmp(order_str,"--str")!=0){

        return;
    }
    }else{
    halat=NON_OPTION;


    }


    input_str();
 char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }

int n_line=0;
FILE *cptr=fopen("matn.txt","w");

fclose(cptr);
  char x=' ';
  while(x!='\n'){

    char addres[1001];
    input_addres(addres);
    char sar_addres[1000];
for(int i=0;i<strlen(addres);i++){
    sar_addres[i]=addres[i+1];
    }
FILE*fptr=fopen(sar_addres,"r");
if (fptr==NULL){

            printf("file in this address is not existed: %s\n",addres);
            return;
            }
fclose(fptr);
fptr=fopen(sar_addres,"r");
FILE*str=fopen("str.txt","r");

char c;
char s;
long int s_index,f_index;
int f;
int n=1;
int flag=0;
while((c=fgetc(fptr))!=EOF){
    s_index=ftell(fptr);
    f=0;
    for(;(s=fgetc(str))!=EOF;){
         if (c=='\n'){

         }
          if (s=='\\'){
             s=fgetc(str);
             if (s=='n'){
                s='\n';
             }


          }


        if(s!=c || c==EOF){
            f=1;

            break;
          }
        c=fgetc(fptr);

          }


if(f==0){
n_line++;
f_index=ftell(fptr);
fseek(fptr,s_index-f_index,SEEK_CUR);

char b=' ';
cptr=fopen("matn.txt","a");
fprintf(cptr,"%s:",sar_addres);

for(;b!='\n';){
    if(b==EOF){
        rewind(fptr);
        break;
    }
    fseek(fptr,-2,SEEK_CUR);
    b=fgetc(fptr);

}

for (;ftell(fptr)!= f_index;){
    if(b!=EOF){
    fprintf(cptr,"%c",b);
    }
    b=fgetc(fptr);


}
for (;b!= '\n';){
   if(b==EOF){
    break;
   }
    fprintf(cptr,"%c",b);
    b=fgetc(fptr);
}
fprintf(cptr,"\n");
fclose(cptr);
flag=1;
}
fseek(str,0,SEEK_SET);


}
if (flag==0){

FILE *cptr=fopen("matn.txt","a");
fprintf(cptr,"there is nothing in this addres: %s\n",sar_addres);
fclose(cptr);
}else{
if (halat==L){
    printf("%s\n",sar_addres);
}

}
fclose(fptr);
x=getchar();

  }


if (halat==NON_OPTION){


cptr=fopen("matn.txt","r");
char c;
for(;(c=fgetc(cptr))!=EOF;){

  printf("%c",c);



}



fclose(cptr);
}else if (halat==C){
printf("%d\n",n_line);

}





}
void compare_str(){
char order_file[10];
            scanf("%s",order_file);
            if  (strcmp(order_file,"--file")!=0){
                return;
            }


 char addres1[1001];
 input_addres(addres1);


char sar_addres1[1000];
for(int i=0;i<strlen(addres1);i++){
    sar_addres1[i]=addres1[i+1];
    }
FILE*fptr=fopen(sar_addres1,"r");
if (fptr==NULL){

            printf("file in this address is not existed: %s\n",addres1);
            return;
            }

 char addres2[1001];
 input_addres(addres2);


char sar_addres2[1000];
for(int i=0;i<strlen(addres2);i++){
    sar_addres2[i]=addres2[i+1];
    }
FILE*cptr=fopen(sar_addres2,"r");
if (cptr==NULL){

            printf("file in this address is not existed: %s\n",addres2);
            return;


            }
FILE*uptr=fopen("matn.txt","w");
int x,y;

int emt=0;
int flag=0;
int line_number=1;
long s1_line,s2_line;
int f=0;
int e1_line=0,e2_line=0;
int e1_file=0,e2_file=0;
while(1){
    s1_line=ftell(fptr);
    s2_line=ftell(cptr);
    f=0;
    char a=' ',b=' ';
    e1_line=0;
    e2_line=0;
    flag=0;
    while(1){

        if (a==EOF){
            e1_file=1;
        }
         if (b==EOF){
            e2_file=1;
        }

        if (a=='\n'){
            e1_line=1;
        }
         if (b=='\n'){
            e2_line=1;
        }

        if(e1_line+e2_line+e1_file+e2_file>=2  ){
            break;
        }


        if (a!=b){
            f=1;
           if(flag==0){
                x=ftell(fptr);
                y=ftell(cptr);

                emt=check_kalame(fptr,cptr);
             }

             flag=1;
        }
        if(e1_line==0 && e1_file==0){
            a=fgetc(fptr);
        }
        if(e2_line==0 && e2_file==0){
            b=fgetc(cptr);
        }







    }

if(f==1 && emt==0){
   fseek(fptr,s1_line,SEEK_SET);
   fseek(cptr,s2_line,SEEK_SET);
   print_to(uptr,fptr,cptr,line_number);

}else if (f==1 && emt==1){
fseek(fptr,s1_line,SEEK_SET);
fseek(cptr,s2_line,SEEK_SET);
print_to_emt(uptr,fptr,cptr,x,y);

}

line_number++;
if(e1_file+e2_file>=1){
        break;

    }

}
int sline_number=line_number;
if(e1_file==1){
 s2_line=ftell(cptr);
 char c;
 while((c=fgetc(cptr))!=EOF){
    if(c=='\n'){
        line_number++;
    }

 }
   fseek(cptr,s2_line,SEEK_SET);
   fprintf(uptr,">>>>>>>>>>>> #%d - #%d>>>>>>>>>>>>\n",sline_number,line_number);
    while((c=fgetc(cptr))!=EOF){
    fprintf(uptr,"%c",c);

 }


}else if (e2_file==1){
s1_line=ftell(fptr);
 char c;
 while((c=fgetc(fptr))!=EOF){
    if(c=='\n'){
        line_number++;
    }

 }
   fseek(fptr,s1_line,SEEK_SET);
   fprintf(uptr,"<<<<<<<<<<<< #%d - #%d <<<<<<<<<<<<\n",sline_number,line_number);
    while((c=fgetc(fptr))!=EOF){
    fprintf(uptr,"%c",c);

 }

}

fclose(fptr);
fclose(cptr);
fclose(uptr);
uptr=fopen("matn.txt","r");
char c;
while((c=fgetc(uptr))!=EOF){

    printf("%c",c);

}
printf("\n");







}

void print_to(FILE* matn,FILE*fptr,FILE* cptr ){

char a=' ',b=' ';
while(a!='\n' ){
        a=fgetc(fptr);
        if(a==EOF){
            fprintf(matn,"\n");
            break;
        }
        fprintf(matn,"%c",a);

    }
while(b!='\n'){
        b=fgetc(cptr);
         if(b==EOF){
            fprintf(matn,"\n");
            break;
        }
        fprintf(matn,"%c",b);

    }



}
void print_to_emt(FILE* matn,FILE*fptr,FILE* cptr,int x,int y ){
int f=0;
char a=' ',b=' ';
while(a!='\n' ){
        a=fgetc(fptr);
        if(a==EOF){
            fprintf(matn,"\n");
            break;
        }
        if(ftell(fptr)!=x){
         if(f==1){
         if(a==' '){
          fprintf(matn,"<<");
         }
         f=0;
         }
         fprintf(matn,"%c",a);

        }else{
        fprintf(matn,">>%c",a);
        f=1;


        }

    }
while(b!='\n' ){
        b=fgetc(cptr);
        if(b==EOF){
            fprintf(matn,"\n");
            break;
        }
         if(ftell(cptr)!=y){
         if(f==1){
         if(b==' '){
          fprintf(matn,"<<");
         }
         f=0;
         }
         fprintf(matn,"%c",b);

        }else{
        fprintf(matn,">>%c",b);
        f=1;


        }

    }

}
int  check_kalame(FILE* fptr,FILE*cptr){
int x=ftell(fptr);
int y=ftell(cptr);

fseek(fptr,-2,SEEK_CUR);
char c=fgetc(fptr);
if(c!=' '){
    return 0;
}else{
while((c=fgetc(fptr))!=' '){

}
while((c=fgetc(cptr))!=' '){

}
char a=' ',b=' ';
int f=0;
int e1_line=0,e2_line=0;
int e1_file=0,e2_file=0;
while(1){

        if (a==EOF){
            e1_file=1;
        }
         if (b==EOF){
            e2_file=1;
        }

        if (a=='\n'){
            e1_line=1;
        }
         if (b=='\n'){
            e2_line=1;
        }

        if(e1_line+e2_line+e1_file+e2_file>=2  ){
            break;
        }


        if (a!=b){
            f=1;

        }
        if(e1_line==0 && e1_file==0){
            a=fgetc(fptr);
        }
        if(e2_line==0 && e2_file==0){
            b=fgetc(cptr);
        }

    }


   fseek(fptr,x,SEEK_SET);
   fseek(cptr,y,SEEK_SET);

if(f==0){
return 1;
}
return 0;


}




}











void tree_str(){
int depth;
scanf("%d",&depth);
tree();













}
void tree(){


 DIR *d;
    struct dirent *dir;
    char path[1000]="root";
    d = opendir(path);
    char full_path[1000];
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(dir->d_type==DT_REG){
                full_path[0]='\0';
                strcat(full_path,path);
                strcat(full_path,"/");
                strcat(full_path,dir->d_name);
                printf("%s\n",full_path);
            }
        }
        closedir(d);
    }

}

void input_hichi(){
    char c;
    while((c=getchar())!='\n'){}

}


int main()
{
    char order[100];
    while(1){
        scanf("%s",order);
        if  (strcmp(order,"create")==0){
            create_file();


        }else if  (strcmp(order,"insertstr")==0){

                insert_str();



        }else if  (strcmp(order,"cat")==0){

                cat();

        }else if  (strcmp(order,"removestr")==0){
                remove_str();


        }else if  (strcmp(order,"copystr")==0){
                copy_str();


        }else if  (strcmp(order,"cutstr")==0){
                cut_str();


        }else if  (strcmp(order,"pastestr")==0){
                paste_str();


        }else if  (strcmp(order,"undo")==0){
                undo();


        }
        else if  (strcmp(order,"auto-indent")==0){
                indent();



        }
        else if  (strcmp(order,"find")==0){
                find_str();


        } else if  (strcmp(order,"grep")==0){
                grep_str();


        } else if  (strcmp(order,"compare")==0){
                compare_str();


        }
        else {

                input_hichi();

            printf("invalid command\n");



        }


    }
    return 0;
}
