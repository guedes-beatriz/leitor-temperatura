
#ifndef AUTOMATICO_H
#define AUTOMATICO_H

#include <Arduino.h>

const char pagina_automatico[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Modo Automático</title>

    <!-- Icones Lucide -->
    <script src="https://unpkg.com/lucide@latest/dist/umd/lucide.js"></script>

    <!-- Fonte Sora e CSS -->
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Sora:wght@100..800&display=swap');

        body {
            background-color: #D0D0D0;
            min-height: 100vh;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            margin: 0;
            padding: 20px;
            box-sizing: border-box;
        }

        .monitoramento {
            font-family: 'Sora', sans-serif;
            font-weight: 800;
            font-size: 30px;
            text-align: center;
            position: relative;
            top: -22px;
        }

        /* IDENTIFICACAO DO MODO AUTOMATICO */
        .modo-automatico {
            position: relative;
            top: -40px;
            font-family: 'Sora', sans-serif;
            font-weight: 700;
            font-size: 20px;
            display: flex;
            align-items: center;
            gap: 6px;
            width: fit-content;
            background-color: #B7D8F5;
            color: #070000;
            padding: 12px 6px;
            border-radius: 12px;
            text-align: center;
            margin: 0 auto;
            border: 1px solid #15518A;
        }

        .modo-automatico svg {
            width: 20px !important;
            height: 20px !important;
        }

        /* AVISO */
        .aviso-automatico {
            font-family: 'Sora', sans-serif;
            color: #15518A;
            font-size: 16px;
            font-weight: 600;
            text-align: center;
            margin: 0 0 25px;
        }

        /* CARDS DE TEMPERATURA E UMIDADE */
        .cards-meio {
            display: flex;
            flex-direction: row;
            justify-content: center;
            align-items: stretch;
            gap: 20px;
            flex-wrap: wrap;
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

        .meio-temperatura svg,
        .meio-umidade svg {
            width: 100% !important;
            height: 20px !important;
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
            font-family: 'Sora', sans-serif;
            font-weight: 400;
            font-size: 25px;
            align-self: flex-start;
            margin: 35px 0 20px 40px;
        }

        /* CARDS DOS MODOS */
        .card-fim {
            display: flex;
            flex-direction: column;
            align-items: flex-start;
            gap: 15px;
            align-self: flex-start;
            margin-left: 40px;
            max-width: calc(100% - 40px);
        }

        .fim-ligado,
        .fim-automatico,
        .fim-desligado {
            display: flex;
            align-items: center;
            gap: 12px;
            width: 600px;
            max-width: 100%;
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

        .fim-automatico {
            background-color: #B7D8F5;
            border-color: #15518A;
        }

        .fim-ligado a,
        .fim-automatico a,
        .fim-desligado a {
            color: inherit;
            text-decoration: none;
        }

        @media (max-width: 700px) {
            .monitoramento {
                font-size: 24px;
            }

            .troca-operacao,
            .card-fim {
                align-self: center;
                margin-left: 0;
            }

            .fim-ligado,
            .fim-automatico,
            .fim-desligado {
                width: 100%;
            }
        }
    </style>
</head>

<body>
    <h1 class="monitoramento">Monitoramento do Ambiente</h1>

    <div class="modo-automatico">
        <i data-lucide="refresh-cw"></i>
        AUTOMÁTICO
    </div>

    <p class="aviso-automatico">
        Monitoramento automático ativo.
    </p>

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
    <div class="alerta" style="display:none; background:#ffcccc; color:#900; padding:10px; margin-top:15px; border-radius:8px; text-align:center; font-weight:600;">Temperatura alta! Buzzer ativado.</div>

    <h2 class="troca-operacao">Trocar modo de operação</h2>

    <div class="card-fim">
        <div class="fim-ligado" onclick="window.location.href='/ligado'">
            <i data-lucide="power"></i>
            LIGADO
        </div>

        <div class="fim-desligado" onclick="window.location.href='/desligado'">
            <i data-lucide="power-off"></i>
            DESLIGADO
        </div>
    </div>

    <script>
        lucide.createIcons();

        function atualizarLeituras() {
            fetch('/dados')
                .then(resposta => resposta.json())
                .then(dados => {
                    document.querySelector('.valor-temperatura').innerText = dados.temperatura + "°C";
                    document.querySelector('.valor-umidade').innerText = dados.umidade + "%";
                    const alerta = document.querySelector('.alerta');
                    if (dados.temperatura > 30) {
                        alerta.style.display = 'block';
                    } else if (dados.temperatura <= 28) {
                        alerta.style.display = 'none';
                    }
                })
                .catch(erro => console.log("Erro:", erro));
        }

        setInterval(atualizarLeituras, 2000);
        atualizarLeituras();
    </script>
</body>
</html>
)rawliteral";

#endif
