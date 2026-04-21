let arr = [120, 60, 180, 90, 150, 30, 200, 80, 140, 70];


function loadArray() {
const container = document.getElementById("array");
container.innerHTML = "";

for (let i = 0; i < arr.length; i++) {


let box = document.createElement("div");
box.style.display = "flex";
box.style.flexDirection = "column";
box.style.alignItems = "center";


let value = document.createElement("span");
value.innerText = arr[i];


let bar = document.createElement("div");
bar.className = "bar";
bar.style.height = arr[i] + "px";

box.appendChild(value);
box.appendChild(bar);
container.appendChild(box);


}
}

function bubbleSort() {
let bars = document.getElementsByClassName("bar");
let values = document.getElementsByTagName("span"); // NEW

for (let i = 0; i < arr.length; i++) {
for (let j = 0; j < arr.length - i - 1; j++) {


  if (arr[j] > arr[j + 1]) {

    
    let temp = arr[j];
    arr[j] = arr[j + 1];
    arr[j + 1] = temp;

    bars[j].style.height = arr[j] + "px";
    bars[j + 1].style.height = arr[j + 1] + "px";

    
    values[j].innerText = arr[j];
    values[j + 1].innerText = arr[j + 1];
  }
}


}
}

loadArray();
