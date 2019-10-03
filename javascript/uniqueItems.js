// Two functions that return an array of unique values in a given array
export const usingSet = array => [...new Set(array)];
export const usingFilter = array => array.filter((item, idx) => array.indexOf(item) === idx);
