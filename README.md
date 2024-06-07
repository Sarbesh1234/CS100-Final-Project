# Papua New Guinea Chess ![example workflow](https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/actions/workflows/main.yml/badge.svg)
 
Authors: [Andrew Garcia](https://github.com/andytgarcia) [Justin Albert](https://github.com/jnalbert) [Rishabh Pillai](https://github.com/hackinrish) [Sarbesh Sankar](https://github.com/sarbesh1234)


## Project Description
1. Why is it important or interesting to you?

This project is important to us because we all love playing chess. We often play on sites like chess.com together and against other people in the world. However, while playing, we never think about the inner workings of the game. We know the rules of chess, but as computer science majors, we don’t know exactly how they are implemented, how the games are saved, and how moves are exactly executed. With this project, we’re excited to combine our love for chess with the computer science principles we have been learning.

2. What languages/tools/technologies do you plan to use?

We plan to use C++ as our programming language. Our app will be entirely terminal so we will use C++ to code the “user interface” as well as the backend logic. We will also be using Google’s GTest as well as Valgrind and GDB for our debugging.

3. What will be the input/output of your project?

Our project input and output will involve movements of chess pieces. So, for example, the user will specify the location of a piece they want to move and then the destination they want to move it to. For previously saved games, we will allow users to name the game and save it for later to be played again. The output of this project will display the chess board in its current state after any piece is moved. The game will also display error messages if a piece is moved into an invalid location.  

4. What are the features that the project provides?

Our application will involve a functional two-player chess game that adheres to all of the rules of chess.
* Players will be able to select squares on the chess board through the terminal that acts as the to and from locations.
  * These moves will be validated against basic chess rules based on whichever piece they choose.
* Users will be able to play against another person on the same device with the game switching off “plays” between each player
* Users will be able to save a game with a certain player for later and give it a name
* Users will be able to come back at a later date and access this game and restart it right where they left off


## Phase II

## User Interface Specification

### Navigation Diagram
<img width="4682" alt="rchess" src="https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/112200249/5c4d029e-aa41-4343-9b09-93593e05c210">


### Screen Layouts
![CS100-Screen-Layout-Final-Project](https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/112200249/10384dbc-4606-4afe-924c-3ab1fa72319e)


## Class Diagram
![R'Chess UML (0)](https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/112200249/88c2ea4b-87f2-4927-a10e-bc1a34be69bf)



## Phase III

Updated UML diagram
![R'Chess UML](https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/112200249/4f7400e5-c852-4ae7-afff-d654687fe6ae)


The SOLID principle applied in our new UML diagram is the Single Responsibility Principle. We applied it by making a new class called DisplayBoard that was in charge of displaying the board to the terminal, as opposed to the Board class being in charge of printing. This ensure that the Board has only the responsibility of holding the locations of the Pieces by being a 2D array of Square pointers. This change has helped us write better code because it makes less tests for either class, and it keeps the classes smaller and more organized. 
 
 ## Final deliverable
 
 ## Screenshots
<img width="710" alt="Screenshot 2024-06-06 at 8 39 11 PM" src="https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/65417105/cc937e79-e127-4615-83e2-1d0f80e6e267">
<img width="710" alt="Screenshot 2024-06-06 at 8 40 14 PM" src="https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/65417105/dce010be-a5de-43b9-9e16-eceb70b2ee5b">

 <img width="710" alt="Screenshot 2024-06-06 at 8 40 31 PM" src="https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/65417105/0ffb0f97-cf46-48c4-9100-3ea9ab0f296f">

 <img width="710" alt="Screenshot 2024-06-06 at 8 44 01 PM" src="https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/65417105/b5f93080-297f-4814-9b16-abbe5b17f9fa">
 
<img width="710" alt="Screenshot 2024-06-06 at 8 44 17 PM" src="https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/65417105/9dff7bca-f1c3-469c-8ce9-148952c46cb5">

<img width="752" alt="Screenshot 2024-06-06 at 8 47 00 PM" src="https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/65417105/590f1404-720a-478f-ac48-20b22bd10a9f">

<img width="753" alt="Screenshot 2024-06-06 at 8 47 43 PM" src="https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/65417105/7f9bb3dc-8713-4f8f-b0ec-e2f89720c879">


 ## Installation/Usage

 To run our project, first you must clone the repository recursively, using
 ```
 git clone --recursive https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019.git
 ```

 Once the project is installed, open the root directory and run cmake to install all dependencies.
 ```
 cmake .
 ```

 After, you can run make to compile
 ```
 make
 ```

 Finally, to start playing, run
 ```
 ./bin/startGame
 ```
 
 ## Testing
 Our project was tested using the [GoogleTest](https://github.com/google/googletest) framework. It was validated using GitHub Actions Continuous Integration.
 You can run these tests by running the above cmake commands and then running
 
 ```
 ./bin/runAllTests
 ```
