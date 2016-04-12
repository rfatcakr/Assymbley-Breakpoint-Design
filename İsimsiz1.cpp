#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
FILE *outputfp;


int control;
char sub1[1000]="        jsr brpnt";
char sub2[1000]="        jsr sstep";


void readsub1(){
  char filename[] = "mk1.txt"; 
  FILE *file = fopen ( filename, "r" ); 
  if ( file != NULL ) { char line [ 128 ];
   /* or other suitable maximum line size */
    while ( fgets ( line, sizeof line, file ) != NULL )	 /* read a line */
	{ 
	  
//	fputs ( line, stdout ); /* write the line */
	//printf("%s",line);
	
	 fputs(line,outputfp);
	} 
	
	fclose ( file );
           
           }
}


void readsub2(){
  char filename[] = "mk2.txt"; 
  FILE *file = fopen ( filename, "r" ); 
  if ( file != NULL ) { char line [ 128 ];
   /* or other suitable maximum line size */
    while ( fgets ( line, sizeof line, file ) != NULL )	 /* read a line */
	{ 
	  
//	fputs ( line, stdout ); /* write the line */
	//printf("%s",line);

	 fputs(line,outputfp);
	} 
	
	fclose ( file );
           
           }
}


void part(char x[100]){
     int v=0;
     
        
     
     
     while(v < sizeof(x)){
                     if(x[v]=='.' && x[v+1]=='o' && x[v+2]=='r' && x[v+3]=='g'){
                                   fputs("       .org $100",outputfp);
                                  
                                  readsub1();
                                   fputs(" \n",outputfp);
                                 
                                  readsub2();
                                
                                  return ;
                                  }else   if(x[v]=='.' && x[v+1]=='e' && x[v+2]=='n' && x[v+3]=='d'){
                                         
                                  return ;
                                  }
                     
                     v++;
                     }



  while(v < sizeof(x)){
                     if(x[v]=='.' && x[v+1]=='e' && x[v+2]=='n' && x[v+3]=='d'){
                              
                                  return ;
                                  }
                     
                     v++;
                     }

	
	if(x[0]=='<' && x[1]=='b' && x[2]=='p' && x[3]=='>')
	{
	int i=0;
	while(i<4){
		x[i]=' ';
		i++;
	}
	  fputs(sub1,outputfp);
	  fputs(" \n",outputfp);
    		control=1;
			i=0;
	}else	if(control==1){
   
		 fputs(sub2,outputfp);
	
	  fputs(" \n",outputfp);
	}
	
	 fputs(x,outputfp);
}
 int main ( void ) {
 	control=0;
 	outputfp=fopen("example.dbg", "w" );
 	
  static const char filename[] = "example.asm"; 
  FILE *file = fopen ( filename, "r" ); 
  if ( file != NULL ) { char line [ 128 ];
   /* or other suitable maximum line size */
    while ( fgets ( line, sizeof line, file ) != NULL )	 /* read a line */
	{ 
	  
//	fputs ( line, stdout ); /* write the line */
	//printf("%s",line);
	part(line);
	
	} 
	
	fclose ( file );
	
	 } 
	 else { 
	 perror ( filename ); /* why didn't the file open? */
	} 

	fputs("   .end",outputfp);
  fclose(outputfp);
  printf("Process has been completed...\n");
	  system("pause"); 
 
	  return 0; 
	  
	  }
