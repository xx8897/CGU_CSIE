<?php
	session_start();
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>首頁</title>
		<link rel="stylesheet" href="style.css" type="text/css">
		
	</head>
	<body background="./background.png">
		<nav>
            <ul class="flex-nav">
                <li><a href="home.php">首頁</a></li>
                <li><a href="movie_list.php">熱映中</a></li>
				<li><a href="showingTime.php">場次查詢</a></li>
                <li><a href="buy.php">會員專區</a></li>
				<li><a href="login.html">登入/註冊</a></li>
				<li><a href="logout.php"> <?php echo $_SESSION['username'] ;?>  </a></li>
            </ul>
        </nav>
		<img class="back" src="gray2.png" title="gray_background" >
		<span class="t">About us</span>
		
		<div class="text">
			<br class="about">PONY影城</br>
			<br>地址 : 桃園市龜山區文化一路259號</br>
			<br>電話 : (03)1234567</br>
			<br>營業時間 : 24hr</br>
			<br>信箱 : wearepony@gmail.com</br>
		</div>
	</body>
</html>