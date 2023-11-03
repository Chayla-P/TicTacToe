<!DOCTYPE html>
<html>
  <head>
    <style>
      .board {
        display: grid;
        grid-template-columns: repeat(3, 100px);
        grid-gap: 5px;
      }

      .cell {
        width: 100px;
        height: 100px;
        font-size: 100px;
        text-align: center;
        border: 2px solid #000;
        cursor: pointer;
      }
    </style>
  </head>
  <body>
    <h1>Tic-Tac-Toe</h1>
    <div class="board" id="board">
      <div class="cell" onclick="makeMove(0, 0)"></div>
      <div class="cell" onclick="makeMove(0, 1)"></div>
      <div class="cell" onclick="makeMove(0, 2)"></div>
      <div class="cell" onclick="makeMove(1, 0)"></div>
      <div class="cell" onclick="makeMove(1, 1)"></div>
      <div class="cell" onclick="makeMove(1, 2)"></div>
      <div class="cell" onclick="makeMove(2, 0)"></div>
      <div class="cell" onclick="makeMove(2, 1)"></div>
      <div class="cell" onclick="makeMove(2, 2)"></div>
    </div>
    <h2 id="statusText"></h2>
    <button id=restart">Restart</button>

    <p id="result"></p>

    <script>
      const board = document.getElementById("board");
      const cells = board.getElementsByClassName("cell");
      const result = document.getElementById("result");

      let currentPlayer = "X";
      let boardState = [
        ["", "", ""],
        ["", "", ""],
        ["", "", ""]
      ];
      let gameOver = false;

      function makeMove(row, col) {
        if (!gameOver && boardState[row][col] === "") {
          boardState[row][col] = currentPlayer;
          cells[row * 3 + col].textContent = currentPlayer;

          if (checkWin(row, col)) {
            result.textContent = `Player ${currentPlayer} wins!`;
            gameOver = true;
          } else if (boardIsFull()) {
            result.textContent = "It's a draw!";
            gameOver = true;
          } else {
            currentPlayer = currentPlayer === "X" ? "O" : "X";
          }
        }
      }

      function checkWin(row, col) {
        return checkRow(row) || checkCol(col) || checkDiagonals(row, col);
      }

      function checkRow(row) {
        return (
          boardState[row][0] === currentPlayer &&
          boardState[row][1] === currentPlayer &&
          boardState[row][2] === currentPlayer
        );
      }

      function checkCol(col) {
        return (
          boardState[0][col] === currentPlayer &&
          boardState[1][col] === currentPlayer &&
          boardState[2][col] === currentPlayer
        );
      }

      function checkDiagonals(row, col) {
        if (row === col || row + col === 2) {
          return (
            boardState[0][0] === currentPlayer &&
            boardState[1][1] === currentPlayer &&
            boardState[2][2] === currentPlayer
          );
        }
        return false;
      }

      function boardIsFull() {
        for (let i = 0; i < 3; i++) {
          for (let j = 0; j < 3; j++) {
            if (boardState[i][j] === "") {
              return false;
            }
            function restartgame() {}
          }
        }
        return true;
      }
    </script>
  </body>
</html>
