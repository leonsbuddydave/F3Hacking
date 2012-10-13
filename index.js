var http = require("http");
var sys = require("sys");
var exec = require("child_process").exec;
var url = require("url");
var child;

process.on('uncaughtException', function(error)
{
	console.log(error.stack);
});

var server = http.createServer(function(request, response)
{
	var url_parts = url.parse(request.url, true);
	var query = url_parts.query;
	child = exec("./getwords " + query.length + " " + query.count + " 40", function(error, stdout, stderr)
	{
		if (stderr != "")
			console.log("Error:" + stderr);
		
		console.log(stdout);
		response.writeHead(200, { "Content-Type": "text/plain"});
		
		var callback = query.callback + "('" + stdout + "')";
		
		response.end(callback);
	});
}).listen(8888);

console.log("Server started.");