/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#pragma warning(disable:4996)


typedef struct service {

   int arr[50][100];
   int limit;
}Team;

Team team[100];
int region[50];
int support_region[50];
int Answer;
void setting();
int my_service(int, int, int);
int other_service(int, int, int, int);
int Region_check(int);
void next(int, int, int);

int main(void)
{
   int a, b;
   int i, j;
   int T, test_case;
   int team_num, service_week, M;
   int listLength;
   int check;
   int count = 0;
   int for_count = 0;
   int amazing = 0;

   setbuf(stdout, NULL);

   scanf("%d", &T);
   for (test_case = 0; test_case < T; test_case++)
   {
      setting();

      scanf("%d %d %d", &team_num, &service_week, &M);
      for (i = 0; i<service_week; i++)
      {
         scanf("%d", &region[i]);
         support_region[i] = region[i];
      }

      for (i = 0; i<team_num; i++) {

         scanf("%d", &listLength);


         for (j = 0; j<listLength; j++) {
            scanf("%d %d", &a, &b);
            team[i].arr[a][b] = 1;
            for_count++;
         }
      }



      while (count < for_count) {

         for (i = 0; i<team_num; i++) {

            for (a = 0; a<service_week; a++) {

               for (b = 0; b<team_num; b++) {

                  if (team[i].limit > M) {
                     amazing = 1;
                     break;
                  }

                  else if (team[i].arr[a][b] == 1 && region[a] > 0)
                  {
                     check = my_service(i, a, team_num);
                     if (check == -1)
                        break;

                     check = other_service(i, a, b, team_num);
                     if (check == -1)
                        break;

                     team[i].arr[a][b] = 2;
                     region[a]--;
                     team[i].limit++;

                  }

               }
               if (amazing == 1) {
                  amazing = 0;
                  break;
               }

            }


         }

         if (Region_check(service_week))
            break;

         next(team_num, service_week, team_num);
         count++;

      }

      Answer = Region_check(service_week);

      printf("Case #%d\n", test_case + 1);
      printf("%d\n", Answer);

   }

   return 0;
}






void setting() {

   int i, j, k;

   for (i = 0; i<100; i++) {
      for (j = 0; j<50; j++) {
         for (k = 0; k<100; k++) {
            team[i].arr[j][k] = 0;
         }
      }
      team[i].limit = 0;
   }
}


int my_service(int teamnum, int a, int real) {

   int i;

   for (i = 0; i<real; i++)
   {
      if (team[teamnum].arr[a][i] == 2)
         return -1;
   }

   return 1;
}

int other_service(int myteam, int a, int b, int real) {

   int i;

   for (i = 0; i<real; i++) {

      if (i != myteam && team[i].arr[a][b] == 2)
         return -1;
   }
   return 1;
}


int Region_check(int service_week) {
   int i;
   for (i = 0; i<service_week; i++) {
      if (region[i]>0)
         return 0;

   }
   return 1;

}

void next(int te, int se, int real) {

   int i, j, k;
   int count = 0;

   for (i = 0; i<te; i++) {
      for (j = 0; j<se; j++) {
         for (k = 0; k<real; k++) {

            if (team[i].arr[j][k] == 2)
               team[i].arr[j][k] = 1;
         }

      }
      region[j] = support_region[j];
      team[i].limit = 0;
   }

   for (i = 0; i<te; i++) {

      for (j = 0; j<se; j++) {
         for (k = 0; k<real; k++) {

            if (team[i].arr[j][k] == 1 && count == 0) {
               team[i].arr[j][k] = 3;
               count++;
               break;
            }
         }
         if (count == 1)
            break;

      }
      if (count == 1)
         break;
   }


}