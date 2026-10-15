#ifndef DESLIGADO_H
#define DESLIGADO_H

#include <Arduino.h>

const char pagina_desligado[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Modo Desligado</title>

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

        /* IDENTIFICACAO DO MODO DESLIGADO */
        .modo-desligado {
            position: relative;
            top: -40px;
            font-family: 'Sora', sans-serif;
            font-weight: 700;
            font-size: 20px;
            display: flex;
            align-items: center;
            gap: 6px;
            width: fit-content;
            background-color: #F5B5B5;
            color: #070000;
            padding: 12px 6px;
            border-radius: 12px;
            text-align: center;
            margin: 0 auto;
            border: 1px solid #9C0000;
        }

        .modo-desligado i {
            display: flex;
            align-items: center;
            justify-content: center;
        }

        .modo-desligado svg {
            width: 20px !important;
            height: 20px !important;
            flex-shrink: 0;
            display: block;
            transform: translateY(-1px);
        }

        /* AVISO DE DESLIGADO */
        .aviso-desligado
        {
            display: flex;
            font-family: 'Sora', sans-serif;
            color:#ff0000
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

    <div class="modo-desligado">
        <i data-lucide="power-off"></i>
        DESLIGADO
    </div>

    <p class="aviso-desligado">
        Sensor desligado. Não há medições sendo realizadas.
    </p>

    <h2 class="troca-operacao">Trocar modo de operação</h2>

    <div class="card-fim">
        <div class="fim-ligado">
            <i data-lucide="power"></i>
            LIGADO
        </div>

        <div class="fim-automatico">
            <i data-lucide="refresh-cw"></i>
            AUTOMÁTICO
        </div>
    </div>

    <script>
        lucide.createIcons();
    </script>
</body>
</html>
)rawliteral";

#endif
