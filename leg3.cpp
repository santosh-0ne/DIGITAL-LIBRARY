//DIGITAL LIBRARY(DL)
//this DL is designed to take input and store it in table format
//which can add (book,student,lenders or borrowers) and checks before adding details
//details of book ,student,lenders can be displayed 
//details can be searched of book,student,lender
//records can be updated 
//book can be returened using lenders table
//the whole library can be hard reset

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



typedef struct {
	int isbn;
	char b_name[20];
	char b_author[20];
	int quantity;
	float price;
}book;

typedef  struct {
	       int s_id;
	       char s_name[20];
}student;

typedef struct{
	int l_isbn;
	int l_sid;
}lenders;


void add_book();
void add_lenders();
void add_student();
//just replace add book with pop to check if it alreday exists
//book pop message
void pop_msg_b()
{
	
	int found=0,bid;
book b;

	FILE *fpb =fopen("books.txt","r");
	 if(!fpb){

	printf("\nerror opening file");
}
	
	printf("\n\n  enter ISBN to check if same isbn exists :\t");
	scanf("%d",&bid);
	
	while(fread(&b,sizeof(book),1,fpb))
	{
		if(b.isbn == bid)    //if not matched write to temp file
		{
			found= 1;
		
			printf("\n%-20s","THE FOUND RECORDS ARE");
			printf("\n%-5s %-20s %-20s %-7s","ISBN","NAME","AUTHOR","PRICE");
			printf("\n.........................................");
			printf("\n%-5d %-20s %-20 %7-d",b.isbn,b.b_name,b.b_author,b.price)	;
			printf("\n\nfound record exit......");
			return;         //will exit this function i.e terminate here
			
		}
       
    }
    fclose(fpb);

	
	if(!found)
	{
     add_book();
		}
		fclose(fpb);
	
	}
	
	

//student pop message

void pop_msg_s()
{
	
		int sid,found=0;
student s;

	FILE *fps =fopen("student.txt","r");
	 if(!fps)
	printf("\nerror opening file");
	
	printf("\nenter student id  check if it already exists :\t");
	scanf("%d",&sid);
	
	while(fread(&s,sizeof(student),1,fps))
	{
		if(s.s_id == sid)    //if not matched write to temp file
		{
			found=1;
			printf("\nfound record:");
			printf("\n%-20s","THE FOUND RECORDS ARE");
			printf("\n%-5s %-20s","ID","NAME");
			printf("\n.........................................");
			printf("\n%-5d %-20s ",s.s_id,s.s_name)	;
			return;
		}
       
    }


	
	if(!found)
	{
	printf("record not found:");
	add_student();
		}
		fclose(fps);
	
		
};



void pop_msg_l()
{
			int lid,found=0;
		lenders  l;

	FILE *fpl =fopen("lender.txt","r");
	 if(!fpl)
	printf("\nerror opening file");
	
	printf("\nenter student id  to  search lender  :\t");
	scanf("%d",&lid);
	
	while(fread(&l,sizeof(lenders),1,fpl))
	{
		if(l.l_sid == lid)    //if not matched write to temp file
		{
			found=1;
			printf("\nfound record:");
			printf("\n%-20s","THE FOUND RECORDS ARE");
			printf("\n%-5s %-20s","ID","ISBN");
			printf("\n.........................................");
			printf("\n%-7d %-7d ",l.l_sid,l.l_isbn)	;
			return;
		}
       
    }


	
	if(!found)
	{
	printf("record not found:");
	add_lenders();
		}
		fclose(fpl);
	
	
	
};

