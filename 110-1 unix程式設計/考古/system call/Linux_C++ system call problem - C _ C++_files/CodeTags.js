var cBlur;
var cHHeight;
var cHWidth;
var cCWidth;
var cCHeight;

function hideSelects(boolHide) {
	var sels=document.getElementsByTagName("SELECT");
	for (var i=0; i<sels.length; i++)  {
		if (boolHide) {
			sels[i].style.display="none";
		} else {
			sels[i].style.display="";
		}
	}
}

function Blur(cObj, cHolder, cContent, show) {
	cBlur = document.getElementById("codeBlur");
	cAbs = document.getElementById("codeAbs");
	setheight();	
	if (show==true) {
		hideSelects(true);	
		cBlur.style.display = "block";
		
		cObj.innerHTML="Contract";
		cHolder.style.display="none";
		cAbs.style.display="block";
		cAbs.style.position="absolute";
		
		cHHeight=cHolder.style.height;
		cHWidth=cHolder.style.width;
		cCHeight=cContent.style.height;
		cCWidth=cContent.style.width;
		
		cAbs.style.width="807px";
		cHolder.style.height="100%";
		cHolder.style.width="807px";
		cContent.style.width="100%";
		cContent.style.height="100%";
		
		objh = parseFloat(cHolder.style.height)/2;
		objw = parseFloat(cHolder.style.width)/2;
		if (document.all) {
			cAbs.style.top = Math.floor(Math.round((document.documentElement.offsetHeight/2)+document.documentElement.scrollTop)-objh)-100+'px';
			cAbs.style.left = Math.floor(Math.round((document.documentElement.offsetWidth/2)+document.documentElement.scrollLeft)-objw)+'px';
		}  else {
			var szScrollTop=document.documentElement.scrollTop;
			var szScrollLeft=document.documentElement.scrollLeft;
			if (szScrollTop==0) { szScrollTop = document.body.scrollTop; }
			if (szScrollLeft=="undefined") { szScrollLeft = document.body.scrollleft; }
			cAbs.style.top = Math.floor(Math.round((window.innerHeight/2)+szScrollTop)-objh)-100+'px';
			cAbs.style.left = Math.floor(Math.round((window.innerWidth/2)+szScrollLeft)-objw)+'px';
		}
	cAbs.innerHTML=cHolder.innerHTML;
	if (document.all) {
		cAbs.childNodes[0].childNodes[0].onclick=function () { Blur(cObj, cHolder, cContent, false); }
	} else {
		cAbs.childNodes[1].childNodes[1].onclick=function () { Blur(cObj, cHolder, cContent, false); }
	}
	cBlur.onclick=function () { Blur(cObj, cHolder, cContent, false); }
	} else {
		hideSelects(false);
		
		cObj.innerHTML="Expand";
		
		cContent.style.width=cCWidth;
		cContent.style.height=cCHeight;
		cContent.className="codeContent";
		
		cHolder.style.width=cHWidth;
		cHolder.style.height=cHHeight;
		cHolder.style.display="block";
		cHolder.style.position="";
		
		cAbs.style.display="none";
		cBlur.style.display = "none";
		cBlur.onclick = "";
	}
}

	
function setheight() {
	cBlur.style.height = document.body.scrollHeight+"px";
}

function getChildren(obj) {
	if (obj.parentNode.parentNode.childNodes[1].className=="codeContent") { 
		return obj.parentNode.parentNode.childNodes[1]; /*because IE does it like this... IE counts its children only.. like its supposed to be*/
	} else {
		return obj.parentNode.parentNode.childNodes[3]; /*and because FF does it like this... Firefox counts children of childrens*/
	}
}

function selectNode (node) { 
   var selection, range, doc, win; 
   if ((doc = node.ownerDocument) && (win = doc.defaultView) && typeof win.getSelection != 'undefined' && typeof doc.createRange != 'undefined' && (selection = window.getSelection()) && typeof selection.removeAllRanges != 'undefined') { 
     range = doc.createRange(); 
     range.selectNode(node); 
     selection.removeAllRanges(); 
     selection.addRange(range); 
   }  else if (document.body && typeof document.body.createTextRange != 'undefined' && (range = document.body.createTextRange())) { 
     range.moveToElementText(node); 
     range.select(); 
   } 

} 


