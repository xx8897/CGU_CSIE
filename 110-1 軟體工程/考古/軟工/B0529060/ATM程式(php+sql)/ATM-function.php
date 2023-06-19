<?php

function page_strat(){
	header("refresh:3;url={$_SERVER['PHP_SELF']}?op=home_page");
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
	  <link rel='stylesheet' href='css/style.css'>
	  <link rel='stylesheet' type='text/css' href='https://cdnjs.cloudflare.com/ajax/libs/animate.css/3.5.2/animate.min.css'/>
	</head>
	<body>
	  <div>
	  <h1>歡迎光臨</h1>
	  <h1>郵局ATM服務系統</h1><br>
	  <h3>LOOKING FORWARD TO BEING</h3>
	  <h3>AT YOUR SERVICE AGAIN</h3>
	  </div>
	  <div>
		<img class='animated  fadeInDown' src='https://i.postimg.cc/NGpSqnW8/012-bank.png'>
	  </div>
	</body>
	</html>";
	return $main;
}
function home_page(){
	
	global $link;
	$money100=1;
	$main="
	<!DOCTYPE html>
	<html lang='en' >

		<head>
		  <meta charset='UTF-8'>
		  <title>A Pen by  Jamie Su</title>
			<meta name='viewport' content='width=device-width, initial-scale=1'>
			<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
			<link rel='stylesheet' href='css/style_login.css'>
		</head>

		<body>
		  <header>
			<div class='note'>
			  <h3>請輸入帳戶名稱和金融密碼</h3>
			  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>";
			  if($money100==1){
			  $main.="
			  <h3 style='color:#e53935;'>*本機百元已用盡，暫不提供百元鈔</h3>
			  <h5 style='color:#e53935;'>OUT OF ONE HUNDRED NOTES</h5>";
			  }
			$main.="
			</div>
		  </header>
		  <form role='form' method='post' action='{$_SERVER['PHP_SELF']}'>
		  <main>
			<div class='list'>
				<div class='left'>
						<h2>金融帳戶登入</h2>
						<img src='https://i.postimg.cc/VkntQkhG/024-owner.png'>
				</div>
				<div class='right'>
					 <label><h2>帳號:</h2><input type='text' name='user_account' maxlength='10'></label><br>
					 <label><h2>密碼:</h2><input type='password' name='user_password' maxlength='10'></label><br>
			   </div>
			</div>
		  </main>
		  <footer>
		  <input type='hidden' name='op' value='check'>
		  <div></div>
				<!--<a class='items' href='#'>
					<p>1.&nbsp;&nbsp;&nbsp;返回</p>
				</a>-->
				<button type='submit' class='items'>
					<p>2.&nbsp;&nbsp;&nbsp;登入</p>
				</button>
		  </footer>
		  </form>
		</body>
	</html>";
	return $main;
}
function check(){
	global $link;
	$sql3="select * from `user_ac_pw` where user_account='{$_POST['user_account']}' and user_password='{$_POST['user_password']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."檢索資料失敗");
	$num=mysqli_num_rows($result);
	if($num==0)
	{
		return wrong2();
	}
	else
	{
		
		$_SESSION['user_account']=$_POST['user_account'];
		return function_menu();
		
	}
}

function stage_step($stage){
	switch($stage){
		case 1:  //取款 1,3
			return take_money_menu();
			break;
		case 2:  //查餘額 2,4
			return waiting_page($stage);
			break;
		case 3:  //取款的money take 等待畫面
		    return waiting_take();
			break;
		case 4:  //查餘額直接連receipt
			return select_receipt();
			break;
		case 5: //轉帳功能 5
			return waiting_page($stage);
			break;
		case 6: //轉帳功能 5
			return waiting_receipt_makeforT();
		break;
		case 7: //轉帳功能 5
			return logout_account();
		break;
		case 8: //轉帳功能 5
			return waiting_page(3);
		break;
		case 9: //變更密碼
			return waiting_page(1);
		break;
		
		case 10: //帳戶登出
			return logout_account();
		break;
		
		case 11: //帳戶登出
			return logout_account();
		break;
	
	}
	
}
function function_menu(){
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>服務項目</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
	    <link rel='stylesheet' href='css/style_menu.css'>
	</head>

	<body>
	  <header>
		<div class='note'>
		  <h3>請選擇服務項目</h3>
		  <h5>PLEASE SELECT A TRANSACTION</h5>
		  <h3>請觸碰螢幕選單或下方數字鍵</h3>
		  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
		</div>
	  </header>
	  <main>
		<div class='line-one'>
			<a href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=1'>
				<div class='items one'>
				  <div class='icon-wrapper'>
					<img class='imgo' src='https://i.postimg.cc/jj5j0hY3/022-cash.png'>
				  </div>
				  <div class='project-name'>
					<p>1.存簿提款</p>
				  </div>
				</div>
			</a>
			<a href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=2'>
				<div class='items two'>
				  <div class='icon-wrapper'>
					<img class='imgo' src='https://i.postimg.cc/fWgSjNbF/006-check.png'>
				  </div>
				  <div class='project-name'>
					<p>2.存簿餘額查詢</p>
				  </div>
				</div>
			</a>
			<a href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=5'>
				<div class='items two'>
				  <div class='icon-wrapper'>
					<img class='imgo' src='https://i.postimg.cc/9Xp0JjQV/023-money-bag.png'>
				  </div>
				  <div class='project-name'>
					<p>3.存簿轉帳</p>
				  </div>
				</div>
			</a>
		</div>
		<div class='line-one'>
			<a href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=8'>
				<div class='items one'>
				  <div class='icon-wrapper'>
					<img class='imgo' src='https://i.postimg.cc/ZRYtqXtF/012-discussion.png'>
				  </div>
				  <div class='project-name'>
					<p>4.跨行轉帳</p>
				  </div>
				</div>
			</a>
			<a href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=9'>
				<div class='items two'>
				  <div class='icon-wrapper'>
					<img class='imgo' src='https://i.postimg.cc/7ZDpXbmY/investment.png'>
				  </div>
				  <div class='project-name'>
					<p>5.晶片密碼變更</p>
				  </div>
				</div>
			</a>
			<a href='{$_SERVER['PHP_SELF']}?op=menu2'>
				<div class='items two'>
				  <div class='icon-wrapper'>
					<img class='next' src='https://i.postimg.cc/WtRtx0ty/right-arrow.png'>
				  </div>
				  <div class='project-name'>
					<p><br>6.下一頁</p>
				  </div>
				</div>
			</a>
		</div>
	  </main>
	</body>
	</html>
	";
	return $main;
	
}
function function_menu2(){
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
	    <link rel='stylesheet' href='css/style_menu.css'>
	</head>
	<body>
	  <header>
		<div class='note'>
		  <h3>請選擇服務項目</h3>
		  <h5>PLEASE SELECT A TRANSACTION</h5>
		  <h3>請觸碰螢幕選單或下方數字鍵</h3>
		  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
		</div>
	  </header>
	  <main>
		<div class='line-one'>
			<a href=''>
				<div class='items one'>
				  <div class='icon-wrapper'>
					<img class='imgo' src='https://i.postimg.cc/k5j6KX5w/018-account.png'>
				  </div>
				  <div class='project-name'>
					<p>7.勞保和勞退資料查詢</p>
				  </div>
				</div>
			</a>
			<a href='{$_SERVER['PHP_SELF']}?op=end_page'>
				<div class='items two'>
				  <div class='icon-wrapper'>
					<img class='imgo' src='https://i.postimg.cc/NGpSqnW8/012-bank.png'>
				  </div>
				  <div class='project-name'>
					<p>8.結束交易</p>
				  </div>
				</div>
			</a>
			<a href='{$_SERVER['PHP_SELF']}?op=menu'>
				<div class='items two'>
				  <div class='icon-wrapper'>
					<img class='next' src='https://i.postimg.cc/85Lzz1xZ/left-arrow.png'>
				  </div>
				  <div class='project-name'>
					<p><br>9.上一頁</p>
				  </div>
				</div>
			</a>
		</div>
	  </main>
	  <embed src='https://picosong.com/wgKyw' hidden='true' autostart='true' loop='flase'></embed>
	</body>
	</html>
	";
	return $main;
}
function check_account_money(){
	global $link;
	$sql3="select `account_money` from `user_ac_money` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."檢索資料失敗");
	
	$row = $result->fetch_assoc();
    
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
		<link rel='stylesheet' href='css/style_check.css'>
	</head>
	<body>
	  <header>
		<div class='note'>
		  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
		  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
		</div>
	  </header>
	  <main>
		<table>
			<thead>
				<tr>
					<th class='three' colspan='2'><h2>本次交易明細</h2></th>
				 </tr>
			</thead>
			<tbody>
				 <tr>
					<th class='one'>
						<h3>交易金額</h3>
					  <h5>TX AMT.</h5>
					</th> 
					<th class='two'></th>
				 </tr>
				 <tr>
					<th class='one'>
						<h3>交易序號</h3>
					   <h5>TX NO.</h5>
					</th> 
					<th class='two'>9990</th>
				 </tr>
				 <tr>
					<th class='one'>
						<h3>可用餘額</h3>
					   <h5>AVAILABLE BALANCE</h5>
					</th> 
					<th class='two'>$$row[account_money]</th>
				 </tr>
				 <tr>
					<th class='one'>
						<h3>訊息代號</h3>
					   <h5>MSG CODE</h5>
					</th> 
					<th class='two'></th>
				 </tr>
				 <tr>
					<th class='one'>
						<h3>手續費</h3>
					   <h5>FEE</h5>
					</th> 
					<th class='two'>$0</th>
				 </tr>
		   </tbody>
		</table>
	  </main>
	  <footer>
			<div>
			</div>
			<a class='items' href='{$_SERVER['PHP_SELF']}?op=select_receipt'>
				<p>1.&nbsp;&nbsp;&nbsp;結束</p>
			</a>
	  </footer>
	</body>
	</html>";
	//money 1,000 need to do
	return $main;
	
}


