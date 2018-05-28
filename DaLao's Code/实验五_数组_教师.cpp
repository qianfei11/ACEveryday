#include <stdio.h>
#include <stdlib.h>

/************************************************************************/
/*                             ��ͨ����                                 */
/************************************************************************/

//��ѧ�ϵľ������C�����еĶ�ά�����ʾ����Ϊ�˸����������ά����Ĵ�ȡ����ʵ����˳�����ģ�����
typedef struct {
	int* elem; // �����洢����Ԫ�صĶ�̬����ռ䣺���������ȴ洢
	int row, col;
}intMatrix;

//����������������������Ծ�����г�ʼ����
void  InitMatrix( intMatrix *pMat, int row, int col )
{
/**********************************************************
�趨pMat��ָ������������������Ϊ֮����Ԫ�صĶ�̬�洢�ռ�
	*********************************************************/
	pMat->row =     row     ; // ����..
	pMat->col =     col  ; // ����
	pMat-> elem =  (int*)malloc(sizeof(int)*row*col) ; // �洢�ռ�
}

//�Ծ���ĵ�i�е�j��λ�õ�Ԫ�ظ�ֵΪx����ֵ�ɹ�����1������0��
int  Assign(intMatrix *pMat , int i , int j,  int x) 
{
	// �ж�i, j�Ƿ�Ϸ�
	if ( (i<1 || i> pMat->row ) || (j<1 || j> pMat->col )  )
	{
		printf("�л���λ�÷Ƿ�����ֵʧ��\n"); return 0;
	}
	// ���Ϸ�����ֵ i,j��1��ʼ����������ݴ�0λ�ÿ�ʼ
	pMat->elem[ (i-1)*pMat->col  + j-1  ]  =  x;
	return 1;
}
//��ȡ������Ԫ��ֵ
//������ĵ�i�е�j��λ�õ�Ԫ�ظ�ֵ��x���ء��ɹ�����1������0��
int  Get(intMatrix *pMat , int i , int j,  int *x) 
{
	// �ж�i ,j�Ƿ�Ϸ�
	if ( (i<1 || i> pMat->row ) || (j<1 || j> pMat->col )  )
	{
		printf("�л���λ�÷Ƿ�����ֵʧ��\n"); return 0;
	}
	// ��x��ֵ
	*x = pMat->elem[ (i-1)*pMat->col  + j-1  ];
	return 1;
}


//���������С��е���ʽ�������Ļ�ϡ�
void  PrintMatrix( intMatrix *pMat )
{
	int i,j;
	for (i=0;i<pMat->row;i++)
	{
		for (j=0;j<pMat->col;j++)
		{
			printf("%d ", pMat->elem[i*pMat->col + j]);
		}
		printf("\n");
	}
}

/************************************************************************/
/*                             �Գƾ���                                 */
/************************************************************************/

//����һ��ѹ������Ľṹ�����ͣ���һά�������洢�����е�Ԫ�ء�Ϊ�˼�����������ΪDIM*DIM�ķ������У�DIMΪһȷ����������С��
#define MAXLEN 100
#define DIM 10
typedef struct {
	int elem[MAXLEN];    // �������������Ԫ�ص�һά����
}intCompressedMatrix;
//�Գƾ���ĳ�ʼ�����ȡ
//��һ���Գƾ�������ʼ����ѹ������
void  InitMatrix( intCompressedMatrix*pMat, int m[DIM ][DIM ] )
{
/**********************************************************
������ڶ�ά����m�еĶԳƾ���������Ԫ�ش�ŵ�pMat��
	*********************************************************/
	int index = 0;
	for(int i=1; i<=DIM; i++) // ��ÿһ��
		for(int j=1; j<= i;  j++) // ��ÿһ���еĲ���Ԫ��
			pMat->elem[ (i-1)*i/2 + j-1 ] = m[  i-1  ][  j-1  ];
}

// ��ȡ
int  Get(intCompressedMatrix*pMat , int i , int j,  int *x) 
{
	// �ж�i, j�Ƿ�Ϸ�
	if ( (i<1 || i> DIM) || (j<1 || j> DIM )  ) 
	{
		printf("�л��������Ƿ�����ֵʧ��\n"); return 0;
	}
	
	// ��x��ֵ
	// ����ֻ������i>=j�������ǣ��������ȡj>i��������Ԫ�أ���ô��ȡ��
	if (i>=j)
		*x = pMat->elem[(i-1)*i/2 + j-1 ];
	else
		*x = pMat->elem[(j-1)*j/2 + i-1 ];
	return 1;
}
//���������С��е���ʽ�������Ļ�ϡ�
void  PrintMatrix( intCompressedMatrix *pMat )
{
	int i,j,x;
	for (i=1;i<=DIM;i++)
	{
		for (j=1;j<=DIM;j++)
		{
			Get(pMat,i,j,&x);
			printf("%3d ", x);
		}
		printf("\n");
	}
}

