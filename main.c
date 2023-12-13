//Emile Vargas
//O Código Zeta T3
#include <stdio.h>
//FUNÇÃO VIRAPALAVRAS
void viraPalavras(char vetor[], int tam) {
  int comeco = 0;
  int final = 0;

  for (int i = 0; i <= tam; i++) {
    if (vetor[i] == ' ' || vetor[i] == '\0') {
      final = i - 1;

      for (int i = comeco; i < final; i++) {
          char temp = vetor[i];
          vetor[i] = vetor[final];
          vetor[final] = temp;
          final--;
      }


      comeco = i + 1;
    }
  }
  comeco = 0;
  final = tam - 1;
  while (comeco < final) {
    char temp = vetor[comeco];
    vetor[comeco] = vetor[final];
    vetor[final] = temp;
    comeco++;
    final--;
  }
}
//FUNÇÃO ROLAESQUERDA
void rolaEsquerda(char vetor[], int tam, int num) {
  if (num >= tam || num <= 0) {
    return;
  }

  char temp[num];

  for (int i = 0; i < num; i++) {
    temp[i] = vetor[i];
  }

  for (int i = 0; i < tam - num; i++) {
    vetor[i] = vetor[i + num];
  }

  for (int i = tam - num, j = 0; i < tam; i++, j++) {
    vetor[i] = temp[j];
  }
}

//FUNCAO ADVANCE 
void advance(char vetor[], int tam, int adv) {
  for (int i = 0; i < tam; i++) {
    char c = vetor[i];

    if (c >= 'a' && c <= 'z') {
      c = 'a' + (c - 'a' + adv) % 26;
    } else if (c >= 'A' && c <= 'Z') {
      c = 'A' + (c - 'A' + adv) % 26;
    }

    vetor[i] = c;
  }
}
//FUNCAO TRANSFORM
void transform(char vetor[], int tam, char s1[], char s2[]) {
  for (int i = 0; i < tam; i++) {
    char c = vetor[i];
    for (int j = 0; s1[j] != '\0'; j++) {
      if (c == s1[j]) {
        vetor[i] = s2[j];
        break;
      }
    }
  }
}
int main() {
  char vetor[256];
  int tam = 0;

  printf("Digite a frase (atencion no máximo 255 caracteres)\n");

  char c;
  for (int i = 0; i < 255; i++) {
    if (scanf("%c", &c) != 1 || c == '\n') {
      break;
    }
    vetor[tam++] = c;
  }
  vetor[tam] = '\0';

  int i = 0;
  viraPalavras(vetor, tam);

  while (i < 100) {
    int num = 5;
    rolaEsquerda(vetor, tam, i / 2);
    advance(vetor, tam, i / 3);
    transform(vetor, tam, "abcdefghijklm", "bamdfhgjcielk");
    i++;

  }
  
  printf("%s\n", vetor);
  return 0;
}