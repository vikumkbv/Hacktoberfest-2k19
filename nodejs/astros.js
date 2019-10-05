const http = require('http');
const fs = require('fs');

// API link
const url = 'http://api.open-notify.org/astros.json';

// Request
const req = http.get(url, function (response) {

    //buffer for bytes
    let buffer = '';

    // response data ->
    response.on('data', function (pices) {
        // encode bytes
        buffer += pices;
    });

    // end response -> Finish connection
    response.on('end', () => {

        // Parsing data for JSON style
        let data = JSON.parse(buffer);
        // print people in space
        let people = data.people.name;
        console.log(people);

        // Change to String
        let jsonString = JSON.stringify(data);

        // Write data to json file
        fs.writeFile('jsonAPI.json', jsonString, 'utf8', (err) => {
            if(err) throw err;
            console.log('Saved!');
        });
    });
});
