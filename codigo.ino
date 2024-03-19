#define tempo 1000 // tempo de 1s
int contador = 0; // contagem para dígitos do display

// pinos utilizados no Arduino
int portasPinos[8] = {2, 3, 4, 5, 6, 7, 8, 9};
// matriz controladora de segmentos que eu quero acender para cada dígito
int valorDigitos[10][8] = 
{
// A  B  C  D  E  F  G  DP
  {1, 1, 1, 1, 1, 1, 0, 0}, //0 
  {0, 1, 1, 0, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1, 0}, //2
  {1, 1, 1, 1, 0, 0, 1, 0}, //3
  {0, 1, 1, 0, 0, 1, 1, 0}, //4
  {1, 0, 1, 1, 0, 1, 1, 0}, //5
  {1, 0, 1, 1, 1, 1, 1, 0}, //6
  {1, 1, 1, 0, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1, 0}, //8
  {1, 1, 1, 1, 0, 1, 1, 0}, //9
};

void setup() {
  // pecorrer todas as portas e configurar como OUTPUT
  for(int i = 0; i < 8; i++) {
  	pinMode(portasPinos[i], OUTPUT);
  }
}

void loop(){
	qualDigitoVaiSerMostrado(contador);
  	delay(tempo);
  // contagem regressiva 
  	contador++;
  	
  if(contador > 9){
    contador = 0;
  }
}

void qualDigitoVaiSerMostrado(int digito){
  // pecorrer a nossa matriz de dígitos | linha não muda e sim a coluna
  for(int i = 0; i < 8; i++){
    digitalWrite(portasPinos[i], valorDigitos[digito][i]);
  }
}