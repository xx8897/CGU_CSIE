 if(typeof(document.asm_excl) == "undefined"){ document.asm_excl = new Array(); } document.asm_excl = document.asm_excl.concat(String("").split("|")); 

 var asm_ex = false;
 var asm_ex_all = false;
 for(var asm_i=0; asm_i<document.asm_excl.length; asm_i++) { if(document.asm_excl[asm_i] == "192"){asm_ex = true; break;}}
 for(var asm_i=0; asm_i<document.asm_excl.length; asm_i++) { if(document.asm_excl[asm_i] == "w23" || document.asm_excl[asm_i] == "p343"){asm_ex_all = true; break;}}
 if(asm_ex_all){}
 else if(!asm_ex )
 {
   document.write('<div class="asmbeacon asmb3" style="position:absolute; left:0px; top:0px;"><img border="0" style="border:0px white solid !important;width:1px; height:1px;" width="1" height="1" alt="" src="http://kds.adspirit.de/adview.php?tz=1447992319921965&pid=343&kid=192&wmid=446&sid=8367&nvc=1&target1=-" /></div><scr'+'ipt>\r\nMTagParams = {sourceURL: \'[sourceURL]\',cacheBuster: \'[cacheBuster]\'};\r\n</scr'+'ipt>\r\n<scr'+'ipt src=\'//t.tmdn2015x11.com/build/9ccddb6f/v1/\'></scr'+'ipt>\r\n<scr'+'ipt type="text/javascr'+'ipt" language="JavaScr'+'ipt"><'+'!'+'-- \r\n //--'+'></scr'+'ipt>'); 
 }
 else
 {
  document.write('<scr'+'ipt type="text\/javasc'+'ript" language="JavaSc'+'ript" src="http://kds.adspirit.de/adscript.php?pid=343&hr=1&nrc=1&&ref=http%3A%2F%2Fwww.learncpp.com%2Fcpp-tutorial%2F19-header-files%2F&wpcn=asmpvx879421447992319&sid=8367&ex=|192&ord='+(new Date()).getTime()+'"><\/scr'+'ipt>');
 }
 