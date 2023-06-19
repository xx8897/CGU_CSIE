<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<pre>
<?php
$data = array();
$data['飲料'] = array('pay'=>50, 'cost'=>35);
$data['早餐'] = array('pay'=>60, 'cost'=>55);
$data['午餐'] = array('pay'=>100, 'cost'=>83);
$data['晚餐'] = array('pay'=>200, 'cost'=>130);
$data['消夜'] = array('pay'=>100, 'cost'=>70);
#print_r($data);

echo "Type 10 5 1\n";
foreach($data as $key => $each){
   $pay = $each['pay'];
   $cost = $each['cost'];
   #=============================================
   #Please input code here.
   
   
   #=============================================
   echo $key." ".$ten." ".$five." ".$one."\n";
}//end foreach
?>
</pre>
