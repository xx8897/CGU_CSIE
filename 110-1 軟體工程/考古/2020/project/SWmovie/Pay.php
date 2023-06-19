<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>購票</title>
		<style type="text/css">
			.login_button{position:relative;
						top:110px;
						left:610px;
						z-index: 3;
						width:100px;
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
					top:200px;
					left:33%;
					width:450px; 
					height:450px;}
							
			p a	{position:relative;
				top:80px;
				left:510px;
				font-weight:bold;
				font-size:25px;
				color:black;
				text-decoration:none;
				z-index: 3;
				width:500px;
				}	
			pre {position:relative;
				top:110px;
				left:230px;
				font-size:25px;
				z-index: 3;
				width:50px;
				margin:0px;
				}
			ol p {position:relative;
				top:85px;
				left:545px;
				font-size:25px;
				z-index: 3;	
				width:500px;
			}
			
			p a:hover	{
				color:#9C9C9C;
				}
		</style>
	</head>
	<body background="./background.png">
		<nav>
            <ul class="flex-nav">
                <li><a href="home.html">首頁</a></li>
                <li><a href="movie_list.php">電影介紹</a></li>
                <li><a href="showingTime.php">場次查詢</a></li>
                <li><a href="buy.php">會員專區</a></li>
				<li><a href="login.html">登入/註冊</a></li>
            </ul>
        </nav>
		
		
        <center>
            <div style="position:relative;top:100px;width: 500px;height:300px; text-align: center; background-color:rgba(255, 255, 255, 0.5);">
            <br><br><br>
            <h3>請輸入註冊時之付款帳號</h3>
                <p style="color:black;">
                    <form action="Payment.php" method="post">
                        <input type="text" name="PayAccount" style="height: 20px;" required="required">
                        <input type="submit" value="付款" style="height: 26px;">
                    </form>
                </p>
            </div>
        </center>
    </body>
</html>