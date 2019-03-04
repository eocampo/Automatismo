
var Blynk = require('blynk-library');
var AUTH = 'be10a8170271464d8b859af62e9b96ba';

var blynk = new Blynk.Blynk(AUTH, options = { connector : new Blynk.TcpClient( options = { addr:"138.128.124.188", port:8080 } )
});

var v1 = new blynk.VirtualPin(1);
var v9 = new blynk.VirtualPin(9);
var v8 = new blynk.VirtualPin(8);


v1.on('write', function(param) {
  console.log('V1:', param[0]);
});

v9.on('read', function() {
  v9.write(new Date().getSeconds());
});

var term = new blynk.WidgetTerminal(3);
term.on('write', function(data) {
  term.write('You wrote:' + data + '\n');
  console.log(data);
  blynk.notify("HAHA! " + data);
});
