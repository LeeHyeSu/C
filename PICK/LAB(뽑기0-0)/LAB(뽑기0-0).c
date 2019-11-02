#include<stdio.h>
void pick (char* items, int numItem, char *bucket, int bucketSize, int k)
{
   int i, lastIndex;
   static int smallest;

   if (k == 0)
   {
      for (i = 0; i < bucketSize; i++)   {
         printf("%c ", bucket[i]);
      }
      printf("\n");
      return;
   }

   lastIndex = bucketSize - k - 1;

   for (i = 0; i < numItem; i++)   {
      if (bucket[lastIndex] + 1 > items[i])
         continue;
      bucket[lastIndex + 1] = items[i];
      pick(items, numItem, bucket, bucketSize, k-1);
   }
}

int main(void)
{
   char items[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
   char bucket[4];

   pick(items, 7, bucket, 3, 3);
}