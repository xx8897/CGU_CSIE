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
				width: 700px;
				height: 180px;
				margin:0px auto;
				text-align: left; 
				background-color:rgba(255, 255, 255, 0.7);
				padding: 30px;
				border-radius: 30px;
				
			}
			
			.SeatList{
				width: 800px;
				margin:0px auto;
				text-align: left; 
				background-color:rgba(255, 255, 255, 0.7);
				padding: 30px;
				border-radius: 30px;
				
			}
			.Seat{
				border-bottom:5px gray solid;
				text-align: center;
				width:800px;
			}
			.SeatIcon:before{
				content: url('./CouchIcon.png');
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
				left:243px;
				width:500px;
				top:50px;
				color:white;
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
		
		<p class="area">
			<a href="buy.html">購票</a>&nbsp &nbsp &nbsp &nbsp &nbsp
			<a href="return_ticket.html">退票</a>&nbsp &nbsp &nbsp &nbsp &nbsp
			<a href="history.html">紀錄查詢</a>
		</p>
		
		
		<div style="border:10px; background-color:#FFAC55 solid;">			
				<h1>訂票資訊</h1>
				<br><br>
				
					<?php
						
						$sqlBook = "SELECT * FROM `booking record` WHERE `memberID` = '$MemberID' AND `Finish` = 1";
						$resultBook = $connect->query($sqlBook);
						if ($resultBook->num_rows > 0) 
						{
							while ($rowB = $resultBook->fetch_assoc())
							{						
								$RecordID = $rowB["recordID"];
								
								if(@$_POST["$RecordID"])
								{
								
									echo"<div class='SeatList'>";
					
									$Ty1 = 0;
									$Ty2 = 0;
									$Ty3 = 0;
									echo"<table class = 'Seat' cellpadding='25px'; rules='rows'>";
									echo "<tr><th style='font-size:0.7cm;'>電影票ID</th><th  style='font-size:0.7cm;'>座位</th></tr>";
									
									
										$sqlTicket = "SELECT * FROM `ticket information` WHERE `recordID` = '$RecordID'" ;
										$resultTicket = $connect->query($sqlTicket);
										if ($resultTicket->num_rows > 0) {
											
											while ($rowT = $resultTicket->fetch_assoc())
											{
												$TicketID = $rowT["ticketID"];
												$Seat = $rowT["seat"];
												$Type = $rowT["ticketType"];
												
												$R = substr($Seat, -2, 1);
												if($Seat < 10)
													$R = 0;
												$L = substr($Seat, -1, 1);
												
												echo "<tr><td>$TicketID</td><td class = 'SeatIcon'>第 $R 排 $L 號</td></tr>";
												if($Type == "優待票")
													$Ty1++;
												elseif($Type == "學生票")
													$Ty2++;
												elseif($Type == "普通票")
													$Ty3++;
											}
										}
									echo"</table>";	
									$TotalPay = 230*$Ty1 + 250*$Ty2 + 380*$Ty3;
									echo"<p class = 'ticket'>優待票 $Ty1 張</p>";
									echo"<p class = 'ticket'>學生票 $Ty2 張</p>";
									echo"<p class = 'ticket'>普通票 $Ty3 張</p>";
									echo"<h3 class='money';'>總計金額 NT$ $TotalPay</h3>";
										
									echo"</div>";
												}
											}
									echo "</table>";
								}
					?>
		</div>
		<br>
		<br>
		<br>
	</body>
</html>