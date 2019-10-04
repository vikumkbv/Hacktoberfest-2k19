var counter = 10;

const Timer = setInterval(() => {
  --counter;
  
  if(counter <= 0) 
  {
    clearInterval(Timer);
    console.log("Time is up!");
  }
  else
  {
    console.log(counter);
  }
}, 1000);