/************************************************************************/
/*                             ϡ�����                                 */
/************************************************************************/
//����һ����Ԫ�飬�����洢����Ԫ�ص��С��к�����ֵ���ٶ���һ��ϡ�����ṹ�壬������ʾϡ�����
#define MAXNUM 20   // �ٶ�����Ԫ�ظ���������20��
typedef struct{
    int r, c, e;   // ����Ԫ�ص��С��к�����ֵ
}Triple;
typedef struct{
    //����Ԫ����Ϣ����
	Triple elem[MAXNUM];
    //�ֱ𱣴�ϡ���������������������ͷ���Ԫ�ظ���
    int nrow, ncol, num; 
}SparseMatrix;
//���ݶ�ά�����ʼ��һ��ϡ�����ṹ��
//��ά�����а�����������Ԫ�أ�ͨ�������ö�ά���飬������Ԫ����Ϣ����ϡ�����ṹ���С�Ϊ��������ٶ���ά����Ϊ�������С�
#define ROWS 6
#define COLS 7
void BuildSparseMatrix(int m[ROWS ][COLS ], SparseMatrix *pSM)
{
    int i,j, n = 0;  // ����ͳ�Ʒ���Ԫ�ظ���
	
    // �����ö�ά����
    for(  i=0;i<ROWS; ++i  )
		for( j=0;j<COLS;++j )
		{
			// ����ҵ�����Ԫ��
			if (m[i][j] != 0)
			{
				// �������Ԫ����Ϣ����Ӧλ�õ���Ԫ����
				 pSM->elem[n].r =  i+1 ;
				 pSM->elem[n].c =  j+1 ;
				 pSM->elem[n].e =  m[i][j] ;
				 ++n;
			}
		}
		
		// �ֱ𱣴�ϡ���������������������ͷ���Ԫ�ظ���	  
		pSM->nrow =  ROWS      ;
		pSM->ncol =  COLS      ;
		pSM->num =    n    ;
}
//���ϡ�����
//����Ԫ����ʽ��ϡ������ն�ά�������ʽ�����
int Get(SparseMatrix *pSM, int r, int c)
{
/**********************************************************
��ϡ������еõ���r��c��Ԫ�ص�ֵ
	*********************************************************/
    int i=0;
	
    // ������ϡ��������Ԫ������
	for( ; i<pSM->num; i++)
	{
        // ���ҵ���r�е�c�еķ���ֵ���򷵻ظ�ֵ
		if (pSM->elem[i].r == r && pSM->elem[i].c == c)
			return pSM->elem[i].e;
	}
	
    // ��û���ҵ���r�е�c�е����ݣ����Ȼ��0
	return 0;
}

