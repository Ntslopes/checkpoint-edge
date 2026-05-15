# checkpoint-edge
# 🌿 Sistema de Monitoramento Ambiental com Arduino

Sistema embarcado para monitoramento de **luminosidade**, **temperatura** e **umidade** em tempo real, com alertas visuais (LEDs), sonoros (buzzer) e exibição em display LCD I2C.

---

## 📦 Componentes Necessários

| Componente | Quantidade | Pino |
|---|---|---|
| Arduino Uno (ou compatível) | 1 | — |
| LDR (sensor de luz) | 1 | A0 |
| TMP36 (sensor de temperatura) | 1 | A1 |
| Potenciômetro (simula umidade) | 1 | A2 |
| LED Verde | 1 | D8 |
| LED Amarelo | 1 | D9 |
| LED Vermelho | 1 | D10 |
| Buzzer | 1 | D7 |
| Display LCD 16x2 (I2C, 0x27) | 1 | SDA/SCL |

---

## 📚 Bibliotecas Utilizadas

- [`Wire.h`](https://www.arduino.cc/en/reference/wire) — comunicação I2C (nativa do Arduino)
- [`LiquidCrystal_I2C`](https://github.com/johnrickman/LiquidCrystal_I2C) — controle do display LCD via I2C

Para instalar a biblioteca do LCD: **Arduino IDE → Gerenciar Bibliotecas → buscar "LiquidCrystal I2C"**

---

## ⚙️ Como Funciona

O sistema realiza leituras contínuas dos três sensores, calcula a **média de 5 amostras** e exibe os resultados em sequência no LCD. LEDs e buzzer são acionados conforme os limites definidos.

### 💡 Luminosidade (LDR — A0)

| Faixa (valor mapeado) | Status | LED | Buzzer |
|---|---|---|---|
| < 300 | Ambiente Escuro | 🟢 Verde | OFF |
| 300 – 800 | Meia Luz | 🟡 Amarelo | OFF |
| > 800 | Muito Claro | 🔴 Vermelho | ON |

> O valor bruto do LDR é remapeado de `[207, 1012]` para `[0, 1023]` para calibração do sensor.

---

### 🌡️ Temperatura (TMP36 — A1)

A tensão lida é convertida em temperatura pela fórmula:

```
Voltagem = leitura * 5.0 / 1024.0
Temperatura (°C) = (Voltagem - 0.5) * 100
```

| Faixa (°C) | Status | LED | Buzzer |
|---|---|---|---|
| 10 – 15 | Temperatura OK | — | OFF |
| > 15 | Temperatura Alta | 🟡 Amarelo | ON |
| < 10 | Temperatura Baixa | 🟡 Amarelo | ON |

---

### 💧 Umidade (Potenciômetro — A2)

O potenciômetro simula um sensor de umidade, com valor mapeado de `[0, 1023]` para `[0, 100]%`.

| Faixa (%) | Status | LED | Buzzer |
|---|---|---|---|
| 50 – 70 | Umidade OK | — | OFF |
| > 70 | Umidade Alta | 🔴 Vermelho | ON |
| < 50 | Umidade Baixa | 🔴 Vermelho | ON |

---

## 🖥️ Saída Serial

Os dados são enviados ao monitor serial (9600 baud) no seguinte formato:

```
Luz: 512 | Temp: 23.5 | Umidade: 65%
```

---

## 🔁 Fluxo do Loop Principal

```
1. Coleta 5 amostras de cada sensor (intervalo de 100ms entre cada)
2. Calcula a média das leituras
3. Envia dados ao Serial Monitor
4. Exibe status de Luminosidade no LCD por 2 segundos
5. Exibe status de Temperatura no LCD por 2 segundos
6. Exibe status de Umidade no LCD por 1 segundo
7. Reinicia o ciclo
```

---

## 🚀 Como Usar

1. Monte o circuito conforme a tabela de pinos acima.
2. Instale a biblioteca `LiquidCrystal_I2C` na Arduino IDE.
3. Carregue o código no Arduino.
4. Abra o **Monitor Serial** (9600 baud) para acompanhar as leituras.
5. O LCD exibirá **"Sistema Iniciado"** por 2 segundos e então começará o monitoramento.

---

## 📝 Observações

- O endereço I2C padrão do LCD é `0x27`. Caso o display não funcione, tente `0x3F`.
- O potenciômetro em A2 é uma simulação — em um sistema real, substitua por um sensor de umidade como o **DHT11** ou **DHT22**.
- Os limites de temperatura (10–15°C) são adequados para ambientes de armazenamento refrigerado (ex: adegas, câmaras frias). Ajuste conforme sua aplicação.

## 👥 Participantes

* Esther dos Santos de Almeida Tozzo - 570860
* Felipe de Oliveira Zimmermann - 570863
* Izabela Pordeus de Almeida - 570316
* João Victor Santos Souza - 569949
* Leonardo Henrique Basseti - 574039
* Matheus Lopes Lima - 571458

---
