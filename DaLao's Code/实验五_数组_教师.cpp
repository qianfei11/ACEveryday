#include <stdio.h>
#include <stdlib.h>

/************************************************************************/
/*                             普通矩阵                                 */
/************************************************************************/

//数学上的矩阵可用C语言中的二维数组表示，但为了更深入地理解二维数组的存取，本实验用顺序表来模拟矩阵。
typedef struct {
	int* elem; // 用来存储矩阵元素的动态数组空间：按照行优先存储
	int row, col;
}intMatrix;

//给定矩阵的行数和列数，对矩阵进行初始化。
void  InitMatrix( intMatrix *pMat, int row, int col )
{
/**********************************************************
设定pMat所指向矩阵的行数，列数并为之开辟元素的动态存储空间
	*********************************************************/
	pMat->row =     row     ; // 行数..
	pMat->col =     col  ; // 列数
	pMat-> elem =  (int*)malloc(sizeof(int)*row*col) ; // 存储空间
}

//对矩阵的第i行第j列位置的元素赋值为x。赋值成功返回1，否则0。
int  Assign(intMatrix *pMat , int i , int j,  int x) 
{
	// 判断i, j是否合法
	if ( (i<1 || i> pMat->row ) || (j<1 || j> pMat->col )  )
	{
		printf("行或列位置非法，赋值失败\n"); return 0;
	}
	// 若合法，赋值 i,j从1开始，数组存数据从0位置开始
	pMat->elem[ (i-1)*pMat->col  + j-1  ]  =  x;
	return 1;
}
//读取矩阵中元素值
//将矩阵的第i行第j列位置的元素赋值到x带回。成功返回1，否则0。
int  Get(intMatrix *pMat , int i , int j,  int *x) 
{
	// 判断i ,j是否合法
	if ( (i<1 || i> pMat->row ) || (j<1 || j> pMat->col )  )
	{
		printf("行或列位置非法，赋值失败\n"); return 0;
	}
	// 给x赋值
	*x = pMat->elem[ (i-1)*pMat->col  + j-1  ];
	return 1;
}


//将矩阵按照行×列的形式输出到屏幕上。
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
/*                             对称矩阵                                 */
/************************************************************************/

//定义一个压缩矩阵的结构体类型，用一维数组来存储矩阵中的元素。为了简单起见，令矩阵为DIM*DIM的方阵。其中，DIM为一确定的整数大小。
#define MAXLEN 100
#define DIM 10
typedef struct {
	int elem[MAXLEN];    // 用来存特殊矩阵元素的一维数组
}intCompressedMatrix;
//对称矩阵的初始化与读取
//用一个对称矩阵来初始化该压缩矩阵
void  InitMatrix( intCompressedMatrix*pMat, int m[DIM ][DIM ] )
{
/**********************************************************
将存放于二维数组m中的对称矩阵下三角元素存放到pMat中
	*********************************************************/
	int index = 0;
	for(int i=1; i<=DIM; i++) // 对每一行
		for(int j=1; j<= i;  j++) // 对每一列中的部分元素
			pMat->elem[ (i-1)*i/2 + j-1 ] = m[  i-1  ][  j-1  ];
}

// 读取
int  Get(intCompressedMatrix*pMat , int i , int j,  int *x) 
{
	// 判断i, j是否合法
	if ( (i<1 || i> DIM) || (j<1 || j> DIM )  ) 
	{
		printf("行或列索引非法，赋值失败\n"); return 0;
	}
	
	// 给x赋值
	// 由于只保存了i>=j的下三角，如果欲读取j>i的上三角元素，怎么读取？
	if (i>=j)
		*x = pMat->elem[(i-1)*i/2 + j-1 ];
	else
		*x = pMat->elem[(j-1)*j/2 + i-1 ];
	return 1;
}
//将矩阵按照行×列的形式输出到屏幕上。
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
/*                             稀疏矩阵                                 */
/************************************************************************/
//定义一个三元组，用来存储非零元素的行、列和数据值。再定义一个稀疏矩阵结构体，用来表示稀疏矩阵。
#define MAXNUM 20   // 假定非零元素个数不超过20个
typedef struct{
    int r, c, e;   // 非零元素的行、列和数据值
}Triple;
typedef struct{
    //非零元素信息数组
	Triple elem[MAXNUM];
    //分别保存稀疏矩阵的总行数、总列数和非零元素个数
    int nrow, ncol, num; 
}SparseMatrix;
//根据二维数组初始化一个稀疏矩阵结构体
//二维数组中包含少量非零元素，通过遍历该二维数组，将非零元素信息填入稀疏矩阵结构体中。为简化起见，假定二维数组为六行七列。
#define ROWS 6
#define COLS 7
void BuildSparseMatrix(int m[ROWS ][COLS ], SparseMatrix *pSM)
{
    int i,j, n = 0;  // 用于统计非零元素个数
	
    // 遍历该二维数组
    for(  i=0;i<ROWS; ++i  )
		for( j=0;j<COLS;++j )
		{
			// 如果找到非零元素
			if (m[i][j] != 0)
			{
				// 保存非零元素信息到相应位置的三元组中
				 pSM->elem[n].r =  i+1 ;
				 pSM->elem[n].c =  j+1 ;
				 pSM->elem[n].e =  m[i][j] ;
				 ++n;
			}
		}
		
		// 分别保存稀疏矩阵的总行数、总列数和非零元素个数	  
		pSM->nrow =  ROWS      ;
		pSM->ncol =  COLS      ;
		pSM->num =    n    ;
}
//输出稀疏矩阵
//将三元组形式的稀疏矩阵按照二维数组的形式输出。
int Get(SparseMatrix *pSM, int r, int c)
{
/**********************************************************
从稀疏矩阵中得到第r行c列元素的值
	*********************************************************/
    int i=0;
	
    // 遍历该稀疏矩阵的三元组数组
	for( ; i<pSM->num; i++)
	{
        // 若找到第r行第c列的非零值，则返回该值
		if (pSM->elem[i].r == r && pSM->elem[i].c == c)
			return pSM->elem[i].e;
	}
	
    // 若没有找到第r行第c列的数据，则必然是0
	return 0;
}

