$(function () {
    if (document.layers) {
        document.captureEvents(Event.MOUSEDOWN);
        document.onmousedown = f1;
    } else {
        document.onmouseup = f2;
        document.oncontextmenu = f1;
    }
    document.oncontextmenu = new function ("return false");
});

function f1() {
    if (document.all) {
        return false;
    }
}

function f2(e) {
    if (document.layers || (document.getElementById & !document.all)) {
        if (e.which == 2 || e.which == 3) {
            return false;
        }
    }
}