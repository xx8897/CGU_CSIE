<?php
$State = $_COOKIE['LoginState'];
$UserName = $_COOKIE['UserName'];

if($State == 0)
{
	echo "<script>alert('請先登入');</script>";
	header("refresh:0;url = login.html"); 
    exit;
}

$host = 'localhost';
//改成你登入phpmyadmin帳號
$user = 'root';
//改成你登入phpmyadmin密碼
$passwd = '20000206';
//資料庫名稱
$database = 'movie';
//實例化mysqli(資料庫路徑, 登入帳號, 登入密碼, 資料庫)
$connect = new mysqli($host, $user, $passwd, $database);
//設定連線編碼，防止中文字亂碼
$connect->query("SET NAMES 'utf8'");

if ($connect->connect_error) {
    die("連線失敗: " . $connect->connect_error);
}

$sqlShow = "SELECT * FROM `showing`";
$resultShow = $connect->query($sqlShow);

$sqlMovie = "SELECT * FROM `movie`";
$resultMovie = $connect->query($sqlMovie);

$sqlMovieName = "SELECT `movie`, `movieID` FROM `movie`";
$resultMovieName = $connect->query($sqlMovieName);
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>購票</title>
		<style type="text/css">
			.H1{
				color: white;
				font-size: 40px;
				margin-top:50px;
			}
			.login_button{position:absolute;
						top:485px;
						left:610px;
						z-index: 3;}	
			
			body {
				padding: 0px;
				margin: 0px;
				background-attachment:fixed;
			}
			nav > ul {
				background-color: #DEDEDE;
				list-style: none;   /* 移除項目符號 */
				margin: 0;
				padding: 0;
			}

			nav a {
				color: inherit; /* 移除超連結顏色 */
				display: block; /* 讓 <a> 填滿 <li> */
				font-size: 1.2rem;
				padding: 20px;
				text-decoration: none;  /* 移除超連結底線 */
			}

			/* 滑鼠移到 <a> 時變成深底淺色 */
			nav li:hover {
				background-color: rgb(115, 115, 115);
				color: white;
			}
			
			.flex-nav {
				display: flex;
				justify-content: space-evenly;
			}
			
			div p{font-size:20px;
				font-weight:bold;
				color:white;
				z-index: 2;}
			
			div p.title {position:absolute;
					font-weight:bold;
					color:white;					
					left:600px;
					top:90px;   
					font-size:1cm;
					z-index: 2;}
			
			.area	{width:500px;}
			.back	{z-index: 1;
					position:fixed;
					top:140px;
					left:32.5%;
					width:450px; 
					height:250px;
					margin-top:50px;}
			
			.selectMovie	{position:relative;
							top:40px;
							
							size:30px;
							font-weight:bold;
							color:black;
							width:200px;
							height:40px;
							z-index: 3;}
			.selectMovie option {position:relative;
							top:100px;
							left:550px;
							size:30px;
							width:200px;
							height:40px;
							z-index: 3;}
							
			.selectNumber	{position:relative;
							top:40px;
							
							size:30px;
							font-weight:bold;
							color:black;
							width:200px;
							height:40px;
							z-index: 3;}
			.selectNumber:hover	{position:relative;
							top:40px;
							size:30px;
							color:white;
							background-color:#403737;
							cursor: pointer;
							font-size:15px; 
							width:200px;
							height:40px;
							z-index: 3;}

			p a	{position:relative;
				top:70px;
				left:510px;
				font-weight:bold;
				font-size:40px;
				color:black;
				text-decoration:none;
				z-index: 3;
				}
			p a:hover	{
				color:#9C9C9C;
				}
				
		</style>
		
	</head>
	<body background="./background.png">
		<nav>
            <ul class="flex-nav">
                <li><a href="home.php">首頁</a></li>
                <li><a href="movie_list.php">電影介紹</a></li>
                <li><a href="showingTime.php">場次查詢</a></li>
                <li><a href="buy.php">會員專區</a></li>
				<li><a href="login.html"> <?php echo $UserName?> </a></li>
            </ul>
		</nav>
		
		<center>
		<img class="back" src="gray2.png" title="gray_background" >
		<form name="Choose" action="NumberChoice.php" method="POST">
		<h1 class="H1">選擇電影票</h1>
			<p><label class="selectMovie">  優待票  <input name="優待票" style="width:50px;height:20px;" type="number" min="0" max="3" size="1" maxlength="1" value="0"/>  張 </p> </label>
			<p><label class="selectMovie">  學生票  <input name="學生票" style="width:50px;height:20px;" type="number" min="0" max="3" size="1" maxlength="1" value="0"/>  張</p>
			<p class="selectMovie">  普通票  <input name="普通票" style="width:50px;height:20px;" type="number" min="0" max="3" size="1" maxlength="1" value="0"/>  張</p>
			<input type="submit" class="selectNumber" style="width:70px;height:30px;" value="確定">
			<br><br><br><br>
		</form>
		</center>
    </body>
</html>