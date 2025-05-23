// Function to be called when a key is pressed
function keyPressed(event) {
    console.log("Key pressed:", event.key);
}

// Adding event listener to the document
document.addEventListener("keydown", keyPressed);
