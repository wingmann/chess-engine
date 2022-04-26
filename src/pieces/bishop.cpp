#include "pieces/bishop.h"
#include "engine.h"

#include <vector>

Bishop::Bishop(const PieceColor& color) : MovablePiece{color}
{
}

void Bishop::updatePossibleMoves(Condition condition, bool check, Coords coords)
{
    std::shared_ptr<std::vector<Coords>> possibleMoves;

    if (condition.getDraw50() > 99) {
        possibleMoves_ = possibleMoves;
        return;
    }
    Status::Type status;
    PieceColor::Type color;

    // For loop columns counter, rows counter.
    int row = coords.getRow();
    int column{};

    auto checkLocation = [&, this]()
    {
        status = condition.getFromChessBoard(row, column).getStatus().getType();

        // If the square is empty.
        if (status == Status::Type::Empty || status == Status::Type::EnPassant) {
            possibleMoves->emplace_back(Coords{row, column});
        }
        // Square has a piece.
        else  {
            color = condition.getFromChessBoard(row, column).getPieceColor().getType();

            // Piece is enemy.
            if (color != getPieceColor()->getType())
                possibleMoves->emplace_back(Coords{row, column});

            return false;
        }
        return true;
    };

    // Left top side.
    for (column = coords.getColumn() - 1; column >= 0; column--) {
        row--;

        if (row >= 0) {
            if (!checkLocation())
                break;
        }
        else {
            break;
        }
    }

    // Right top side.
    row = coords.getRow();

    for (column = coords.getColumn() + 1; column < 8; column++) {
        row--;

        if (row >= 0) {
            if (!checkLocation())
                break;
        }
        else {
            break;
        }
    }

    // Left bottom side.
    row = coords.getRow();

    for (column = coords.getColumn() - 1; column >= 0; column--) {
        row++;

        if (row < 8) {
            if (!checkLocation())
                break;
        }
        else {
            break;
        }
    }

    // Right bottom side.
    row = coords.getRow();

    for (column = coords.getColumn() + 1; column < 8; column++){
        row++;

        if (row < 8) {
            if (!checkLocation())
                break;
        }
        else {
            break;
        }
    }

    // If the king is in check or possible check after move of this piece...
    if (check || getProtectingKing()) {
        // Only check preventing moves are legal.
        for (std::size_t i = possibleMoves->size() - 1; i >= 0; i--) {
            auto validMoveDuring =
                Engine::validMoveDuringCheck(coords, possibleMoves->at(i), condition);

            if (!validMoveDuring) {
                auto iteration = 0;
                for (auto it = possibleMoves->begin(), end = possibleMoves->end(); it != end;) {
                    if (iteration == i) {
                        it = possibleMoves->erase(it);
                        break;
                    }
                    else {
                        ++it;
                    }
                }
            }
        }
    }
    possibleMoves_ = possibleMoves;
}

