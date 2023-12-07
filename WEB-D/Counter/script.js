let counter = document.getElementById("count-el");
let saver = document.getElementById("save-el");
var count = 0;

function increment(){
    count++;
    counter.innerText = count;
}


function save(){
    saver.textContent += count + " - ";
    count = 0;
}

console.log("Let's count people on the subway!")

