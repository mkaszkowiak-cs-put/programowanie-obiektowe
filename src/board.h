#pragma once
#ifndef HEADER_BOARD
#define HEADER_BOARD

#include "constants.h"
#include "pieces.h"


class BoardState {
    public:
        BoardState();
        BoardState(BoardState& boardState);

        void printBoard();
        Piece* get(Position pos);
        std::unique_ptr<Piece> set(Position pos, std::unique_ptr<Piece> piece);
        bool movePiece(Position from, Position to);

    protected:
        std::unique_ptr<Piece> board[BOARD_SIZE][BOARD_SIZE];
};

class Board {
    public:
        Board();
        Board(std::shared_ptr<AbstractPieceFactory> pieceFactory);

        void printBoard();
        bool movePiece(Position from, Position to);

    protected:
        std::vector<Position> generateLegalMoves(Position from);
        bool isFriendlyPiece(Position pos);
        bool isFree(Position pos);
        bool isEnemyPiece(Position pos);
        bool isInsideBoard(Position pos);

        std::shared_ptr<BoardState> board;

        Color turn;
        Result result;
};


#endif