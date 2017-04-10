#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct MACRODEF
{
	char name[15];
	char def[100];
};
struct ARGLIAR
{
	char hash[4];
	char arg[12];
};
struct ARGLIAR a,a1;
struct MACRODEF m;
char label[15];
char op[15];
char operand[15];
int s=0;
FILE *fpm,*fpa;
static int ct=0;
int macro()
{
	int i,st,en;

	int flag;
	char ad[2];
	fpa=fopen("ALA.dil","rb+");
	
	    fpm=fopen("MDT.dil","rb+");
	    if(fpm==NULL)
	      fpm=fopen("MDT.dil","wb+");
	      if(strcmp(op,"MEND")!=0)
	    {
	    if(s==0)
	    {
		    s=1;strcpy(m.name,op);
		    strcat(label,"\t");
		    strcat(op,"\t");
		    strcat(operand,"\n");
		    strcpy(m.def,label);
		    strcat(m.def,op);
		    strcat(m.def,operand);
			printf("%s",&m.def);
	    }
	     else
	    {
	         
	              i=0;
	               flag=0;
	               while(label[i]!='\0')
	               {
	               if(label[i]=='&')
	               {flag=1;break;}i++;
	               }
	
	
	               if(flag==1)
	               {
	               i=0;
	         while(label[i]!='\0')
	    {if(label[i]=='&')
	    {st=i;
	    while(label[i]!=',' && label[i]!='\0')
	    i++;
	         en=i;
	         label[st]='#';
	         itoa(ct,ad,10);
	
	         strcpy(a.hash,"#");
	   
	         strcat(a.hash,ad);
	         label[st+1]=ad[0];
	         st=st+2;
	         while(label[en]!='\0')
	         label[st++]=label[en++];
	         label[st]='\0';
	         fseek(fpa,0,SEEK_END);
	         fwrite(&a,sizeof(a),1,fpa);
	         ct++;
	         }
	       if(label[i]==NULL)
				{break;
				
				}
	         i++;
	         }
	
	          }
	
	
	               i=0;
	               flag=0;
	               while(operand[i]!='\0')
	               {
	               if(operand[i]=='&')
	               {flag=1;break;}
	               i++;
	               }
	           i=0;
	            while(operand[i]!='\0')
	            {//printf("%c\n",operand[i]);
	            i++;}
	               if(flag==1)
	               {
	               i=0;
	
	         while(operand[i]!='\0')
	    {
	         if(operand[i]=='&')
	    {st=i;
	    while(operand[i]!=NULL && operand[i]!=',')
	 		{
	        i++;
	 		}
	        en=i;
	        operand[st]='#';
	        itoa(ct,ad,10);
	        strcpy(a.hash,"#");
	        strcat(a.hash,ad);
	       	operand[st+1]=ad[0];
	        st=st+2;
	        while(operand[en]!='\0')
	        operand[st++]=operand[en++];
	        operand[st]='\0';
	    	fseek(fpa,0,SEEK_END);
	        fwrite(&a,sizeof(a),1,fpa);
	        ct++;
	        }
	if(operand[i]==NULL)
	break;
	         i++;
	         }
	         }
	
		strcat(label,"\t");
	    strcat(op,"\t");
	    strcat(operand,"\n");
	    strcat(m.def,label);
	    strcat(m.def,op);
	    strcat(m.def,operand);
		}
	    }
	    fclose(fpa);
	    }
	    int pass2()
	    {
		char str[100],str1[100];
		char stru[10];
	    char ad2[3];
	    FILE *fpo;
	    int k,flag,i;
	    flag=0;
	    fpa=fopen("ALA2.dil","rb+");
	    fpm=fopen("MDT.dil","r");
	    fpo=fopen("Output.txt","a");//Pass 2 output file
		while(fread(&m,sizeof(m),1,fpm)==1)
	    if(strcmp(m.name,op)==0)
	        {
	                    
	            i=0;
	            while(operand[i]!='\0'&&operand[i]!='_')
	            { 
					k=0;
	                while(operand[i]!=',' && operand[i]!='\0')
	                stru[k++]=operand[i++];
					itoa(ct,ad2,10);
	                stru[k]='\0';
					strcpy(a1.hash,"#\0");
		            strcat(a1.hash,ad2);
		            strcpy(a1.arg,stru);
		            fseek(fpa,0,SEEK_END);
		            fwrite(&a1,sizeof(a1),1,fpa);
		            if(operand[i]=='\0')
		            		break;
		            i++; ct++;
		            }
		           
					k=0;i=0;
	            while(m.def[i]!=10)
			        i++;
			        i++;
	        while(m.def[i]!='\0')
	        str[k++]=m.def[i++];
	              flag=1;
	              k=k-1;
	              str[k]='\0';
	              i=0;
	              while(str[i]!='\0')
	              {k=0;
	                                 while(str[i]!='#' && str[i]!='\0')
	               {str1[k++]=str[i++];	
	               }
	               str1[k]='\0';
	               
	             
	               if(str[i]=='#')
	               {  fprintf(fpo,"%s",str1);
	                              ad2[0]='#';
	               ad2[1]=str[i+1];
	               ad2[2]='\0';
	          
	               rewind(fpa);
	               while(fread(&a1,sizeof(a1),1,fpa)==1)
	              {
	                if(strcmp(a1.hash,ad2)==0)
	            	{
	                    fseek(fpo,0,SEEK_END);
	                    fprintf(fpo,"%s",a1.arg);
	                  
	                    break;
	                    }}
	                    i=i+2;
	                    }
	                     else
	                      fprintf(fpo,"%s\n",str1);
	                    }                                       
	               
	               break;
				   }
	
	
	if(flag!=1)
	   	fprintf(fpo,"%s\t%s\t%s\n",label,op,operand);
	  	fclose(fpo);
	 	fclose(fpm);
		fclose(fpa);
	    }
	
	void PASS1()
	{
		printf("\nMDT View :");
		printf("\n----------\n");
		FILE *fp,*fpn,*fpo;
		fpa=fopen("ALA.dil","wb+");
		fclose(fpa);
		fpa=fopen("ALA2.dil","wb+");
		fclose(fpa);
		char stu[15];//For storing the operand so that endl value is not passed along with it
		int i;
		fpo=fopen("Output.txt","w+");
		fclose(fpo);
		fpm=fopen("MDT.dil","wb+");
		fclose(fpm);//For initialising the needed files
		int flag=0;
		fp=fopen("Input.txt","r");
		while(!feof(fp))
		{
				fscanf(fp,"%s",label);
				fscanf(fp,"%s",op);
				fscanf(fp,"%s",operand);
			if(flag==1)
			macro();//If a macro definetion is found pass-1 is called
				if(strcmp(op,"MACRO")==0)
				flag=1; //Macro definetion found, flag is set so that from next step on, it can be stored in MDT
				if(strcmp(op,"MEND")==0)
				{
				    flag=0;s=0;
				   fseek(fpm,0,SEEK_END);   //For appending in the last, can be prevented if "a" attribute is used during the opening of file
					fwrite(&m,sizeof(m),1,fpm);
					fclose(fpm);
				}
			}
	
		    rewind(fp);
		    fpn=fopen("Input2.txt","w+");//creating the macro definetions free input for pass-2
		    flag=0;
		    i=0;
	        while(!feof(fp))
			{
	            fscanf(fp,"%s",label);
				fscanf(fp,"%s",op);
				fscanf(fp,"%s",operand);
				if(flag==1)
				{
					if(strcmp(op,"MACRO")!=0)//If after MEND, MACRO is not found, that is the end of macro definetions
					flag=2;
					else
					flag=0;
				}
				if(flag==2)//After all the definetions ended we can set the flag to 2, and copy the remaining contents into new file
				{
					fprintf(fpn,"%s\t%s\t%s\n",label,op,operand);
					i++;
				}
				if(strcmp(op,"MEND")==0)
					flag=1;//Checking whether MEND occurs
				}
				fclose(fpn);
				fclose(fp);
	}
	void PASS2()
	{
		int i;
		FILE *fp,*fpn,*fpo;
			printf("\nMDT Expanded View :");
			printf("\n-------------------\n");
	            fpm=fopen("MDT.dil","r");
	            while(fread(&m,sizeof(m),1,fpm)==1)
	            printf("%s\t%s",m.name,m.def);
	            fclose(fpm);
	            fpn=fopen("Input2.txt","r");
	            ct=0;
	            while(!feof(fpn))
	            {
	               	fscanf(fpn,"%s",label);
					fscanf(fpn,"%s",op);
					fscanf(fpn,"%s",operand);
	                pass2();
	                i--;
	                if(i==0)//To prevent the extra space of endl
	                	break;
	            }
	           // printf("Argument List Array :");
            printf("\n---------------------\n");
            fpm=fopen("ALA2.dil","r");
            while(fread(&a1,sizeof(a1),1,fpm)==1)
            printf("%s\t%s\n",a1.hash,a1.arg);
            fclose(fpm);
            printf("\nMNT View :");
			printf("\n----------\n");
			fpm=fopen("MDT.dil","r");
			printf("index\tname\tmdt-index\n");
            while(fread(&m,sizeof(m),1,fpm)==1)
            printf("-\t %s\t-\n",m.name);
            fclose(fpm);
			
}
void input()
{
		FILE *fpo;
		fpo=fopen("Input.txt","r");
		char buf[100];
		while(fgets(buf,100,fpo)!=NULL)
			printf("%s",buf);
		printf("\n");
		printf("\nEnd of Input File\n");
		fclose(fpo);
}
void output()
{
		FILE *fpo;
		fpo=fopen("Output.txt","r");
		char buf[100];
		while(fgets(buf,100,fpo)!=NULL)
			printf("%s",buf);
		printf("\n");
		printf("\nEnd of Output file\n");
		fclose(fpo);
}
int main()
{//To wait, so that screen is not closed abruptly
            printf("%s %s \n",__TIME__,__DATE__);
            int choice=0;
            top:
            printf("----MACRO PROCESSOR----\n");
            printf("\n------------------------\n");
            printf("\n\t1->PASS 1");
			printf("\n\t2->PASS 2");
			printf("\n\t3->Read Input File");
			printf("\n\t4->Read Output File");
			printf("\n\t9->Exit");
			printf("\n\n\tEnter Choice :");            
            choice=getche();
            switch(choice)
            {
            case '1' :  system("cls");
						printf("\n");
            			printf("PASS 1 MACRO PROCESSOR-View MDT\n\n");
						PASS1();
						system("pause");
						system("cls");
						break;
		
			case '2' :  system("cls");
						printf("\n");
						printf("PASS 2 MACRO PROCESSOR - View MNT , Argument List Array\n\n");
						PASS2();
						system("pause");
						system("cls");
						break;
			case '3' :
						system("cls");
						printf("\n");
						printf("Input\n\n");
						input();
						printf("\n-------------------------------------------------\n");
						system("pause");
						system("cls");
						break;
			case '4' :
						system("cls");
						printf("\n");
						printf("Output\n\n");
						output();
						system("pause");
						system("cls");
						break;
			case '9' :  system("cls");
						printf("\n\n\n\n\n\n\n\t\t\t--------MACRO PROCESSOR----------");
						printf("\n\t\t\t---------------------------------");
						printf("\n\n\n\n\n\n\n\n");
						system("pause");
						exit(0);
			default : 	printf("\nWrong Choice\n");
						system("cls");
						
			}
            goto top; 
            return 0;
            }

