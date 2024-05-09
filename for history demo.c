#ifndef PRESCRIPTION_H_INCLUDED
#define PRESCRIPTION_H_INCLUDED
#include <string.h>
#define MAX_LEN 100


typedef struct
{
	char medicine[MAX_LEN];
	float price;
	int quant;
}medi;


	char name[MAX_LEN];
	float pprice;
	float total = 0;
	int ide = 0;
    char namee[MAX_LEN];
    char phonee[MAX_LEN];
    char file[1];
    FILE *fp;
    int filee = 0;



void prescription()
{
	int press;
    ide++;
    filee++;

    printf("\n\nEnter Customer Name: ");
    scanf("%s",&namee);

    printf("\nEnter Customer Phone Number : ");
    scanf("%s",&phonee);

    printf("\nCustomer Id : %d",ide);

	printf("\n\n\tHow many medicine you want to prescript : ");
	scanf("%d",&press);
	medi med[press];




    FILE *file;
    file = fopen("medicine.txt","r");

    if(file==NULL)
    {
    	printf("Error opening file");
        return;
    }

    else
    {

        for(int i = 0; i<press; i++)
        	{

				fscanf(file, "%s %.2f", &name, &pprice);




                while (fscanf(file, "%s %f", med[i].medicine, &med[i].price) == 2)
                {

                    printf("\n\n\n\tEnter Medicine %d			: ",i+1);
                    scanf("%s",&med[i].medicine);
                    printf("\tEnter Medicine %d Quantity (Pcs)  \t: ",i+1);
                    scanf("%d",&med[i].quant);

                    if(strcmp(med[i].medicine,name) == 0)
                    {
                        printf("\n\t\t\t\t\t\t\tMedicine %d : %s X %d\t\t Price : %.2f Taka\n",i+1,med[i].medicine,med[i].quant,med[i].price*med[i].quant);
                    }

                    total = total + med[i].price*med[i].quant;
                }
            }

            fclose(file);

    }


    fp = fopen("filee.txt","w");
    fprintf(fp,"\tCustomer name: %s\n\tCustomer Phone : %s\n\tCustomer ID : %d\n",namee,phonee,ide);
        printf("\n\n\n\n\tTotal Price : %.2f Taka\n",total);
}

#endif
