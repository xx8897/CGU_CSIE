<?php
session_start();
/*刪除session*/
session_destroy();

header('location:login.html');

?>