#include<stdio.h>
#include<stdlib.h>

typedef struct sparseMatrix
{
    int row,col;
    int len;
    int data[100][3];

}sparseMatrix;

void insert(sparseMatrix *sparse,int r,int c,int val)
{
    //invalid entry
    if(r > sparse->row || c > sparse->col)
        printf("Wrong Entry");
    else
    {
        int len=sparse->len;
        sparse->data[len][0]=r;
        sparse->data[len][1]=c;
        sparse->data[len][2]=val;
        sparse->len++;
    }
}
void add(sparseMatrix a,sparseMatrix b)
{
    if(a.row != b.row || a.col != b.col)
        printf("Matrices can't be added");
    else
    {
        int apos,bpos;
        apos=bpos=0;
        sparseMatrix result={a.row,a.col,0};

        while(apos < a.len && bpos < b.len)
        {
            if(a.data[apos][0] > b.data[bpos][0] ||
               (a.data[apos][0] == b.data[bpos][0] &&
               a.data[apos][1] > b.data[bpos][1]))
               {
                   insert(&result,b.data[bpos][0],
								b.data[bpos][1],
								b.data[bpos][2]);
                    bpos++;
               }
               else if (a.data[apos][0] < b.data[bpos][0] ||
				(a.data[apos][0] == b.data[bpos][0] &&
				 a.data[apos][1] < b.data[bpos][1]))

				{

					// insert smaller value into result
					insert(&result,a.data[apos][0],
								a.data[apos][1],
								a.data[apos][2]);

					apos++;
				}

				else {

					// add the values as row and col is same
					int addedval = a.data[apos][2] + b.data[bpos][2];

					if (addedval != 0)
						insert(&result,a.data[apos][0],
									a.data[apos][1],
									addedval);
					// then insert
					apos++;
					bpos++;
				}

        }
        while (apos < a.len)
				insert(&result,a.data[apos][0],
							a.data[apos][1],
							a.data[apos++][2]);

        while (bpos < b.len)
            insert(&result,b.data[bpos][0],
                        b.data[bpos][1],
                        b.data[bpos++][2]);

        printSparse(result);
    }
}
sparseMatrix transpose(sparseMatrix sparse)
{
    sparseMatrix result={sparse.col,sparse.row,sparse.len};

    int count[sparse.col+1];

    for (int i = 1; i <= sparse.col; i++)
        count[i] = 0;

    for(int i=0; i < sparse.len; i++ )
        count[sparse.data[i][1]]++;

    int index[sparse.col+1];
    index[1]=0;

    for(int i=2; i <= sparse.col; i++ )
     index[i]=index[i-1] + count[i-1];


    for(int i=0; i < sparse.len; i++)
    {
        int rpos=index[sparse.data[i][1]]++;

        result.data[rpos][0]=sparse.data[i][1];

        result.data[rpos][1]=sparse.data[i][0];

        result.data[rpos][2]=sparse.data[i][2];
    }

    return result;
}

void multiply(sparseMatrix a, sparseMatrix b)
{
    if(a.col != b.row)
    {
        printf("Can't multiply Invalid dimensions");
        return;
    }

    b=transpose(b);
    int apos,bpos;

    sparseMatrix result={a.row,b.row,0};

    for(apos=0; apos < a.len;)
    {
        int r=a.data[apos][0];

        for(bpos=0; bpos < b.len;)
        {
            int c=b.data[bpos][0];

            int tempa=apos;
            int tempb=bpos;

            int sum=0;

            while(tempa < a.len && a.data[tempa][0]==r
                  && tempb < b.len && b.data[tempb][0]==c)
            {

                if(a.data[tempa][1] < b.data[tempb][1])
                    tempa++;
                else if(a.data[tempa][1] > b.data[tempb][1])
                    tempb++;
                else
                    sum += a.data[tempa++][2] * b.data[tempb++][2];
            }

            if(sum != 0)
                insert(&result,r,c,sum);

            while(bpos < b.len && b.data[bpos][0] == c)
                bpos++;
        }
        while(apos < a.len && a.data[apos][0] ==r )
            apos++;

    }
    printSparse(result);


}

void printSparse(sparseMatrix sparse)
	{
		printf("Dimension: %dx%d\n",sparse.row,sparse.col);
		printf("Sparse Matrix: \nRow Column Value\n");

		for (int i = 0; i < sparse.len; i++) {

			printf("%d %d %d\n",sparse.data[i][0],sparse.data[i][1],sparse.data[i][2]);
		}
	}

int main()
{
    sparseMatrix a={4,4,0};
    sparseMatrix b={4,4,0};


    insert(&a,1, 2, 10);
    insert(&a,1, 4, 12);
    insert(&a,3, 3, 5);
    insert(&a,4, 1, 15);
    insert(&a,4, 2, 12);

    insert(&b,1, 3, 8);
    insert(&b,2, 4, 23);
    insert(&b,3, 3, 9);
    insert(&b,4, 1, 20);
    insert(&b,4, 2, 25);

    printf("Addition: \n");
    add(a,b);
    printf("\nMultiplication: \n");
    multiply(a,b);
    printf("\nTranspose: \n");
    printSparse(transpose(a));
	return 0;
}
