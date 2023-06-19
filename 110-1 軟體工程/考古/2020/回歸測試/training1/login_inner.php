<?php
sleep(3);
?>
<!--
/**
 * Copyright Tyto Software Pvt. Ltd.
 */
-->
<html>
<head><title>Login</title></head>
<body>
<script>
function login(){
	if (document.loginForm.user.value == "test" && document.loginForm.password.value == "secret"){
		top.location.href = "books.php"
	} else {
		document.getElementById("errorMessage").style.display = "block";
	}
}
</script>

<br/><br/>
<center>
<div style="width:300px;text-aslign:left;background-color: #ded;border: 1px solid orange;padding:30px;">
<b>Sahi Training Site</b><br/><br/>
<form name="loginForm" onsubmit="return false;">
<div id="errorMessage" style="display:none;color:red;">Invalid username or password</div>
<table class="test">
<tr><td>Username</td><td><input type="text" name="user" value=""></td></tr>
<tr><td>Password</td><td><input type="password" name="password" value=""></td></tr>
<tr><td>&nbsp;</td><td><input type="submit" value="Login" class="button" onclick="login()"></td></tr>
</table>
</form>
Not a user? <a href="register.htm">Register</a>
</div>
<br/><br/><br/>
Use test/secret to login
</center>
</body>
</html>