void PrintSMatrix(SparseMatrix *pSM)
{
	int  i, j;
	for(i=1; i<=pSM->nrow; i++)
	{
		for(j=1; j<=pSM->ncol; j++)
			printf("%3d ", Get(pSM, i,j)); // �����i�е�j��Ԫ�ص�ֵ
		printf("\n"); 
	}
}
//ϡ������ת��
//�̲���ת�÷����������������������Ĵ洢�ռ�starting_pos��row_terms��Aת��ΪB����������row_terms�д�ŵ��Ǹ��з���Ԫ�صĸ���������starting_pos�����洢ת�ú�ľ���ÿ�з���Ԫ�ص���ʼ��ַ��
void Translate3(SparseMatrix*pMatA, SparseMatrix*pMatB)
{
	int i;
    // ����������������
    int row_terms[COLS ],starting_pos[COLS ];
	
    // ת�ú�����ֵ������������Ԫ�ظ�������
    pMatB->ncol =  pMatA->nrow     ;
    pMatB->nrow =  pMatA->ncol     ;
    pMatB->num  =  pMatA->num      ;
	
    // ͳ��ת�ú�ÿ��Ԫ�ظ���
    // ���Ƚ�ÿ��Ԫ�ظ�������
    for(i=0; i<   COLS         ; i++)
		row_terms[i]=0;
	
	//����һ�����A�еķ���ֵ��Ϣ������ת��֮��ÿ�з���Ԫ�ظ���
    for(i=0; i<pMatA->num; i++)
        row_terms[ pMatA->elem[i].c-1]++;
	
    // ����ת��֮��ÿһ����ʼд��λ��
    // ��1�е�д��λ��Ҳ��0��λ��
    starting_pos[0]=0;
	// �ӵ�2�п�ʼ�� ��i�е�д��λ���ǵ�i-1�е���ʼд��λ��+��i-1
	// �еķ���Ԫ�ظ���
    for(i=1; i<pMatA->ncol; i++)
        starting_pos[i]= starting_pos[i-1] + row_terms[i-1] ;
	
	// ���������������飬�ٴ�ɨ��A
    for(i=0; i<pMatA->num ;i++)
    {
		// A�еĵ�i������ֵת��֮��ΪB�ĵڼ��У���starting_pos
		// ���ҵ��ڼ��е���ʼд��λ��
		pMatB->elem[  starting_pos[pMatA->elem[i].c-1 ]           ].r =  pMatA->elem[i].c ;
		pMatB->elem[  starting_pos[pMatA->elem[i].c-1 ]           ].c =  pMatA->elem[i].r ;
		pMatB->elem[  starting_pos[pMatA->elem[i].c-1 ]           ].e =  pMatA->elem[i].e ;
		
		// B�еĵڼ���д�����ݺ� starting_pos����Ӧ�е�д��λ��
		// ����һλ
		starting_pos[pMatA->elem[i].c-1 ]++;
    }
}
//ϡ��������
//�Ը��ݺ���ԭ�ͣ�д��ϡ�����C=A+B�ĺ�����
void Add(SparseMatrix*pMatA, SparseMatrix*pMatB, SparseMatrix*pMatC)
{
	int i=0,j=0,n=0, sum;
	//����Ҫ�ж�AB���������
	if (pMatA->nrow != pMatB->nrow  || pMatA->ncol != pMatB->ncol )
	{
		printf("������к��в���ȣ�������ӣ�\n");
		return;
	}
	while (i<pMatA->num  && j<pMatB->num)
	{
		//A�����ݵ��� С�� B�����ݵ���
		if (pMatA->elem[i].r < pMatB->elem[j].r)
		{
			pMatC->elem[n++] = pMatA->elem[i++];
		}
		else if (pMatA->elem[i].r > pMatB->elem[j].r)
		{
			pMatC->elem[n++] = pMatB->elem[j++];
		}
		else //��ͬ��
		{
			//�ٿ��С�
			//A����С��B����
			if (pMatA->elem[i].c < pMatB->elem[j].c)
			{
				pMatC->elem[n++] = pMatA->elem[i++];
			}
			else if (pMatA->elem[i].c > pMatB->elem[j].c)
			{
				pMatC->elem[n++] = pMatB->elem[j++];
			}
			else //��Ҳ��ȣ� �����
			{
				sum = pMatA->elem[i].e + pMatB->elem[j].e;
				if (sum != 0)
				{
					pMatC->elem[n].r = pMatB->elem[j].r;
					pMatC->elem[n].c = pMatB->elem[j].c;
					pMatC->elem[n++].e = sum;
				}
				i++;j++;
			}
		}
        
	}
	//������ʣ�������
	if (i<pMatA->num )
	{
		for (;i<pMatA->num ;i++)
		{
			pMatC->elem[n++] = pMatA->elem[i];
		}
	}
	else if (j<pMatB->num)
	{
		for (;j<pMatA->num ;j++)
		{
			pMatC->elem[n++] = pMatB->elem[j];
		}
	}
	pMatC->nrow = pMatA->nrow;
	pMatC->ncol = pMatA->ncol;
	pMatC->num = n;
}
//ϡ��������
//�Ը��ݺ���ԭ�ͣ�д��ϡ�����C=A*B�ĺ�����
void Mul(SparseMatrix*pMatA, SparseMatrix*pMatB, SparseMatrix*pMatC)
{
	int i,j,mul,sum, r, c;
	//��ÿһ�е�����
	int rterm[COLS] = {0};
	//��ÿһ�е�����
	int cterm[COLS] = {0};
	//����Ҫ�ж�A���� �� B�������
	if (pMatA->nrow != pMatB->ncol)
	{
		printf("����A���в�����B���У�������ˣ�\n");
		return;
	}
	pMatC->nrow = pMatA->nrow;
	pMatC->ncol = pMatB->ncol;
	pMatC->num = 0;

	//��A��ÿһ��
	for (i=1;i<=pMatA->nrow;i++)
	{
		//�Ƚ�������������
		for (r=0;r<pMatA->ncol;r++)
		{
			rterm[r] = 0;
		}
		//�õ���������
		for (j=0;j<pMatA->num;j++)
		{
			if (pMatA->elem[j].r == i)
			{
				rterm[ pMatA->elem[j].c-1] = pMatA->elem[j].e;
			}
		}
		
		//��B��ÿһ��
		for (j=1;j<=pMatB->ncol;j++)
		{
			//�Ƚ�������������
			for (c=0;c<pMatB->nrow;c++)
			{
				cterm[c] = 0;
			}
			//�õ���������
			for (c=0;c<pMatB->num;c++)
			{
				if (pMatB->elem[c].c == j)
				{
					cterm[ pMatB->elem[c].r-1] = pMatB->elem[c].e;
				}
			}

			//����i �� j�е�ֵ
			sum = 0;
			for (r = 0;r<pMatA->ncol;r++)
			{
				sum += rterm[r]*cterm[r];
			}
			if (sum	!=0)
			{
				pMatC->elem[pMatC->num].r = i;
				pMatC->elem[pMatC->num].c = j;
				pMatC->elem[pMatC->num++].e = sum;
			}
			
		}
	}




}




