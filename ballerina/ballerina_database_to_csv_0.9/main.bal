import ballerina/io;
import ballerina/mysql;
import ballerina/sql;
import ballerina/log;

//add your database querry here
const string DATABASE_QUERRY = "";
//add your host here
const string DATABASE_HOST = "";
//add you Database here
const string DATABASE = "";
// add user here
const string DATABASE_USER = "";
//add database password here
const string DATABASE_PASSWORD = "";

//add your path here

string path = "";
mysql:Client testDB = new({
        host: DATABASE_HOST,
        port: 3306,
        name: DATABASE,
        username: DATABASE_USER,
        password: DATABASE_PASSWORD,
        dbOptions: { useSSL: false }
    });

function getFields(json rec) returns (string[], string[]) {
    int count = 0;
    string [] headers = [];
    string [] fields = [];
    headers = rec.getKeys();
    foreach var field in headers {
        fields[count] = rec[field].toString();
        count = count + 1;
    }
    return (headers, fields);
}

function writeCsv(json content, string path) returns error? {
    io:WritableCSVChannel csvch = io:openWritableCsvFile(path);
    int recIndex = 0;
    int recLen = content.length();
    while (recIndex < recLen) {
        (string [], string []) result = getFields(content[recIndex]);
        var (headers, fields) = result;
        if (recIndex == 0) {

            check csvch.write(headers);
        }
        check csvch.write(fields);
        recIndex = recIndex + 1;
    }
    return;
}



public function main() {
  

    var custDynamics= testDB -> select(DATABASE_QUERRY,());

    
    

    if (custDynamics is table<record {}>) {

        io:println("\nConvert the table into json");
        var jsonConversionRet = json.convert(custDynamics);
        if (jsonConversionRet is json) {
            json employee = jsonConversionRet;
            var result = writeCsv(employee, path);
            if (result is error) {
                log:printError("Error occurred while writing csv record :",
                err = result);
            } else {
                int l = employee.length();
                int i = 0;
                while(i <l){
                    io:println(employee[i].Name);
                    i = i + 1;
                }
                io:println("json record successfully transformed to a csv, file could" +" be found in " + path);
            } 
        }
    }else{
        io:println(custDynamics);
    }
}