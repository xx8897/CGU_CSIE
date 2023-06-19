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
echo "連線成功";
echo "<br>";
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>電影介紹</title>

		<style type="text/css">	
			.Seat{
				width: 1000px;
				margin:0px auto;
				display:flex;
				justify-content:center;
				background-color:rgba(255, 255, 255, 0.7);
				padding: 30px;
				border-radius: 15px;
				margin-top: 0px;
			}
			.MovieList{
				padding:80px;
				
			}
			h1{
				text-align: center;
				font-size: 1.4cm;
				margin-top:120px;
				margin-bottom: 50px;
				color: white;
			}
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
				top:100px;
				left:130px;
				font-size:17px;
				opacity:0.9;
				border-collapse:collapse;
				border:1px solid black;
			}
			.movie_name{
				font-size:20px;
				background-color:transparent;
				height:40px;
				font-size:20px;'
			
			}
			.movie_name{
				font-size:20px;
				background-color:transparent;
				height:40px;
				font-size:20px;

			
			}
			.movie_name:hover{
				font-size:20px;			
				height:40px;
				color:white;
				background-color:#403737;
				cursor: pointer;
				
			}
			
		</style>
		
		<script>
			function aa() {
				var a = document.getElementById("result_data").scrollTop;
				var b = document.getElementById("result_data").scrollLeft;
				document.getElementById("result_items").scrollTop = a;
				document.getElementById("result_head").scrollLeft = b;
			};
		</script>
	</head>
	<body background="./background.png">
		<nav>
            <ul class="flex-nav">
                <li><a href="home.php">首頁</a></li>
                <li><a href="movie_list.php">熱映中</a></li>
                <li><a href="showingTime.php">場次查詢</a></li>
                <li><a href="buy.php">會員專區</a></li>
				<li><a href="login.html">登入/註冊</a></li>
				<li><a href="logout.php">  <?php echo $_SESSION['username'] ;?></a></li>
            </ul>
		</nav>
		<h1>強檔熱映中</h1>
		<div class='Seat'>
		<form action="MovieList.php" method="post">
			<table class="MovieList" cellpadding='35px' style="text-align:center">
				<?php
				$count = 0;
				$c = 0;
				$sqlMovie = "SELECT * FROM `movie` WHERE 1" ;
				$resultMovie = $connect->query($sqlMovie);
				if ($resultMovie->num_rows > 0) {
					
					while ($rowM = $resultMovie->fetch_assoc())
					{
						
						if($count == 3){
							$count = 0;
							echo"<tr>";
						}
						$count++;
						$Name = $rowM["movie"];
						$Year = $rowM["releaseYear"];
						$Month = $rowM["releaseMonth"];
						$Day = $rowM["releaseDay"];
						
						echo"<td><img src = './$Name.jpg' width='200px';height='320px'>
							<br><br><input type='submit' name='MovieName' value='$Name' class='movie_name'>
							<p style='color:#2D2C2C;'>$Year-$Month-$Day</p><br><br></td>";
						
						if($count == 4)
						{
							echo"</tr>";
						}
					}
				}
				?>
			</table>
		</form>
		</div>
		<br><br>
							
	</body>
</html>