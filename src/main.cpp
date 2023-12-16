#include <Arduino.h>

#define BOTAO 16
#define TEMPO_DEBOUNCE 10

int statusBotao = LOW;
int ultimoStatusBotao = LOW;
int cont = 0;
bool status = LOW;

unsigned long tempoUltimoDebounce = 0;
unsigned long tempoDebounce = 10;

//necessario declarar a funcao antes por estar usando o VSCode/PlatformIO, na IDE do arduino nao eh necessario
void debounceBotao();
void ligaDesligaLampada();

void setup() {
  Serial.begin(115200);
  pinMode(BOTAO, INPUT_PULLDOWN);
  Serial.println("== INICIANDO ... ");

}

void loop() {

  debounceBotao();
  Serial.print("cont = ");
  Serial.println(cont);
  Serial.print("lampada = ");
  Serial.println(status);


}

void debounceBotao() {
  int leitura = digitalRead(BOTAO);

  if(leitura != ultimoStatusBotao){
    tempoUltimoDebounce = millis();
  }

  if((millis() - tempoUltimoDebounce) > tempoDebounce) {
    if(leitura != statusBotao) {
      statusBotao = leitura;
      if(statusBotao == HIGH) {
        cont++;
        ligaDesligaLampada();
      }
    }
  }

  ultimoStatusBotao = leitura;

}

void ligaDesligaLampada(){
  status = !status;
}