void Bishop::updatePossibleAttacks(Condition condition, Coords coords)
{
    setPieceProtectingKingCoords(Coords{8, 8});
    std::shared_ptr<std::vector<Coords>> possibleAttacks;

    Status::Type status;
    PieceColor::Type color;

    // For loop columns counter, rows counter.
    int row = coords.getRow();
    int column{};

    enum class LocationOperationType {
        ColumnMinusOne_MoreOrEqualThanZero_Dec,
        ColumnPlusOne_LessThanEight_Inc
    };

    auto checkInner = [&, this](auto innerRow, auto innerColumn)
    {
        status = condition
            .getFromChessBoard(innerRow, innerColumn)
            .getStatus()
            .getType();

        // Piece found.
        if (status == Status::Type::Empty || status == Status::Type::EnPassant) {
            return true;
        }

        // King found.
        if (status == Status::Type::King) {
            color = condition
                .getFromChessBoard(innerRow, innerColumn)
                .getPieceColor()
                .getType();

            // Enemy king..
            if (color != getPieceColor()->getType())
                setPieceProtectingKingCoords(Coords{row, column});
        }
        else {
            return false;
        }
    };

    // Left top side.
    for (column = coords.getColumn() - 1; column >= 0; column--) {
        row--;

        if (row >= 0) {
            status = condition.getFromChessBoard(row, column).getStatus().getType();

            // If the square is empty.
            if (status == Status::Type::Empty || status == Status::Type::EnPassant) {
                possibleAttacks->emplace_back(Coords{row, column});
            }
            // Square has a piece.
            else {
                possibleAttacks->emplace_back(Coords{row, column});

                color = condition.getFromChessBoard(row, column).getPieceColor().getType();

                // Checking whether there is enemy king behind the enemy piece.
                if (color != getPieceColor()->getType()) {
                    // Creating new variables for keeping the piece variables
                    int innerRow = row;
                    int innerColumn;

                    // Continuing in row after finding the 2nd piece
                    for (innerColumn = column - 1; innerColumn >= 0; innerColumn--) {
                        innerRow--;

                        if (innerRow >= 0) {
                            if (!checkInner(innerRow, innerColumn))
                                break;
                            else
                                continue;
                        }
                        else {
                            break;
                        }
                    }
                }
                break;
            }
        }
        else {
            break;
        }
    }

    // Right top side.
    row = coords.getRow();

    for (column = coords.getColumn() + 1; column < 8; column++) {
        row--;

        if (row >= 0) {
            status = condition.getFromChessBoard(row, column).getStatus().getType();

            // If the square is empty.
            if (status == Status::Type::Empty || status == Status::Type::EnPassant) {
                possibleAttacks->emplace_back(Coords{row, column});
            }
            // Square has a piece.
            else {
                possibleAttacks->emplace_back(Coords{row, column});

                color = condition.getFromChessBoard(row, column).getPieceColor().getType();

                // Checking whether there is enemy king behind the enemy piece.
                if (color != getPieceColor()->getType()) {
                    // Creating new variables for keeping the piece variables.
                    int innerRow = row;
                    int innerColumn;

                    // Continuing in row after finding the 2nd piece.
                    for (innerColumn = column + 1; innerColumn < 8; innerColumn++) {
                        innerRow--;

                        if (innerRow >= 0) {
                            if (!checkInner(innerRow, innerColumn))
                                break;
                            else
                                continue;
                        }
                        else {
                            break;
                        }
                    }
                }
                break;
            }
        }
        else {
            break;
        }
    }

    // Left bottom side.
    row = coords.getRow();

    for (column = coords.getColumn() - 1; column >= 0; column--) {
        row++;

        if (row < 8) {
            status = condition.getFromChessBoard(row, column).getStatus().getType();

            // If the square is empty.
            if (status == Status::Type::Empty || status == Status::Type::EnPassant) {
                possibleAttacks->emplace_back(Coords{row, column});
            }
            // Square has a piece.
            else {
                possibleAttacks->emplace_back(Coords{row, column});

                color = condition.getFromChessBoard(row, column).getPieceColor().getType();

                // Checking whether there is enemy king behind the enemy piece.
                if (color != getPieceColor()->getType()) {
                    // Creating new variables for keeping the piece variables.
                    int innerRow = row;
                    int innerColumn;

                    // Continuing in row after finding the 2nd piece.
                    for (innerColumn = column - 1; innerColumn >= 0; innerColumn--) {
                        innerRow++;

                        if (innerRow < 8) {
                            if (!checkInner(innerRow, innerColumn))
                                break;
                            else
                                continue;
                        }
                        else {
                            break;
                        }
                    }
                }
                break;
            }
        }
        else {
            break;
        }
    }

    row = coords.getRow();

    // Right bottom side.
    for (column = coords.getColumn() + 1; column < 8; column++) {
        row++;

        if (row < 8) {
            status = condition.getFromChessBoard(row, column).getStatus().getType();

            // If the square is empty.
            if (status == Status::Type::Empty || status == Status::Type::EnPassant) {
                possibleAttacks->emplace_back(Coords{row, column});
            }
                // Square has a piece.
            else {
                possibleAttacks->emplace_back(Coords{row, column});

                color = condition.getFromChessBoard(row, column).getPieceColor().getType();

                // Checking whether there is enemy king behind the enemy piece.
                if (color != getPieceColor()->getType()) {
                    // Creating new variables for keeping the piece variables.
                    int innerRow = row;
                    int innerColumn;

                    // Continuing in row after finding the 2nd piece.
                    for (innerColumn = column + 1; innerColumn < 8; innerColumn++) {
                        innerRow++;

                        if (innerRow < 8) {
                            if (!checkInner(innerRow, innerColumn))
                                break;
                            else
                                continue;
                        }
                        else {
                            break;
                        }
                    }
                }
                break;
            }
        }
        else {
            break;
        }
    }
    possibleAttacks_ = possibleAttacks;
}
