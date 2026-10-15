
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

    <!-- Ícones usados -->
    <script src="https://unpkg.com/lucide@latest/dist/umd/lucide.js"></script>

    <style>
        @import url('https://fonts.googleapis.com/css2?family=Sora:wght@100..800&display=swap');

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
            background-color: #B5F5C1;
            color: #070000;
            padding: 12px 6px;
            border-radius: 12px;
            text-align: center;
            margin: 0 auto;
            border: 1px solid #009C24;
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

        .cards-meio {
            display: flex;
            justify-content: center;
            gap: 20px;
            position: relative;
            top: -20px;
        }

        .meio-temperatura,
        .meio-umidade {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            background-color: white;
            border: 1px solid #BDBDBD;
            border-radius: 15px;
            width: 280px;
            height: 180px;
            gap: 10px;
            font-family: 'Sora', sans-serif;
        }

        .valor-temperatura,
        .valor-umidade {
            font-size: 32px;
            font-weight: 800;
        }

        .texto-temperatura,
        .texto-umidade {
            font-size: 16px;
            font-weight: 400;
        }

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