function selectAll(obj) {
        
	if (document.all) { 
		var ele=obj.parentNode.nextSibling;
	} else {
		var ele=obj.parentNode.nextSibling.nextSibling;
	}
       selectNode(ele);
       
}

function WordWrap(obj) {
	if (document.all) { 
		var cObj=obj.parentNode.nextSibling;
		if (cObj.style.whiteSpace=="nowrap") {
			cObj.style.whiteSpace="normal";
		} else {
			cObj.style.whiteSpace="nowrap";
		}
	} else {
		var check=obj.parentNode.nextSibling.nextSibling;
		var cObj=obj.parentNode.nextSibling.nextSibling.childNodes[1].childNodes;
		if (check.getAttribute("wrapped")==null || check.getAttribute("wrapped")=="" || check.getAttribute("wrapped")=="false") {
			check.setAttribute("wrapped", "true");
			var max_len=55;
			for (var i=0; i<cObj.length; i++) {
				var ih=cObj[i].innerHTML;
				if (ih!=null) {
					if (ih.length>max_len) {
						var rstr="";
						for (var c=0; c<ih.length/max_len; c++) {
							rstr+=ih.substr(c*max_len, max_len)+"<br>";
						}
						cObj[i].innerHTML=rstr;
						rstr="";
					}
				}
			}
		} else {
			/*undo wrap */
			check.setAttribute("wrapped", "false");
			check.innerHTML=check.innerHTML.replace(/<BR>/gi, "");
		}
	}
}


function LineNumbers(obj) {
	if (document.all) { 
		var cH=obj.parentNode.nextSibling;

	} else {
		var cH=obj.parentNode.nextSibling.nextSibling;		
	}
	var NT=getNextTag(cH);
	if (NT.tagName=="OL") {
		var str="";
		var div=document.createElement("DIV");
		for (var i=0; i<NT.childNodes.length; i++) {
			if (NT.childNodes[i].innerHTML!=null) {
				var span=document.createElement("span");
				var br=document.createElement("BR");
				span.className="codeSpan";
				if (i==NT.childNodes.length-1) {
						span.innerHTML=NT.childNodes[i].innerHTML;
						div.appendChild(span);
				} else {
					span.innerHTML=NT.childNodes[i].innerHTML;
					div.appendChild(span);
					div.appendChild(br);
				}
			}
		}
		cH.appendChild(div);
		cH.removeChild(NT);
		/*var ta=document.createElement("TEXTAREA");
		ta.innerText=cH.innerHTML;
		cH.appendChild(ta);*/
	} else {
		var ol=document.createElement("OL");
		var div=document.createElement("DIV");
		div.innerHTML=NT.innerHTML;
		cH.removeChild(NT);
			div.innerHTML=div.innerHTML.replace(/<br>/ig, "<!---->");		  
			div.innerHTML=div.innerHTML.replace(/<span class=codespan>/ig, "");
			div.innerHTML=div.innerHTML.replace(/<span class=\"codespan\">/ig, "");
			div.innerHTML=div.innerHTML.replace(/<\/span>/ig, "");
			spItems=div.innerHTML.split("<!---->");
		for (var i=0; i<spItems.length; i++) {
			if (spItems[i]!=null) {
				var li=document.createElement("LI");
				li.innerHTML=spItems[i];
				li.className="codeLI";
				ol.appendChild(li);
			}
		}
		cH.appendChild(ol);
	}
}

function getNextTag(obj) {
	for (var i=0; i<obj.childNodes.length; i++) {
		if (obj.childNodes[i].tagName!="" && obj.childNodes[i].tagName!="undefined" && obj.childNodes[i].tagName!=null) {
			return obj.childNodes[i];
			i=10000;
		}
	}
}