function take_money_menu(){
	
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
		<head>
		  <meta charset='UTF-8'>
		  <title>A Pen by  Jamie Su</title>
			<meta name='viewport' content='width=device-width, initial-scale=1'>
			<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
			<link rel='stylesheet' href='css/style_menu_m.css'>
		</head>
		<body>
		  
		  <header>
			<div class='note'>
			  <h3>請選擇定額提款鍵</h3>
			  <h5>PLEASE SELECT WITHDRAWAL AMOUNT</h5>
			  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
			  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
			</div>
		  </header>
		  <main>
			<div class='line-one'>
				<a class='items one' href='{$_SERVER['PHP_SELF']}?op=take_money_page'>
					<p>1.&nbsp;&nbsp;&nbsp;其他金額</p>
				</a>
				<a class='items two' href='{$_SERVER['PHP_SELF']}?op=take_money&S=1000'>
					<p>2.&nbsp;&nbsp;&nbsp;NT$1000</p>
				</a>
				<a class='items two' href='{$_SERVER['PHP_SELF']}?op=take_money&S=3000'>
					<p>3.&nbsp;&nbsp;&nbsp;NT$3000</p>
				</a>
				<a class='items two' href='{$_SERVER['PHP_SELF']}?op=take_money&S=5000'>
					<p>4.&nbsp;&nbsp;&nbsp;NT$5000</p>
				</a>
			</div>
			<div class='line-two'>
				<a class='items one' href='{$_SERVER['PHP_SELF']}?op=take_money&S=10000'>
					<p>5.&nbsp;&nbsp;&nbsp;NT$10,000</p>
				</a>
				<a class='items two' href='{$_SERVER['PHP_SELF']}?op=take_money&S=20000'>
					<p>6.&nbsp;&nbsp;&nbsp;NT$20,000</p>
				</a>
				<a class='items two' href='{$_SERVER['PHP_SELF']}?op=take_money&S=40000'>
					<p>7.&nbsp;&nbsp;&nbsp;NT$40,000</p>
				</a>
				<a class='items two' href='{$_SERVER['PHP_SELF']}?op=take_money&S=60000'>
					<p>8.&nbsp;&nbsp;&nbsp;NT$60,000</p>
				</a>
			</div>
		  </main>
		  <!--<embed src='https://picosong.com/wgKyw' hidden='true' autostart='true' loop='flase'></embed>-->
		</body>
		
	</html>
	";
	
	return $main;
	
}
function take_money_page(){
	global $link;
	$sql3="select `account_money` from `user_ac_money` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."檢索資料失敗");
	
	$row = $result->fetch_assoc();
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
		<link rel='stylesheet' href='css/style_takem.css'>
	</head>

	<body>

	  <header>
		<div class='note'>
		  <h3>請輸入提款金額，輸入完請按下方確定鍵</h3>
		  <h5>PLEASE ENTER WITHDRAW AMOUNT THEN PRESS ACCEPT KEY</h5>
		</div>
	  </header>
	  <form role='form' method='post' action='{$_SERVER['PHP_SELF']}'>
	  <main>
		<div class='my-form'>
			<div class='title'>
			<h2>存簿提款服務</h2>
			</div>
		  <div class='cointer'>
			<label><h4>輸入提款金額</h4><br><input type='number' name='account_money' max='60000'></label><br>
		  </div>
		  <div class='last'>
			<h3 style='color:#d32f2f'>提款請以100元為單位</h3>
			<h3 style='color:#d32f2f'>*每次限額: NT$&nbsp;&nbsp;6萬元</h3>
			<h3 style='color:#d32f2f'>*每日限額: NT$15萬元</h3>
		  </div>
		</div>
	  </main>
	  <footer>
			<a class='items' href='{$_SERVER['PHP_SELF']}?op=logout_account'>
				<p>1.&nbsp;&nbsp;&nbsp;取消提款</p>
			</a>
			<input type='hidden' name='op' value='take_money'>
			<input type='hidden' name='S' value='0'>
			<button class='items' type='submit'>
				<p>2.&nbsp;&nbsp;&nbsp;確定提款</p>
			</button>
	  </footer>
	  </form>
	</body>

	</html>
	";
	return $main;
	
}
function take_account_money($S_money){
	    $money100=1;
		global $link;
		$sql3="select `account_money` from `user_ac_money` where user_account='{$_SESSION['user_account']}'";
		$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."123");
		$row = $result->fetch_assoc();
		$money=0;
		if($S_money!=0){
			$money=$S_money;
		}
		else{
			$money=$_POST['account_money'];
		}
		
		
		if(($money%100)==0){
			if($row['account_money']>$money){
				
				$sql="UPDATE `user_ac_money`
				SET `account_money`=`account_money`-$money
				WHERE `user_account`='{$_SESSION['user_account']}'";
				mysqli_query($link,$sql) or die_content("已經設定過此月份資料");
				if($money>=1000 && $money100==0)return next_money();
				else return waiting_ad();
			}
			else{
				$letter='，您的餘額不足';
				return wrong($letter);
			}
		}
		else{
			$letter='，金額請以一百元為單位';
			return wrong($letter);
		}
}
function next_money(){
	global $link;
	
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
		<link rel='stylesheet' href='css/style_change.css'>
	</head>

	<body>

	  <header>
		<div class='note'>
		  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
		  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
		</div>
	  </header>
	  <main>
		<div class='note-two'>
		<h2>您若需要百元鈔，請按換鈔鍵<br>否則請按大鈔鍵 </h2>
		<h4>DO YOU WANT TO CHANGE NOTES</h4>
		</div>
	  </main>
	  <footer>
		 <a class='items' href='{$_SERVER['PHP_SELF']}?op=waiting'>
			<p>1.&nbsp;&nbsp;&nbsp;大鈔</p>
		</a>
		<a class='items' href='{$_SERVER['PHP_SELF']}?op=waiting'>
			<p>2.&nbsp;&nbsp;&nbsp;換鈔100X10</p>
		</a>
	  </footer>
	</body>
	</html>
	";
	return $main;
}