//book add function complete
void add_book(){

	FILE *fpb=fopen("books.txt","a");
	if(!fpb){
	
	printf("error opening file");
}
//	book *b;
book b;


	printf("\nenter details to add:");
//	scanf("%d",&n);
	
//	b=(book*)calloc(n,sizeof(book));
	printf("\nenter isbn of book:");    //isbn of book
		scanf("%d",&b.isbn);

		fflush(stdin);
		printf("\nenter book name:");     //book name
		scanf("%[^\n]s",b.b_name);
		fflush(stdin);
		printf("\n enter book author:");    //book author
		scanf("%s[^\n]",b.b_author);
			fflush(stdin);
		printf("\nenter the quantity:");    //book quantity
		scanf("%d",&b.quantity);
		printf("\n enter price:");           //book price
		scanf("%f",&b.price);
			fwrite(&b,sizeof(book),1,fpb);
			fclose(fpb);
	
	}
	
	
// student add function complete	
void add_student()
{
		FILE *fps =fopen("student.txt","a");
		if(!fps)
	printf("error opening file");
	
		student s;
		printf("\n enter student id: ");    //student id
		scanf("%d",&s.s_id);
		fflush(stdin);
		printf("\n enter student name:");   //student name
		scanf("%[^\n]s",s.s_name);
		

		fwrite(&s,sizeof(student),1,fps);
		fclose(fps);
	}
	
	//complete
void add_lenders()
{

	FILE *fpl =fopen("lender.txt","a");
		if(!fpl)
	printf("error opening file");
	
	lenders l;
	
		printf("\n enter book isbn to lend: ");    //book isbn
		scanf("%d",&l.l_isbn);
		
		printf("\n enter student id:");   //student id
		scanf("%d",&l.l_sid);
		

		fwrite(&l,sizeof(lenders),1,fpl);
		fclose(fpl);	
	
};

//complete
void add()
{
		
	int ch;
	do{
		printf("\n1.add book :");
		    printf("\n2.add student :");
		           printf("\n3.add lenders  :");
		                 printf("\n4. exit press 0:");
		                 
		printf("\n enter your choice:");
		scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			pop_msg_b();
			break;
		case 2:
			pop_msg_s();
			break;
		case 3:
			pop_msg_l();
			break;
			
	}
}while(0);
	
	
	
}

	

	


//complete			
void display_book(){
	FILE *fpb=fopen("books.txt","r");
	if(!fpb)
	printf("error opening file");
	book b;
	rewind(fpb);
	printf("\n%-20 ","BOOK TABLE");
	printf("%-5s%-20s%-20s%-10s%-5s","isbn","name","author","quantity","price");
	printf("\n----------------------------------------------------------------");
	while(fread(&b,sizeof(book),1,fpb))
	{
		printf("\n %-5d %-20s %-20s %-5d %-5f",b.isbn,b.b_name,b.b_author,b.quantity,b.price);
	}
	fclose(fpb);
	printf("\n");
};



//complete			
void display_student(){
		FILE *fps=fopen("student.txt","r");
	if(!fps)
	printf("error opening file");
	
	student s;
	rewind(fps);
	printf("\n%-20 ","STUDENT TABLE");
	printf("%-7s %-20s","s_id","s_name");
	printf("\n------------------------------");
	while(fread(&s,sizeof(student),1,fps))
	{
		printf("\n %-5d %-20s",s.s_id,s.s_name);
	}
	fclose(fps);
	printf("\n");
};


//complete
void display_lenders()
{
			FILE *fpl=fopen("lender.txt","r");
	if(!fpl)
	printf("error opening file");
	
	lenders l;
	rewind(fpl);
	printf("\n%-20s ","lenders table");
	printf("\n%-8s %-10s","isbn","s_id");
	printf("\n------------------------------");
	while(fread(&l,sizeof(lenders),1,fpl))
	{
		printf("\n %-8d %-10d",l.l_isbn,l.l_sid);
	}
	fclose(fpl);
	printf("\n");
	
	
};


