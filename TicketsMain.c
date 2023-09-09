#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
int i,l,j,n,k,count,ch1,ch2,ch3,nt,flag,tot_cost;
char command[100];
char seat[2][10]={"Normal","Recliner"};
char pos[4][20]={"Front Seat","Middle Seat","Back Seat","Balcony Seat"};
int price[14]={295,250,175,250,250,250,250,250,250,150,250,250,200,200};
char theatre[14][100]={"AMB Cinemas: Gachibowli","INOX GVK One, Banjara Hills","Asian Ganga 4K: Dilsukhnagar","Cinepolis: DSL Virtue Mall, Uppal","Miraj Cinemas: Shalini Shivani","PVR: Inorbit Mall, Cyberabad","Cinepolis: Mantra Mall, Attapur","INOX GSM Mall","PVR: Central Mall, Panjagutta","Mahalaxmi Complex: Kothapet","Asian CineSquare Multiplex: Uppal","JP Cinemas: Chandanagar","Miraj Cinemas: A2A Central Mall, Balanagar","PVR ICON: Hitech, Madhapur"};
char lang[3][10]={"Telugu","Hindi","English"};
char telugu[10][50]={"Amigos","Pathaan","Ant-Man and the Wasp: Quantumania","Writer Padmabhushan","Waltair Veerayya","Michael","Avatar: The Way of Water","Shiva Vedha","Veera Simha Reddy","Sir"};
char hindi[7][50]={"Pathaan","Ant-Man and the Wasp: Quantumania","Shehzada","Shiv Shastri Balboa","Gandhi Godse Ek Yudh","Dilwale Dulhania Le Jayenge","Vedalam"};
char english[9][50]={"Ant-Man and the Wasp: Quantumania","Avatar: The Way of Water","A Man Called Otto","The Fabelmans","Magic Mike's Last Dance","The Whale","Knock at the Cabin","Puss In Boots: The Last Wish","Titanic"};

 struct Customer{
    char name[50];
    int age;
    char movie[50];
    int ticket;
    char language[10];
    char hall[100];
    char seat_number[10][4];
    char seat_type[10][20];
    char seat_position[10][20];
    int total_price;
    char mobile[10];
} ;

char sn[20][4];
int ticket_counter = 0;
struct Customer customer[20];

void clear_screen() {
    system("cls");
}

void print_header() {
    printf("\n\t\t\t\t\t************************************************\n");
    printf("\t\t\t\t\t*                                              *\n");
    printf("\t\t\t\t\t*         MOVIE TICKET BOOKING SYSTEM          *\n");
    printf("\t\t\t\t\t*                                              *\n");
    printf("\t\t\t\t\t************************************************\n");
}

void tel()
{
	clear_screen();
	PlaySound(TEXT("movie.wav"),NULL,SND_ASYNC);
    print_header();
	printf("\nAvailable Movies in Telugu:\n\n\n");
	for(i=0;i<10;i++)
	printf("%d. %s\n\n",i+1,telugu[i]);
	printf("Enter your choice:\n");
	a:
	scanf("%d",&flag);
	if(flag>10)
	{
	printf("\nWrong Input\n");
	printf("Enter your choice again:\n");
	goto a;
	}
	strcpy(customer[ticket_counter].movie,telugu[flag-1]);
}

void hin()
{
	
    clear_screen();
    PlaySound(TEXT("movie.wav"),NULL,SND_ASYNC);
    print_header();
	printf("\nAvailable Movies in Hindi:\n\n\n");
	for(i=0;i<7;i++)
	printf("%d. %s\n\n",i+1,hindi[i]);
	printf("Enter your choice:\n");
	b:
	scanf("%d",&flag);
	if(flag>7)
	{
	printf("\nWrong Input\n");
	printf("Enter your choice again:\n");
	goto b;
	}
	strcpy(customer[ticket_counter].movie,hindi[flag-1]);
}

void eng()
{
	clear_screen();
	PlaySound(TEXT("movie.wav"),NULL,SND_ASYNC);
    print_header();
	printf("\nAvailable Movies in English:\n\n\n");
	for(i=0;i<9;i++)
	printf("%d. %s\n\n",i+1,english[i]);
	printf("Enter your choice:\n");
	c:
	scanf("%d",&flag);
	if(flag>9)
	{
	printf("\nWrong Input\n");
	printf("Enter your choice again:\n");
	goto c;
	}
	strcpy(customer[ticket_counter].movie,english[flag-1]);
}

