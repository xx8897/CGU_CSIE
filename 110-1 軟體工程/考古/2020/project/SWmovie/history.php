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
//echo "連線成功";
//echo "<br>";

$State = $_COOKIE['LoginState'];

$UserName = $_COOKIE['UserName'];

$MemberID = 0;

$sqlID = "SELECT `memberID` FROM `member profile` WHERE `account` = '$UserName'";

$resultID = $connect->query($sqlID);

if ($resultID->num_rows > 0) {
    while ($rowID = $resultID->fetch_assoc())
    {
        $MemberID = $rowID['memberID'];
    }
}

?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>退票</title>
		<style type="text/css">
			.MovieData{
				width: 600px;
				height: 300px;
				margin:0px auto;
				text-align: left; 
				background-color:rgba(255, 255, 255, 0.7);
				padding: 30px;
				border-radius: 30px;
			}

			.Name{
				font-weight:bold;
				font-size: 25px;
			}
			.Cinema:before{
				content: url('./CinemaIcon.png');
				vertical-align: middle;
				margin-right: 10px;	
			}
			.Time:before{
				content: url('./DateIcon.png');
				vertical-align: middle;
				margin-right: 10px;	
			}
			.button{
				position:fixed;
				bottom:0;
				display:flex;
				width:100%;
				justify-content:center;
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
				width:1280px;
				z-index:3;
				top:0px;
			}
			
			.movietable{
				position:relative;
				left:30px;
				font-size:17px;
				top:60px;
				opacity:0.9;
				border-collapse:collapse;
				border:1px solid black;
			}
			
			h1{
				position:relative;
				text-align:center;
				top:50px;
				color:white;
				font-size: 40px;
			}
			
			h2{
				position:relative;
				left: 0px;
				width:500px;
				top:10px;
				color:black;
			}
			
			.title {font-size:50px;}
			
			.test{line-height:1pt;
				font-weight:bold;
				color:black;}
			
			.button1{
				top:530px;
				left:980px;}
				
			.button2{
				top:530px;
				left:1100px;}
				
			.back{z-index:-1;
				position:fixed;
				top:0px;
				left:10px;
				width:1230px;}
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
			.return{
				font-size:15px;
				width:80px;
				font-weight:bold;
				border:solid 1;

			}
			.return:hover{
				font-size:15px;
				width:80px;
				font-weight:bold;
				border:solid 1;
				color:white;
				background-color:#403737;
				cursor: pointer;
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
			<a href="buy.php">購票</a>&nbsp &nbsp &nbsp &nbsp &nbsp
			<a href="return_ticket.php" >退票</a>&nbsp &nbsp &nbsp &nbsp &nbsp
			<a href="history.php" style="text-decoration: underline; ">紀錄查詢</a>
		</p>
       	<br><br>
		
		<h1>訂票資訊</h1>

		<form name='Block' action="hisTicketInformation.php" method="post">
		<div style="border:10px; background-color:#FFAC55 solid;">			
				
				<br><br>
				
					<?php
						$Refund = false;
						$MovieID = 0;
						$Day = 0;
						$Start = 0;
						$Name = 0;
						date_default_timezone_set('Asia/Taipei');
						$NowTime = date("Y/m/d h:i");
						$NowTimeA2 = date("Y/m/d h:i", strtotime($NowTime."+2 hour"));
						
						$sqlBook = "SELECT * FROM `booking record` WHERE `memberID` = '$MemberID' AND `Finish` = 1";
						
						$resultBook = $connect->query($sqlBook);
						if ($resultBook->num_rows > 0) 
						{
							while ($rowB = $resultBook->fetch_assoc())
							{
								
								$RecordID = $rowB["recordID"];
								$ShowID = $rowB["showingID"];
								$Num = $rowB["number"];
								$PayWay = $rowB["paymentMethod"];
								$Pay = $rowB["payment"];

								$sqlShow = "SELECT * FROM `showing` WHERE `showingID` = '$ShowID'";
								$resultShow = $connect->query($sqlShow);
								if ($resultShow->num_rows > 0) {
									
									while ($rowS = $resultShow->fetch_assoc())
									{
										$MovieID = $rowS["movieID"];
										$Day = $rowS["day"];
										$Start = $rowS["startTime"];
									}
								}
								$TimeT = "2021/1/$Day $Start";

								$sqlName = "SELECT * FROM `movie` WHERE `movieID` = '$MovieID'";
								$resultName = $connect->query($sqlName);
								
								if ($resultName->num_rows > 0) {
									
									while ($rowN = $resultName->fetch_assoc())
									{
										$Name = $rowN["movie"];
									}
								}

								if(strtotime($TimeT) - strtotime($NowTime) > 0)
									$Refund = true;
								
								$Cinema = intval(substr($ShowID, -3) / 15) + 1;
								echo"<div class='MovieData'>";
								echo "<table  width='600px;';>";//style='border:solid 1px;'RULES='COLS' 
								echo "<tr colsapn='2' >";
								
								echo "<td>";
								echo "<p style='color:#41464D;'>NO.$RecordID&nbsp&nbsp&nbsp&nbsp";
								if(!$Refund)
								{
									echo"<input type='button' disabled='disabled' style='color:black' value='已過期'></p>";
								}
								else{
									echo"<input type='button' disabled='disabled' style='color:black' value='未觀看'></p>";
								}
								
								echo "<p class='Name'>$Name</p>";
								echo "<p><span class='Cinema'>第 $Cinema 廳&emsp;&emsp;</span></p>";
								echo "<span class='Time'>$TimeT &nbsp&nbsp $Num 張&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</span>";
								echo "<input type='submit' name='$RecordID' class='return'  value='詳細資訊'>";
								
								echo "</td>";
								echo "<td><img src='Thumbnail_vertical_QRC_1610162263981.png' style='width:190px;height:280px;position:relative; top:30px;'></td>";
								
								echo "</tr>";
								echo "</table>";
								echo "</div><br>";
								
							}
						}
						
					?>
		</div>
		</form>
	</body>
</html>