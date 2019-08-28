#include <QCoreApplication>
#include "normalgpz.h"
#include "sunrotation.h"
#include "abnormalgpz.h"
int main()
{
        TIntegrator * integrator=new TDormandPrince();
        SunRotation *Arg1=new SunRotation(0,50000,1);
         Arg1->getInitialPosition(0,0,0,10000000,0,0);
        integrator->setPrecision(1e-16L);
         integrator->Run(Arg1);
        TMatrix Result = Arg1->getResult();
        std::ofstream out;
        out.open("first.txt");
        if (out.is_open())
        {
               for (int i=0;i<Result.GetRowCount();i++)
                       {
                               for(int j=0;j<Result.GetColCount()-3;j++)
                               {
                                   out<< std::to_string(Result(i,j));
                                   out<<(" ");
                               }
                               out <<std::endl;
                       }
                       out.close();
        }

        out.open("firstX.txt");
        if (out.is_open())
        {
               for (int i=0;i<Result.GetRowCount();i++)
                       {
                              out<< std::to_string(Result(i,0)); out<<(" ");
                                   out<< std::to_string(Result(i,1));
                                   out<<(" ");
                               out <<std::endl;
                       }
                       out.close();
        }

        out.open("firstY.txt");
        if (out.is_open())
        {
               for (int i=0;i<Result.GetRowCount();i++)
                       {
                              out<< std::to_string(Result(i,0)); out<<(" ");
                                   out<< std::to_string(Result(i,2));
                                   out<<(" ");
                               out <<std::endl;
                       }
                       out.close();
        }
        out.open("firstZ.txt");
        if (out.is_open())
        {
               for (int i=0;i<Result.GetRowCount();i++)
                       {
                              out<< std::to_string(Result(i,0)); out<<(" ");
                                   out<< std::to_string(Result(i,3));
                                   out<<(" ");
                               out <<std::endl;
                       }
                       out.close();
        }



        NormalGPZ *Arg2=new NormalGPZ (0,50000,1);
        Arg2->getInitialPosition(0,0,0,10000000,0,0);
        integrator->Run(Arg2);
        TMatrix Result1 = Arg2->getResult();

        out.open("second.txt");
        if (out.is_open())
        {
               for (int i=0;i<Result1.GetRowCount();i++)
                       {
                               for(int j=0;j<Result1.GetColCount()-3;j++)
                               {
                                   out<< std::to_string(Result1(i,j));
                                   out<<(" ");
                               }
                               out <<std::endl;
                       }
                       out.close();
        }
        out.open("secondX.txt");
        if (out.is_open())
        {
               for (int i=0;i<Result1.GetRowCount();i++)
                       {
                               out<< std::to_string(Result1(i,0)); out<<(" ");

                                   out<< std::to_string(Result1(i,1));
                                   out<<(" ");

                               out <<std::endl;
                       }
                       out.close();
        }
        out.open("secondY.txt");
        if (out.is_open())
        {
               for (int i=0;i<Result1.GetRowCount();i++)
                       {
                               out<< std::to_string(Result1(i,0)); out<<(" ");

                                   out<< std::to_string(Result1(i,2));
                                   out<<(" ");

                               out <<std::endl;
                       }
                       out.close();
        }
        out.open("secondZ.txt");
        if (out.is_open())
        {
               for (int i=0;i<Result1.GetRowCount();i++)
                       {
                               out<< std::to_string(Result1(i,0)); out<<(" ");

                                   out<< std::to_string(Result1(i,3));
                                   out<<(" ");

                               out <<std::endl;
                       }
                       out.close();
        }

    AbnormalGPZ *Arg3=new  AbnormalGPZ(0,50000,1);
    Arg3->getInitialPosition(0,0,0,10000000,0,0);
    integrator->Run(Arg3);
    TMatrix Result2 = Arg3->getResult();
    out.open("last.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                           for(int j=0;j<Result2.GetColCount()-3;j++)
                           {
                               out<< std::to_string(Result2(i,j));
                               out<<(" ");
                           }
                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("lastX.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                                   out<< std::to_string(Result2(i,0)); out<<(" ");
                               out<< std::to_string(Result2(i,1));
                               out<<(" ");

                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("lastY.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                                   out<< std::to_string(Result2(i,0)); out<<(" ");
                               out<< std::to_string(Result2(i,2));
                               out<<(" ");

                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("lastZ.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                                   out<< std::to_string(Result2(i,0)); out<<(" ");
                               out<< std::to_string(Result2(i,3));
                               out<<(" ");

                           out <<std::endl;
                   }
                   out.close();
    }


    out.open("BetweenAbnormalandClassic.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                            out<< std::to_string(Result2(i,0)); out<<(" ");
                           for(int j=1;j<Result2.GetColCount()-3;j++)
                           {
                               out<< std::to_string(-Result2(i,j)+Result(i,j));
                               out<<(" ");
                           }
                           out <<std::endl;
                   }
                   out.close();
    }

    out.open("BetweenAbnormalandClassicX.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                            out<< std::to_string(Result2(i,0)); out<<(" ");
                               out<< std::to_string(-Result2(i,1)+Result(i,1));
                               out<<(" ");
                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("BetweenAbnormalandClassicY.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                            out<< std::to_string(Result2(i,0)); out<<(" ");
                               out<< std::to_string(-Result2(i,2)+Result(i,2));
                               out<<(" ");
                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("BetweenAbnormalandClassicZ.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                            out<< std::to_string(Result2(i,0)); out<<(" ");
                               out<< std::to_string(-Result2(i,3)+Result(i,3));
                               out<<(" ");
                           out <<std::endl;
                   }
                   out.close();
    }


    out.open("BetweenNormalandClassic.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
               out<< std::to_string(Result2(i,0)); out<<(" ");
                           for(int j=1;j<Result2.GetColCount()-3;j++)
                           {
                               out<< std::to_string(-Result1(i,j)+Result(i,j));
                               out<<(" ");
                           }
                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("BetweenNormalandClassicX.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
               out<< std::to_string(Result2(i,0)); out<<(" ");

                               out<< std::to_string(-Result1(i,1)+Result(i,1));
                               out<<(" ");

                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("BetweenNormalandClassicY.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
               out<< std::to_string(Result2(i,0)); out<<(" ");

                               out<< std::to_string(-Result1(i,2)+Result(i,2));
                               out<<(" ");

                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("BetweenNormalandClassicZ.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
               out<< std::to_string(Result2(i,0)); out<<(" ");

                               out<< std::to_string(-Result1(i,3)+Result(i,3));
                               out<<(" ");

                           out <<std::endl;
                   }
                   out.close();
    }

    out.open("BetweenNormalandAbnormal.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                           out<< std::to_string(Result2(i,0)) ; out<<(" ");
                           for(int j=1;j<Result2.GetColCount()-3;j++)
                           {
                               out<< std::to_string(-Result2(i,j)+Result1(i,j));
                               out<<(" ");
                           }
                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("BetweenNormalandAbnormalX.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                           out<< std::to_string(Result2(i,0)) ; out<<(" ");

                               out<< std::to_string(-Result2(i,1)+Result1(i,1));
                               out<<(" ");

                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("BetweenNormalandAbnormalY.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                           out<< std::to_string(Result2(i,0)) ; out<<(" ");

                               out<< std::to_string(-Result2(i,2)+Result1(i,2));
                               out<<(" ");

                           out <<std::endl;
                   }
                   out.close();
    }
    out.open("BetweenNormalandAbnormalZ.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result2.GetRowCount();i++)
                   {
                           out<< std::to_string(Result2(i,0)) ; out<<(" ");

                               out<< std::to_string(-Result2(i,3)+Result1(i,3));
                               out<<(" ");

                           out <<std::endl;
                   }
                   out.close();
    }

                FILE *gp=popen("gnuplot -persist","w");
                if (gp==nullptr)
                {
                    printf("error opening pipe to GNU");
                    exit(1);
                }
                fprintf(gp,"cd \"/home/maksim/build-OPRS_Lab6-Desktop_Qt_5_12_0_GCC_64bit-Debug\" \n" );
                fprintf(gp, "plot \"BetweenAbnormalandClassicY.txt\" w l ,\"BetweenNormalandAbnormalY.txt\" w l,\"BetweenNormalandClassicY.txt\" w l  \n");
                       fprintf(gp,"set xzeroaxis lt -1 \n");
                pclose(gp);

                FILE *gp1=popen("gnuplot -persist","w");
                if (gp1==nullptr)
                {
                    printf("error opening pipe to GNU");
                    exit(1);
                }
    fprintf(gp1,"cd \"/home/maksim/build-OPRS_Lab6-Desktop_Qt_5_12_0_GCC_64bit-Debug\" \n" );
                fprintf(gp1, "plot \"BetweenAbnormalandClassicX.txt\" w l ,\"BetweenNormalandAbnormalX.txt\" w l,\"BetweenNormalandClassicX.txt\" w l \n");
                       fprintf(gp1,"set xzeroaxis lt -1 \n");
                pclose(gp1);

                FILE *gp2=popen("gnuplot -persist","w");
                if (gp2==nullptr)
                {
                    printf("error opening pipe to GNU");
                    exit(1);
                }
fprintf(gp2,"cd \"/home/maksim/build-OPRS_Lab6-Desktop_Qt_5_12_0_GCC_64bit-Debug\" \n" );
                fprintf(gp2, "plot \"BetweenAbnormalandClassicZ.txt\" w l ,\"BetweenNormalandAbnormalZ.txt\" w l,\"BetweenNormalandClassicZ.txt\" w l  \n");
                      fprintf(gp2,"set xzeroaxis lt -1 \n");
                pclose(gp2);

                FILE *gp3=popen("gnuplot -persist","w");
                if (gp3==nullptr)
                {
                    printf("error opening pipe to GNU");
                    exit(1);
                }
fprintf(gp3,"cd \"/home/maksim/build-OPRS_Lab6-Desktop_Qt_5_12_0_GCC_64bit-Debug\" \n" );
                fprintf(gp3, "plot \"firstX.txt\" w l ,\"secondX.txt\" w l,\"lastX.txt\" w l  \n");
                      fprintf(gp3,"set xzeroaxis lt -1 \n");
                pclose(gp3);

                FILE *gp4=popen("gnuplot -persist","w");
                if (gp4==nullptr)
                {
                    printf("error opening pipe to GNU");
                    exit(1);
                }
fprintf(gp4,"cd \"/home/maksim/build-OPRS_Lab6-Desktop_Qt_5_12_0_GCC_64bit-Debug\" \n" );
                fprintf(gp4, "plot \"firstY.txt\" w l ,\"secondY.txt\" w l,\"lastY.txt\" w l  \n");
                      fprintf(gp4,"set xzeroaxis lt -1 \n");
                pclose(gp4);

                FILE *gp5=popen("gnuplot -persist","w");
                if (gp5==nullptr)
                {
                    printf("error opening pipe to GNU");
                    exit(1);
                }
fprintf(gp5,"cd \"/home/maksim/build-OPRS_Lab6-Desktop_Qt_5_12_0_GCC_64bit-Debug\" \n" );
                fprintf(gp5, "plot \"firstZ.txt\" w l ,\"secondZ.txt\" w l,\"lastZ.txt\" w l  \n");
                      fprintf(gp5,"set xzeroaxis lt -1 \n");
                pclose(gp5);

                FILE *gp6=popen("gnuplot -persist","w");
                if (gp5==nullptr)
                {
                    printf("error opening pipe to GNU");
                    exit(1);
                }
fprintf(gp6,"cd \"/home/maksim/build-OPRS_Lab6-Desktop_Qt_5_12_0_GCC_64bit-Debug\" \n" );
                fprintf(gp6, "plot \"firstZ.txt\" w l   \n");
                      fprintf(gp6,"set xzeroaxis lt -1 \n");
                pclose(gp6);

                FILE *gp7=popen("gnuplot -persist","w");
                if (gp7==nullptr)
                {
                    printf("error opening pipe to GNU");
                    exit(1);
                }
                fprintf(gp7,"cd \"/home/maksim/build-OPRS_Lab6-Desktop_Qt_5_12_0_GCC_64bit-Debug\" \n" );
                fprintf(gp7, "plot \"BetweenAbnormalandClassicZ.txt\" w l   \n");
                       fprintf(gp7,"set xzeroaxis lt -1 \n");
                pclose(gp7);



    return 0;
}
