<?php

setcookie("LoginState", true, time()+3600);
echo $_COOKIE["LoginState"];
header("refresh:1;url = s2.php");
?>