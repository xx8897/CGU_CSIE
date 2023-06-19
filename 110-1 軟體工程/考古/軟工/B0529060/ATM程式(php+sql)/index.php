<?php

include_once("ATM-setup.php");
include_once("ATM-function.php");
//-------------------設定區-----------------------//

@$op=$_REQUEST['op'];
$S=empty($_REQUEST['S'])?'0':intval($_REQUEST['S']);
$continue=empty($_REQUEST['continue'])?'0':intval($_REQUEST['continue']);
$STAGE=empty($_REQUEST['STAGE'])?'0':intval($_REQUEST['STAGE']);




//---------------流程控制區----------------------//
switch($op){
    //----------註冊--------//
	case "home_page":
    $content=home_page();
    break;
	
    case "check":
    $content=check();
    break;
	case "menu":
    $content=function_menu();
    break;
	
	case "menu2":
    $content=function_menu2();
    break;
	case "check_money":
    $content=check_account_money();
    break;
	
	case "stage_step":
	$_SESSION['stage']=$STAGE;
	$_SESSION['contiune']=$continue; //$continue=1 continue
	$content=stage_step($_SESSION['stage']);
	break;
	
	case "take_money_menu":
    $content=take_money_menu();
    break;
	case "take_money_page":
    $content=take_money_page();
    break;
	
	case "take_money":
    $content=take_account_money($S);
    break;
	case "give_money_page":
    $content=give_account_money_page();
    break;
	case "give_money":
    $content=registe_transfer_money();
    break;
	
	
	case "registe_transfer_money2":
    $content=registe_transfer_money2();
    break;
	
	
	case "waiting":
	$content=waiting_ad($_SESSION['stage']);
	break;
	
	case "continue":
	$content=continue_page($_SESSION['stage']);
	break;
	
	
	case "waiting_take":
	$content=waiting_take();
	break;
	
	
	//transfer_money
	
	case "transfer_money": //確認是否轉帳
	$content=transfer_money();
	break;
	case "transfer_money2": //確認是否轉帳
	$content=transfer_money2();
	break;
	
	case "inquire_bankID": //確認是否轉帳
	$content=inquire_bankID();
	break;
	
	case "confirm_transfer": //確認是否轉帳
	$content=confirm_transfer();
	break;

	case "confirm_transfer_money": //確認轉帳金額
	$content=confirm_transfer_money();
	break;
	
	case "confirm_transfer_list": //確認轉帳金額
	$content=confirm_transfer_list();
	break;
	
	case "confirm_transfer_list2": //確認轉帳金額
	$content=confirm_transfer_list2();
	break;
	
	case "confirm_transfer_last": //確認轉帳金額
	$content=confirm_transfer_last();
	break;
	
	case "do_transfer": //確認轉帳金額
	$content=do_transfer();
	break;
	
	case "do_transfer2": //確認轉帳金額
	$content=do_transfer2();
	break;
	
	case "waiting_receipt_makeforT":
	$content=waiting_receipt_makeforT();
	break;
	
	case "change_password": //確認轉帳金額
	$content=change_password();
	break;
	
	case "registe_password": //確認轉帳金額
	$content=registe_password();
	break;
	
	
	case "logout_account": //確認轉帳金額
	$content=logout_account();
	break;
	
	case "confirm_changeP": //確認轉帳金額
	$content=confirm_changeP();
	break;
	
	case "change_new_password": //確認轉帳金額
	$content=change_new_password();
	break;
	//receipt
	case "select_receipt":
	$content=select_receipt();
	break;
	
	case "take_receipt":
	$content=take_receipt();
	break;
	
	case "output_receipt":
	$content=output_receipt();
	break;
	
	case "no_output_receipt":
	$content=no_output_receipt();
	break;
	
	case "waiting_receipt_makeforT":
	$content=waiting_receipt_makeforT();
	break;
	
	
	case "delete_registe":
	$content=delete_registe();
	break;
	
	case "delete_registe2":
	$content=delete_registe2();
	break;
	
	case "delete_registeP":
	$content=delete_registeP();
	break;
	
	case "end_page":
	$content=end_page();
	break;
	//end the system or not
	case "select_end":
	if($_SESSION['contiune']==0)$content=home_page();
	else $content=function_menu();
	break;
	
	case "select_end2":
	if($_SESSION['contiune']==0) $content=end_page();
	else $content=function_menu();
	break;
	
    default:
	$content=page_strat();
}

//------------------輸出區----------------------//
echo $content;
//----------------------函數區-------------------------//

?>