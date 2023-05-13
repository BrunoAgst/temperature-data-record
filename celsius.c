#include <stdio.h>
#include <stdlib.h>
#define temp "temperature.dat"

void writeFile(float *vec);
void writeCelsius(float *vec);
void readFile(void);

int main(){
      FILE *arq;
      float vec[3];

      arq = fopen(temp, "rb");

      if(arq == NULL){
            fclose(arq);
            printf("File not empty.\n\n");
            writeCelsius(vec);
            writeFile(vec);
            readFile();
            return 0;
      }

      fclose(arq);

      printf("Currently recorded values:\n");
      
      readFile();
      
      printf("\nEnter new temperature values\n\n");

      writeCelsius(vec);
      writeFile(vec);
      
      return 0;

}

void writeFile(float *vec){
      FILE *arq;
      arq = fopen(temp, "wb");
      fwrite(vec, sizeof(float), 3, arq);
      fclose(arq);
}

void writeCelsius(float *vec) {
      for(int i=0; i<3; i++){
            printf("Enter value %d in Celsius: ", i);
            scanf("%f", &vec[i]);
            printf("\n");
      }
}

void readFile(void){
      float vec[3];
      FILE *arq;
      
      arq = fopen(temp, "rb");
      fread(vec, sizeof(float), 3, arq);

      for(int i=0; i<3; i++){
            printf("Celsius %d: %.2f\n", i, vec[i]);
      }
}