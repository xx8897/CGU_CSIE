<?php

//系統基本資料
define("_WEB_ROOT_URL","http://{$_SERVER['SERVER_NAME']}/user/");
define("_WEB_ROOT_PATH","{$_SERVER['DOCUMENT_ROOT']}/user/");
//系統變數
$title="客戶管理系統";
//資料庫連線
$db_id="";//資料庫使用者//
$db_passwd="";//資料庫使用者密碼//
$db_name="";//資料庫名稱//
//連入資料庫
$link=mysqli_connect('localhost',$db_id,$db_passwd,$db_name) or die_content(mysqli_connect_errno().mysqli_connect_error()."資料庫無法連線");
mysqli_query($link,"SET NAMES 'utf8'");
//自定輸出錯誤訊息
function die_content($content=""){
    $main="
        <!DOCTYPE html>
        <html lang='zh-TW'>
        <head>
        <meta charset='utf-8'>
        <title>輸出錯誤訊息</title>
        <meta name='viewport' content='width=device-width, initial-scale=1.0'>
        <meta name='description' content='輸出錯誤訊息'>
        <meta name='author' content='aandd'>
		<!-- 引入css檔案開始 -->
        <link rel='stylesheet' href='http://cdn.bootcss.com/bootstrap/3.3.5/css/bootstrap.min.css'>
		<link rel='stylesheet' href='http://cdn.bootcss.com/bootstrap/3.3.5/css/bootstrap-theme.min.css'>
		<!-- 引入css檔案結束 -->
		<!-- 引入js檔案開始 -->
		<script src='http://cdn.bootcss.com/jquery/1.11.3/jquery.min.js'></script>
		<script src='http://cdn.bootcss.com/bootstrap/3.3.5/js/bootstrap.min.js'></script>
        <!-- 引入js檔案結束 -->

        </head>
        <body>
        <!--放入網頁主體-->
        <div class='container' id='main_content'>
          <!-- 主要內容欄位開始 -->
            <div class='hero-unit'>
			<div  class='alert alert-warning alert-dismissible' role='alert'>
			<button type='button'  class='close' data-dismiss='alert' aria-label='Close'><span aria-hidden='true'>&times;</span></button>
			<strong>{$content}</strong>
			</div>
            </div>
          <!-- 主要內容欄位結束 -->
          <!-- 頁腳開始 -->
          <footer>
          </footer>
          <!-- 頁腳結束 -->
        </div> 
        <!-- 主要內容欄位結束 -->
        </body>
        </html>
    ";
    die($main);
}
session_start();

function page($content=""){
	//$_SESSION['user_account']='jamie';
	$_SESSION['user_account']=empty($_SESSION['user_account'])?"":$_SESSION['user_account'];
	$_SESSION['contiune']=empty($_SESSION['contiune'])?"0":$_SESSION['contiune'];
	$_SESSION['stage']=empty($_SESSION['stage'])?"0":$_SESSION['stage'];
    $main=$content;
	return $main;
}

?>
