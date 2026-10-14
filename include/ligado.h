
#ifndef LIGADO_H
#define LIGADO_H

#include <Arduino.h>

const char pagina_ligado[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Modo Ligado</title>

    <!-- Icones Lucide -->
    <script src="https://unpkg.com/lucide@latest/dist/umd/lucide.js"></script>

    <!-- Fonte Sora e CSS -->
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Sora:wght@100..800&display=swap');

        /* PAGINA DE MONITORAMENTO */
        body {
            background-color: #D0D0D0;
            min-height: 100vh;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
        }

        .monitoramento {
            font-family: 'Sora', sans-serif;
            font-weight: 800;
            font-size: 30px;
            position: relative;
            top: -22px;
        }

        /* IDENTIFICACAO DO MODO LIGADO */
        .modo-ligado {
            position: relative;
            top: -40px;
            font-family: 'Sora', sans-serif;
            font-weight: 700;
            font-size: 20px;
            display: flex;
            align-items: center;
            gap: 6px;
            width: fit-content;
            background-color: #A5D294;
            color: #070000;
            padding: 12px 6px;
            border-radius: 12px;
            text-align: center;
            margin: 0 auto;
            border: 1px solid #155800;
        }

        .modo-ligado i {
            display: flex;
            align-items: center;
            justify-content: center;
        }

        .modo-ligado svg {
            width: 20px !important;
            height: 20px !important;
            flex-shrink: 0;
            display: block;
            transform: translateY(-1px);
        }

        /* CARDS DE TEMPERATURA E UMIDADE */
        .cards-meio {
            display: flex;
            flex-direction: row;
            justify-content: center;
            align-items: stretch;
            gap: 20px;
        }

        .meio-temperatura,
        .meio-umidade {
            background-color: white;
            border: 1px solid #BDBDBD;
            border-radius: 20px;
            padding: 20px;
            width: 250px;
            height: 150px;
            box-sizing: border-box;
        }

        .meio-temperatura i,
        .meio-umidade i {
            display: flex;
            align-items: center;
            justify-content: center;
        }

        .meio-temperatura svg,
        .meio-umidade svg {
            width: 100% !important;
            height: 20px !important;
            flex-shrink: 0;
            display: block;
            transform: translateY(-1px);
            color: #666666;
            stroke: #666666;
        }

        .texto-temperatura,
        .texto-umidade {
            font-family: 'Sora', sans-serif;
            font-size: 80%;
            font-weight: 400;
            color: #666666;
            display: flex;
            margin-top: 2%;
            align-items: center;
            justify-content: center;
        }

        .valor-temperatura,
        .valor-umidade {
            font-family: 'Sora', sans-serif;
            font-size: 50px;
            font-weight: 700;
            color: #000000;
            display: flex;
            align-items: center;
            height: 80px;
            text-align: center;
            justify-content: center;
        }

        /* TROCA DE OPERACAO */
        .troca-operacao {
            display: flex;
            font-family: 'Sora', sans-serif;
            font-weight: 200;
            font-size: 30px;
            align-items: flex-start;
            gap: 15px;
            align-self: flex-start;
            margin-left: 40px;
        }

        /* CARDS DOS MODOS */
        .card-fim {
            display: flex;
            flex-direction: column;
            align-items: flex-start;
            gap: 15px;
            align-self: flex-start;
            margin-left: 40px;
        }

        .fim-ligado,
        .fim-automatico,
        .fim-desligado {
            display: flex;
            align-items: center;
            justify-content: flex-start;
            gap: 12px;
            width: 600px;
            padding: 20px;
            box-sizing: border-box;
            background-color: white;
            border: 1px solid #BDBDBD;
            border-radius: 15px;
            font-family: 'Sora', sans-serif;
            font-size: 16px;
            font-weight: 600;
            cursor: pointer;
        }


    </style>
</head>

<body>
    <h1 class="monitoramento">Monitoramento do Ambiente</h1>

    <div class="modo-ligado">
        <i data-lucide="power"></i>
        LIGADO
    </div>

    <div class="cards-meio">
        <div class="meio-temperatura">
            <i data-lucide="thermometer"></i>
            <span class="valor-temperatura">00°C</span>
            <span class="texto-temperatura">Temperatura</span>
        </div>

        <div class="meio-umidade">
            <i data-lucide="droplets"></i>
            <span class="valor-umidade">00%</span>
            <span class="texto-umidade">Umidade</span>
        </div>
    </div>

    <h2 class="troca-operacao">Trocar modo de operação</h2>

    <div class="card-fim">
        <div class="fim-automatico">
            <i data-lucide="refresh-cw"></i>
            AUTOMÁTICO
        </div>

        <div class="fim-desligado">
            <i data-lucide="power-off"></i>
            DESLIGADO
        </div>
    </div>

    <script>
        lucide.createIcons();
    </script>
</body>
</html>
)rawliteral";

#endif
