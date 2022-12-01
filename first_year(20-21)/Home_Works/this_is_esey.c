#include <stdio.h>
#include <math.h>

int main ()
{
  double a, b, c, cos1, cos2, cos3;
  scanf("%lf%lf%lf",&a,&b,&c);

  cos3 = (a * a + b * b - c * c)/(2 * a * b);
  cos2 =(a * a + c * c - b * b)/(2 * a * c);
  cos1 =(b * b + c * c - a * a)/(2 * b * c);


printf("%lf\n %lf\n %lf\n",cos1,cos2,cos3);

  if (cos1 < 0 || cos2 < 0 || cos3 < 0)
    printf("obtuse-angle");
    
  else
    {
    if  (cos1 == 0 ||cos2 == 0|| cos3 == 0)
        printf("rectangular");
        
        else printf("sharp-angle");
    }

  return 0;
}