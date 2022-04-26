#include "pieces/types/piece_id.h"

PieceId::PieceId(const Status& status, const PieceColor& color)
    : status_{status},
      pieceColor_{color}
{
}

Status PieceId::getStatus() const
{
    return status_;
}

void PieceId::setStatus(const Status& status)
{
    status_ = status;
}

PieceColor PieceId::getPieceColor() const
{
    return pieceColor_;
}

void PieceId::setPieceColor(const PieceColor& color)
{
    pieceColor_ = color;
}