function continue_page($stage){
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
		<link rel='stylesheet' href='css/style_continue.css'>
	</head>
	<body>
	  <header>
		<div class='note'>
		  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
		  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
		</div>
	  </header>
	  <main>
		<div class='note-two'>
		<h2>本交易完成後是否繼續其他交易 </h2>
		<h4>DO YOU NEED OTHER SERVICES</h4>
		</div>
	  </main>
	  <footer>";
	  if($stage==1){
		  
		  $main.="
		  <a class='items' href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=3&continue=1'>
			<p>1.&nbsp;&nbsp;&nbsp;繼續交易</p>
		  </a>
		  <a class='items' href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=10'>
			<p>2.&nbsp;&nbsp;&nbsp;結束交易</p>
		  </a>";
	  }
	  else if($stage==5 || $stage==8){
		  
		  $main.="
		  <a class='items' href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=6&continue=1'>
			<p>1.&nbsp;&nbsp;&nbsp;繼續交易</p>
		  </a>
		  <a class='items' href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=7'>
			<p>2.&nbsp;&nbsp;&nbsp;結束交易</p>
		  </a>";
	  }
	  else if($stage==9){
		  $main.="
		  <a class='items' href='{$_SERVER['PHP_SELF']}?op=menu'>
			<p>1.&nbsp;&nbsp;&nbsp;繼續交易</p>
		  </a>
		  <a class='items' href='{$_SERVER['PHP_SELF']}?op=end_page'>
			<p>2.&nbsp;&nbsp;&nbsp;結束交易</p>
		  </a>";
	  }
	  else if($stage==2){
		  $main.="
		  <a class='items' href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=4&continue=1'>
			<p>1.&nbsp;&nbsp;&nbsp;繼續交易</p>
		  </a>
		  <a class='items' href='{$_SERVER['PHP_SELF']}?op=stage_step&STAGE=11'>
			<p>2.&nbsp;&nbsp;&nbsp;結束交易</p>
		  </a>";
	  }
	$main.="
	  </footer>
	</body>
	</html>";
	
	return $main;
}
function continue_page2(){
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
		<link rel='stylesheet' href='css/style_continue.css'>
	</head>
	<body>
	  <header>
		<div class='note'>
		  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
		  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
		</div>
	  </header>
	  <main>
		<div class='note-two'>
		<h2>本交易完成後是否繼續其他交易 </h2>
		<h4>DO YOU NEED OTHER SERVICES</h4>
		</div>
	  </main>
	  <footer>
		<a class='items' href='{$_SERVER['PHP_SELF']}?op=select_receipt&continue=1'>
				<p>1.&nbsp;&nbsp;&nbsp;繼續交易</p>
			</a>
			<a class='items' href='{$_SERVER['PHP_SELF']}?op=select_receipt'>
				<p>2.&nbsp;&nbsp;&nbsp;結束交易</p>
			</a>
	  </footer>
	</body>
	</html>";
	
	return $main;
}

function select_receipt(){
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
		<link rel='stylesheet' href='css/style_selectR.css'>
	</head>
	<body>
	  <header>
		<div class='note'>
		  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
		  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
		</div>
	  </header>
	  <main>
		<div class='note-two'>
		<h2>是否需要明細表，請自行點選</h2>
		<h4>WOULD YOU LIKE A PRINTED RECEIPT?</h4>
		</div>
	  </main>
	  <footer>
			<a class='items' href='{$_SERVER['PHP_SELF']}?op=no_output_receipt'>
				<p>1.&nbsp;&nbsp;&nbsp;不列印明細表</p>
			</a>
			<a class='items' href='{$_SERVER['PHP_SELF']}?op=output_receipt'>
				<p>2.&nbsp;&nbsp;&nbsp;列印明細表</p>
			</a>
	  </footer>
	</body>
	</html>
	";
	return $main;
}
function output_receipt(){
	header("refresh:5;url={$_SERVER['PHP_SELF']}?op=take_receipt");
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en'>
	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
	  <link rel='stylesheet' href='css/style_takeR.css'>
	</head>
	<body>
	  <div>
		<h1>交易明細表列印中</h1>
	    <h1>請稍後</h1><br>
		<h3>RECEIPT PRINTING, PLEASE WAIT</h3>
	  </div>
	  <div>
		<img src='https://i.postimg.cc/nhtqzSJM/invoice.png'>
	  </div>
	</body>
	</html>
    ";
	return $main;
	
}
function no_output_receipt(){
	global $link;
	$sql3="select `account_money` from `user_ac_money` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."檢索資料失敗");
	
	$row = $result->fetch_assoc();
    
	$main="
	<!DOCTYPE html>
	<html lang='en' >

		<head>
		  <meta charset='UTF-8'>
		  <title>A Pen by  Jamie Su</title>
			<meta name='viewport' content='width=device-width, initial-scale=1'>
			<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
			<link rel='stylesheet' href='css/style_transferL.css'>
		</head>

		<body>
		  <header>
			<div class='note'>
			  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
			  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
			</div>
		  </header>
		  <main>
			<div class='list'>
				<div class='left'>
						<h2>本次交易明細</h2>
						<img src='https://i.postimg.cc/d3jQqyGt/approval.png'>
				</div>
				<div class='right'>
					 <div class='item'>
						<div>
						  <h3>交易金額</h3>
						  <h5>TX AMT.</h5>
						</div>
						<div ></div>
					</div>
					<div class='item o'>
						<div>
						   <h3>交易序號</h3>
						   <h5>TX NO.</h5>
						</div> 
						<div >No.153</div>
					 </div>
					 <div class='item o'>
						<div>
							<h3>可用餘額</h3>
						   <h5>AVAILABLE BALANCE</h5>
						</div> 
						<div >$$row[account_money]</div>
					 </div>
					 <div class='item o'>
						<div>
							<h3>訊息代號</h3>
						   <h5>MSG CODE</h5>
						</div> 
						<div ></div>
					 </div>
					 <div class='item o'>
						<div>
							<h3>手續費</h3>
						   <h5>FEE</h5>
						</div> 
						<div >$0</div>
					 </div>
			   </div>
			</div>
		  </main>
		  <footer>
				 <div>
				</div>
				<a class='items' href='{$_SERVER['PHP_SELF']}?op=select_end2'>
					<p>1.&nbsp;&nbsp;&nbsp;結束</p>
				</a>
		  </footer>
		</body>
	</html>";
	//money 1,000 need to do
	return $main;
}
function take_receipt(){
	
	if($_SESSION['contiune'] == 0) header("refresh:3;url={$_SERVER['PHP_SELF']}?op=home_page");
	else header("refresh:3;url={$_SERVER['PHP_SELF']}?op=select_end");
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en'>
	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
	  <link rel='stylesheet' href='css/style_takeR.css'>
	</head>
	<body>
	  <div>
		<h1>請取回交易明細表</h1>";
		if($_SESSION['contiune'] == 0){
			
			$main.="<h1>謝謝您的惠顧</h1><br>";
		}
		$main.="
		<h3>PLEASE TAKE YOUR RECEIPT<br>
		THANK YOU</h3>
	  </div>
	  <div>
		<img src='https://i.postimg.cc/L4fDv1Nd/bill.png'>
	  </div>
	</body>
	</html>
	";
	return $main;
}
function logout_account(){
	if($_SESSION['stage']==1 || $_SESSION['stage']==5 || $_SESSION['stage']==8 ||  $_SESSION['stage']==9){
		$_SESSION['user_account']="";
		header("refresh:3;url={$_SERVER['PHP_SELF']}");
	}
	else if($_SESSION['stage']==10){
		header("refresh:5;url={$_SERVER['PHP_SELF']}?op=waiting_take");
	}
    else if($_SESSION['stage']==11){
		header("refresh:5;url={$_SERVER['PHP_SELF']}?op=select_receipt");
	} 	
	else header("refresh:5;url={$_SERVER['PHP_SELF']}?op=waiting_receipt_makeforT");
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
		<head>
			<meta charset='UTF-8'>
			<title>A Pen by  Jamie Su</title>
			<link rel='stylesheet' href='css/style_takeW.css'>
		</head>
		<body>
			<div>";
			if($_SESSION['stage']==1 || $_SESSION['stage']==5 || $_SESSION['stage']==8 || $_SESSION['stage']==9){
			    $main.="<h1>本次交易已取消</h1>
				<h1>登出您的帳戶中，請稍後</h1><br>
				<h3>PROCESSING HAS BEEN CANCELLED</h3>
				<h3>PROCESSING LOGOUT YOUR ACCOUNT
				<br>PLEASE WAIT</h3>";
				}
				else{
				$main.="
				<h1>登出您的帳戶中</h1>
				<h1>請稍後</h1><br>
				<h3>PROCESSING LOGOUT YOUR ACCOUNT
				<br>PLEASE WAIT</h3>";
				}
			$main.="</div>
			<div>
				<img src='https://i.postimg.cc/J4KPb9Yn/exit.png'>
			</div>  
		</body>
	</html>
	";
	return $main;
}
function end_page(){
	$_SESSION['user_account']="";
	header("refresh:3;url={$_SERVER['PHP_SELF']}?op=home_page");
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
	  <link rel='stylesheet' href='css/style_takeR.css'>
	</head>
	<body>
	  <div>
	  <h1>謝謝您的惠顧，歡迎再次光臨</h1>
	  <h1>請稍後再登入</h1><br>
	  <h3>LOOKING FORWARD TO BEING</h3>
	  <h3>AT YOUR SERVICE AGAIN</h3>
	  </div>
	  <div>
		<img src='https://i.postimg.cc/NGpSqnW8/012-bank.png'>
	  </div>
	</body>
	</html>
	";
	return $main;
}

