<?php
session_start();
$State = $_COOKIE["LoginState"];

$UserName = $_COOKIE['UserName'];
//echo $UserName;

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
			
			.movieLi li {
				list-style: none;
				float: left;
			}
			.movieLi li:before{
				content: url('./arrow.png');
				vertical-align: middle;
			
			}
			.MovieData{
				width: 800px;
				margin:0px auto;
				text-align: left; 
				background-color:rgba(255, 255, 255, 0.7);
				padding: 45px;
				border-radius: 30px;
                margin-top: 100px;
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
				position:fixed;
				display: flex;
				justify-content: space-evenly;
				width:1280px;
				z-index:100;
				top:0px;
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
				color:white;
				}
			p a:hover	{
				color:#9C9C9C;
				}
			.book{
				font-size:13px;
				border:solid 1;
			}
			.book:hover{
				font-size:13px;
				border:solid 1;
				color:white;
				background-color:#403737;
				cursor: pointer;
			}
			.text-up{
				text-decoration:none; 
				color:#403737;
				font-weight:bolder;
				font-size: 18px;
				text-align: center;
			}
			.text-up:hover{
				text-decoration:none; 
				color:#BCC5D2;
				font-weight:bolder;
				font-size: 18px;
				text-align: center;

			}

				
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
				<li><a href="logout.php"> <?php echo $_SESSION['username'] ;?>  </a></li>
            </ul>
        </nav>
		
		<br>
		<p class="area">
			<a href="buy.php" style="text-decoration: underline; ">購票</a>&nbsp &nbsp &nbsp &nbsp &nbsp
			<a href="return_ticket.php">退票</a>&nbsp &nbsp &nbsp &nbsp &nbsp
			<a href="history.php">紀錄查詢</a>
		</p>
		
		<form name="Choose" action="Choose.php" method="POST">
			<?php echo "<p name='Session' value='$State'></p>"?>
			<p><select name="Date" class="selectMovie" style="width:200px;height:40px;">
						<option  style="width:200px;height:40px;">選擇日期</option>
						<option  style="width:200px;height:40px;" value="15">2021/01/15</option>
						<option  style="width:200px;height:40px;" value="16">2021/01/16</option>
						<option  style="width:200px;height:40px;" value="17">2021/01/17</option>
				</select>
			</p>

			
			<br><br><br><br><br><br>

			<div style="color:white">
				<ul class="movieLi">
					<?php
						
						if ($resultMovieName->num_rows > 0) {
							while ($rowM = $resultMovieName->fetch_assoc())
							{
								$NameL = $rowM['movie'];
								echo "<li><a href='#$NameL' class ='text-up'>$NameL&nbsp&nbsp&nbsp&nbsp</a></li>";
							}
						}
					?>
				</ul>
			</div>
				<br><br><br><br>

			<center>
			<div class="MovieData">
				
			<p style="color:black;">
				<?php
					$sqlMovieName = "SELECT `movie`, `movieID` FROM `movie`";
					$resultMovieName = $connect->query($sqlMovieName);
					
					if ($resultMovieName->num_rows > 0) {
								
						while ($rowMN = $resultMovieName->fetch_assoc())
						{
							$Name = $rowMN['movie'];
							$ID = $rowMN['movieID'];

							$sqlTime = "SELECT `startTime` FROM `showing` WHERE `movieID` = '$ID' AND `day` = '15'";
							$resultTime = $connect->query($sqlTime);
							
							echo "<tr><td><span class='test'><h2 id='$Name'>$Name</h2>時間:<br><br>";
												if ($resultTime->num_rows > 0) {
													while ($rowT = $resultTime->fetch_assoc())
													{	
														$Time = $rowT['startTime'];
														echo "&nbsp<input type='submit' class='book' name='$ID' value='$Time'>&nbsp";
													}
													echo"<br><br>";
												}
							echo "</br></span> </td>";
							echo "</tr>";
						}
					}	
							
					?>
			</p>
			</div>
			</center>
			
		</form>
		<br><br>
	</body>
</html>