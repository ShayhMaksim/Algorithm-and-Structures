#ifndef EXERCISE1_7_H
#define EXERCISE1_7_H


int ** rotateImage(int **a,int n)
{
    int **res=new int*[n];
    for(int i=0;i<4;i++){
        res[i]=new int[n];
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j]=a[n-1-j][i];
        }
    }
    return res;
}

/**
 * @brief rotateImage2 - ЧТО ЗА ГЕНИИ ЭТО ПРИДУМЫВАЮТ?!
 * @param a
 * @param n
 */
void rotateImage2(int **a, int n)
{
    for(int layer=0;layer<n/2;++layer)
    {
        int first=layer;
        int last=n-1-layer;
        for(int i=first;i<last;i++){
            int offset=i-first;
            //сохранить верхнюю картинку
            int top=a[first][i];

            //левая сторона -> верхняя сторона
            a[first][i]=a[last][last-offset];

            //нижняя сторона -> левая сторона
            a[last][last-offset]=a[i][last];

            //верхняя сторона -> правая сторона
            a[i][last]=top;
        }
    }
}

//Так делают простые работяги
void rotateImage3(int **a, int n)
{
    for (int layer=0;layer<n/2;layer++){
        int first=layer;
        int last=n-1-layer;

        for(int i=first;i<last;i++){

            int offset=i-first;

            int tmp=a[first][i];

            a[first][i]=a[last][last-offset];

            a[last][last-offset]=a[i][last];

            a[i][last]=tmp;

        }
    }
}


#endif // EXERCISE1_7_H
