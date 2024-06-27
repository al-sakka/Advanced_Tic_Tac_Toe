# Advanced Tic Tac Toe Game

## Overview

This project is a Tic Tac Toe game developed using Qt C++. It features both multiplayer and single-player modes with three difficulty levels: Easy, Medium, and Hard. The game employs the minimax algorithm for medium and hard modes, while the easy mode uses a simpler algorithm to select moves. Additionally, the game records every move in a database and maintains a history of all played matches. A registration system (login and signup) is also implemented, utilizing QtSql for database operations.

## Features

- **Multiplayer Mode**: Play against another player.
- **Single Player Mode**:
  - **Easy**: Uses a simple algorithm to select moves.
  - **Medium**: Employs the minimax algorithm for a challenging experience.
  - **Hard**: Utilizes the minimax algorithm for the most challenging experience.
- **Game History**: Records and maintains the history of all played matches.
- **Move Recording**: Each move is recorded in the database.
- **User Registration**: Includes a registration system with login and signup functionality.
- **Database Integration**: Uses QtSql to manage the game database.

## Installation

### Prerequisites

- **Qt**: Make sure you have Qt installed on your system. You can download it from [Qt Downloads](https://www.qt.io/download).
- **QtSql**: Ensure that QtSql is installed and properly configured.
- **C++ Compiler**: A compatible C++ compiler is required.

### Steps

1. **Clone the Repository**:
   ```sh
   git clone https://github.com/al-sakka/Advanced_Tic_Tac_Toe
   ```

2. **Open the Project**:
   Open the project using Qt Creator or any other compatible IDE.

3. **Configure the Database**:
   - Ensure your database is set up correctly.
   - Update the database connection details in the project source code as necessary.

4. **Build and Run**:
   - Build the project using your IDE.
   - Run the executable to start playing.

## Usage

### Single Player Mode

1. Select "Single Player" from the main menu.
2. Choose the desired difficulty level: Easy, Medium, or Hard.
3. Play against the computer.

### Multiplayer Mode

1. Select "Multiplayer" from the main menu.
2. Play against another player on the same device.

### Registration

1. Register a new account using the "Sign Up" option.
2. Log in using the "Login" option to access the game's features.

### Viewing Game History

1. Log in to your account.
2. Access the game history from the main menu to view all previously played matches.

## Algorithms

### Minimax Algorithm

- **Medium Difficulty**: The minimax algorithm is used to provide a challenging game experience.
- **Hard Difficulty**: The minimax algorithm ensures the highest level of challenge.

### Easy Mode Algorithm

- A simple algorithm that searches for empty cells to make a move.

## Database

- The game uses QtSql to interact with the database.
- Every move and game result is recorded for future reference.
- User information and game history are stored securely.


Please fork the repository and create a pull request with your changes. Ensure that your code adheres to the project's coding standards and includes appropriate documentation.


## Contact

For any inquiries or issues, please contact [sakka.bt@gmail.com](mailto:sakka.bt@gmail.com).

Happy Coding.
