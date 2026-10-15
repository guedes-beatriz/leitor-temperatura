#ifndef INDEX_H
#define INDEX_H

#include <Arduino.h>

const char pagina_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Painel de Controle</title>

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

        h1 {
            font-family: 'Sora', sans-serif;
            font-weight: 800;
            font-size: 50px;
            position: relative;
            top: -30px;
        }

        .sub-texto {
            font-family: 'Sora', sans-serif;
            font-weight: 300;
            position: relative;
            top: -70px;
        }

        .card {
            background-color: white;
            border-radius: 20px;
            height: 110px;
            padding: 10px;
            box-sizing: border-box;
            margin-bottom: 25px;
            border: 1px solid #BDBDBD;
            width: 600px;
            max-width: 90%;
            cursor: pointer;
            transition: 0.3s;
        }

        .card-topo {
            display: flex;
            justify-content: flex-start;
            gap: 10px;
            margin: 0;
        }

        .ligado,
        .automatico,
        .desligado {
            font-family: 'Sora', sans-serif;
            font-size: 25px;
            position: relative;
            top: -22px;
        }

        .descricao-card {
            font-family: 'Sora', sans-serif;
            text-align: left;
            margin: 0;
            position: relative;
            top: -30px;
        }

        .card:hover {
            border-color: #28a745;
            box-shadow: 0 0 30px #28a745;
        }
    </style>
</head>

<body>
    <h1>Painel de Controle</h1>

    <h2 class="sub-texto">Selecione o modo de funcionamento</h2>

    <!-- CARD LIGADO -->
    <div class="card" onclick="window.location.href='/ligado'">
        <div class="card-topo">
            <i data-lucide="power"></i>
            <h2 class="ligado">LIGADO</h2>
        </div>

        <p class="descricao-card">
            Sistema pronto para tomar decisões
            quando solicitado.
        </p>
    </div>

    <!-- CARD AUTOMÁTICO -->
    <div class="card" onclick="window.location.href='/automatico'">
        <div class="card-topo">
            <i data-lucide="refresh-cw"></i>
            <h2 class="automatico">AUTOMÁTICO</h2>
        </div>

        <p class="descricao-card">
            Realiza medições e toma decisões automaticamente.
        </p>
    </div>

    <!-- CARD DESLIGADO -->
    <div class="card" onclick="window.location.href='/desligado'">
        <div class="card-topo">
            <i data-lucide="power-off"></i>
            <h2 class="desligado">DESLIGADO</h2>
        </div>

        <p class="descricao-card">
            Sensores desligados.
        </p>
    </div>

    <script>
        lucide.createIcons();
    </script>
</body>
</html>
)rawliteral";

#endif

