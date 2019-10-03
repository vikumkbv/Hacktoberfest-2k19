<?php
  //check for posted data
  /*if (filter_has_var(INPUT_POST, 'data')) {
    echo "data found";
  }else{
    echo "not found data";
  }

  // email validation
  if (filter_has_var(INPUT_POST, 'data')) {
    $email = $_POST['data'];

    //remove illegle characters
    $email = filter_var($email, FILTER_SANITIZE_EMAIL);
    echo $email.'<br>';

    if (filter_input(INPUT_POST, 'data', FILTER_VALIDATE_EMAIL)) {
      echo "e mail is valid";
    }else {
      echo "e mail is not valid";
    }
  }
  //integer validation
  $var = 11;

  if (filter_var($var, FILTER_VALIDATE_INT)) {
    echo $var.'is a number';
  }else {
    echo $var.'is not a number';
  }
  */
  //filter input array
  $filters = array(
    "data" => FILTER_VALIDATE_EMAIL,
    "data2" => array(
      "filter" => FILTER_VALIDATE_INT,
      "options" => array(
        "min_range" = 1,
        "max_range" = 100
      )
    )
  );

  print_r(filter_input_array(INPUT_POST, $filters));


 ?>


<form class="" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
  <input type="text" name="data" value="">
  <input type="text" name="data2" value="">
  <button type="submit" name="button">Submit</button>
</form>
