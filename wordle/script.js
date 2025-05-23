var dictionary = 'https://rawcdn.githack.com/maheshmurag/bjspell/master/dictionary.js/en_US.js';
var lang = BJSpell(dictionary, function() {

});

function isValidWord(word) {
    const found = lang.check(word);
    return found;
}

function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

const randomInteger = getRandomInt(0, 99);

const words = ["apple", "beach", "cloud", "dance", "earth", "faith", "grape", "house", "image", "juice", "kiosk", "lemon", "music", "night", "olive", "peace", "quiet", "river", "sugar", "teach", "umbra", "vivid", "watch", "xenon", "young", "zebra", "amber", "brave", "chess", "drift", "eagle", "flora", "giant", "happy", "ivory", "jolly", "koala", "leash", "maple", "novel", "ocean", "piano", "quick", "rhyme", "scent", "theme", "unity", "verse", "whale", "xerox", "yield", "zealot", "almond", "baker", "coast", "drift", "elixir", "fable", "globe", "hazel", "ivory", "jumbo", "kiwi", "laser", "mango", "noble", "oasis", "prism", "quilt", "rifle", "sable", "tiger", "ultra", "vital", "whisk", "xylan", "youth", "zebra", "amuse", "bliss", "clove", "daisy", "elite", "flame", "giddy", "halcy", "inlay", "jewel", "kiwif", "lilac", "mirth", "novel", "onset", "pique", "quest", "radar", "savor", "taste", "umbra", "venom", "whiff", "xenon", "yield", "zebra"];

let currGrid = 1;
let usr = '';
let ans = words[randomInteger];
ans = ans.toUpperCase();
// let ans = 'GIDDY';
// console.log(ans);

keys = document.getElementsByClassName('key');
const length = keys.length

function clearOne() {
    currGrid--;
    const temp = currGrid + "";
    const currElement = document.getElementById(`${temp}`);
    currElement.innerHTML = '';
}

for (let i = 0; i < length; i++) {
    keys[i].addEventListener('click', () => {
        if (currGrid <= 31 && currGrid > 0) {
            if (keys[i].innerHTML == "Bksp") {
                if (usr != '') {
                    clearOne();
                    usr = usr.slice(0, -1);
                }
            }
            else if (keys[i].innerHTML == "Clear") {
                if (usr != '') {
                    usr = '';
                    do {
                        clearOne();
                    } while (currGrid % 5 > 1 || currGrid % 5 == 0);
                }
            }
            else if (keys[i].innerHTML.length == 1) {  // letter click
                if (usr.length < 5) {
                    const temp = currGrid + "";
                    const currElement = document.getElementById(`${temp}`);
                    currElement.innerHTML = keys[i].innerHTML;
                    usr += keys[i].innerHTML;
                    currGrid++;
                }
            }
            else {  // keys[i].innerHTML == "enter"
                if (usr === ans) {  // win
                    evaluate(currGrid - 5, currGrid - 1, currGrid - 5);
                    setTimeout(() => {
                        alert("YOU WIN!");
                        window.location.href = './index.html';
                    }, 2000);
                }
                else if (currGrid == 31 && isValidWord(usr)) {  // couldn't guess
                    evaluate(currGrid - 5, currGrid - 1, currGrid - 5);
                    setTimeout(() => {
                        alert(`YOU LOSE!, The answer is ${ans}`);
                        window.location.href = './index.html';
                    }, 2000);
                }
                if (usr.length == 5) {  // if the word is 5 lettered
                    if (isValidWord(usr)) {  // handling valid word
                        // console.log("it is valid");
                        evaluate(currGrid - 5, currGrid - 1, currGrid - 5);
                    }
                    else {  // invalid word
                        alert("Enter a valid 5 letter english word");
                        do {
                            clearOne();
                        } while (currGrid % 5 > 1 || currGrid % 5 == 0);
                    }
                    usr = '';
                }
                else {
                    alert("Enter a 5 letter word");
                }
            }
        }
    });
}

