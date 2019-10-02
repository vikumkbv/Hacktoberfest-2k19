/*
    Exemple:
    const someElm = document.querySelector('.foo');
    toggleClass(someElm, 'someClass');

    Util to toggle classes like '.disable', '.hidden', etc.
*/

const toggleClass = (elm, targetClass) => {
    const classList = elm.className.split(' ');

    if ( classList.includes(targetClass)) {
        const classPosition = classList.indexOf(targetClass);
        classList.splice(classPosition, 1);
    } else {
        classList.push(targetClass);
    }

    elm.className = classList.join(' ');
}