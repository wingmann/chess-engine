#include "io/file.h"

#include <utility>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>

File::File(std::unique_ptr<Condition> condition,
    std::unique_ptr<std::vector<std::unique_ptr<PieceId>>> blackTaken,
    std::unique_ptr<std::vector<std::unique_ptr<PieceId>>> whiteTaken,
    std::unique_ptr<std::vector<std::unique_ptr<Condition>>> history)
    : condition_{std::move(condition)},
      blackTaken_{std::move(blackTaken)},
      whiteTaken_{std::move(whiteTaken)},
      history_{std::move(history)}
{
}

void File::Save(const std::string& fileName)
{
    // Writing out into the file.
    std::ofstream out{fileName, std::fstream::out};

    if (out.is_open()) {
        writeBasicData(out, condition_);

        // Writing taken pieces into 11th and 12th line.
        for (const auto& id : *blackTaken_) {
            out << id->getStatus().toChar();
            out << PieceColor{PieceColor::Type::Black}.toChar();
        }
        out << '\n';

        for (const auto& id : *whiteTaken_) {
            out << id->getStatus().toChar();
            out << PieceColor{PieceColor::Type::White}.toChar();
        }
        out << '\n';

        // Writing moves history into 13th to n-th line.
        for (const auto& condition : *history_)
            writeBasicData(out, (std::unique_ptr<Condition>&)condition);
    }
    out.close();
}

void File::Load(const std::ifstream& in)
{
    condition_ = std::make_unique<Condition>();
    history_->clear();
    blackTaken_->clear();
    whiteTaken_->clear();

    if (in.is_open()) {
        condition_ = readBasicData(in);

        // Loading taken pieces in logical form.
        std::string lineText;

//        std::getline(in, lineText);

        for (int charNumber = 0; charNumber < lineText.size(); charNumber += 2) {
            blackTaken_->emplace_back(std::make_unique<PieceId>(
                Status{lineText[charNumber]},
                PieceColor{PieceColor::Type::Black}));
        }
//        in >> lineText;

        for (int charNumber = 0; charNumber < lineText.size(); charNumber += 2) {
            whiteTaken_->emplace_back(std::make_unique<PieceId>(
                Status{lineText[charNumber]},
                PieceColor{PieceColor::Type::White}));
        }

        // Loading executed moves history.
        std::vector<std::unique_ptr<Condition>> reversedHistory;

        while (true) {
            auto condition = readBasicData(in);
            if (!condition) break;

            reversedHistory.emplace_back(std::move(condition));
        }

        for (std::size_t i = reversedHistory.size() - 1; i >= 0; i--)
            history_->emplace_back(std::move(reversedHistory[i]));
    }
}

void File::writeBasicData(const std::ofstream& stream, const std::unique_ptr<Condition>& condition)
{
}

std::unique_ptr<Condition> File::readBasicData(const std::ifstream& stream)
{
    return std::make_unique<Condition>();
}

char File::tokenToChar(File::Token token)
{
    switch (token) {
    case Token::True:
        return static_cast<char>(Token::True);
    case Token::False:
        return static_cast<char>(Token::False);
    case Token::Return:
        return static_cast<char>(Token::Return);
    default:
        return static_cast<char>(Token::Invalid);
    }
}
