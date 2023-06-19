<?php

$State = $_COOKIE['LoginState'];
$UserName = $_COOKIE['UserName'];
$MemberID = $_COOKIE['MemberID'];
$RecordID = $_COOKIE['RecordID'];

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
			
			.NoneSeat{
				background-color: dodgerblue;
				color:white;
				width: 40px;
				height: 30px;
				border-radius: 5px;
				
			}
			.NoneSeat:hover{
				background-color: green;
				color:white;
				width: 40px;
				height: 30px;
				border-radius: 5px;
				
			}

			.NullSeat{
				background-color: red;
				color:white;
				width: 40px;
				height: 30px;
				border-radius: 5px;
			}

			.Seat{
				width: 700px;
				margin:0px auto;
				display:flex;
				
				justify-content:center;
				background-color:rgba(255, 255, 255, 0.7);
				padding: 30px;
				border-radius: 5px;
			}
			.Screen{
				border:5px black solid;
				border-radius: 50px;
				text-align: center;
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
					top:100px;
					left:33%;
					width:450px; 
					height:450px;}
			
			.selectMovie	{position:relative;
							top:100px;
							left:550px;
							size:30px;
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
							top:115px;
							left:523px;
							size:30px;
							font-weight:bold;
							color:black;
							width:200px;
							height:40px;
							z-index: 3;}


			p a	{position:relative;
				top:80px;
				left:510px;
				font-weight:bold;
				font-size:25px;
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
		
		<h1 style="text-align: center; color:white">選擇座位</h1>
		<div class="Seat">
			
			<form name="SeatList" action="SeatChoice.php" method="POST">
				<div>
					<div class="Screen">
						銀幕
					</div>
				<?php
					$ShowingID = substr($RecordID, -4);
					echo "<br>";
					for($i = 0;$i < 5;$i++)
					{
						for($j = 0;$j < 10;$j++)
						{
							$Now = $i.$j;
							$Empty = 0;
							
							$sqlSeat = "SELECT * FROM `ticket information`";
							$resultSeat = $connect->query($sqlSeat);
							if ($resultSeat->num_rows > 0) {
								while ($rowS = $resultSeat->fetch_assoc())
								{
									$Seat = $rowS["seat"];
									$RecordIDNow = $rowS["recordID"];

									$ShowingIDNow = substr($RecordIDNow, -4);

									if(($Now == $Seat) && ($ShowingID == $ShowingIDNow))
									{
										$Empty = 1;
									}
								}
							}
							if($Empty == 0)
								echo"<input type='submit' class= 'NoneSeat' name='SeatNum' value= $i$j>&nbsp&nbsp ";
							else
								echo"<input type='submit' class= 'NullSeat' disabled='disabled' name='SeatNum' value= $i$j>&nbsp&nbsp ";
						}
						echo "<br><br>";
					}
				
				?>  
				</div>
			</form>
		</div>
		
    </body>
</html>