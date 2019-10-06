<?php

$favcolor = "red";
switch ($favcolor) {
    case "red":
        echo "Your favorite color is red!";
        break;
    case "blue":
        echo "Your favorite color is blue!";
        break;
    case "green":
        echo "Your favorite color is green!";
        break;
    default:
        echo "Your favorite color is neither red, blue, nor green!";
}

// Output will be Your favorite color is red!



$favcolor = 4;
switch ($favcolor) {
    case 1:
        echo "Your favorite number is 1";
        break;
    case 2:
        echo "Your favorite number is 2";
        break;
    case 3:
        echo "Your favorite number is 3";
        break;
    default:
        echo "Your favorite number is neither 1, 2, nor 3";
}

// Output will be Your favorite number is neither 1, 2, nor 3