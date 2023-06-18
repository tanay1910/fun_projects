var p1 = Math.ceil(Math.random()*6);
var p2 = Math.ceil(Math.random()*6);

if (p1>p2)
{
    document.querySelector("p").textContent="P1 wins";
}
else if (p2>p1)
{
    document.querySelector("p").textContent="P2 wins";

}
else if (p1==p2) {    document.querySelector("p").textContent="Draw! Try again :(";
};

if(p1==1) {document.querySelector(".img1").setAttribute("src","./images/dice1.png");}
else if (p1==2) {document.querySelector(".img1").setAttribute("src","./images/dice2.png");}
else if (p1==3) {document.querySelector(".img1").setAttribute("src","./images/dice3.png");}
else if (p1==4) {document.querySelector(".img1").setAttribute("src","./images/dice4.png");}
else if (p1==5) {document.querySelector(".img1").setAttribute("src","./images/dice5.png");}
else if (p1==6) {document.querySelector(".img1").setAttribute("src","./images/dice6.png");} 

if(p2==1) {document.querySelector(".img2").setAttribute("src","./images/dice1.png");}
else if (p2==2) {document.querySelector(".img2").setAttribute("src","./images/dice2.png");}
else if (p2==3) {document.querySelector(".img2").setAttribute("src","./images/dice3.png");}
else if (p2==4) {document.querySelector(".img2").setAttribute("src","./images/dice4.png");}
else if (p2==5) {document.querySelector(".img2").setAttribute("src","./images/dice5.png");}
else if (p2==6) {document.querySelector(".img2").setAttribute("src","./images/dice6.png");} 



// document.querySelector(".img1").setAttribute("src","./images/dice1.png");