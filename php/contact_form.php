<?php
$msg = '';
$msgClass= '';

if (filter_has_var(INPUT_POST, 'submit')) {
  //echo "Submitted";
  //get form data
  $name = htmlspecialchars($_POST['name']);
  $email = htmlspecialchars($_POST['email']);
  $message = htmlspecialchars($_POST['message']);

  //check required fields
  if (!empty($email) && !empty($name) && !empty($message)) {
    // passed
    //check email
    if (filter_var($email, FILTER_VALIDATE_EMAIL) === false) {
      // failed
      $msg = 'please use a valid email!!';
      $msgClass = 'alert-danger';
    }else {
      // passed --> sending the mail
      $toEmail = 'email@address.com';
      $subject = 'Contact request from'.$name;
      $body = '<h2>Contact request</h2>
      <h4>Name</h><p>'.$name.'</p>
      <h4>Email</h><p>'.$email.'</p>
      <h4>Message</h><p>'.$message.'</p>
      ';

      // Email headers
      $headers = "MIME_Version: 1.0"."\r\n";
      $headers .="Content_Type:text/html;charset=UTF-8" . "\r\n";

      //Additional $headers
      $headers .= "From: " .$name. "<".$email.">". "\r\n";

      if (mail($toEmail, $subject, $body, $headers)) {
        $msg = 'Your request has been sent!!';
        $msgClass = 'alert-success';
      }else {
        $msg = 'Your request cant be fulfilled at this time';
        $msgClass = 'alert-danger';
      }
    }
  }else {
    // failed
    $msg = 'fill all feilds!!';
    $msgClass = 'alert-danger';
  }
}
?>

<!DOCTYPE html>
<html lang="en" dir="ltr">
<head>
  <meta charset="utf-8">
  <title>Contact Us</title>
  <link rel="stylesheet" href="bootstrap.min.css">
</head>
<body>
  <nav class="navbar navbar-default">
    <div class="container">
      <div class="navbar-header">
        <a class="navbar-brand" href="Contact_form.php">My Website</a>

      </div>

    </div>

  </nav>
  <div class="container">
    <?php if($msg != ''): ?>
      <div class="alert <?php echo $msgClass; ?>"><?php echo $msg; ?>

      </div>
    <?php endif; ?>
    <form class="" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
      <div class="form-group">
        <label for="">Name</label>
        <input type="text" name="name" value="<?php echo isset($_POST['name']) ? $name : ''; ?>" class="form-control">
      </div>
      <div class="form-group">
        <label for="">Email</label>
        <input type="text" name="email" value="<?php echo isset($_POST['email']) ? $email : ''; ?>" class="form-control">
      </div>
      <div class="form-group">
        <label for="">Message</label>
        <textarea name="message" rows="8" cols="80" class="form-control"><?php echo isset($_POST['message']) ? $message : ''; ?></textarea>
      </div>
      <br>
      <button type="submit" name="submit" class="btn btn-primary">Submit</button>

    </form>

  </div>

</body>
</html>
