// A system module containing protocol access constructs
// Module objects referenced with "http:" in code
import ballerina/http;
import ballerina/io;
import ballerina/mime;

public function main() {

    //api call 1
    io:println("Calling api 1...");
    http:Client clientEP = new("https://api.chucknorris.io");
    var resp = clientEP->get("/jokes/random");
    http:Request req = new;
    string text = "";
    string url = "";

    if (resp is http:Response) {
        var payload = resp.getJsonPayload();
        if (payload is json) {
           text += "\tChuck-noris joke\n";
           text = text + payload.value.toString();
           io:println(payload.value.toString());
        }
    } else {

        io:println(resp.detail());
    }

    //api call 2
    io:println("\nCalling api 2...");
    clientEP = new("https://icanhazdadjoke.com/");
    req = new;
    req.setHeader("Accept","text/plain");
    resp = clientEP->get("", req);

    if (resp is http:Response) {
        var payload = resp.getTextPayload();
        if (payload is string) {
            json joke = payload;
            text += "\n\n\tDad joke\n";
            text = text + joke.toString();
            io:println(joke);
        }
    } else {
        io:println(resp.detail());
    }

    //api call 3
    io:println("\nCalling api 3...");
    clientEP = new("https://api.kanye.rest");
    resp = clientEP->get("");

    if (resp is http:Response) {
        var payload = resp.getJsonPayload();
        if (payload is json) {
           text += "\n\n\tKanye west quote\n";
           text += payload.quote.toString();
           io:println(payload.quote);
        }
    } else {
        io:println(resp.detail());
    }

    //api call 4
    io:println("\nCalling api 4...");
    clientEP = new("https://api.tronalddump.io/search/quote?");
    resp = clientEP->get("query=obama");

    if (resp is http:Response) {
        var payload = resp.getJsonPayload();
        if (payload is json) {
            json|error quote = payload._embedded.quotes;

            text += "\n\n\tThings Donald Trump has said about Obama\n";
            
            if (quote is json[]) {
            foreach int i in 0 ... quote.length()-1 {
                io:println( quote[i].value.toString());
                text += quote[i].value.toString() + "\n";  
                }
            }
        }
    } else {
        io:println(resp.detail());
    }

    //api call 5
    io:println("\nCalling api 5...");
    clientEP = new("https://www.foaas.com");
    req = new;
    req.setHeader("Accept","text/plain");
    resp = clientEP->get("/awesome/Giga", req);

    if (resp is http:Response) {
        var payload = resp.getTextPayload();
        if (payload is json) {
            json foaas = payload;
            text += "\n\n\tFoaas\n";
            text += foaas.toString();
            io:println(foaas);
            
        }
    } else {
        io:println(resp.detail());
    }

    io:println();
    io:println(text);

    //pastebin api call
    io:println("\nPasting to pastebin...");
    var api_dev_key 			= "xxxx";
    var api_paste_code 		    = text;
    var api_paste_private 		= "2"; 
    var api_paste_name			= "Bal";
    var api_paste_expire_date 	= "1D";
    var api_paste_format 		= "text";

    clientEP = new("https://pastebin.com");
    req = new;
    req.setTextPayload("api_option=paste&api_user_key= &api_paste_private="+api_paste_private+"&api_paste_name="+api_paste_name+"&api_paste_expire_date="+api_paste_expire_date+"&api_paste_format="+api_paste_format+"&api_dev_key="+api_dev_key+"&api_paste_code="+api_paste_code);                  
                        
    req.setHeader("Content-type","application/x-www-form-urlencoded");
    req.setHeader("accept-encoding","gzip, deflate");
    req.setHeader("cache-control","no-cache");

    resp = clientEP->post("/api/api_post.php", req);

    if (resp is http:Response) {
        var payload = resp.getTextPayload();
        url = payload.toString();
        
    } else {
        io:println(resp.detail());
    }

    //cleanuri api call
    io:println("\nshortening url...");

    clientEP = new("https://cleanuri.com");
    req = new;
    req.setTextPayload("url="+url);                  
                        
    req.setHeader("Content-type","application/x-www-form-urlencoded");

    resp = clientEP->post("/api/v1/shorten", req);

    if (resp is http:Response) {
        var payload = resp.getJsonPayload();
        if (payload is json) {
            json shorten = payload;
            io:println(shorten.result_url);
            
        }
    } else {
        io:println(resp.detail());
    }
}
