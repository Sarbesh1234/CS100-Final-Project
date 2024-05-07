# R'Chess
 
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
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from the User Interface Design Document Template of CMSC 345 at the University of Maryland Global Campus)

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

 <img width="4682" alt="rchess" src="https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/112200249/438fc5cd-5fe6-42a3-baa1-8b9b648e6d7c">


### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs and expected output, or any graphical user interface components if applicable (e.g. buttons, text boxes, etc). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

![CS100-Screen-Layout-Final-Project](https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/112200249/0188ad2a-ed3f-469f-a28d-e20cdec6d3b3)


## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).

 ![R'Chess UML](https://github.com/cs100/final-project-agarc938-jalbe020-rpill005-ssank019/assets/112200249/a196bcbf-e972-4483-8f70-7344f008eee1)

 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
