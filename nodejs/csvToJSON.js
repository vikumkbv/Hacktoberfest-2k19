// install before use
// import {qs} from "qs"

const data2obj = (data) => {
    try {
        let allData = []; // array [[],[]] all lines
        let firstColumnNames = []; // column names array
        let nestedArray = []; // objs in names
        let finalData = {}; // final parsed data

        //? store data
        let indata = data;
        //? Check rows
        let rows = indata.split(/\r?\n|\r/);
        //? if last element is a empty string - remove it
        if(rows[rows.length - 1] == '' || rows[rows.length - 2] == '') {
            rows.pop();
        }

        //? make headers array
        let headers = rows[0].split(',');
        //? if columns>2
        if(headers.length > 2) {
            //? make a arrays
            for(let el in rows) {
                let splitedData = rows[el].split(/\,/);
                allData.push(splitedData);
            }

            for(let i = 1; i < allData.length; i++) {
                //? set obj names array
                firstColumnNames.push(allData[i][0]);
            }

            //? Array of nested objects
            for(let i = 1; i < rows.length; i++) {
                let nestedObj = {};
                let currentLine = rows[i].split(",");

                for(let j = 1; j < headers.length; j++) {
                    nestedObj[headers[j]] = currentLine[j];
                }
                nestedArray.push(nestedObj);
            }

            for(let i = 0; i < firstColumnNames.length; i++) {
                finalData[firstColumnNames[i]] = nestedArray[i];
            }
            return finalData;

        } else {
            //? if only two columns
            let clearIn = indata.replace(/,/g, ':').replace(/\n/g, ',');
            let parseObj = qs.parse(clearIn, ',', ':');
            let stringifyObj = JSON.stringify(parseObj);
            let parsedJSON = JSON.parse(stringifyObj);
            return parsedJSON;
        }
    } catch (error) {
        console.error('Data to object ->' + error.message);
    }
};

let a = `nameOfObject,Variable1,Variable2,Variable3
FirstObject,1,2,3
SecondObject,1,2,3`;

// need qs
let c= `name, var1
Mike, S.`

let b = data2obj(a);
console.log(b);