# Interface Web do Leitor de Temperatura

Documentação da interface web do projeto Leitor de Temperatura e Umidade (ESP32). A interface é servida pela própria ESP32 e permite escolher o modo de operação e acompanhar a temperatura e a umidade em tempo real, pelo navegador do celular ou do computador.


## Visão geral

- A interface é feita com **HTML, CSS e JavaScript puros**, sem framework e sem etapa de build.
- Cada tela é um arquivo `.h` na pasta `include/`, com a página inteira guardada como texto na memória da ESP32 (`PROGMEM`). O `main.cpp` entrega a página certa quando o navegador pede uma rota.
- O layout é centralizado, com fundo cinza claro e cartões brancos, e se adapta à largura da tela, por isso funciona no celular.

## Como acessar

1. Ligue a ESP32 e aguarde a conexão com o Wi-Fi.
2. Pegue o IP no Monitor Serial (115200). Ele aparece na mensagem `Conectado! IP da ESP32: ...`.
3. Com o celular ou computador **na mesma rede Wi-Fi** da ESP32, abra no navegador:

```
http://<IP_DA_ESP32>
```

Exemplo: `http://192.168.0.50`. A página inicial (Painel de Controle) será exibida.

## Telas

A interface tem quatro telas.

### 1. Painel de Controle (`/`)

Tela inicial, com o título **Painel de Controle** e o subtítulo "Selecione o modo de funcionamento". Mostra três cartões clicáveis:

| Cartão | Descrição exibida |
| --- | --- |
| **LIGADO** | Sistema pronto para tomar decisões quando solicitado. |
| **AUTOMÁTICO** | Realiza medições e toma decisões automaticamente. |
| **DESLIGADO** | Sensores desligados. |

Ao passar o mouse sobre um cartão, a borda e o brilho ficam verdes. Ao clicar, o navegador abre a tela do modo escolhido.

### 2. Modo Ligado (`/ligado`)

Título **Monitoramento do Ambiente**, com o selo **LIGADO**. Mostra:

- cartão de **Temperatura** (em °C);
- cartão de **Umidade** (em %);
- aviso de temperatura alta (aparece só quando necessário, com atalhos "Ir para Automático" e "Ir para Desligado");
- seção **Trocar modo de operação**, com os botões **AUTOMÁTICO** e **DESLIGADO**.

### 3. Modo Automático (`/automatico`)

Título **Monitoramento do Ambiente**, com o selo **AUTOMÁTICO** e o texto "Monitoramento automático ativo.". Mostra:

- cartões de **Temperatura** e **Umidade**;
- aviso "Temperatura alta! Buzzer ativado." quando necessário;
- seção **Trocar modo de operação**, com os botões **LIGADO** e **DESLIGADO**.

### 4. Modo Desligado (`/desligado`)

Título **Monitoramento do Ambiente**, com o selo **DESLIGADO** e o texto "Sensor desligado. Não há medições sendo realizadas.". Não mostra temperatura nem umidade e não consulta a ESP32. Tem a seção **Trocar modo de operação**, com os botões **LIGADO** e **AUTOMÁTICO**.