void PrintSMatrix(SparseMatrix *pSM)
{
	int  i, j;
	for(i=1; i<=pSM->nrow; i++)
	{
		for(j=1; j<=pSM->ncol; j++)
			printf("%3d ", Get(pSM, i,j)); // 输出第i行第j列元素的值
		printf("\n"); 
	}
}
//稀疏矩阵的转置
//教材中转置方法三：引入了两个辅助的存储空间starting_pos和row_terms将A转置为B。其中数组row_terms中存放的是各行非零元素的个数，数组starting_pos用来存储转置后的矩阵每行非零元素的起始地址。
void Translate3(SparseMatrix*pMatA, SparseMatrix*pMatB)
{
	int i;
    // 定义两个辅助数组
    int row_terms[COLS ],starting_pos[COLS ];
	
    // 转置后，行列值交换，但非零元素个数不变
    pMatB->ncol =  pMatA->nrow     ;
    pMatB->nrow =  pMatA->ncol     ;
    pMatB->num  =  pMatA->num      ;
	
    // 统计转置后每行元素个数
    // 首先将每行元素个数置零
    for(i=0; i<   COLS         ; i++)
		row_terms[i]=0;
	
	//遍历一遍矩阵A中的非零值信息，计算转置之后每行非零元素个数
    for(i=0; i<pMatA->num; i++)
        row_terms[ pMatA->elem[i].c-1]++;
	
    // 计算转置之后每一行起始写入位置
    // 第1行的写入位置也在0号位置
    starting_pos[0]=0;
	// 从第2行开始， 第i行的写入位置是第i-1行的起始写入位置+第i-1
	// 行的非零元素个数
    for(i=1; i<pMatA->ncol; i++)
        starting_pos[i]= starting_pos[i-1] + row_terms[i-1] ;
	
	// 有了两个辅助数组，再次扫描A
    for(i=0; i<pMatA->num ;i++)
    {
		// A中的第i个非零值转置之后为B的第几行？从starting_pos
		// 中找到第几行的起始写入位置
		pMatB->elem[  starting_pos[pMatA->elem[i].c-1 ]           ].r =  pMatA->elem[i].c ;
		pMatB->elem[  starting_pos[pMatA->elem[i].c-1 ]           ].c =  pMatA->elem[i].r ;
		pMatB->elem[  starting_pos[pMatA->elem[i].c-1 ]           ].e =  pMatA->elem[i].e ;
		
		// B中的第几行写入数据后， starting_pos中相应行的写入位置
		// 后移一位
		starting_pos[pMatA->elem[i].c-1 ]++;
    }
}
//稀疏矩阵相加
//试根据函数原型，写出稀疏矩阵C=A+B的函数。
void Add(SparseMatrix*pMatA, SparseMatrix*pMatB, SparseMatrix*pMatC)
{
	int i=0,j=0,n=0, sum;
	//首先要判断AB的行列相等
	if (pMatA->nrow != pMatB->nrow  || pMatA->ncol != pMatB->ncol )
	{
		printf("矩阵的行和列不相等，不能相加！\n");
		return;
	}
	while (i<pMatA->num  && j<pMatB->num)
	{
		//A中数据的行 小于 B中数据的行
		if (pMatA->elem[i].r < pMatB->elem[j].r)
		{
			pMatC->elem[n++] = pMatA->elem[i++];
		}
		else if (pMatA->elem[i].r > pMatB->elem[j].r)
		{
			pMatC->elem[n++] = pMatB->elem[j++];
		}
		else //相同行
		{
			//再看列。
			//A的列小于B的列
			if (pMatA->elem[i].c < pMatB->elem[j].c)
			{
				pMatC->elem[n++] = pMatA->elem[i++];
			}
			else if (pMatA->elem[i].c > pMatB->elem[j].c)
			{
				pMatC->elem[n++] = pMatB->elem[j++];
			}
			else //列也相等， 则相加
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
	//若还有剩余的数据
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
//稀疏矩阵相乘
//试根据函数原型，写出稀疏矩阵C=A*B的函数。
void Mul(SparseMatrix*pMatA, SparseMatrix*pMatB, SparseMatrix*pMatC)
{
	int i,j,mul,sum, r, c;
	//存每一行的数据
	int rterm[COLS] = {0};
	//存每一列的数据
	int cterm[COLS] = {0};
	//首先要判断A的列 与 B的行相等
	if (pMatA->nrow != pMatB->ncol)
	{
		printf("矩阵A的列不等于B的行，不能相乘！\n");
		return;
	}
	pMatC->nrow = pMatA->nrow;
	pMatC->ncol = pMatB->ncol;
	pMatC->num = 0;

	//对A的每一行
	for (i=1;i<=pMatA->nrow;i++)
	{
		//先将该行数据置零
		for (r=0;r<pMatA->ncol;r++)
		{
			rterm[r] = 0;
		}
		//得到该行数据
		for (j=0;j<pMatA->num;j++)
		{
			if (pMatA->elem[j].r == i)
			{
				rterm[ pMatA->elem[j].c-1] = pMatA->elem[j].e;
			}
		}
		
		//对B的每一列
		for (j=1;j<=pMatB->ncol;j++)
		{
			//先将该列数据置零
			for (c=0;c<pMatB->nrow;c++)
			{
				cterm[c] = 0;
			}
			//得到该列数据
			for (c=0;c<pMatB->num;c++)
			{
				if (pMatB->elem[c].c == j)
				{
					cterm[ pMatB->elem[c].r-1] = pMatB->elem[c].e;
				}
			}

			//计算i 行 j列的值
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
	/*                             普通矩阵                                 */
	/************************************************************************/
	int i,j,x,y;
	// 定义一个4*5矩阵mat和一个5*4矩阵matT
	intMatrix mat, matT;
	// 初始化该矩阵，并为其每个元素赋值
	InitMatrix(&mat,4,5);
	InitMatrix(&matT,5,4);
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=5;j++)
		{
			Assign(&mat, i,j,  i+j);
		}
	}
	// 打印该mat
	PrintMatrix(&mat);
	// 将mat矩阵转置，即将i,j位置元素与j,i位置元素互换，并打印
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
	/*                             对称矩阵                                 */
	/************************************************************************/
	// 定义一个二维数组m1并初始化为对称矩阵形式
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
	// 定义一个压缩矩阵mat，并用m1初始化mat
	intCompressedMatrix mat2;
	InitMatrix(&mat2, m1);
		
	// 打印该mat
	PrintMatrix(&mat2);




	/************************************************************************/
	/*                             稀疏矩阵                                 */
	/************************************************************************/	
    // 定义两个二维数组a和b，用少量非零值初始化a和b
	int a[ROWS][COLS] = {{0,2},{0,0,5},{8},{0,0,0,0,0,10},{0,0,0,7},{45}};
	int b[ROWS][COLS] = {{0,-2},{0,0,6},{0,0,13},{0,0,0,0,0,0,-70},{66,0,7},{0, 0,0 , 88}}; 
	SparseMatrix smat1, smat2, smat3,smat4;
    //定义两个三元组形式稀疏矩阵mat1和mat2，分别用a和b初始化
	BuildSparseMatrix(a, &smat1);
	BuildSparseMatrix(b, &smat2);    
	//输出mat1和mat2
	printf("矩阵A\n");
	PrintSMatrix(&smat1);
	printf("矩阵B\n");
	PrintSMatrix(&smat2);
    // 定义三元组形式稀疏矩阵mat3， 计算mat3=mat1+mat2
	Add(&smat1, &smat2, &smat3);
	//输出mat3
	printf("矩阵C=A+B:\n");
	PrintSMatrix(&smat3);
 	// 将mat3转置到mat2
	Translate3(&smat3, &smat2);
	//输出mat2
	printf("矩阵C的转置\n");
	PrintSMatrix(&smat2);
    // 定义三元组形式稀疏矩阵mat4， 计算mat4=mat1 * mat2
	Mul(&smat1, &smat2, &smat4);
	//输出mat4
	printf("矩阵D=A*C\n");
    PrintSMatrix(&smat4);
}