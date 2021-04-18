#ifndef ACTIONPAGE_H
#define ACTIONPAGE_H

const char actionpage[] PROGMEM = R"=====(
<div class="content">
    <h2>Movements</h2>
    <div class="card">
        <div class="radio">
            <label for="walk">Walk</label> <input id="walk" name="movementType" type="radio" value="wk" checked>
        </div>
        <div class="radio">
            <label for="run">Run</label> <input id="run" name="movementType" type="radio" value="rn">
        </div>
        <div class="radio">
            <label for="trot">Trot</label> <input id="trot" name="movementType" type="radio" value="tr">
        </div>
        <div class="radio">
            <label for="crawl">Crawl</label> <input id="crawl" name="movementType" type="radio" value="cr">
        </div>
    </div>
    <div class="card">
        <button onclick="movement('F')" style="width: 100%;">Forward</button>
        <button onclick="movement('L')" style="width: 50%;">Forward Left</button>
        <button onclick="movement('R')" style="width: 50%;">Forward Right</button>
        <button onclick="location.href='/actionpage?cmd=kbkL'" style="width: 50%;">Back Left</button>
        <button onclick="location.href='/actionpage?cmd=kbkR'" style="width: 50%;">Back Right</button>
        <button onclick="location.href='/actionpage?cmd=kbk'" style="width: 100%;">Back</button>
    </div>
    <h2 class="center">Mode</h2>
    <div class="card wide">
        <button onclick="location.href='/actionpage?cmd=g'">Gyro On/Off</button>
        <button onclick="location.href='/actionpage?cmd=c'">Calibration</button>
        <button onclick="location.href='/actionpage?cmd=kbalance'">Balanced</button>
    </div>
    <h2>Actions</h2>
    <div class="card wide">
        <button onclick="location.href='/actionpage?cmd=ksit'">Sit</button>
        <button onclick="location.href='/actionpage?cmd=kck'">Check</button>
        <button onclick="location.href='/actionpage?cmd=kbuttUp'">Buttup</button>
        <button onclick="location.href='/actionpage?cmd=khi'">Hello</button>
        <button onclick="location.href='/actionpage?cmd=kstr'">Stretch</button>
        <button onclick="location.href='/actionpage?cmd=kpee'">Pee</button>
        <button onclick="location.href='/actionpage?cmd=kpu'">Push ups</button>
        <button onclick="location.href='/actionpage?cmd=kvt'">Stepping</button>
        <button onclick="location.href='/actionpage?cmd=lu'">Look up</button>
        <button onclick="location.href='/actionpage?cmd=kbf'">Backflip</button>
        <button onclick="location.href='/actionpage?cmd=kbdF'">Jumps</button>
        <button onclick="location.href='/actionpage?cmd=krc'">Recover</button>
        <button class="redBG" style="width: 100%" onclick="location.href='/actionpage?cmd=d'">STOP</button>
    </div>
    <h2 class="center">Custom commands</h2>
    <form action="/action" method="get">
        <div class="center" style="width: 100%; margin-top: 25px;">
            <input name="name" type="text" placeholder="input command"><input type="submit" value="Send"/>
        </div>
    </form>
    <script type="text/javascript">
        document.addEventListener('DOMContentLoaded', function() {
            let query = window.location.search;
            const urlParams = new URLSearchParams(query);
            if (urlParams.has('cmd')) {
                let cmd = urlParams.get('cmd');
                if (cmd.startsWith('kwk')) {
                    document.getElementById('walk').checked = true;
                } else if (cmd.startsWith('krn')) {
                    document.getElementById('run').checked = true;
                } else if (cmd.startsWith('kcr')) {
                    document.getElementById('crawl').checked = true;
                } else if (cmd.startsWith('ktr')) {
                    document.getElementById('trot').checked = true;
                }
            }
        });

        function movement(direction) {
            const movementType = document.querySelector('input[name="movementType"]:checked').value;
            window.location.href = `/actionpage?cmd=k${movementType}${direction}`;
        }
    </script>
</div>
)=====";

#endif