void seat_num()
{
	clear_screen();
	print_header();
	PlaySound(TEXT("seat.wav"),NULL,SND_ASYNC);
	 k=65;
	    printf("\n\n\n\n_______________________________________________________________________________________________________________________________________\n");
		printf("\n\t\t\t\t\t\t\tS  C  R  E  E  N\n");
		 printf("\n_______________________________________________________________________________________________________________________________________\n");
		for(i=1;i<=10;i++)
		{
			if(i==1)
			{
		    	printf("\n\t\t\t\t\t\t\tFront Seats\n");
			    printf("\n");
			}
			if(i==3)
			{
				printf("\n\t\t\t\t\t\t\tMiddle Seats\n");
				printf("\n");
			}
			if(i==8)
			{
				printf("\n\t\t\t\t\t\t\tBack Seats (Recliner)\n");
				printf("\n");
			}
			printf("  ");
			for(j=1;j<16;j++)
			{
				if(j==5||j==12)
				{
					printf("      ");
				}
				printf("%c%d      ",(char)k,j);
			}
			printf("\n\n");
			k++;
		}
		printf("\n\n");
		printf("\t\t\t\t\t\t\tBalcony Seats\n");
		for(i=1;i<=3;i++)
		{
			printf("\t\t\t\t");
			for(j=1;j<=6;j++)
			{
				if(j==4)
				printf("\t\t\t");
				printf("%c%d      ",(char)k,j);
			}
			printf("\n\n");
			k++;
		}
	
		for(i=0;i<nt;i++)
		{
			printf("Enter Seat number %d:",i+1);
			v1:
			u:
		    v:
		    w:
			scanf("%s",sn[i]);
			for(j=0;j<i;j++)
			{
				if(strcmp(sn[i],sn[j])==0)
				{
					printf("Wrong Input.\nEnter your seat number again:\n");
	        	    goto v1; 
				}
			}
		    l=strlen(sn[i]);
			if(!(sn[i][0]>='A'&&sn[i][0]<='M'))
			{
				printf("Wrong Input.\nEnter your seat number again:\n");
	        	goto u; 
			}
			if(sn[i][1]>='1'&&sn[i][1]<='9')
			{
				if(l==2)
				{
					goto u1;
				}
			    else	if((sn[i][1]!='1'&&(sn[i][2]>='1'&&sn[i][2]<='9'))||(sn[i][1]=='1'&&!(sn[i][2]>='1'&&sn[i][2]<='5')))
				{
					printf("Wrong Input.\nEnter your choice again:\n");
		            goto v; 
				}
			}
			else
			{
				printf("Wrong Input.\nEnter your choice again:\n");
	        	goto w; 
			}
			u1:
			strcpy(customer[ticket_counter].seat_number[i],sn[i]);
			
			if(sn[i][0]>='A'&&sn[i][0]<='B')
			{
				strcpy(customer[ticket_counter].seat_type[i],seat[0]);
				strcpy(customer[ticket_counter].seat_position[i],pos[0]);
				customer[ticket_counter].total_price+=(price[ch3-1]);
			}
			else if(sn[i][0]>='C'&&sn[i][0]<='G')
			{
				strcpy(customer[ticket_counter].seat_type[i],seat[0]);
				strcpy(customer[ticket_counter].seat_position[i],pos[1]);
				customer[ticket_counter].total_price+=(price[ch3-1]);
			}
			else if(sn[i][0]>='H'&&sn[i][0]<='J')
			{
				strcpy(customer[ticket_counter].seat_type[i],seat[1]);
				strcpy(customer[ticket_counter].seat_position[i],pos[2]);
				customer[ticket_counter].total_price+=(price[ch3-1]+100);
			}
			else if(sn[i][0]>='K'&&sn[i][0]<='M')
			{
				strcpy(customer[ticket_counter].seat_type[i],seat[0]);
				strcpy(customer[ticket_counter].seat_position[i],pos[3]);
				customer[ticket_counter].total_price+=(price[ch3-1]);	
			}
		}
	printf("\n\n\nLOADING..........");
        sleep(2);	
		
}

