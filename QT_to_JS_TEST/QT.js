//var LiveServer = require("/usr/local/lib/node_modules/live-server/live-server.js");
document.write("<script language=javascript src='/usr/local/lib/node_modules/live-server/index.js'></script>");
document.write("<script language=javascript src='/usr/local/lib/node_modules/live-server/live-server.js'></script>");
 function startLiveServer()
 {
    var LiveServer = require('live-server');
    var params = {
        port: 8080, // Set the server port. Defaults to 8080.
        host: "127.127.0.1", // Set the address to bind to. Defaults to 0.0.0.0 or process.env.IP.
        root: "", // Set root directory that's being served. Defaults to cwd.
        open: false, // When false, it won't load your browser by default.
        ignore: '', // comma-separated string for paths to ignore
        file: "index.html", // When set, serve this file (server root relative) for every 404 (useful for single-page applications)
        wait: 1000, // Waits for all changes, before reloading. Defaults to 0 sec.
        mount: [['/components', './node_modules']], // Mount a directory to a route.
        logLevel: 2, // 0 = errors only, 1 = some, 2 = lots
        middleware: [function(req, res, next) { next(); }] // Takes an array of Connect-compatible middleware that are injected into the server middleware stack
    };
    LiveServer.start(params);
     //escape("122");
 }

 function stopLiveServer()
 {
     var LiveServer = require('/usr/local/lib/node_modules/live-server/index.js');
    LiveServer.shutdown();
 }

function trans2wCal(var1,var2)
{
    return var1+var2;
}

function trans3wCal(var1,var2)
{    return var1*var2+5;
}