//complete return
void return_book()
{
	//delete concept used 
int id,found=0;
lenders l;

	FILE *fpl =fopen("lender.txt","r");
	 if(!fpl)
	printf("\nerror opening file");
	
	FILE *temp=fopen("temp.txt","w");
	if(!temp)
	printf("error opening file:");
	
	printf("\nenter student id to  returned book :\t");
	scanf("%d",&id);
	
	while(fread(&l,sizeof(lenders),1,fpl))
	{
		if(l.l_sid == id)    //if not matched write to temp file
		{
			found=1;	
		}
        else
        {
		fwrite(&l,sizeof(lenders),1,temp);
		}
    }
	fclose(fpl);
	fclose(temp);
	
	if(found)
	{
		 temp= fopen("temp.txt","r");
		 fpl=fopen("lender.txt","w");
		while(fread(&l,sizeof(lenders),1,temp))
		{
			fwrite(&l,sizeof(lenders),1,fpl);
		}
		fclose(fpl);
		fclose(temp);
	}

	
};


	
//complete
void search_b()
{
	int bid,found=0;
book b;

	FILE *fpb =fopen("books.txt","r");
	 if(!fpb)
	printf("\nerror opening file");
	
	printf("\nenter ISBN to  search book :\t");
	scanf("%d",&bid);
	
	while(fread(&b,sizeof(book),1,fpb))
	{
		if(b.isbn == bid)    //if not matched write to temp file
		{
			found=1;
			printf("\nfound record:");
			printf("\n%-20s","THE FOUND RECORDS ARE");
			printf("\n%-5s %-20s %-20s %-7s","ISBN","NAME","AUTHOR","PRICE");
			printf("\n.........................................");
			printf("\n%-5d %-20s %-20 %7-d",b.isbn,b.b_name,b.b_author,b.price)	;
		}
       
    }


	
	if(!found)
	{
	printf("record not found:");
		}
		fclose(fpb);
	
	}

	
//complete
void search_s()

{	int sid,found=0;
student s;

	FILE *fps =fopen("student.txt","r");
	 if(!fps)
	printf("\nerror opening file");
	
	printf("\nenter ISBN to  search book :\t");
	scanf("%d",&sid);
	
	while(fread(&s,sizeof(student),1,fps))
	{
		if(s.s_id == sid)    //if not matched write to temp file
		{
			found=1;
			printf("\nfound record:");
			printf("\n%-20s","THE FOUND RECORDS ARE");
			printf("\n%-5s %-20s","ID","NAME");
			printf("\n.........................................");
			printf("\n%-5d %-20s ",s.s_id,s.s_name)	;
		}
       
    }


	
	if(!found)
	{
	printf("record not found:");
		}
		fclose(fps);
	
	}

	
//complete
void search_l()
{
	
		int lid,found=0;
		lenders  l;

	FILE *fpl =fopen("lender.txt","r");
	 if(!fpl)
	printf("\nerror opening file");
	
	printf("\nenter student id  to  search lender  :\t");
	scanf("%d",&lid);
	
	while(fread(&l,sizeof(lenders),1,fpl))
	{
		if(l.l_sid == lid)    //if not matched write to temp file
		{
			found=1;
			printf("\nfound record:");
			printf("\n%-20s","THE FOUND RECORDS ARE");
			printf("\n%-5s %-20s","ID","ISBN");
			printf("\n.........................................");
			printf("\n%-7d %-7d ",l.l_sid,l.l_isbn)	;
		}
       
    }


	
	if(!found)
	{
	printf("record not found:");
		}
		fclose(fpl);
	
	}
	
	
	
//complete
void search_file(){
	
	int ch;
	do{
		printf("\n1.search book using isbn:");
		    printf("\n2.search student  using s_id:");
		           printf("\n3.search lenders  using s_id:");
		                 printf("\n4. exit press 0:");
		                 
		printf("\n enter your choice:");
		scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			search_b();
			break;
		case 2:
			search_s();
			break;
			case 3:
			search_l();
			break;
			
	}
}while(0);
	
};
	