void movie_display()
{
	clear_screen();
	print_header();
	PlaySound(TEXT("review.wav"),NULL,SND_ASYNC);
	printf("\n%s\n",customer[ticket_counter].movie);
	printf("\n1. See review of the above movie\n");
	printf("2. Select Theatres\n");
	printf("Enter your choice:\n");
	y:
	z:
	scanf("%d",&ch2);
	switch(ch2)
	{
		case 1:
			printf("\n\n\nLOADING..........");
            sleep(2);
            sprintf(command, "start https://www.imdb.com/find/?q=%s", customer[ticket_counter].movie);
            system(command);
            printf("Enter your choice again:\n");
            goto y;
            break;
        case 2:
        	printf("\n\n\nLOADING..........");
            sleep(1);
        	clear_screen();
            print_header();
            PlaySound(TEXT("theatre.wav"),NULL,SND_ASYNC);
            printf("\n%s\n\n\n",customer[ticket_counter].movie);
		    for(i=0;i<14;i++)
			printf("\n%d. %s ----->>>>> Rs. %d/- per normal seat\n",i+1,theatre[i],price[i]);
			printf("\n\nEnter your choice:\n");
			d:
			scanf("%d",&ch3);
			if(ch3>14)
	        {
	            printf("\nWrong Input\n");
	            printf("Enter your choice again:\n");
	            goto d;
	        }
			strcpy(customer[ticket_counter].hall,theatre[ch3-1]);
			break;
		default:
		printf("Wrong Input.\nEnter your choice again:\n");
		goto z;    
	}
	printf("\n\n\nLOADING..........");
        sleep(1);
	clear_screen();
    print_header();
    PlaySound(TEXT("ticketnumber.wav"),NULL,SND_ASYNC);
	printf("Enter Number of Tickets:\n");
	scanf("%d",&customer[ticket_counter].ticket);
	nt=customer[ticket_counter].ticket;
	printf("\n\n\nLOADING..........");
        sleep(1);
}

void add_customer() {
    clear_screen();
    print_header();

    if (ticket_counter >= 20) {
        printf("\nNo more tickets available.\n");
        return;
    }
    PlaySound(TEXT("languageselect.wav"),NULL,SND_ASYNC);
    printf("Available languages:\n");
    for(i=0;i<3;i++)
    printf("%d. %s\n",i+1,lang[i]);
    printf("Enter The Language:\n");
    x:
    scanf("%d",&ch1);
    strcpy(customer[ticket_counter].language,lang[ch1-1]);
     
    switch(ch1)
    {
    	case 1:
    		printf("\n\n\nLOADING..........");
            sleep(1);
    		tel();
    		printf("\n\n\nLOADING..........");
            sleep(1);
    		break;
    	case 2:
    		printf("\n\n\nLOADING..........");
            sleep(1);
		    hin();
		    printf("\n\n\nLOADING..........");
            sleep(1);
			break;
		case 3:
			printf("\n\n\nLOADING..........");
            sleep(1);
		    eng();
		    printf("\n\n\nLOADING..........");
            sleep(1);
			break;
		case 4:
		    printf("\nWrong Input\n");
			printf("Enter your choice again\n");
			goto x;			
	}
	
	movie_display();
	seat_num();
	
    clear_screen();
    print_header();
    PlaySound(TEXT("details.wav"),NULL,SND_ASYNC);
    printf("\nEnter Customer Details\n");
    printf("----------------------\n");
    printf("Name: ");
    fflush(stdin);
    gets(customer[ticket_counter].name);
    printf("Age: ");
    scanf("%d", &customer[ticket_counter].age);
    printf("Mobile Number: ");
    scanf("%s",customer[ticket_counter].mobile);
    printf("\n\n\nLOADING..........");
        sleep(2);
   
         clear_screen();
         print_header();
         PlaySound(TEXT("confirmticket.wav"),NULL,SND_ASYNC);
         printf("\nMovie Name:             %s\n",customer[ticket_counter].movie);
         printf("Theatre:                %s\n",customer[ticket_counter].hall);
         printf("Language:               %s\n",customer[ticket_counter].language);
         printf("Number Of Tickets:      %d\n",customer[ticket_counter].ticket);
         for(i=0;i<nt;i++)
		 {
             printf("Seat Number %d:          %s\n",i+1,customer[ticket_counter].seat_number[i]);
             printf("Seat %d Type:            %s\n",i+1,customer[ticket_counter].seat_type[i]);
             printf("Seat %d Position:        %s\n",i+1,customer[ticket_counter].seat_position[i]);
         }
         printf("Name Of The Customer:   %s\n",customer[ticket_counter].name);
         printf("Age:                    %d\n",customer[ticket_counter].age);
         printf("Mobile Number:          %s\n",customer[ticket_counter].mobile);
         printf("Total Amount:           %d\n",customer[ticket_counter].total_price);
         
         printf("\n1. Confirm ticket\n");
		 printf("2. Delete the above details and register again\n");
		 printf("Enter your choice:\n");
		 z1:
		 scanf("%d",&ch1);
		 if(ch1==1)
		 {
		 	printf("\n\n\nLOADING..........\n");
            sleep(4);
            PlaySound(TEXT("ticketsuccess.wav"),NULL,SND_ASYNC);
		    printf("\nCongratulations!!!Ticket Booked Successfully!\n");
		    ticket_counter++;
		 }
		 else if(ch1>2||ch1<1)
		 {
		 	PlaySound(TEXT("wrong.wav"),NULL,SND_ASYNC);
		 	printf("Wrong Input.\nEnter your choice again:\n");
		 	goto z1;
		 }
}

