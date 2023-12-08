let boxes = document.querySelectorAll(".box");
let msgbox = document.querySelector("#msg");
let msgcontainer = document.querySelector(".msg-container");

let resetBtn = document.querySelector("#reset-btn");
let newGameBtn = document.querySelector("#new-btn");

let count = 0;
let turnX = true;

const winlist = [
    [0,1,2],
    [3,4,5],
    [6,7,8],
    [0,3,6],
    [1,4,7],
    [2,5,8],
    [0,4,8],
    [2,4,6]
];

const resetGame = () => {
    turnX = true;
    count = 0;
    enableBoxes();
    msgcontainer.classList.add("hide");
};

boxes.forEach((box) =>{
    box.addEventListener("click",()=>{
        if(turnX){
            box.innerText = "X";
            turnX = false;
        }else{
            box.innerText = "O";
            turnX = true;
        }
        box.disabled = true;
        count++;

        let winner = checkWinner();

        if(count === 9 && !winner){
            gameDraw();
        }
    })
});

const gameDraw = () => {
    msg.innerText = `Game was a Draw.`;
    msgcontainer.classList.remove("hide");
    disableBoxes();
};

const disableBoxes = () => {
    for (let box of boxes) {
    box.disabled = true;
    }
};

const enableBoxes = () => {
    for (let box of boxes) {
    box.disabled = false;
    box.innerText = "";
    }
};

showWinner=(val)=>{
    msgbox.innerText = `Congratulations! Winner is ${val}`;
    msgcontainer.classList.remove("hide");
    disableBoxes();
}

checkWinner = ()=>{
    for (let pattern of winlist) {
        let pos1 = boxes[pattern[0]].innerText ;
        let pos2 = boxes[pattern[1]].innerText;
        let pos3 = boxes[pattern[2]].innerText;

        if(pos1 !== "" && pos1 === pos2 && pos1 === pos3){
            showWinner(pos1);
        }


    }
}

newGameBtn.addEventListener("click", resetGame);
resetBtn.addEventListener("click", resetGame);

