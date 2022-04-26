#ifndef WINGMANN_CHESS_ENGINE_ENGINE_H
#define WINGMANN_CHESS_ENGINE_ENGINE_H

#include "utility_components/coords.h"
#include "conditions/condition.h"
#include "conditions/calculated_condition.h"

#include <memory>
#include <functional>
#include <stack>
#include <chrono>

class Engine {
    double turnLength_{};
    double progressValue_{};
    double progressMaximum_{};

    // Keeps all possible moves.
    // Null in case nothing is selected.
    std::shared_ptr<Coords> selectedCoords_;

    // Keeps selected Emulator moves.
    // Null in case nothing is selected.
    std::shared_ptr<Coords> selectedAiCoords_;

    // Opens dialog window with pawn promotion options.
    std::function<bool(Status)> openPromotionOptions_;

    // Logically and memory inexpensive recorded condition.
    std::shared_ptr<Condition> condition_;

    // Calculated condition, including pieces and their possible moves.
    // std::shared_ptr<CalculatedCondition> calculatedCondition_;

    // History of executed moves by both players.
    std::shared_ptr<std::stack<Condition>> history_;

    // Future moves done by both players.
    std::shared_ptr<std::stack<Condition>> future_;

    // DateTime for turn length.
    std::chrono::high_resolution_clock dateTime_;

    // How many times player requested to return back to previous turn.
    int backCount_{};

    // How many times player requested to go forward to the next turn.
    int forwardCount_{};




// The chessboard.
// private readonly Button[,] _buttons;

// Text of color that is on turn.
// private readonly TextBlock _textBlockOnTurn;

// Text block for status displaying (check, mate...).
// private readonly TextBlock _textBlockStatus;

// Menu button for previous turn.
// private readonly MenuItem _back;

// Menu button for previous turn.
// private readonly MenuItem _forward;

// PieceColor lost pieces.
// private readonly WrapPanel _whiteLost;

// Black lost pieces.
// private readonly WrapPanel _blackLost;

// Emulator turn calculation progress.
// private readonly Grid _progressBar;

// Timer that updates UI during turn calculation.
//private readonly DispatcherTimer _timerUpdateUi;

// Task that calculates half turn of Emulator.
// private Task _turnTask = Task.Delay(0);

public:
    // event PropertyChangedEventHandler? PropertyChanged;

    /**
     * Specifies size of image of the taken piece, based on size of the play area.
     * The value is recalculated during window size change.
     */
    // public double ImageSizeWrapPanel { get; set; }

    /// <summary>
    /// Turn length in seconds.
    /// </summary>
    // double TurnLength
    //  {
    //        get => _turnLength;
    //        set
    //        {
    //            _turnLength = value;
    //            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(TurnLength)));
    //        }
    //  }

    /// <summary>
    /// ProgressBar value.
    /// </summary>
    //public double ProgressValue
    //  {
    //        get => _progressValue;
    //        set
    //        {
    //            _progressValue = value;
    //            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(ProgressValue)));
    //        }
    //  }

    /// <summary>
    /// ProgressBar maximum value.
    /// </summary>
    //public double ProgressMaximum
    //  {
    //        get => _progressMaximum;
    //        set
    //        {
    //            _progressMaximum = value;
    //            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(ProgressMaximum)));
    //        }
    //  }

// static int ProgressValueStatic;
// static int ProgressMaximumStatic = 0;
// static ConcurrentQueuedDictionary<string, CalculatedConditionData>
// CalculatedConditionData = new(50'000);

public:
//    Engine(
//        Button[,] buttons,
//        TextBlock textBlockOnTurn,
//        TextBlock textBlockStatus,
//        MenuItem back,
//        MenuItem forward,
//        WrapPanel whiteLost,
//        WrapPanel blackLost,
//        Grid progressBar,
//        Func<bool, Status> openPromotionOptions);

public:
    static void movePiece(Coords from, Coords to, Condition condition, bool automaticPromotion = true);
    static bool validMoveDuringCheck(Coords from, Coords to, Condition condition);
//    void ButtonClick(Coords coords);
//    void Back();
//    void Forward()

    void saveIntoFile();
    void loadFromFile();
    void loadedChessUserControl();
    void loadedNewGameUserControl();

private:
    void newGame();
    void movePiece(Coords from, Coords to, bool automaticPromotion = false);
    bool playerOnTurn();
    void drawCalculatedSituation();
    void setupBack();
    void setupForward();
    void selectPossibleMoves(Coords coords);
    void selectSquare(Coords coords, bool ai = false, bool main = false);
    void deselectSquare(Coords coords);
    void deselectAiCoords();
    void loadingUnsuccessful();
//    static Rectangle GenerateSelectedSquare(Brush color);
//    Image GeneratePieceImage(PieceId id, bool forWrapPanel = false);
//    static TextBlock GenerateNoLostPiecesTextBlock();
    void emulatorTurn();
//    void TimerUpdateUi_Tick(object? sender, EventArgs? e);
};

#endif // WINGMANN_CHESS_ENGINE_ENGINE_H