void view_customers() {
    clear_screen();
    print_header();
    PlaySound(TEXT("view.wav"),NULL,SND_ASYNC);
    count=ticket_counter-1;
    if(count==-1)
    printf("\n       NO TICKETS BOOKED\n");
    else
    {
    for(i=0;i<=count;i++)
    {
    printf("\nMovie Name:               %s\n",customer[i].movie);
    printf("Theatre:                  %s\n",customer[i].hall);
    printf("Language:                 %s\n",customer[i].language);
    printf("Number Of Tickets:        %d\n",customer[i].ticket);
    for(j=0;j<nt;j++)
		 {
             printf("Seat Number %d:            %s\n",j+1,customer[i].seat_number[j]);
             printf("Seat %d Type:              %s\n",j+1,customer[i].seat_type[j]);
             printf("Seat %d Position:          %s\n",j+1,customer[i].seat_position[j]);
         }
    printf("Name Of The Customer:     %s\n",customer[i].name);
    printf("Age:                      %d\n",customer[i].age);
    printf("Mobile Number:            %s\n",customer[i].mobile);
    printf("Total Amount:             %d\n",customer[i].total_price);
    printf("\n\n\n");
    }
    }
    
}

void main()
 {
	PlaySound(TEXT("introvoice.wav"),NULL,SND_ASYNC);
    int choice;
    
    do {
    	
        clear_screen();
        print_header();
        printf("\n1. Book Tickets\n");
        printf("2. View Booked Tickets\n");
        printf("3. Cancel previous ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        x1:
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
            	printf("\n\n\nLOADING..........");
                sleep(1);
                add_customer();
                break;
            case 2:
            	printf("\n\n\nLOADING..........");
                sleep(3);
                view_customers();
                break;
            case 3:
            	if(ticket_counter>0)
            	{
            	ticket_counter--;
            	printf("\n\n\nLOADING..........");
                sleep(2);
                PlaySound(TEXT("cancel.wav"),NULL,SND_ASYNC);
            	printf("\nTicket successfully cancelled.\n");
                }
                else
                printf("\nNo tickets booked.\n");
            	break;
            case 4:
            	 printf("\n\nTHANK  YOU");
                exit(0);
                break;
            default:
                printf("\nInvalid option.\n");
                printf("\nEnter your choice again: ");
                goto x1;
                break;
        }
        
        printf("\nPress enter key to continue...");
        getchar();
        getchar();
    
    } while (choice != 4);
    PlaySound(TEXT("thankyou.wav"),NULL,SND_ASYNC);
    printf("\n\nTHANK  YOU");
}
   
   


