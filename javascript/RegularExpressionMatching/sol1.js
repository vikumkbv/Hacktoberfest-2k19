let patternMatch = function(s,p) {
    let regex = new RegExp(p)
    return s.match(regex) ? s.match(regex)[0] : false 
}