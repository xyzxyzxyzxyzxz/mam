/*test file of matrix class for matrx.h*/
/*Determinant of any order matrix Algorithm*/

/*created under Lo SY*/
/*end in AD 2015_9_27_10:31:05_GMT+8:00*/



#include <stdlib.h>
#include <iostream>


int sig (int argt);
double * subd(double * mda,int rw,int cw,int ri,int ci);
double dett(double * mda,int k);
double tdet(double * mda);
double wdet(double * mda);

int sig (int argt)
{
    if (argt%2==0)
        return 1;
    if (argt%2==1)
        return -1;
}

double dett(double * mda,int k)
{
    int ii=0;
    double *smda,res=0,smdv=0;

    switch (k)
    {
        case 1:
            {
                res=*(mda);
                break;
            }
        case 2:
            {
                res=wdet(mda);
                break;
            }
        case 3:
            {
                res=tdet(mda);
                break;
            }
        default:
            {
    for (ii=1;ii<=k;ii++)
    {
        smdv=0;
        smda=subd(mda,k,k,1,ii);
        if (k==4)
            smdv=tdet(smda);
        else smdv=dett(smda,k-1);

        res+=(*(mda+ii-1))*sig(ii+1)*smdv;
    }
    break;
    }
    }
    return res;

}

double tdet (double * mda)
{
    double res=0;

    res=(*mda)*(*(mda+4))*(*(mda+8))+(*(mda+1))*(*(mda+5))*(*(mda+6))+(*(mda+2))*(*(mda+3))*(*(mda+7))-(*(mda+2))*(*(mda+4))*(*(mda+6))-(*(mda+1))*(*(mda+3))*(*(mda+8))-(*(mda))*(*(mda+5))*(*(mda+7));

    return res;
}

double wdet (double *mda)
{
    double res=0;
    res=(*(mda))*(*(mda+3))-(*(mda+1))*(*(mda+2));
    return res;
}

double * subd (double * mda,int rw,int cw,int ri,int ci)
{
    int ii=0,ismi=0;
    double * rmda;
    rmda=(double *)malloc(sizeof(double)*(rw-1)*(cw-1));
    /*roe:ii/3+1 col:ii%3+1*/
    for (ii=0;ii<rw*cw;ii++)
    {
        if((ii/rw+1)!=ri&&(ii%rw+1)!=ci)
        {
            *(rmda+ismi)=*(mda+ii);
            ismi++;
        }
    }
    return rmda;
}

int main (void)
{
    int il=0;
    double da1[1]={12};
    double da2[4]={3,2,1,12};
    double da3[9]={3,5,2,1,45,6,4,1,2};
    double da4[16]={2,14,3,1,1,1,4,2,1,12,33,1,45,1,55,2};
    double da5[25]={2,32,14,2,1,3,5,2,1,1,2,1,1,4,2,1,12,33,1,45,6,4,1,55,2};
    double re=0,*sm;
    re=dett(da,3);
    for (il=0;il<9;il++)
    std::cout<<re<<std::endl;
    return 0;
}



/*suki suki S.K.Y*/
/*S_Y*//*X Y Z*/
