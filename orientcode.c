#include <kipr/botball.h>

int main()
{
   int numsamp = 1000;
   double sample_interval = 5;
   int tcaln = 30;
   float tcal = 0;
   int count;
   double tint;
   float x[numsamp];
   float y[numsamp];
   float z[numsamp];
   double time[numsamp];
  // printf("magnetometer calibrate\n");
     clock_t t;
     clock_t t2;
     t = clock();

     for(count = 0;count < tcaln;count++)
     {
         x[count] = magneto_x();
         y[count] = magneto_y();
         z[count] = magneto_z();
         t2 = clock();

         while((double)(t2-t) / CLOCKS_PER_SEC < (sample_interval *0.001) ) //-0.000031 is timing calibration value - 0.000031
         {
              t2 = clock();

         }
         time[count] = (double)(t2-t) / CLOCKS_PER_SEC;
         t = clock();
     }

     for(count = 0;count < tcaln;count++)
     {
     tcal += (sample_interval *0.001 - time[count]);
     }
     tcal = tcal / tcaln;
     t = clock;
    for(count = 0;count < numsamp;count++)
    {
        x[count] = magneto_x();
        y[count] = magneto_y();
        z[count] = magneto_z();
        t2 = clock();

        while((double)(t2-t) / CLOCKS_PER_SEC < (sample_interval *0.001 + tcal) ) //-0.000031 is timing calibration value - 0.000031
        {
             t2 = clock();

        }
        time[count] = (double)(t2-t) / CLOCKS_PER_SEC;
        t = clock();
    }
    t2 = clock();
    tint =(double)((t2-t) / CLOCKS_PER_SEC)/numsamp;

    printf("Average Time: %f\n",tint);
printf("T  ,   X\n[");
    for(count = 0;count < numsamp;count++)
    {
        printf("%f %f",time[count],x[count]);
        if (count < numsamp -1)
        {
            printf("; ");
        }
    }
    printf("]\n");
    printf("T  ,   Y\n[");
   for(count = 0;count < numsamp;count++)
    {
        printf("%f %f",time[count],y[count]);
        if (count < numsamp -1)
        {
            printf("; ");
        }
    }
    printf("]\n");
    printf("T  ,   Z\n[");
    for(count = 0;count < numsamp;count++)
    {
        printf("%f %f",time[count],z[count]);
        if (count < numsamp -1)
        {
            printf("; ");
        }
    }
    printf("]/n");
    //printf("T: %f, X: %f, Y: %f, Z: %f\n",time[count],x[count],y[count],z[count]);
  //printf("%f,%f\n",time[count],x[count],y[count],z[count]);






    /*printf("accelerometer calibrate\n");

    t = clock();
    for(count = 0;count < tcaln;count++)
    {
        x[count] = accel_x();
        y[count] = accel_y();
        z[count] = accel_z();
        t2 = clock();

        while((double)(t2-t) / CLOCKS_PER_SEC < (sample_interval *0.001) ) //-0.000031 is timing calibration value - 0.000031
        {
             t2 = clock();

        }
        time[count] = (double)(t2-t) / CLOCKS_PER_SEC;
        t = clock();
    }

    for(count = 0;count < tcaln;count++)
    {
    tcal += (sample_interval *0.001 - time[count]);
    }
    tcal = tcal / tcaln;
    t = clock;
   for(count = 0;count < numsamp;count++)
   {
       x[count] = accel_x();
       y[count] = accel_y();
       z[count] = accel_z();
       t2 = clock();

       while((double)(t2-t) / CLOCKS_PER_SEC < (sample_interval *0.001 + tcal) ) //-0.000031 is timing calibration value - 0.000031
       {
            t2 = clock();

       }
       time[count] = (double)(t2-t) / CLOCKS_PER_SEC;
       t = clock();
   }
   t2 = clock();
   tint =(double)((t2-t) / CLOCKS_PER_SEC)/numsamp;

   printf("Average Time: %f\n",tint);
printf("T  ,   X\n");
   for(count = 0;count < numsamp;count++)
   {
       printf("%f,%f\n",time[count],x[count]);
   }
   printf("T  ,   Y\n");
   for(count = 0;count < numsamp;count++)
   {
       printf("%f,%f\n",time[count],y[count]);
   }
   printf("T  ,   Z\n");
   for(count = 0;count < numsamp;count++)
   {
       printf("%f,%f\n",time[count],z[count]);
   }






       printf("gyroscope calibrate\n");

       t = clock();
       for(count = 0;count < tcaln;count++)
       {
           x[count] = gyro_x();
           y[count] = gyro_y();
           z[count] = gyro_z();
           t2 = clock();

           while((double)(t2-t) / CLOCKS_PER_SEC < (sample_interval *0.001) ) //-0.000031 is timing calibration value - 0.000031
           {
                t2 = clock();

           }
           time[count] = (double)(t2-t) / CLOCKS_PER_SEC;
           t = clock();
       }

       for(count = 0;count < tcaln;count++)
       {
       tcal += (sample_interval *0.001 - time[count]);
       }
       tcal = tcal / tcaln;
       t = clock;
      for(count = 0;count < numsamp;count++)
      {
          x[count] = gyro_x();
          y[count] = gyro_y();
          z[count] = gyro_z();
          t2 = clock();

          while((double)(t2-t) / CLOCKS_PER_SEC < (sample_interval *0.001 + tcal) ) //-0.000031 is timing calibration value - 0.000031
          {
               t2 = clock();

          }
          time[count] = (double)(t2-t) / CLOCKS_PER_SEC;
          t = clock();
      }
      t2 = clock();
      tint =(double)((t2-t) / CLOCKS_PER_SEC)/numsamp;

      printf("Average Time: %f\n",tint);
   printf("T  ,   X\n");
      for(count = 0;count < numsamp;count++)
      {
          printf("%f,%f\n",time[count],x[count]);
      }
      printf("T  ,   Y\n");
      for(count = 0;count < numsamp;count++)
      {
          printf("%f,%f\n",time[count],y[count]);
      }
      printf("T  ,   Z\n");
      for(count = 0;count < numsamp;count++)
      {
          printf("%f,%f\n",time[count],z[count]);
      }



*/


   return 0;
}