//complete

 void update_book()
 {
		int bid,found=0;
book b;

	FILE *fpb =fopen("books.txt","r");
	 if(!fpb){
	 
	printf("\nerror opening book file");
}
	
		FILE *temp =fopen("temp.txt","w");
	 if(!temp){
	 
	printf("\nerror opening temp file");
}
	
	
	
	printf("\nenter ISBN to  search book :\t");
	scanf("%d",&bid);
	
	while(fread(&b,sizeof(book),1,fpb))
	{
		if(b.isbn == bid)    //if not matched write to temp file
		{
			found=1;
			printf("\nfound record:");
		//	printf("\n%-20s","THE FOUND RECORDS ARE");
		//	printf("\n%-5s %-20s %-20s %-7s","ISBN","NAME","AUTHOR","PRICE");
		//	printf("\n.........................................");
		//	printf("\n%-5d %-20s %-20 %7-d",b.isbn,b.b_name,b.b_author,b.price)	;
		printf("\nenter new isbn of book:");    //isbn of book
		scanf("%d",&b.isbn);
		fflush(stdin);
		printf("\nenter new book name:");     //book name
		scanf("%[^\n]s",b.b_name);
		fflush(stdin);
		printf("\n enter new book author:");    //book author
		scanf("%s[^\n]",b.b_author);
			fflush(stdin);
		printf("\nenter the new quantity:");    //book quantity
		scanf("%d",&b.quantity);
		printf("\n enter new  price:");           //book price
		scanf("%f",&b.price);
		}
		fwrite(&b,sizeof(book),1,temp);
       
    }
    fclose(temp);

fclose(fpb);

	
	if(found)
	{
	FILE *fpb =fopen("books.txt","w");
FILE	*temp=fopen("temp.txt","r");
	
	while(fread(&b,sizeof(book),1,temp))
	{
		
		fwrite(&b,sizeof(book),1,fpb);
	}
	fclose(temp);
	fclose(fpb);
		}
		
	
	
	
};
	

	
//complete		
void	update_student(){
	
	
		int sid,found=0;
student  s;

	FILE *fps =fopen("student.txt","r");
	 if(!fps){
	 
	printf("\nerror opening student file");
}
	
		FILE *temp =fopen("temp.txt","w");
	 if(!temp){
	 
	printf("\nerror opening temp file");
}
	
	
	
	printf("\nenter student id to  update :\t");
	scanf("%d",&sid);
	
	while(fread(&s,sizeof(student),1,fps))
	{
		if(s.s_id == sid)    //if not matched write to temp file
		{
			found=1;
			printf("\nfound record:");
		//	printf("\n%-20s","THE FOUND RECORDS ARE");
		//	printf("\n%-5s %-20s %-20s %-7s","ISBN","NAME","AUTHOR","PRICE");
		//	printf("\n.........................................");
		//	printf("\n%-5d %-20s %-20 %7-d",b.isbn,b.b_name,b.b_author,b.price)	;
	
	
		printf("\n enter  new student id: ");    //student id
		scanf("%d",&s.s_id);
		fflush(stdin);
		printf("\n enter new  student name:");   //student name
		scanf("%[^\n]s",s.s_name);
		}
		fwrite(&s,sizeof(student),1,temp);
       
    }
    fclose(temp);

fclose(fps);

	
	if(found)
	{
	FILE *fps =fopen("student.txt","w");
    FILE *temp=fopen("temp.txt","r");
	
	while(fread(&s,sizeof(student),1,temp))
	{
		
		fwrite(&s,sizeof(student),1,fps);
	}
	fclose(temp);
	fclose(fps);
		}
		
	
		};
			
			
