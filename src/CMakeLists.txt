add_library(chessLibrary
  Board.cpp
  Game.cpp
  Piece.cpp
  Player.cpp
  Square.cpp
  ./Pieces/Bishop.cpp
  ./Pieces/King.cpp
  ./Pieces/Knight.cpp
  ./Pieces/Pawn.cpp
  ./Pieces/Queen.cpp
  ./Pieces/Rook.cpp
  DisplayBoard.cpp
)

add_dependencies(chessLibrary rapidjson)

find_library(M_LIB m)
target_link_libraries(chessLibrary ${M_LIB})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

add_executable(startGame
  main.cpp
)

target_link_libraries(startGame chessLibrary)
