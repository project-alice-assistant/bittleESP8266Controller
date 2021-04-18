#ifndef COMMONS_H
#define COMMONS_H

const char head[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <title>OpenCAT Nybble Web Control</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=0.5, maximum-scale=0.8, user-scalable=yes"/>
    <style>

        :root {
            --main: #181818;
            --secondary: #212121;
            --hover: #3D3D3D;
            --active: #2D2D2D;
            --text: #e8e8e8;
            --secondaryText: #AAAAAA;
        }

        .header {
            background-color: var(--secondary);
            text-align: center;
            padding: 10px;
            box-sizing: border-box;
        }

        body, html {
            font-family: "Segoe UI", sans-serif;
            background-color: var(--main);
            color: var(--text);
            padding: 0;
            margin: 0 auto;
        }

        ul {
            list-style-type: none;
            margin: 0;
            padding: 0;
            overflow: hidden;
            background-color: var(--secondary);
        }

        li {
            float: left;
            margin-right: 15px;
        }

        a {
            color: var(--secondaryText);
            text-decoration: none;
        }

        li a {
            display: block;
            text-align: center;
            padding: 14px;
            text-transform: uppercase;
            font-weight: bold;
        }

        li a:hover:not(.active) {
            background-color: var(--hover);
        }

        li a.active {
            color: var(--text);
            background-color: var(--active);
        }

        h1 {
            color: var(--text);
            text-transform: uppercase;
            font-size: 2em;
            font-weight: bold;
            text-align: center;
        }

        h2 {
            color: var(--text);
            text-align: center;
            font-size: 1.5em;
        }

        h3 {
            color: var(--text);
            text-align: left;
            font-size: 1.25em;
        }

        .card {
            display: flex;
            flex-wrap: wrap;
            width: 50%;
            background-color: var(--secondary);
            margin: 0 auto 25px;
            justify-content: center;
            min-height: 50px;
        }

        .wide {
            width: 80%;
        }

        button, input[type="submit"], input[type="text"] {
            border-radius: 0;
            background-color: var(--secondary);
            border: 1px solid var(--main);
            color: var(--text);
            text-align: center;
            text-decoration: none;
            font-size: 1.5em;
            height: 75px;
            cursor: pointer;
            width: 33.333%;
            outline: none;
        }

        button:hover {
            background-color: var(--hover);
        }

        .footer {
            width: 100%;
            background-color: var(--secondary);
            border-top: 2px solid var(--main);
            text-align: center;
            position: fixed;
            bottom: 0;
            height: 45px;
            font-size: 15px;
            padding: 10px;
        }

        .center {
            text-align: center;
        }

        .content {
            margin: 50px 50px 150px;
        }

        .explanation {
            width: 50%;
            margin: 15px auto;
            background-color: var(--active);
            border: 1px solid var(--secondary);
            padding: 15px;
            box-sizing: border-box;
        }

        label {
            font-size: 1.2em;
            color: var(--secondaryText);
            text-transform: uppercase;
            margin-right: 20px;
            cursor: pointer;
        }

        .radio {
            display: flex;
            height: 50px;
            align-content: center;
            justify-content: center;
            align-items: center;
            justify-items: center;
            flex: 1;
        }

        .redBG {
            background-color: orangered;
        }

        button.redBG:hover {
            background-color: red;
        }

    </style>
    <script type="text/javascript">
        document.addEventListener('DOMContentLoaded', function () {
            let title = "%TITLE%";
            document.getElementById(title).classList.add('active')
        });
    </script>
</head>

<body>
<div class="header">
    <ul>
        <li><a id="Home" href="/">Home</a></li>
        <li><a id="Actions" href="/actionpage">Actions</a></li>
        <li><a id="Calibration" href="/calibrationpage">Calibration</a></li>
    </ul>
    <h1 id="pageTitle">%TITLE%</h1>
</div>
)=====";

const char foot[] PROGMEM = R"=====(
<div class="footer">
    <p><a href="www.petoi.com" target="_blank">www.petoi.com</a> - Web interface by Psycho <a href="https://www.projectalice.io" target="_blank">Project Alice</a></p>
</div>
</body>
</html>
)=====";

#endif