//complete			
void update_lenders()
{
	
	lenders  l; 
	int found=0,sid;

	FILE *fpl =fopen("lender.txt","r");
	 if(!fpl)
	 {
	 
	printf("\nerror opening lender file");
     }
	
	FILE *temp =fopen("temp.txt","w");
	
	 if(!temp)
	 {
	 
	printf("\nerror opening temp file");
    }
    
	printf("\nenter lender  student id to  update :");
	scanf("%d",&sid);
	
	while(fread(&l,sizeof(lenders),1,fpl))
	{
	
		if(l.l_sid==sid)    //if not matched write to temp file
		{
			found=1;
			printf("\nfound record:");
		//	printf("\n%-20s","THE FOUND RECORDS ARE");
		//	printf("\n%-5s %-20s %-20s %-7s","ISBN","NAME","AUTHOR","PRICE");
		//	printf("\n.........................................");
		//	printf("\n%-5d %-20s %-20 %7-d",b.isbn,b.b_name,b.b_author,b.price)	;
	fflush(stdin);
		printf("\n enter new book isbn to update lend: ");    //book isbn
		scanf("%d",&l.l_isbn);
		
		printf("\n enter new student id of lend table:");   //student id
		scanf("%d",&l.l_sid);
	
    }
	
	fwrite(&l,sizeof(lenders),1,temp);
      
    
    fclose(fpl);

    fclose(temp);
}

	if(found)
	{
	FILE *fpl =fopen("lender.txt","w");
    FILE *temp=fopen("temp.txt","r");
	
	while(fread(&l,sizeof(lenders),1,temp))
	{
		
		fwrite(&l,sizeof(lenders),1,fpl);
	}
	fclose(temp);
	fclose(fpl);
	}
	
else{
		printf("not found");
	}
		
	
	}

	
	
	
	

//complete			
void update_record(){
	
		int ch;
	do{
		printf("\n1.update book using isbn:");
		    printf("\n2.update student  using s_id:");
		           printf("\n3.update lenders  using s_id:");
		                 printf("\n4. exit press 0:");
		                 
		printf("\n enter your choice:");
		scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			update_book();
			break;
		case 2:
			update_student();
			break;
		case 3:
			update_lenders();
			break;
			
	}
}while(0);

}

 
 
//complete reset
void reset_library_files()
{
FILE *fpb=fopen("books.txt","w");               //



if (!fpb) {
        printf("\nError opening file books.txt");
    } else {
        fclose(fpb);
    }

 FILE *fps = fopen("student.txt", "w");
    if (!fps) {
        printf("\nError opening file student.txt");
    } else {
        fclose(fps);
    }

 FILE *fpl = fopen("lender.txt", "w");
    if (!fpl) {
        printf("\nError opening file lenders.txt");
    } else {
        fclose(fpl);
    }


//fwrite(&s,sizeof(student),1,fps);
//fwrite(&b,sizeof(book),1,fpb);
//fwrite(&l,sizeof(lenders),1,fpl);


printf("\nFile contents deleted successfully.\n");

};


//completed
void display_details()
{
	
	
		int ch;
	do{
		printf("\n1. display book ");
		    printf("\n2.display student  ");
		           printf("\n3.display lenders ");
		                 printf("\n4. exit press 0");    
		                     printf("\n\n enter your choice");
		scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			display_book();
			 break;
		case 2:
		    display_student();
			   break;
		case 3:
			display_lenders();
			   break;
			
	}
}while(0);

};



//starts main function

int main()
{
	int ch;
	do{
		printf("\n---------------------------------------------------------------");
		  printf("\n%-30s","\e[1m........WELCOME TO Digital  Library.....\e[0m\n"); //\e[1m,\e[0m to make bold
		     printf("\n 1.add details :");
		           printf("\n 2.display details:");
		                   printf("\n 3.return books:");
						        printf("\n 4.search details:");
			                            printf("\n 5.update records:");
				                            printf("\n 6.reset library file:");
		                                       	printf("\n enter  0 to exit:");
	    	printf("\n enter your choice:");
		     scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				add();
					//system("cls");
				   break;
			case 2:
			    display_details();
			    	//system("cls");
				    break;
			case 3:
				return_book();
					//system("cls");
					 break;
			case 4:
			     search_file();    //		void search_ch();     void update_record
				   //	system("cls");
				       break;
		    case 5:
		    	update_record();
		    		//system("cls");
		    	   break;
		    case 6:
			     reset_library_files();
			     	//system("cls");
				    break;	
		    	
					   		
					
				
		}
	}while(ch!=0);
//	system("cls");
	return 0;
}
