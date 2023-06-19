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

$sqlMovie = "SELECT * FROM `movie`";
$resultMovie = $connect->query($sqlMovie);


?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>訂票資訊</title>
		<style type="text/css">	

			.MovieData{
				width: 800px;
				margin:0px auto;
				text-align: left; 
				background-color:rgba(255, 255, 255, 0.7);
				padding: 30px;
				border-radius: 30px;
				
				
			}
			.Date:before{
				content: url('./DateIcon.png');
				vertical-align: middle;
				margin-right: 10px;	
			}
			.Time:before{
				content: url('./TimeIcon.png');
				vertical-align: middle;
				margin-right: 10px;	
			}
			.Card:before{
				content: url('./CardIcon.png');
				vertical-align: middle;
				margin-right: 10px;	
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
			.money{
				text-align: right;
				font-size: 0.7cm;
			}
			.ticket{

				font-size: 0.6cm;
				text-align: center;
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
				
				top:50px;
				color:white;
				text-align: center;
				font-size:40px;
			}
			
			h2{
				position:relative;
				left: 0px;
				width:500px;
				top:-20px;
				color:black;

			}
			
			.title {font-size:50px;}
			
			pre{width:500px;}
			
			.test{line-height:1pt;
				font-weight:bold;
				color:black;}
			
			.button1{
				top:530px;
				left:980px;
				width:100px;
				height:50px;
				background-color:white;
				color:dodgerblue;
				font-size: 18px;
				font-weight:bold;}
				
			.button1:hover{
				top:530px;
				left:980px;
				width:100px;
				height:50px;
				font-size: 18px;
				color:white;
				background-color:#403737;
				cursor: pointer;
				}

			.button2{
				top:530px;
				left:1100px;
				background-color:#403737;
				cursor: pointer;
				background-color:white;
				color:red;
				font-size: 18px;
				font-weight:bold;
			width:100px;height:50px}
			.button2:hover{
				top:530px;
				left:1100px;
				cursor: pointer;
				color:white;
				background-color:#403737;
				cursor: pointer;
				font-size: 18px;
				font-weight:bolder;
				width:100px;
				height:50px
			}
				
			.back{z-index:-1;
				position:fixed;
				top:0px;
				left:10px;
				width:1230px;}
			

		</style>
		<script>
			function success(){
				alert('完成訂票！');
				document.Check.submit();
			}
			function cancel(){
				alert('訂票已取消');
				document.Check.submit();
			}
		</script>
	</head>
	<body background="./background.png">
		
		<nav>
            <ul class="flex-nav">
                <li><a href="home.html">首頁</a></li>
                <li><a href="movie_list.php">電影介紹</a></li>
                <li><a href="showingTime.php">場次查詢</a></li>
                <li><a href="buy.php">會員專區</a></li>
				<li><a href="login.html"><?php echo $UserName?></a></li>
            </ul>
		</nav>
		
		<br>
		<div style="border:10px; background-color:#FFAC55 solid;">			
				<h1>訂票資訊</h1>
				<br><br>
				<div class="MovieData">
					<?php
						$Total = 0;
						$PayWay = 0;
						$ShowingID = substr($RecordID, -4);
						$sqlShow = "SELECT * FROM `showing` WHERE `showingID` = '$ShowingID'";
						
						$resultShow = $connect->query($sqlShow);
						if ($resultShow->num_rows > 0) {
							
							while ($rowS = $resultShow->fetch_assoc())
							{
								$MovieID = $rowS["movieID"];

								$sqlMovieName = "SELECT `movie`, `systematics`, `length` FROM `movie` WHERE `movieID` = $MovieID" ;
								$resultMovieName = $connect->query($sqlMovieName);

								if ($resultMovieName->num_rows > 0) {
							
									while ($rowMN = $resultMovieName->fetch_assoc())
									{
										$Name = $rowMN['movie'];
										$Systematics = $rowMN["systematics"];
										echo"<table><tr>";												
										echo "<td  rowspan='4' width='500px'><img src = './$Name.jpg' width='250px';height='400px'></td>";
										echo "<td><h2>$Name <img src = './$Systematics.png' width='10%';height='0%';></h2></td></tr>";
										$Len = $rowMN["length"];
										echo "<tr><td><span class='Time'>$Len鐘</span></td></tr>";
										
									}
								}
								$Date = $rowS["day"];
								$Start = $rowS["startTime"];
								echo "<tr><td><p class='Date'>2020/1/$Date&nbsp$Start</p></tr></tr>";

								$sqlRec = "SELECT * FROM `booking record` WHERE `recordID` = '$RecordID'" ;
								$resultRec = $connect->query($sqlRec);

								if ($resultRec->num_rows > 0) {
							
									while ($rowR = $resultRec->fetch_assoc())
									{
										$Total = $rowR["number"];
										$PayWay = $rowR["paymentMethod"];
										if($PayWay == 'online')
											$PayWay = "線上支付";
										else
											$PayWay = "現場付款";
										echo "<tr><td><p class='Card'>$PayWay</p></tr></tr></table>";
									}
								}
							}
						}
					?>
				</div>
				<h1>電影票</h1>
				<br><br>
				<div class="SeatList">
					<?php
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
					?>
				</div>
				
		</div>
		
		<div class="button" >
			<div style="position:absoulte">
				<form name="Check" action="Finish.php" method="post">
					<span ><input type="submit" name="FState"class="button1" value="確定訂票"/></span>
					<span><input type="submit" name="FState" value="取消訂票"  class="button2"/></span>
				</form>
			</div>
		</div>
		<br><br>
	</body>
</html>