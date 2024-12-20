//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object MagicSquare;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    load_object("/lib/dictionaries/environmentDictionary.c");

    ToggleCallOutBypass();
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("Gorthaur");
    set_this_player(Player);
    Player.addCommands();
    Player.colorConfiguration("none");

    MagicSquare = clone_object("/tutorial/temple/objects/magic-square.c");
    move_object(Player, this_object());
    move_object(MagicSquare, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(MagicSquare);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void BaseGridDisplaysCorrectBaseGrid()
{
    Player.colorConfiguration("3-bit");
    ExpectEq("\x1b[0;31m\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| \x1b[0;35m. \x1b[0;31m: \x1b[0;37;1mA \x1b[0;31m| \x1b[0;35m. \x1b[0;31m: \x1b[0;34;1mH \x1b[0;31m|        | \x1b[0;35mw \x1b[0;31m: \x1b[0;35m  \x1b[0;31m| \x1b[0;35ms \x1b[0;31m: \x1b[0;35m  \x1b[0;31m|\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| \x1b[0;35m. \x1b[0;31m: \x1b[0;34;1mH \x1b[0;31m| \x1b[0;32;1mY \x1b[0;31m: \x1b[0;35m. \x1b[0;31m|        | \x1b[0;35ma \x1b[0;31m: \x1b[0;35m  \x1b[0;31m| \x1b[0;35m  \x1b[0;31m: \x1b[0;35mf \x1b[0;31m|\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| \x1b[0;35m. \x1b[0;31m: \x1b[0;31;1mF \x1b[0;31m| \x1b[0;37;1mA \x1b[0;31m: \x1b[0;35m. \x1b[0;31m|        | \x1b[0;35mn \x1b[0;31m: \x1b[0;35m  \x1b[0;31m| \x1b[0;35m  \x1b[0;31m: \x1b[0;35mr \x1b[0;31m|\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| \x1b[0;35m. \x1b[0;31m: \x1b[0;35m. \x1b[0;31m| \x1b[0;35m. \x1b[0;31m: \x1b[0;35m. \x1b[0;31m|        | \x1b[0;35mp \x1b[0;31m: \x1b[0;35me \x1b[0;31m| \x1b[0;35md \x1b[0;31m: \x1b[0;35mt \x1b[0;31m|\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n\x1b[0m", 
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void BaseGridDisplaysCorrectBaseGridInUnicode()
{
    Player.colorConfiguration("3-bit");
    Player.charsetConfiguration("unicode");

    ExpectEq("\x1b[0;31m\n\t\t\u2554\u2550\u2550\u2550\u2564\u2550\u2550\u2550\u2566\u2550\u2550\u2550\u2564\u2550\u2550\u2550\u2557"
             "        \u2554\u2550\u2550\u2550\u2564\u2550\u2550\u2550\u2566\u2550\u2550\u2550\u2564\u2550\u2550\u2550\u2557\n"
             "\t\t\u2551 \x1b[0;35m\u2237 \x1b[0;31m\u250a \x1b[0;37;1m\u16a3 \x1b[0;31m\u2551 \x1b[0;35m\u2237 \x1b[0;31m\u250a \x1b[0;34;1m\u16bb \x1b[0;31m\u2551"
             "        \u2551 \x1b[0;35mw \x1b[0;31m\u250a \x1b[0;35m  \x1b[0;31m\u2551 \x1b[0;35ms \x1b[0;31m\u250a \x1b[0;35m  \x1b[0;31m\u2551\n"
             "\t\t\u255f\u2508\u2508\u2508+\u2508\u2508\u2508\u256b\u2508\u2508\u2508+\u2508\u2508\u2508\u2562"
             "        \u255f\u2508\u2508\u2508+\u2508\u2508\u2508\u256b\u2508\u2508\u2508+\u2508\u2508\u2508\u2562\n"
             "\t\t\u2551 \x1b[0;35m\u2237 \x1b[0;31m\u250a \x1b[0;34;1m\u16bb \x1b[0;31m\u2551 \x1b[0;32;1m\u16a1 \x1b[0;31m\u250a \x1b[0;35m\u2237 \x1b[0;31m\u2551"
             "        \u2551 \x1b[0;35ma \x1b[0;31m\u250a \x1b[0;35m  \x1b[0;31m\u2551 \x1b[0;35m  \x1b[0;31m\u250a \x1b[0;35mf \x1b[0;31m\u2551\n"
             "\t\t\u255f\u2550\u2550\u2550\u256a\u2550\u2550\u2550\u256c\u2550\u2550\u2550\u256a\u2550\u2550\u2550\u2562"
             "        \u255f\u2550\u2550\u2550\u256a\u2550\u2550\u2550\u256c\u2550\u2550\u2550\u256a\u2550\u2550\u2550\u2562\n"
             "\t\t\u2551 \x1b[0;35m\u2237 \x1b[0;31m\u250a \x1b[0;31;1m\u16ab \x1b[0;31m\u2551 \x1b[0;37;1m\u16a3 \x1b[0;31m\u250a \x1b[0;35m\u2237 \x1b[0;31m\u2551"
             "        \u2551 \x1b[0;35mn \x1b[0;31m\u250a \x1b[0;35m  \x1b[0;31m\u2551 \x1b[0;35m  \x1b[0;31m\u250a \x1b[0;35mr \x1b[0;31m\u2551\n"
             "\t\t\u255f\u2508\u2508\u2508+\u2508\u2508\u2508\u256b\u2508\u2508\u2508+\u2508\u2508\u2508\u2562"
             "        \u255f\u2508\u2508\u2508+\u2508\u2508\u2508\u256b\u2508\u2508\u2508+\u2508\u2508\u2508\u2562\n"
             "\t\t\u2551 \x1b[0;35m\u2237 \x1b[0;31m\u250a \x1b[0;35m\u2237 \x1b[0;31m\u2551 \x1b[0;35m\u2237 \x1b[0;31m\u250a \x1b[0;35m\u2237 \x1b[0;31m\u2551"
             "        \u2551 \x1b[0;35mp \x1b[0;31m\u250a \x1b[0;35me \x1b[0;31m\u2551 \x1b[0;35md \x1b[0;31m\u250a \x1b[0;35mt \x1b[0;31m\u2551\n"
             "\t\t\u255a\u2550\u2550\u2550\u2567\u2550\u2550\u2550\u2569\u2550\u2550\u2550\u2567\u2550\u2550\u2550\u255d"
             "        \u255a\u2550\u2550\u2550\u2567\u2550\u2550\u2550\u2569\u2550\u2550\u2550\u2567\u2550\u2550\u2550\u255d\n\x1b[0m", 
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void FirstGridEntryCyclesWhenWPressed()
{
    command("push W", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| Y : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n", 
        MagicSquare.displayMagicSquare());

    command("push w", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| A : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());


    command("push w", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| F : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());

    command("push W", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| H : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());

    command("push W", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| Y : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void SecondGridEntryCyclesWhenWPressed()
{
    command("push S", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : A | Y : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void ThirdGridEntryCyclesWhenWPressed()
{
    command("push A", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| Y : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void FourthGridEntryCyclesWhenWPressed()
{
    command("push F", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : Y |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void FifthGridEntryCyclesWhenWPressed()
{
    command("push N", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| Y : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void SixthGridEntryCyclesWhenWPressed()
{
    command("push R", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : Y |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void SeventhGridEntryCyclesWhenWPressed()
{
    command("push P", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| Y : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void EigthGridEntryCyclesWhenWPressed()
{
    command("push E", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : Y | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void NinthGridEntryCyclesWhenWPressed()
{
    command("push D", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | Y : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void TenthGridEntryCyclesWhenWPressed()
{
    command("push T", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : Y |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void DoNotCycleInitialSolvedSquares()
{
    command("push z", Player);
    command("push y", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : A | . : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : H | Y : . |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| . : F | A : . |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| . : . | . : . |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void CanSolvePuzzle()
{
    command("push w", Player);
    command("push s", Player);
    command("push s", Player);
    command("push s", Player);
    command("push a", Player);
    command("push a", Player);
    command("push a", Player);
    command("push f", Player);
    command("push f", Player);
    command("push n", Player);
    command("push n", Player);
    command("push n", Player);
    command("push n", Player);
    command("push r", Player);
    command("push p", Player);
    command("push p", Player);
    command("push e", Player);
    command("push d", Player);
    command("push d", Player);
    command("push d", Player);
    command("push d", Player);
    command("push t", Player);
    command("push t", Player);
    ExpectFalse(present("rune", this_object()));

    command("push t", Player);
    ExpectEq("\n\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| Y : A | F : H |        | w :   | s :   |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| F : H | Y : A |        | a :   |   : f |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n"
        "\t\t| H : F | A : Y |        | n :   |   : r |\n"
        "\t\t+---+---+---+---+        +---+---+---+---+\n"
        "\t\t| A : Y | H : F |        | p : e | d : t |\n"
        "\t\t+===+===+===+===+        +===+===+===+===+\n",
        MagicSquare.displayMagicSquare());

    ExpectTrue(present("rune", this_object()));
}
