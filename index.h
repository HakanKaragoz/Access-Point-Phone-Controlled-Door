const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>

<html>
<body>
<style>
.title1
{
  font-family:Georgia;
  font-size:60px;
  position: relative;
  top: 200px;
  left: calc(50% - 95px);
}
.title2
{
  font-family:Georgia;
  font-size:60px;
  position: relative;
  top: 150px;
  left: calc(50% - 115px);
}
.btn
{
  width:150px;
  height:150px;
  font-weight:bold;
  font-family:Comic;
  font-size:37px;
  margin-bottom: 20px;
  position: relative;
  left: calc(50% - 70px);
  box-sizing: border-box;
  border-radius: 750px;
  top: 160px;
}

.button1{
    color:#000000;
    background-color:#f1bfbc;
}

.button1:hover{
    background-color: #d50c0c;
    color: white;
}
.command
{
  font-family:Georgia ;
  font-size:40px;
  position: relative;
  top: 180px;
  left: calc(50% - 65px);
}
.information
{
  font-family:Georgia ;
  font-size:40px;
  position: relative;
  top: 195px;
  left: calc(50% - 205px);
}
.link
{
  font-family:Arial;
  font-size:40px;
  position: relative;
  top: 195px;
  left: calc(50% - 225px);
}
.loginbox{
  width: 620px;
  height: 1050px;
  background: #ff5a0a;
  color: #fff;
  top: 705px;
  left: 50%;
  position: absolute;
  box-sizing: border-box;
  transform: translate(-50%,-50%);
  border-radius: 40px;
  padding: 70px 30px;
}


body
{
  margin:0;
  padding: 0;
  background: #000000;
  background-size: cover;
  background-position: center;
  font-family: sans-serif;

}
</style>
<div class="loginbox">
  </div>

<div id="demo">

<h1 class="title1">TelkAS</h1>
<h2 class="title2">KEPENK</h2>
  <button class="btn button1" onclick="sendData(1)">Ac</button><br/>
  <button class="btn button1" onclick="sendData(2)">Durdur</button><br/>
  <button class="btn button1" onclick="sendData(0)">Kapat</button><BR>

</div>

<div class="command">
  <span id="LEDState">Bekliyor</span> <br>
</div>
<div class="information">AS DEMIR OTOMASYON</div>
<div class="link">
  <a href="http://kepenkmerkezi.com/"target="_blank">www.kepenkmerkezi.com</a>
</div>

<script>
function sendData(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED?LEDstate="+led, true);
  xhttp.send();
}

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 2000); //2000mSeconds update rate

</script>
</body>
</html>

)=====";