function waiting_receipt_makeforT(){
	header("refresh:5;url={$_SERVER['PHP_SELF']}?op=take_receipt");
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
		<head>
		  <meta charset='UTF-8'>
		  <title>A Pen by  Jamie Su</title>
		  <link rel='stylesheet' href='css/style_takeR.css'>
		</head>

		<body>
		  <div>
			<h2>交易明細表列印中，請稍後</h2>
			<h5>RECEIPT PRINTING, PLEASE WAIT</h5>
			<br>
			<h2 style='color:#d32f2f'>交易明細表為轉帳憑證</h2>
			<h2 style='color:#d32f2f'>請務必妥善收存</h2>
			<h5 style='color:#d32f2f'>Transaction receipt is certificate of account transfer,</h5>
			<h5 style='color:#d32f2f'>please keep it carefully.</h5>
		  </div>
		  <div>
			<img src='https://i.postimg.cc/nhtqzSJM/invoice.png'>
		  </div>
		</body>
	</html>
    ";
	return $main;
}

function transfer_money(){  //操作畫面 轉帳金額輸入
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
		<link rel='stylesheet' href='css/style_transferM.css'>
	</head>
	<body>
	  <header>
		<div class='note'>
		  <h3>請輸入轉帳帳號和轉帳金額</h3>
		  <h5>PLEASE ENTER TRANSFEREE ACCOUNT AND AMOUNT</h5>
		  <h3>輸入完請按下方確定鍵</h3>
		  <h5>PLEASE ACCEPT KEY WHEN FINISHED</h5>
		</div>
	  </header>
	  <form role='form' method='post' action='{$_SERVER['PHP_SELF']}'>
	  <main>
		<div class='my-form'>
			<div class='title'>
			<h2>存簿轉帳服務</h2>
			</div>
		  <div class='cointer'>
			<label>輸入帳號名稱:&nbsp;&nbsp;&nbsp;&nbsp;<input type='text' name='user_account'></label>
			<label class='two'>輸入轉帳金額:&nbsp;&nbsp;&nbsp;&nbsp;<input type='number' name='account_money'></label><br>
		  </div>
		</div>
	  </main>
	  <footer>
			<a class='items' href='{$_SERVER["PHP_SELF"]}?op=logout_account'>
				<p>1.&nbsp;&nbsp;&nbsp;取消</p>
		    </a>
			<input type='hidden' name='op' value='give_money'>
			<button type='submit' class='items'>
				<p>1.&nbsp;&nbsp;&nbsp;確定</p>
			</button>
	  </footer>
	  </form>
	</body>
	</html>
	";
	return $main;
}
function transfer_money2(){
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
		<link rel='stylesheet' href='css/style_transfer2.css'>
	</head>
	<body>
	  <header>
		<div class='note'>
		  <h3>請輸入銀行代號、轉帳帳號和轉帳金額</h3>
		  <h5>PLEASE ENTER BANK ID, TRANSFEREE ACCOUNT AND AMOUNT</h5>
		  <h3>輸入完請按下方確定鍵</h3>
		  <h5>PLEASE ACCEPT KEY WHEN FINISHED</h5>
		</div>
	  </header>
	  <form role='form' method='post' action='{$_SERVER['PHP_SELF']}'>
	  <main>
		<div class='my-form'>
			<div class='title'>
			<h2>跨行存簿轉帳服務</h2>
			</div>
		  <div class='cointer'>
			<label>轉入銀行代號:&nbsp;&nbsp;&nbsp;&nbsp;<input type='text' name='bank_number'></label>
			<label class='two'>轉入帳號名稱:&nbsp;&nbsp;&nbsp;&nbsp;<input type='text' name='user_account'></label>
			<label class='two'>轉入轉帳金額:&nbsp;&nbsp;&nbsp;&nbsp;<input type='number' name='account_money'></label><br>
		  </div>
		  <div class='f2'>
			 <div></div>
			 <a href='{$_SERVER['PHP_SELF']}?op=inquire_bankID'>銀行代號查詢</a>
		  </div>
		</div>
	  </main>
	  <footer>
			<a class='items' href='{$_SERVER["PHP_SELF"]}?op=logout_account'>
				<p>1.&nbsp;&nbsp;&nbsp;取消</p>
		    </a>
			<input type='hidden' name='op' value='registe_transfer_money2'>
			<button class='items'>
				<p>2.&nbsp;&nbsp;&nbsp;確定</p>
			</button>
	  </footer>
	  </form>
	</body>
	</html>";
	return $main;
}
function inquire_bankID(){
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en'>

		<head>
		  <meta charset='UTF-8'>
		  <title>A Pen by  Jamie Su</title>
			<meta name='viewport' content='width=device-width, initial-scale=1'>
			<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
			<link rel='stylesheet' href='css/style_bankID.css'>
		</head>

		<body>
		  <header>
			<div class='note'>
			  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
			  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
			  <h3>查詢銀行代號</h3>
			  <h5>INQUIRY BANK ID</h5>
			</div>
		  </header>
		  <main>
		  <div class='cc'>
			  <div class='title'>
			  <p>銀行代碼表</p>
			  </div>
			<div class='list'>
				<div class='left'>
					<div class='item a'>
						<h3>001</h3>
						<h3>中央信託</h3>
					</div>
					<div class='item a'>
						<h3>004</h3>
						<h3>台灣銀行</h3>
					</div>
					<div class='item a'>
						<h3>006</h3>
						<h3>合庫商銀</h3>
					</div>
					<div class='item a'>
						<h3>008</h3>
						<h3>華南銀行</h3>
					</div>
					<div class='item a'>
						<h3>012</h3>
						<h3>台北富邦</h3>
					</div>
					<div class='item a'>
						<h3>016</h3>
						<h3>高雄銀行</h3>
					</div>
					<div class='item a'>
						<h3>018</h3>
						<h3>農業金庫</h3>
					</div>
					<div class='item a'>
						<h3>050</h3>
						<h3>臺灣企銀</h3>
					</div>
					<div class='item a'>
						<h3>052</h3>
						<h3>新竹商銀</h3>
					</div>
					<div class='item a'>
						<h3>053</h3>
						<h3>台中商銀 </h3>
					</div>
					<div class='item a'>
						<h3>075</h3>
						<h3>東亞銀行</h3>
					</div>
					<div class='item a'>
						<h3>804</h3>
						<h3>中華銀行</h3>
					</div>
					<div class='item a'>
						<h3>808</h3>
						<h3>玉山銀行</h3>
					</div>
				</div>
				<div class='right'>
					 <div class='item a'>
						<h3>003</h3>
						<h3>交通銀行</h3>
					</div>
					<div class='item a'>
						<h3>005</h3>
						<h3>土地銀行</h3>
					</div>
					<div class='item a'>
						<h3>007</h3>
						<h3>第一銀行</h3>
					</div>
					<div class='item a'>
						<h3>009</h3>
						<h3>彰化銀行</h3>
					</div>
					<div class='item a'>
						<h3>011</h3>
						<h3>上海銀行</h3>
					</div>
					<div class='item a'>
						<h3>013</h3>
						<h3>國泰世華</h3>
					</div>
					<div class='item a'>
						<h3>017</h3>
						<h3>兆豐商銀</h3>
					</div>
					<div class='item a'>
						<h3>021</h3>
						<h3>花旗銀行</h3>
					</div>
					<div class='item a'>
						<h3>025</h3>
						<h3>首都銀行</h3>
					</div>
					<div class='item a'>
						<h3>052</h3>
						<h3>渣打銀行</h3>
					</div>
					<div class='item a'>
						<h3>803</h3>
						<h3>聯邦銀行</h3>
					</div>
					<div class='item a'>
						<h3>812</h3>
						<h3>台新銀行</h3>
					</div>
					<div class='item a'>
						<h3>822</h3>
						<h3>中國信託</h3>
					</div>
				</div>
					
			   </div>
			</div>
		  </div>
		  </main>
		  <footer>
				<a class='items' href='{$_SERVER['PHP_SELF']}?op=transfer_money2'>
					<p>1.&nbsp;&nbsp;&nbsp;返回</p>
				</a>
				<a style='display:none;'class='items' href='#'>
				</a>
		  </footer>
		</body>
	</html>";
	
	
	return $main;
}
function confirm_transfer(){  //確認畫面 是否轉帳 第一次
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
	    <link rel='stylesheet' href='css/style_confirmT.css'>
	</head> 
	<body> 
	  <header>
		<div class='note'>
		  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
		  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
		</div>
	  </header>
	  <main>
		<div class='note-two'>
		<h2>請慎防轉帳受騙</h2>   
		<h2>*請勿聽信他人指示操作</h2>  
		<h2>*您選則的是轉帳交易，</h2>  
		<h2>會從您的帳戶內扣款給他人。</h2><br>  
		<h2 style='color:#d32f2f'>您確定要轉帳嗎?</h2>
		<br>
		<h4>Please be cautious to deceit of account transfer.</h4>
		<h4>*Please don't operate ATM under instructions of others.</h4>
		<h4>*If you choose account transfer,</h4>
		<h4>your money will be transferred to others account.</h4><br>
		<h3 style='color:#d32f2f'>Are you sure you want to transfer?</h3>
		</div>
	  </main>
	  <footer>";
	if($_SESSION['stage']==5){
		$main.="
		<a class='items' href='{$_SERVER["PHP_SELF"]}?op=logout_account'>
			<p>1.&nbsp;&nbsp;&nbsp;取消交易</p>
		</a>
		<a class='items' href='{$_SERVER["PHP_SELF"]}?op=transfer_money'>
			<p>2.&nbsp;&nbsp;&nbsp;繼續交易</p>
		</a>";
	}else{
		$main.="
		<a class='items' href='{$_SERVER["PHP_SELF"]}?op=logout_account'>
			<p>1.&nbsp;&nbsp;&nbsp;取消交易</p>
		</a>
		<a class='items' href='{$_SERVER["PHP_SELF"]}?op=transfer_money2'>
			<p>2.&nbsp;&nbsp;&nbsp;繼續交易</p>
		</a>";
	} 
	
	$main.="
	</footer>
	</body> 
	</html>
	";
	return $main;
}
function confirm_transfer_list(){  //確認畫面 轉帳清單確認
	global $link;
	$sql3="select * from `confirm_transfer_money` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."123");
	$row = $result->fetch_assoc();
	
	$main="
	<!DOCTYPE html>
	<html lang=en >

		<head>
		  <meta charset=UTF-8>
		  <title>A Pen by  Jamie Su</title>
			<meta name='viewport' content='width=device-width, initial-scale=1'>
			<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
			<link rel=stylesheet href=css/style_transferL.css>
		</head>

		<body>
		  <header>
			<div class=note>
			  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
			  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
			  <h3>請核對轉入單位/轉入帳號/轉帳金額</h3>
			  <h5>PLEASE CHECK THE FOLLOWING DATA</h5>
			</div>
		  </header>
		  <main>
			<div class=list>
				<div class=left>
						<h2>轉帳交易明細</h2>
						<img src=https://i.postimg.cc/d3jQqyGt/approval.png>
				</div>
				<div class=right>
					 <div class=item>
						<div>
						  <h3>轉出單位</h3>
						  <h5>TRANSFEROR BANK ID</h5>
						</div>
						<div >700(郵局)</div>
					</div>
					<div class=item o>
						<div>
						   <h3>轉出帳號</h3>
						   <h5>divANSFEROR ACCOUNT</h5>
						</div> 
						<div>$row[user_account]</div>
					 </div>
					 <div class=item o>
						<div>
							<h3>轉入單位</h3>
						   <h5>divANSFEREE BANK ID</h5>
						</div> 
						<div >700(郵局)</div>
					 </div>
					 <div class=item o>
						<div>
							<h3>轉入帳號</h3>
						   <h5>divANSFEREE ACCOUNT</h5>
						</div> 
						<div>$row[transfer_account]</div>
					 </div>
					 <div class=item o>
						<div>
							<h3>轉帳金額</h3>
						   <h5>divANSFER AMOUNT</h5>
						</div> 
						<div>$$row[transfer_money]</div>
					 </div>
			   </div>
			</div>
		  </main>
		  <footer>
				<a class=items href='{$_SERVER["PHP_SELF"]}?op=delete_registe'>
					<p>1.&nbsp;&nbsp;&nbsp;取消轉帳</p>
				</a>
				<a class=items href='{$_SERVER['PHP_SELF']}?op=confirm_transfer_last'>
					<p>1.&nbsp;&nbsp;&nbsp;確認轉帳</p>
				</a>
		  </footer>
		</body>
	</html>
	";
	return $main;
}
function confirm_transfer_list2(){
	global $link;
	$sql3="select * from `confirm_transfer_money2` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."123");
	$row = $result->fetch_assoc();
	
	$sql4="select * from `atm_bank_number` where bank_number=$row[bank_number]";
	$result=mysqli_query($link,$sql4)or die_content(mysql_error($link)."123");
	$bank = $result->fetch_assoc();
	
	$main="
	<!DOCTYPE html>
	<html lang='en'>

		<head>
		  <meta charset='UTF-8'>
		  <title>A Pen by  Jamie Su</title>
			<meta name='viewport' content='width=device-width, initial-scale=1'>
			<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
			<link rel='stylesheet' href='css/style_transferL.css'>
		</head>

		<body>
		  <header>
			<div class='note'>
			  <h3>請觸碰螢幕選單或下方數字鍵盤</h3>
			  <h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
			  <h3>請核對轉入單位/轉入帳號/轉帳金額</h3>
			  <h5>PLEASE CHECK THE FOLLOWING DATA</h5>
			</div>
		  </header>
		  <main>
			<div class='list'>
				<div class='left'>
						<h2>跨行轉帳交易明細</h2>
						<img src='https://i.postimg.cc/d3jQqyGt/approval.png'>
				</div>
				<div class='right'>
					 <div class='item'>
						<div>
						  <h3>轉出單位</h3>
						  <h5>TRANSFEROR BANK ID</h5>
						</div>
						<div>700(郵局)</div>
					</div>
					<div class='item o'>
						<div>
						   <h3>轉出帳號</h3>
						   <h5>divANSFEROR ACCOUNT</h5>
						</div> 
						<div>$row[user_account]</div>
					 </div>
					 <div class='item o'>
						<div>
							<h3>轉入單位</h3>
						   <h5>divANSFEREE BANK ID</h5>
						</div> 
						<div>$row[bank_number]($bank[bank_name])</div>
					 </div>
					 <div class='item o'>
						<div>
							<h3>轉入帳號</h3>
						   <h5>divANSFEREE ACCOUNT</h5>
						</div> 
						<div>$row[transfer_account]</div>
					 </div>
					 <div class='item o'>
						<div>
							<h3>轉帳金額</h3>
						   <h5>divANSFER AMOUNT</h5>
						</div> 
						<div>$$row[transfer_money]</div>
					 </div>
			   </div>
			</div>
		  </main>
		  <footer>
				<a class='items' href='{$_SERVER["PHP_SELF"]}?op=delete_registe2'>
					<p>1.&nbsp;&nbsp;&nbsp;取消轉帳</p>
				</a>
				<a class='items' href='{$_SERVER['PHP_SELF']}?op=confirm_transfer_last'>
					<p>2.&nbsp;&nbsp;&nbsp;確認轉帳</p>
				</a>
		  </footer>
		</body>
	</html>
	";
	return $main;
	
}
function confirm_transfer_last(){  //確認畫面 最終確認 第二次也是最後一次
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
		<head>
			<meta charset='UTF-8'>
			<title>A Pen by  Jamie Su</title>
			<meta name='viewport' content='width=device-width, initial-scale=1'>
			<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
			<link rel='stylesheet' href='css/style_transferLA.css'>
		</head>
		<body>
			<header>
			<div class='note'>
				<h3>請觸碰螢幕選單或下方數字鍵盤</h3>
				<h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
			</div>
			</header>
				<main>
					<div class='note-two'>
					<h2 style='color:#d32f2f'>注意!</h2>   
					<h2 style='color:#d32f2f'>您的錢即將轉入別人帳戶，</h2>  
					<h2 style='color:#d32f2f'>確定要轉帳嗎?</h2>
					<br>
					<h4 style='color:#d32f2f'>ATENTION!</h4>
					<h4 style='color:#d32f2f'>Your money will be tranferred to others account,</h4>
					<h4 style='color:#d32f2f'>are you sure you want to transfer?</h4>
				</div>
				</main>
			<footer>";
			if($_SESSION['stage']==5){
				$main.="
					<a class='items' href='{$_SERVER["PHP_SELF"]}?op=delete_registe'>
						<p>1.&nbsp;&nbsp;&nbsp;取消轉帳</p>
					</a>
					<a class='items' href='{$_SERVER['PHP_SELF']}?op=do_transfer'>
						<p>2.&nbsp;&nbsp;&nbsp;繼續轉帳</p>
					</a>";
			}
		    else{
				$main.="
				<a class='items' href='{$_SERVER["PHP_SELF"]}?op=delete_registe2'>
					<p>1.&nbsp;&nbsp;&nbsp;取消轉帳</p>
				</a>
				<a class='items' href='{$_SERVER['PHP_SELF']}?op=do_transfer2'>
					<p>2.&nbsp;&nbsp;&nbsp;繼續轉帳</p>
				</a>";
			}
			
	$main.="
			</footer>
		</body>
	</html>";
	
	return $main;
}


