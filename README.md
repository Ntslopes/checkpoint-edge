# checkpoint-edge

# 📦 Projeto: Sensor de Luminosidade com Arduino (LDR + LEDs + Buzzer)

## 🧠 Descrição

Este projeto utiliza um sensor de luminosidade (LDR) conectado a um Arduino para monitorar a intensidade da luz ambiente e reagir de forma visual e sonora.

O sistema classifica a luminosidade em três níveis:

* **Baixa luminosidade** → LED verde acende
* **Média luminosidade** → LED amarelo acende
* **Alta luminosidade** → LED vermelho acende + buzzer dispara

Quando a luz está muito intensa, o buzzer emite um som por alguns segundos como alerta.

---

## ⚙️ Componentes Utilizados

* 1x Arduino Uno (ou compatível)
* 1x LDR (fotoresistor)
* 3x LEDs (verde, amarelo, vermelho)
* 3x Resistores (220Ω para os LEDs)
* 1x Resistor (10kΩ para o LDR – divisor de tensão)
* 1x Buzzer
* Jumpers (fios)
* 1x Protoboard

---

## 🔌 Funcionamento

1. O LDR mede a luminosidade do ambiente.
2. O valor analógico é lido pelo pino A5 do Arduino.
3. Esse valor é ajustado com a função `map()` para melhorar a precisão.
4. Dependendo do valor obtido:

   * **0 – 299** → LED verde (baixa luz)
   * **300 – 600** → LED amarelo (luz média)
   * **601 – 1023** → LED vermelho + buzzer (luz alta)

---

## 🧪 Como Reproduzir o Projeto

### 1. Montagem do Circuito

* Conecte o LDR em um divisor de tensão com um resistor de 10kΩ:

  * Um lado no **5V**
  * Outro lado no **GND**
  * Meio (entre LDR e resistor) → **A5**

* LEDs:

  * Verde → pino 8
  * Amarelo → pino 9
  * Vermelho → pino 10
    (todos com resistor de 220Ω)

* Buzzer:

  * Positivo → pino digital
  * Negativo → GND

---

### 2. Upload do Código

1. Abra a IDE do Arduino
2. Cole o código fornecido
3. Selecione a placa correta (Arduino Uno)
4. Envie para o Arduino

---

### 3. Teste

* Cubra o LDR → LED verde deve acender
* Luz ambiente → LED amarelo
* Luz forte (lanterna/celular) → LED vermelho + buzzer

---

## 💡 Aplicações

* Monitoramento de luz ambiente
* Adega inteligente (controle de luminosidade)
* Sistemas de alerta
* Automação residencial

---

## 👥 Participantes

* Esther dos Santos de Almeida Tozzo - 570860
* Felipe de Oliveira Zimmermann - 570863
* Izabela Pordeus de Almeida - 570316
* João Victor Santos Souza - 569949
* Leonardo Henrique Basseti - 574039
* Matheus Lopes Lima - 571458

---
