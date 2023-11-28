const inputBox = document.getElementById('input-box');
const list = document.getElementById('list');

function addTask(){
    if(inputBox.value === ''){
        alert("Write Something");
    }else{
        let li = document.createElement("li");
        li.innerHTML = inputBox.value;
        list.appendChild(li);

        let span = document.createElement("span");
        span.innerHTML = "\u00d7";
        li.appendChild(span);
    }
    inputBox.value = "";
    SaveData();
}

list.addEventListener("click",function(e){
    if(e.target.tagName === "LI"){
        e.target.classList.toggle("checked");
        SaveData()
    }else if(e.target.tagName === "SPAN") {
        e.target.parentElement.remove();
        SaveData()
    }
},false);

function SaveData(){
    localStorage.setItem("data",list.innerHTML);
}

function showTask(){
    list.innerHTML = localStorage.getItem("data");
}

showTask();