function change_password(){
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
		<link rel='stylesheet' href='css/style_changeP.css'>
	</head>
	<body>
	  <header>
		<div class='note'>
		  <h3>請輸入帳號名稱、舊的密碼和新的密碼</h3>
		  <h5>PLEASE ENTER ACCOUNT, OLD PASSWORD AND NEW PASSWORD</h5>
		  <h3>輸入完請按下方確定鍵</h3>
		  <h5>PLEASE ACCEPT KEY WHEN FINISHED</h5>
		</div>
	  </header>
	  <form role='form' method='post' action='{$_SERVER['PHP_SELF']}'>
	  <main>
		<div class='my-form'>
			<div class='title'>
			<h2>帳戶密碼修改</h2>
			</div>
		  <div class='cointer'>
			<label>輸入舊的密碼:&nbsp;&nbsp;&nbsp;&nbsp;<input type='password' name='user_old'></label>
			<label class='two'>輸入新的密碼:&nbsp;&nbsp;&nbsp;&nbsp;<input type='password' name='user_new'></label>
			<label class='two'>重復新的密碼:&nbsp;&nbsp;&nbsp;&nbsp;<input type='password' name='user_confirm_new'></label><br>
		  </div>
		  <!--<div class='f2'>
			 <div></div>
			 <a href='#'></a>
		  </div>
		</div>-->
	  </main>
	  <footer>
			<a class='items' href='{$_SERVER["PHP_SELF"]}?op=logout_account'>
				<p>1.&nbsp;&nbsp;&nbsp;取消</p>
		    </a>
			<input type='hidden' name='op' value='registe_password'>
			<button class='items'>
				<p>1.&nbsp;&nbsp;&nbsp;確定</p>
			</button>
	  </footer>
	  </form>
	</body>
	</html>";
	return $main;
	
}

