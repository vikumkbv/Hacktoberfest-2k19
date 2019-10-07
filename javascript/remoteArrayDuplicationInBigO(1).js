/*
* Easiest way to remove duplicate from an array
*/

let arr = [1,2,3,4,5,3,4,7,8,6,5];

let uniqueValues = {};

for(let i = 0; i < arr.length; i++) {
    uniqueValues[arr[i]] = arr[i];
}

console.log("Array that contains only unique values", Object.values(uniqueValues));
