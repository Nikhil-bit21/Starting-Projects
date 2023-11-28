console.log("Welcome To Tic-Tac-Toe");

// Create an Audio object for each sound
let music = new Audio("music.mp3");
let ting = new Audio("ting.mp3");
let gameover = new Audio("gameover.mp3"); 
let turn = "X";
let Gameover = false;

// Function to change the turn 
const changeTurn = () => {
    return turn === "X"? "0": "X";
};

// Function to check for a win
const checkWin = () => {
    let boxText = document.getElementsByClassName('BoxText');
    let win = [
        [0,1,2],
        [3,4,5],
        [6,7,8],
        [0,3,6],
        [1,4,7],
        [2,5,8],
        [0,4,8],
        [2,4,6],
]
    win.forEach(e=>{
        if((boxText[e[0]].innerText === boxText[e[1]].innerText) &&
        (boxText[e[1]].innerText=== boxText[e[2]].innerText) && 
        (boxText[e[0]].innerText !== "")){
                document.querySelector('.Info').innerText = boxText[e[0]].innerText + " WON ";
                Gameover = true;
                document.querySelector('.imgbox').getElementsByTagName('img')[0].style.width = "200px";
        }
    })
};

// Main game logic
let boxes = document.getElementsByClassName("Box");
Array.from(boxes).forEach(element => {
    let boxText = element.querySelector('.BoxText');
    element.addEventListener('click', () => {
        if (boxText.innerText === '') {
            boxText.innerText = turn;
            turn = changeTurn();
            ting.play();
            checkWin();
            if(!Gameover){
            document.getElementsByClassName("Info")[0].innerText = "Turn => " + turn;
            }
        }
    });
});

// ADD onclick listener to reset button
reset.addEventListener('click' , ()=>{
    let boxText = document.querySelectorAll('.BoxText');
    Array.from(boxText).forEach(element=>{
        element.innerText="";
    });
    turn="X";
    Gameover = false;
    document.getElementsByClassName("Info")[0].innerText = "Turn => " + turn;
    document.querySelector('.imgbox').getElementsByTagName('img')[0].style.width = "0px";
});