//等待畫面區 strat

function waiting_take(){  //等待畫面 收取現金
	header("refresh:5;url={$_SERVER['PHP_SELF']}?op=select_receipt");
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		  <link rel='stylesheet' href='css/style_takeW.css'>
	</head>
	<body>
	  <div>
		<h1>請收取現金</h1>
		<h1>並妥善保管</h1><br>
		<h3>PLEASE TAKE YOUR CASH</h3>
	  </div>
	  <div>
		<img src='https://i.postimg.cc/jj5j0hY3/022-cash.png'>
	  </div>  
	</body>
	</html>
	";
	return $main;
}
function waiting_page($STAGE){  //等待畫面 交易處理中，請稍後 無廣告
	global $link;
	if($STAGE==2) header("refresh:3;url={$_SERVER['PHP_SELF']}?op=continue"); //2 查詢餘額
	else if($STAGE==5)header("refresh:3;url={$_SERVER['PHP_SELF']}?op=confirm_transfer");//5 轉帳
	else if($STAGE==6)header("refresh:3;url={$_SERVER['PHP_SELF']}?op=confirm_transfer_list");//6 轉帳金額輸入完畢 跳確認畫面
	else if($STAGE==7)header("refresh:3;url={$_SERVER['PHP_SELF']}?op=continue");//7 轉帳結束 跳至是否繼續交易
	else if($STAGE==3)header("refresh:3;url={$_SERVER['PHP_SELF']}?op=confirm_transfer");//8 跨行轉帳
	else if($STAGE==4)header("refresh:3;url={$_SERVER['PHP_SELF']}?op=confirm_transfer_list2");//6 轉帳金額輸入完畢 跳確認畫面
    else if($STAGE==1)header("refresh:3;url={$_SERVER['PHP_SELF']}?op=change_password");
	else if($STAGE==8)header("refresh:3;url={$_SERVER['PHP_SELF']}?op=confirm_changeP");
	else if($STAGE==9)header("refresh:3;url={$_SERVER['PHP_SELF']}?op=continue");
	$main="
	<!DOCTYPE html>
	<html lang='en' >

	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
	  <link rel='stylesheet' href='css/style_takeW.css'>
	</head>
	<body>
	  <div>
	   <h1>交易處理中，請稍後</h1>
	   <h3>PROCESSING, PLEASE WAIT</h3>
	  </div>
	  <div>
		<img src='https://i.postimg.cc/HLB4hq1v/005-collaboration.png'>
	  </div>  
	</body>
    </html>
	";
	return $main;
}
function waiting_ad(){   //等待畫面 交易處理中，請稍後 有廣告
	global $link;
	header("refresh:3;url={$_SERVER['PHP_SELF']}?op=continue");
	$main="
	<!DOCTYPE html>
	<html lang='en' >
    <head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
		<link rel='stylesheet' href='css/style_ad.css'>
	</head>
	<body>
	  <img src='https://i.postimg.cc/9Xd7BW2k/VISA-1-696x364.jpg'>
	  <div>
		<h2>交易處理中，請稍後</h2>
		<h3>PROCESSING..., PLEASE WAIT</h3>
	  </div>
	</body>
	</html>
    ";
	return $main;
}

