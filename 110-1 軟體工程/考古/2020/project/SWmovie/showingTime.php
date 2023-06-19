<?php
session_start();
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
		<title>場次時間表</title>
		<link rel="stylesheet" type="text/css" href="css/login.css"/>
		<script type="text/javascript" src="js/jquery-3.5.1.js"></script>
		<script type="text/javascript" src="js/jquery.form.js"></script>
		
		<style type="text/css">	
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
				position:fixed;
				display: flex;
				justify-content: space-evenly;
				width:1265px;
				z-index:3;
				top:0px;
			}
			
			.movietable{
				position:absolute;
				top:150px;
				left:380px;
				font-size:17px;
				width:500px;
				opacity:0.9;
				margin-top: 50px;
				padding:20px;
				
			}
			
			h1{
				text-align: center;
				font-size: 50px;
				margin-top:120px;
				margin-bottom: 50px;
				color: white;
			}
			h3{
				color:#6C1B1B;

			}
			
			.title {font-size:50px;}
			
			.back{z-index:-1;
				position:fixed;
				top:0px;
				left:10px;
				width:1230px;}
				
			.test{font-weight:bold;}

		</style>
	</head>
	<body background="./background.png">
		<nav>
            <ul class="flex-nav">
                <li><a href="home.php">首頁</a></li>
                <li><a href="movie_list.php">熱映中</a></li>
                <li><a href="showingTime.php">場次查詢</a></li>
                <li><a href="buy.php">會員專區</a></li>
				<li><a href="login.html">登入/註冊</a></li>
				<li><a href="logout.php"> <?php echo $_SESSION['username'] ;?></a></li>
				
            </ul>
        </nav>
		<div>
			<h1>場次時間表</h1>
			<div>
			<table bgcolor="#FAFAFA" border="0"  class="movietable"  width="1200px">
					
					<?php
						if ($resultMovieName->num_rows > 0) {
							
							while ($rowMN = $resultMovieName->fetch_assoc())
							{
								$Name = $rowMN['movie'];
								$ID = $rowMN['movieID'];

								$sqlTime = "SELECT `startTime` FROM `showing` WHERE `movieID` = '$ID' AND `day` = '15'";
								$resultTime = $connect->query($sqlTime);
								echo "<tr>";
								echo "<td><span class='test'> 	<h3 >$Name</h3>
																日期:&nbsp
																<button type='button' disabled='disabled'style='color:black'>2021/1/15</button>
																&nbsp
																<button type='button' disabled='disabled'style='color:black'>2021/1/16</button>
																&nbsp
																<button type='button' disabled='disabled'style='color:black'>2021/1/17</button></br>
																<br>時間:";

													if ($resultTime->num_rows > 0) {
														while ($rowT = $resultTime->fetch_assoc())
														{	
															$Time = $rowT['startTime'];
															echo "&nbsp<button type='button' disabled='disabled' style='color:black'>$Time</button>";
														}
													}
								echo "</br></span><br> </td>";
								echo "</tr>";
							}
						}
						
						
					?>
			</table>

			<div>
		</div>
		
	</body>
</html>