void main()
{
	/************************************************************************/
	/*                             ��ͨ����                                 */
	/************************************************************************/
	int i,j,x,y;
	// ����һ��4*5����mat��һ��5*4����matT
	intMatrix mat, matT;
	// ��ʼ���þ��󣬲�Ϊ��ÿ��Ԫ�ظ�ֵ
	InitMatrix(&mat,4,5);
	InitMatrix(&matT,5,4);
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=5;j++)
		{
			Assign(&mat, i,j,  i+j);
		}
	}
	// ��ӡ��mat
	PrintMatrix(&mat);
	// ��mat����ת�ã�����i,jλ��Ԫ����j,iλ��Ԫ�ػ���������ӡ
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=5;j++)
		{
			Get(&mat, i,j , &x);			
			Assign(&matT, j,i, x );			
		}
	}
	PrintMatrix(&matT);

	
	/************************************************************************/
	/*                             �Գƾ���                                 */
	/************************************************************************/
	// ����һ����ά����m1����ʼ��Ϊ�Գƾ�����ʽ
	int m1[DIM][DIM] ;
	for (i=0;i<DIM;i++)
	{
		for (j=0;j<=i;j++)
		{
			m1[i][j] =	m1[j][i] =  i+j;
			printf("%3d ", m1[i][j]);
		}
		printf("\n");
	}
	// ����һ��ѹ������mat������m1��ʼ��mat
	intCompressedMatrix mat2;
	InitMatrix(&mat2, m1);
		
	// ��ӡ��mat
	PrintMatrix(&mat2);




	/************************************************************************/
	/*                             ϡ�����                                 */
	/************************************************************************/	
    // ����������ά����a��b������������ֵ��ʼ��a��b
	int a[ROWS][COLS] = {{0,2},{0,0,5},{8},{0,0,0,0,0,10},{0,0,0,7},{45}};
	int b[ROWS][COLS] = {{0,-2},{0,0,6},{0,0,13},{0,0,0,0,0,0,-70},{66,0,7},{0, 0,0 , 88}}; 
	SparseMatrix smat1, smat2, smat3,smat4;
    //����������Ԫ����ʽϡ�����mat1��mat2���ֱ���a��b��ʼ��
	BuildSparseMatrix(a, &smat1);
	BuildSparseMatrix(b, &smat2);    
	//���mat1��mat2
	printf("����A\n");
	PrintSMatrix(&smat1);
	printf("����B\n");
	PrintSMatrix(&smat2);
    // ������Ԫ����ʽϡ�����mat3�� ����mat3=mat1+mat2
	Add(&smat1, &smat2, &smat3);
	//���mat3
	printf("����C=A+B:\n");
	PrintSMatrix(&smat3);
 	// ��mat3ת�õ�mat2
	Translate3(&smat3, &smat2);
	//���mat2
	printf("����C��ת��\n");
	PrintSMatrix(&smat2);
    // ������Ԫ����ʽϡ�����mat4�� ����mat4=mat1 * mat2
	Mul(&smat1, &smat2, &smat4);
	//���mat4
	printf("����D=A*C\n");
    PrintSMatrix(&smat4);
}