function evaluate(leftBound, rightBound, base) {
    if (leftBound <= rightBound) {
        let i = leftBound;
        let current = i + "";
        const currElement = document.getElementById(`${current}`);
        const temp = currElement.innerHTML;
        let color = '';
        if (temp == ans[i - base]) {
            currElement.style.backgroundColor = '#538d4e';
            currElement.style.color = 'white';
            color = '#538d4e';         // green
        }
        else if (ans.includes(temp)) {
            currElement.style.backgroundColor = '#b59f3b';
            currElement.style.color = 'white';
            color = '#b59f3b';           // yellow
        }
        else {
            currElement.style.backgroundColor = '#422a14';
            currElement.style.color = 'white';
            color = '#422a14';          // brown
        }
        updateKeyboard(temp, color);
        currElement.classList.add('flipanimation');
        // currElement.classList.add('flipanimation', () => {
        //     evaluate(leftBound + 1, rightBound, base);
        // });
        setTimeout(() => {
            evaluate(leftBound + 1, rightBound, base);
        }, 300);
    }
}

function updateKeyboard(character, color) {
    for (let i = 0; i < length; i++) {
        if (character == keys[i].innerHTML) {
            var computedStyle = window.getComputedStyle(keys[i]);
            // console.log(computedStyle.backgroundColor, length);
            if (computedStyle.backgroundColor != 'rgb(83, 141, 78)') {
                keys[i].style.backgroundColor = `${color}`;
                keys[i].style.color = `white`;
                break;
            }
        }
    }
}

function print() {
    console.log(ans);
}

function Reveal() {
    alert(`Sorry, We don't have time for hackers. The answer is ${ans}`);
    window.location.href = './index.html';
}

function isLetter(char) {
    return /^[a-zA-Z]$/.test(char);
}

document.addEventListener('keyup', (event) => {
    const keyPress = event.key;
    console.log("Pressed key: ", keyPress, typeof(keyPress));
    if (keyPress.length == 1) {
        if (isLetter(keyPress)) {
            if (usr.length < 5) {
                const temp = currGrid + "";
                const currElement = document.getElementById(`${temp}`);
                console.log(keyPress.toUpperCase());
                currElement.innerHTML = keyPress.toUpperCase();
                usr += keyPress.toUpperCase();
                currGrid++;
            }
        }
        else {
            alert("Please enter a valid key");
        }
    }
    else if (keyPress == "Backspace") {
        if (usr != '') {
            clearOne();
            usr = usr.slice(0, -1);
        }
    }
    else if (keyPress == "Enter") {
        if (usr === ans) {  // win
            evaluate(currGrid - 5, currGrid - 1, currGrid - 5);
            setTimeout(() => {
                alert("YOU WIN!");
                window.location.href = './index.html';
            }, 2000);
        }
        else if (currGrid == 31 && isValidWord(usr)) {  // couldn't guess
            evaluate(currGrid - 5, currGrid - 1, currGrid - 5);
            setTimeout(() => {
                alert(`YOU LOSE!, The answer is ${ans}`);
                window.location.href = './index.html';
            }, 2000);
        }
        if (usr.length == 5) {  // if the word is 5 lettered
            if (isValidWord(usr)) {  // handling valid word
                // console.log("it is valid");
                evaluate(currGrid - 5, currGrid - 1, currGrid - 5);
            }
            else {  // invalid word
                alert("Enter a valid 5 letter english word");
                do {
                    clearOne();
                } while (currGrid % 5 > 1 || currGrid % 5 == 0);
            }
            usr = '';
        }
        else {
            alert("Enter a 5 letter word");
        }
    }
    else if (keyPress == "Shift") {
        if (usr != '') {
            usr = '';
            do {
                clearOne();
            } while (currGrid % 5 > 1 || currGrid % 5 == 0);
        }
    }
})