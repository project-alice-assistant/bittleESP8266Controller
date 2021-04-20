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
        <button onclick="sendCmd('kbkL')" style="width: 50%;">Back Left</button>
        <button onclick="sendCmd('kbkR')" style="width: 50%;">Back Right</button>
        <button onclick="sendCmd('kbk')" style="width: 100%;">Back</button>
    </div>
    <h2 class="center">Mode</h2>
    <div class="card wide">
        <button onclick="sendCmd('g')">Gyro On/Off</button>
        <button onclick="sendCmd('c')">Calibration</button>
        <button onclick="sendCmd('kbalance')">Balanced</button>
    </div>
    <h2>Actions</h2>
    <div class="card wide">
        <button onclick="sendCmd('ksit')">Sit</button>
        <button onclick="sendCmd('kck')">Check</button>
        <button onclick="sendCmd('kbuttUp')">Buttup</button>
        <button onclick="sendCmd('khi')">Hello</button>
        <button onclick="sendCmd('kstr')">Stretch</button>
        <button onclick="sendCmd('kpee')">Pee</button>
        <button onclick="sendCmd('kpu')">Push ups</button>
        <button onclick="sendCmd('kvt')">Stepping</button>
        <button onclick="sendCmd('lu')">Look up</button>
        <button onclick="sendCmd('kbf')">Backflip</button>
        <button onclick="sendCmd('kbdF')">Jumps</button>
        <button onclick="sendCmd('krc')">Recover</button>
        <button class="redBG" style="width: 100%" onclick="sendCmd('d')">STOP</button>
    </div>
    <h2 class="center">Custom commands</h2>
    <div class="card">
        <input id="input" style="width: 60%" name="name" type="text" placeholder="input command"><button  style="width: 39%" onclick="sendInputCmd()">Send</button>
    </div>
    <div class="card">
        <div class="console" id="serialOutput">Serial output</div>
    </div>
    <script type="text/javascript">
        document.addEventListener('DOMContentLoaded', function() {
            setInterval(function() {
                fetch('/getOutput', {
                    method: "POST"
                }).then(response => {
                    return response.text();
                }).then(text => {
                    if (!text) {
                      return;
                    }
                    document.getElementById('serialOutput').innerHTML = `${text}<br/>${document.getElementById('serialOutput').innerHTML}`;
                });
            }, 500);
        });

        function movement(direction) {
            const movementType = document.querySelector('input[name="movementType"]:checked').value;
            sendCmd(`k${movementType}${direction}`);
        }

        function sendInputCmd() {
            const cmd = document.getElementById('input').value;
            sendCmd(cmd);
        }
    </script>
</div>
)=====";

#endif