//end

function give_account_money_page()
{
	
	global $link;
	$sql3="select `account_money` from `user_ac_money` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."檢索資料失敗");
	
	$row = $result->fetch_assoc();
	$main="
	<!DOCTYPE htnl>
	<html lang='en' >
	<head>
		<meta charset='UTF-8'>
		<title>主頁</title>
   
	</head>
	<body>
	<p>your money $row[account_money]</p>
	<form role='form' method='post' action='{$_SERVER['PHP_SELF']}'>
		<label>帳號:<input type='text' name='user_account'></label>
		<label>帳號:<input type='number' name='account_money'></label>
		<input type='hidden' name='op' value='give_money'>
		<button type='submit'>確認</button>
	</form>
	<a href='{$_SERVER["PHP_SELF"]}?op=menu'>home</a>
	
	</body>
	</html>";
	return $main;
	
}
function give_account_money()
{
	global $link;
	$sql3="select `account_money` from `user_ac_money` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."123");
	$row = $result->fetch_assoc();
	$sql1="select * from `user_ac_money` where user_account='{$_POST['user_account']}'";
	$result2=mysqli_query($link,$sql1)or die_content(mysql_error($link)."123");
	$num=mysqli_num_rows($result2);
	if($num>0 && $row['account_money']>$_POST['account_money']){
		
		
		$sql="UPDATE `user_ac_money`
		SET `account_money`=`account_money`-{$_POST['account_money']}
		WHERE `user_account`='{$_SESSION['user_account']}'";
		mysqli_query($link,$sql) or die_content("已經設定過此月份資料");
		
		
		$sql="UPDATE `user_ac_money`
		SET `account_money`=`account_money`+{$_POST['account_money']}
		WHERE `user_account`='{$_POST['user_account']}'";
		mysqli_query($link,$sql) or die_content("已經設定過此月份資料");
		return give_account_money_page();
		
		
	}
	else{
		
		echo '<p>no this account too much</p>';
	}
}

function delete_registe(){
	global $link;
	$sql="DELETE FROM `confirm_transfer_money` WHERE `user_account`='{$_SESSION['user_account']}'";
	mysqli_query($link,$sql) or die_content("3");
	
	return logout_account();

}
function delete_registe2(){
	global $link;
	$sql="DELETE FROM `confirm_transfer_money2` WHERE `user_account`='{$_SESSION['user_account']}'";
	mysqli_query($link,$sql) or die_content("3");
	
	return logout_account();

}
function delete_registeP(){
	global $link;
	$sql="DELETE FROM `confirm_password` WHERE `user_account`='{$_SESSION['user_account']}'";
	mysqli_query($link,$sql) or die_content("3");
	
	return logout_account();

}

function wrong($letter){
	$_SESSION['user_account']="";
	header("refresh:8;url={$_SERVER['PHP_SELF']}?op=home_page");
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
	  <link rel='stylesheet' href='css/style_takeR.css'>
	</head>
	<body>
	  <div>
		<h1>對不起$letter</h1><!--交易操作發生錯誤-->
		<h1>已登出您的帳戶，請重新操作</h1><br>
		<h3>SORRY, PLEASE TRY AGAIN</h3>
	  </div>
	  <div>
		<img src='https://i.postimg.cc/NLhpybWc/red-card.png'>
	  </div>
	</body>
	</html>
	";
	return $main;
}

function wrong2(){
	header("refresh:4;url={$_SERVER['PHP_SELF']}?op=home_page");
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
	<head>
	  <meta charset='UTF-8'>
	  <title>A Pen by  Jamie Su</title>
	  <link rel='stylesheet' href='css/style_takeR.css'>
	</head>
	<body>
	  <div>
		<h1>對不起，查無此帳戶</h1>
		<h1>請確認帳戶名稱和密碼是否有誤</h1><!--交易操作發生錯誤-->
		<h1>請重新操作</h1><br>
		<h3>SORRY, PLEASE TRY AGAIN</h3>
	  </div>
	  <div>
		<img src='https://i.postimg.cc/NLhpybWc/red-card.png'>
	  </div>
	</body>
	</html>
	";
	return $main;
}

