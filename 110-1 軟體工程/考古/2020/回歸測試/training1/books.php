<?php
sleep(2);
?>
<html>
<head>
<title>Books</title>
<link rel="stylesheet" type="text/css" href="common.css" media="all" /> 
</head>
<body>
<center>
<form name="f">
<div id="available" class="d">
<h2>All available books</h2>
	<table style="" id="listing">
	<tr>
	<td>Title</td><td>In stock</td><td>Cost</td><td>Add quantity to cart</td>
	</tr>
	<tr>
	<td>Core Java</td><td>5</td><td>Rs. 300</td><td><input type="text" name="q" value="0"></td>
	</tr>
	<tr>
	<td>Ruby for Rails</td><td>12</td><td>Rs. 200</td><td><input type="text" name="q" value="0"></td>
	</tr>
	<tr>
	<td>Python Cookbook</td><td>7</td><td>Rs. 350</td><td><input type="text" name="q" value="0"></td>
	</tr>
	</table>
	<br/>
	<input type="button" value="Add" onclick="addToCart()" id="add"/> 
	| <input type="button" value="Clear" onclick="clearCart()"/>
	| <input type="button" value="Logout" onclick="location.href='login.php'"/>
</div>
</form>

<script>
function addToCart() {
	var req = new XMLHttpRequest();
	req.open('GET', 'ajax_add.php', true);
	req.onreadystatechange = function() {
		if (req.readyState == 4 && req.status == 200) {
			addToCartCallBack();
		}
	}		
	document.getElementById("add").style.cursor = "wait";
	document.body.style.cursor = "wait";
	req.send(null);
}
function addToCartCallBack(){
	document.getElementById("add").style.cursor = "default";
	document.body.style.cursor = "default";
	var s = "<table id='added'><tr><td>Title</td><td>Quantity</td><td>Unit Cost</td><td>Total Cost</td></tr>";
	var sum = 0

	for (var i=0; i<books.length; i++){
		var book = books[i];
		var el = document.getElementsByTagName("INPUT")[book.i];
		var val = parseInt(el.value);
		if (val > 0){
			s += "<tr><td>" + book.t + "</td><td>" + el.value + "</td><td>Rs." + book.q + "</td><td> Rs." + (val * book.q) + "</td></tr>";
			sum += val * book.q;
		}
	}
	s += "</table>";
	//alert(document.getElementById("cartDiv").innerHTML);
	document.getElementById("cartDiv").innerHTML = s;	
	document.getElementById("total").value = sum;
}
var books = [{"t":"Core Java", "q":300, "i":0},{"t":"Ruby for Rails", "q":200, "i":1},{"t":"Python Cookbook", "q":350, "i":2}];
function clearCart(){
	for (var i=0; i<books.length; i++){
		document.getElementsByTagName("INPUT")[i].value = "";
	}
	addToCart();	
}
</script>
<style>
#cartDiv {
	xborder: 1px solid gray;
}
td{
  width:150px;
}
</style>
<div id="cart" class="d">
	<h2>My Cart</h2>
	<div id="cartDiv">
	<table id="added">
		<tr><td>Title</td><td>Quantity</td><td>Unit Cost</td><td>Total Cost</td></tr>
	</table>
	</div><br/><br/>
	Grand Total: <input type="text" id="total" value="0"> 
</div>

</center>
</body>
</html>