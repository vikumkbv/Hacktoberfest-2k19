      function removeTransition(e) {
                if (e.propertyName !== 'transform') return;
                e.target.classList.remove('playing');
            }
          
           function playSound(e) {
                const audio = document.querySelector(`audio[data-key="${e.keyCode}"]`);
                const key = document.querySelector(`.key[data-key="${e.keyCode}"]`);
                if(!audio){ //to stop the function to be executed at all and give alert message
                   alert("Press a valid DrumKey!!")
                    return;
                }
                audio.currentTime = 0 ; //to rewind the audio or to send it to begining
                audio.play();
                key.classList.add("playing");
            }
            
            const keys = Array.from(document.querySelectorAll('.key'));
            keys.forEach(key => key.addEventListener('transitionend', removeTransition));
            window.addEventListener("keydown",playSound);
