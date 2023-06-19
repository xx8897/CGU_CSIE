(function(win,doc,undefined){
var splitTable = function(table,srow,newId){
this.table = doc.getElementById(table);
this.author = "Aaron Li";
this.srow=srow;
this.newId=newId;
this.init();
}
splitTable.prototype={
constractor:splitTable,
init:function()
{
var _self=this;
var split=_self.table.getAttribute("split");
if (split.toString()=="true")
{
_self.cutTable(_self.table,_self.srow,_self.newId);
}
},
cutTable:function(table,srow,newId){
var body=document.getElementsByTagName('body')[0];
if(isNaN(srow))
{
console.log("msg:srow error");
return;
}
srow = parseInt(srow);
srow = srow<1?1:srow;
srow = table.rows.length>srow?srow:(table.rows.length-1);
var newtable = table.cloneNode(false);
var tbody = newtable.appendChild(document.createElement("tbody"));
table.id = newId?newId:(table.id+"_cut");
table.parentNode.insertBefore(newtable,table);
for(var i=0;i<srow;i++)
{
tbody.appendChild(table.rows[0]);
}
var divNode1=document.createElement("div");
divNode1.setAttribute("id","divHeader");
divNode1.setAttribute("style","overflow: hidden;margin-bottom: 0px;"); 
var divNode2=document.createElement("div");
divNode2.setAttribute("id","divTbody");
newtable.setAttribute("style","margin-bottom: 0px; table-layout: fixed; ");
divNode2.setAttribute("style","overflow-y: scroll; overflow-x: scroll; max-height: 245px");
divNode2.setAttribute("onscroll","javascript:divHeader.scrollLeft = divTbody.scrollLeft;");
table.setAttribute("style","margin-bottom: 0px; table-layout: fixed; ");
var tableParent= table.parentNode;
divNode1.appendChild(newtable)
divNode2.appendChild(table);
tableParent.appendChild(divNode1);
tableParent.appendChild(divNode2);
}

}
win.splitTable=splitTable;
}(window,document))