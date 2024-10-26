<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">


<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>石头剪子布游戏</title>
    <style>
        #game-results {
            margin-top: 20px;
        }
        .result {
            margin-bottom: 10px;
        }
    </style>
    <script>
        function playGame(playerChoice) {
            var computerChoice = getComputerChoice();
            var result = determineWinner(playerChoice, computerChoice);
            displayResult(playerChoice, computerChoice, result);
        }

        function getComputerChoice() {
            var choices = ["rock", "paper", "scissors"];
            return choices[Math.floor(Math.random() * choices.length)];
        }

        function determineWinner(playerChoice, computerChoice) {
            if (playerChoice === computerChoice) {
                return "平局！";
            } else if ((playerChoice === "rock" && computerChoice === "scissors") ||
                       (playerChoice === "scissors" && computerChoice === "paper") ||
                       (playerChoice === "paper" && computerChoice === "rock")) {
                return "你赢了！";
            } else {
                return "电脑赢了！";
            }
        }

        function displayResult(playerChoice, computerChoice, result) {
            var resultsContainer = document.getElementById('game-results');
            var resultElement = document.createElement('div');
            resultElement.className = 'result';
            resultElement.innerHTML = "你出了 " + playerChoice + "，电脑出了 " + computerChoice + "。" + result;
            resultsContainer.appendChild(resultElement);
        }
    </script>
</head>
<body>
    <h1>石头剪子布游戏</h1>
    <div>
        <button onclick="playGame('rock')">石头</button>
        <button onclick="playGame('paper')">剪子</button>
        <button onclick="playGame('scissors')">布</button>
    </div>
    <div id="game-results"></div>
</body>
</html>
