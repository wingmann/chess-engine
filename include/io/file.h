#ifndef WINGMANN_CHESS_ENGINE_IO_FILE_H
#define WINGMANN_CHESS_ENGINE_IO_FILE_H

#include "conditions/condition.h"

#include <list>
#include <fstream>
#include <memory>
#include <vector>

/**
 *
 */
class File {
    enum class Token : char {
        True = 'T',
        False = 'F',
        Invalid = '\xff',
        Return = '\r'
    };

    std::unique_ptr<Condition> condition_{};
    std::unique_ptr<std::vector<std::unique_ptr<PieceId>>> blackTaken_{};
    std::unique_ptr<std::vector<std::unique_ptr<PieceId>>> whiteTaken_{};
    std::unique_ptr<std::vector<std::unique_ptr<Condition>>> history_{};

public:
    File() = default;

    /**
     *
     * @param condition
     * @param blackTaken
     * @param whiteTaken
     * @param history
     */
    File(
        std::unique_ptr<Condition> condition,
        std::unique_ptr<std::vector<std::unique_ptr<PieceId>>> blackTaken,
        std::unique_ptr<std::vector<std::unique_ptr<PieceId>>> whiteTaken,
        std::unique_ptr<std::vector<std::unique_ptr<Condition>>> history);

public:
    /**
     *
     * @param fileName
     */
    void Save(const std::string& fileName);

    /**
     *
     * @param in
     */
    void Load(const std::ifstream& in);

private:
    void writeBasicData(const std::ofstream& stream, const std::unique_ptr<Condition>& condition);
    std::unique_ptr<Condition> readBasicData(const std::ifstream& stream);

    [[nodiscard]] static char tokenToChar(File::Token token);
};

#endif // WINGMANN_CHESS_ENGINE_IO_FILE_H
