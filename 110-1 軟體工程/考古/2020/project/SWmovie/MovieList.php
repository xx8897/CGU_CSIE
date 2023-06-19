<?php
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

$Name = @$_POST["MovieName"];
echo "Name $Name";
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>電影介紹</title>

		<style type="text/css">	

			.MovieData{
				width: 800px;
				margin:0px auto;
				text-align: left; 
				background-color:rgba(255, 255, 255, 0.7);
				padding: 45px;
				border-radius: 30px;
                margin-top: 70px;
                padding-top: 30px;
			}
            .Title1{
                font-size: 40px;
                font-weight:450;
            }
            .Title2{
                font-size: 30px;
                font-weight:450;
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

		</style>
	</head>
	<body background="./background.png">
		<nav>
            <ul class="flex-nav">
                <li><a href="home.php">首頁</a></li>
                <li><a href="movie_list.php">電影介紹</a></li>
                <li><a href="showingTime.php">場次查詢</a></li>
                <li><a href="buy.php">會員專區</a></li>
				<li><a href="login.html">登入/註冊</a></li>
            </ul>
		</nav>

        <?php
            $sqlMovie = "SELECT * FROM `movie` WHERE `movie` = '$Name'";
            $resultMovie = $connect->query($sqlMovie);

            $Director = 0;
            $Actor = 0;
            $Len = 0;
            $Sys = 0;
            $Year = 0;
            $Month = 0;
            $Day = 0;
            $Intro = 0;

            if ($resultMovie->num_rows > 0) {
                while ($rowMovie = $resultMovie->fetch_assoc())
                {
                    $Director = $rowMovie["director"];
                    $Actor = $rowMovie["actor"];
                    $Len = $rowMovie["length"];
                    $Sys = $rowMovie["systematics"];
                    $Year = $rowMovie["releaseYear"];
                    $Month = $rowMovie["releaseMonth"];
                    $Day = $rowMovie["releaseDay"];
                    $Intro = $rowMovie["introduction"];
                }
            }
        ?>

        <div class="MovieData">
            <table>
                <tr>
                    <td rowspan='6' width='300px'><img src = './<?php echo$Name;?>.jpg' width='250px';height='400px'></td>
                    <td width='550px'><p class="Title1"><?php echo"$Name ";?><img src = './<?php echo$Sys;?>.png' width='8%';height='0%';></p></td>
                </tr>
                <tr>
                    <td><p>上映日期：<?php echo"$Year/$Month/$Day";?></p></td>
                </tr>
                <tr>
                    <td><p class="Title2">MOVIE INFO</p></td>
                </tr>
                <tr>
                    <td><p>導演：<?php echo$Director;?></p></td>
                </tr>
                <tr>
                    <td><p>演員：<?php echo$Actor;?></p></td>
                </tr>
                <tr>
                    <td><p>片長：<?php echo$Len;?></p></td>
                </tr>
            </table>
        </div>
        <div class="MovieData">
            <p class="Title1">劇情簡介</p>
            <p><?php echo$Intro;?></p>
        </div>
        <br><br>
    </body>
</html>