function registe_transfer_money(){
	global $link;
	$sql3="select `account_money` from `user_ac_money` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."123");
	$row = $result->fetch_assoc();
	$sql1="select * from `user_ac_money` where user_account='{$_POST['user_account']}'";
	$result2=mysqli_query($link,$sql1)or die_content(mysql_error($link)."123");
	$num=mysqli_num_rows($result2);
	//echo $row['account_money'];
    $title="，查無 {$_POST['user_account']} 此帳戶";
	if($num==0) return wrong($title);
	if($num>0 && $row['account_money']>$_POST['account_money']){
		
		$sql="INSERT INTO `confirm_transfer_money` (
			`user_account`,
			`transfer_account`,
			`transfer_money`) VALUES(
			'{$_SESSION['user_account']}',
			'{$_POST['user_account']}',
			{$_POST['account_money']});";
		mysqli_query($link,$sql) or die_content("已經設定過此月份資料");
		return waiting_page(6);
		
		/*$sql="UPDATE `user_ac_money`
		SET `account_money`=`account_money`-{$_POST['account_money']}
		WHERE `user_account`='{$_SESSION['user_account']}'";
		mysqli_query($link,$sql) or die_content("已經設定過此月份資料");
		
		
		$sql="UPDATE `user_ac_money`
		SET `account_money`=`account_money`+{$_POST['account_money']}
		WHERE `user_account`='{$_POST['user_account']}'";
		mysqli_query($link,$sql) or die_content("已經設定過此月份資料");
		return give_account_money_page();*/
	}
	else{
		$title="，您的帳戶餘額不足";
		return wrong($title);
	}
	
}
function do_transfer(){
	global $link;
	$sql3="select * from `confirm_transfer_money` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."123");
	$row = $result->fetch_assoc();
	
	$sql="UPDATE `user_ac_money`
	SET `account_money`=`account_money`-$row[transfer_money]
	WHERE `user_account`='$row[user_account]'";
	mysqli_query($link,$sql) or die_content("1");
		
	
	$sql="UPDATE `user_ac_money`
	SET `account_money`=`account_money`+$row[transfer_money]
	WHERE `user_account`='$row[transfer_account]'";
	mysqli_query($link,$sql) or die_content("2");
	
	$sql="DELETE FROM `confirm_transfer_money` WHERE `user_account`='$row[user_account]'";
	mysqli_query($link,$sql) or die_content("3");
	
	return waiting_page(7);
}
function do_transfer2(){
	global $link;
	$sql3="select * from `confirm_transfer_money2` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."123");
	$row = $result->fetch_assoc();
	
	$sql="UPDATE `user_ac_money`
	SET `account_money`=`account_money`-$row[transfer_money]
	WHERE `user_account`='$row[user_account]'";
	mysqli_query($link,$sql) or die_content("1");
		
	
	$sql="UPDATE `user_bank_account`
	SET `account_money`=`account_money`+$row[transfer_money]
	WHERE `user_account`='$row[transfer_account]' AND `bank_number`='$row[bank_number]'";
	mysqli_query($link,$sql) or die_content("2");
	
	$sql="DELETE FROM `confirm_transfer_money2` WHERE `user_account`='$row[user_account]'";
	mysqli_query($link,$sql) or die_content("3");
	
	return waiting_page(7);
}

function registe_transfer_money2(){
	global $link;
	$sql3="select `account_money` from `user_ac_money` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."123");
	$row = $result->fetch_assoc();
	$sql1="select * from `user_bank_account` where user_account='{$_POST['user_account']}' and bank_number='{$_POST['bank_number']}'";
	$result2=mysqli_query($link,$sql1)or die_content(mysql_error($link)."123");
	$num=mysqli_num_rows($result2);
	
	$title="<br>查無 {$_POST['user_account']} 此帳戶或銀行代碼錯誤";
	if($num==0) return wrong($title);
	
	if($num>0 && $row['account_money']>$_POST['account_money']){
		
		
		
		$sql="INSERT INTO `confirm_transfer_money2` (
		    `bank_number`,
			`user_account`,
			`transfer_account`,
			`transfer_money`) VALUES(
			'{$_POST['bank_number']}',
			'{$_SESSION['user_account']}',
			'{$_POST['user_account']}',
			{$_POST['account_money']});";
		mysqli_query($link,$sql) or die_content("已經設定過此月份資料");
		return waiting_page(4);
	}
	else{
		
		$title="，您的帳戶餘額不足";
		return wrong($title);
	}
	
}
function registe_password(){
	global $link;
	$sql3="select * from `user_ac_pw` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."123");
	$num=mysqli_num_rows($result);
	$row = $result->fetch_assoc();
	
	$title="";
	if($num==0) return wrong($title);
	
	if($row['user_password'] == $_POST['user_old']){
		if($_POST['user_confirm_new'] == $_POST['user_new']){
			$sql="INSERT INTO `confirm_password` (
				`user_account`,
				`user_password`) VALUES(
				'{$_SESSION['user_account']}',
				'{$_POST['user_new']}');";
			mysqli_query($link,$sql) or die_content("已經設定過此月份資料");
			return confirm_changeP();
		}
		else{
			$title="，新密碼輸入有誤";
			return wrong($title);
		} 
	}
	else{
		$title="，密碼輸入有誤";
		return wrong($title);
	}
}

function confirm_changeP(){
	global $link;
	$main="
	<!DOCTYPE html>
	<html lang='en' >
		<head>
			<meta charset='UTF-8'>
			<title>A Pen by  Jamie Su</title>
			<meta name='viewport' content='width=device-width, initial-scale=1'>
			<link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.5.0/css/all.css' integrity='sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU' crossorigin='anonymous'>
			<link rel='stylesheet' href='css/style_transferLA.css'>
		</head>
		<body>
			<header>
			<div class='note'>
				<h3>請觸碰螢幕選單或下方數字鍵盤</h3>
				<h5>PLEASE TOUCH THE SCREEN OR USE THE NUMBERIC KEYPAD</h5>
			</div>
			</header>
				<main>
					<div class='note-two'>
					<h2 style='color:#d32f2f'>注意!</h2>   
					<h2 style='color:#d32f2f'>您的帳戶密碼即將變更，</h2>  
					<h2 style='color:#d32f2f'>確定要更改嗎?</h2>
					<br>
					<h4 style='color:#d32f2f'>ATENTION!</h4>
					<h4 style='color:#d32f2f'>Your account password will be change,</h4>
					<h4 style='color:#d32f2f'>are you sure you want to change?</h4>
				</div>
				</main>
			<footer>
				<a class='items' href='{$_SERVER['PHP_SELF']}?op=delete_registeP'>
					<p>1.&nbsp;&nbsp;&nbsp;取消</p>
				</a>
				<a class='items' href='{$_SERVER['PHP_SELF']}?op=change_new_password'>
					<p>2.&nbsp;&nbsp;&nbsp;確定</p>
				</a>
			</footer>
		</body>
	</html>";
	return $main;
}
function change_new_password(){
	global $link;
	$sql3="select * from `confirm_password` where user_account='{$_SESSION['user_account']}'";
	$result=mysqli_query($link,$sql3)or die_content(mysql_error($link)."123");
	$row = $result->fetch_assoc();
	
	$sql="UPDATE `user_ac_pw`
		SET `user_password`={$row['user_password']}
		WHERE `user_account`='{$_SESSION['user_account']}'";
		mysqli_query($link,$sql) or die_content("已經設定過此月份資料");
	
	$sql="DELETE FROM `confirm_password` WHERE `user_account`='{$_SESSION['user_account']}'";
	mysqli_query($link,$sql) or die_content("3");
	
	return waiting_page(9);
}


?>