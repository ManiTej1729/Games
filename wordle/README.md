# Wordle Game

Welcome to Wordle! This is a simple word-guessing game implemented using HTML, CSS, and vanilla JavaScript.

## How to Play

1. **Objective**: Guess the secret word within five attempts.

2. **Game Interface**:
   - The game interface consists of a grid of empty cells where you can input your guesses and a virtual keyboard to select letters.
   - Each cell represents a letter in the word you need to guess.
   - The virtual keyboard provides buttons for selecting letters, a backspace button for correcting mistakes, and a clear button to reset your guesses.
   - You can also use the physical keyboard to input your guesses:
     - Press any letter key to input the corresponding letter into the grid.
     - Use the "Backspace" key to delete the last letter entered.
     - Press "Enter" to submit your guess.
     - Press "Shift" to clear all entered letters of your current guess.

3. **Guessing Mechanism**:
   - Click on the letters in the virtual keyboard or use the physical keyboard to input your guesses into the grid.
   - Once you've entered a five-letter word, click the "Enter" button or press "Enter" on the keyboard to submit your guess.
   - If your guess is correct, you win the game. Otherwise, you'll be given feedback on each letter's correctness:
     - Green: Correct letter in the correct position.
     - Yellow: Correct letter, but in the wrong position.
     - Brown: Incorrect letter.

4. **Give Up Button**: If you want to give up, you can click the "Give Up" button to reveal the secret word and end the game.

## Technologies Used

- HTML
- CSS
- JavaScript
- jQuery

## Credits

- **BJSpell**: A JavaScript library for spell checking, used for word validation.
- **jQuery**: JavaScript library for simplifying DOM manipulation.

## Contributing

Contributions are welcome! If you'd like to contribute to the project, feel free to fork the repository and submit pull requests with your changes.
