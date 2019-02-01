//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object MagicSquare;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ToggleCallOutBypass();
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("Gorthaur");
    set_this_player(Player);
    Player->addCommands();
    Player->colorConfiguration("none");

    MagicSquare = clone_object("/lib/tutorial/temple/objects/magic-square.c");
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
    Player->colorConfiguration("3-bit");
    ExpectEq("\x1b[0;31m\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| \x1b[0;35m. \x1b[0;31m: \x1b[0;37;1mA \x1b[0;31m| \x1b[0;35m. \x1b[0;31m: \x1b[0;34;1mH \x1b[0;31m|\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| \x1b[0;35m. \x1b[0;31m: \x1b[0;34;1mH \x1b[0;31m| \x1b[0;32;1mY \x1b[0;31m: \x1b[0;35m. \x1b[0;31m|\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| \x1b[0;35m. \x1b[0;31m: \x1b[0;31;1mF \x1b[0;31m| \x1b[0;37;1mA \x1b[0;31m: \x1b[0;35m. \x1b[0;31m|\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| \x1b[0;35m. \x1b[0;31m: \x1b[0;35m. \x1b[0;31m| \x1b[0;35m. \x1b[0;31m: \x1b[0;35m. \x1b[0;31m|\n"
        "\t\t\t+===+===+===+===+\n\x1b[0m", 
        MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void BaseGridDisplaysCorrectBaseGridInUnicode()
{
    Player->colorConfiguration("3-bit");
    Player->charsetConfiguration("unicode");
    set_this_player(Player);
    ExpectEq("\x1b[0;31m\n\t\t\t\xe2\x95\x94\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\xa4\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\xa6\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\xa4\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x97\n"
             "\t\t\t\xe2\x95\x91 \x1b[0;35m\xe2\x88\xb7 \x1b[0;31m\xe2\x94\x8a \x1b[0;37;1m\xe1\x9a\xa3 \x1b[0;31m\xe2\x95\x91 \x1b[0;35m\xe2\x88\xb7 \x1b[0;31m\xe2\x94\x8a \x1b[0;34;1m\xe1\x9a\xbb \x1b[0;31m\xe2\x95\x91\n"
             "\t\t\t\xe2\x95\x9f\xe2\x94\x88\xe2\x94\x88\xe2\x94\x88+\xe2\x94\x88\xe2\x94\x88\xe2\x94\x88\xe2\x95\xab\xe2\x94\x88\xe2\x94\x88\xe2\x94\x88+\xe2\x94\x88\xe2\x94\x88\xe2\x94\x88\xe2\x95\xa2\n"
             "\t\t\t\xe2\x95\x91 \x1b[0;35m\xe2\x88\xb7 \x1b[0;31m\xe2\x94\x8a \x1b[0;34;1m\xe1\x9a\xbb \x1b[0;31m\xe2\x95\x91 \x1b[0;32;1m\xe1\x9a\xa1 \x1b[0;31m\xe2\x94\x8a \x1b[0;35m\xe2\x88\xb7 \x1b[0;31m\xe2\x95\x91\n"
             "\t\t\t\xe2\x95\x9f\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\xaa\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\xac\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\xaa\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\xa2\n"
             "\t\t\t\xe2\x95\x91 \x1b[0;35m\xe2\x88\xb7 \x1b[0;31m\xe2\x94\x8a \x1b[0;31;1m\xe1\x9a\xab \x1b[0;31m\xe2\x95\x91 \x1b[0;37;1m\xe1\x9a\xa3 \x1b[0;31m\xe2\x94\x8a \x1b[0;35m\xe2\x88\xb7 \x1b[0;31m\xe2\x95\x91\n"
             "\t\t\t\xe2\x95\x9f\xe2\x94\x88\xe2\x94\x88\xe2\x94\x88+\xe2\x94\x88\xe2\x94\x88\xe2\x94\x88\xe2\x95\xab\xe2\x94\x88\xe2\x94\x88\xe2\x94\x88+\xe2\x94\x88\xe2\x94\x88\xe2\x94\x88\xe2\x95\xa2\n"
             "\t\t\t\xe2\x95\x91 \x1b[0;35m\xe2\x88\xb7 \x1b[0;31m\xe2\x94\x8a \x1b[0;35m\xe2\x88\xb7 \x1b[0;31m\xe2\x95\x91 \x1b[0;35m\xe2\x88\xb7 \x1b[0;31m\xe2\x94\x8a \x1b[0;35m\xe2\x88\xb7 \x1b[0;31m\xe2\x95\x91\n"
             "\t\t\t\xe2\x95\x9a\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\xa7\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\xa9\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\xa7\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9d\n\x1b[0m", MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void FirstGridEntryCyclesWhenWPressed()
{
    command("push W", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| Y : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n", 
        MagicSquare->displayMagicSquare());

    command("push w", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| A : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());


    command("push w", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| F : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());

    command("push W", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| H : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());

    command("push W", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| Y : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void SecondGridEntryCyclesWhenWPressed()
{
    command("push S", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : A | Y : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void ThirdGridEntryCyclesWhenWPressed()
{
    command("push A", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| Y : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void FourthGridEntryCyclesWhenWPressed()
{
    command("push F", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : Y |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void FifthGridEntryCyclesWhenWPressed()
{
    command("push N", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| Y : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void SixthGridEntryCyclesWhenWPressed()
{
    command("push R", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : Y |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void SeventhGridEntryCyclesWhenWPressed()
{
    command("push P", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| Y : . | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void EigthGridEntryCyclesWhenWPressed()
{
    command("push E", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : Y | . : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void NinthGridEntryCyclesWhenWPressed()
{
    command("push D", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | Y : . |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());
}

/////////////////////////////////////////////////////////////////////////////
void TenthGridEntryCyclesWhenWPressed()
{
    command("push T", Player);
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : A | . : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : H | Y : . |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| . : F | A : . |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| . : . | . : Y |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());
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
    ExpectEq("\n\t\t\t+===+===+===+===+\n"
        "\t\t\t| Y : A | F : H |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| F : H | Y : A |\n"
        "\t\t\t+===+===+===+===+\n"
        "\t\t\t| H : F | A : Y |\n"
        "\t\t\t+---+---+---+---+\n"
        "\t\t\t| A : Y | H : F |\n"
        "\t\t\t+===+===+===+===+\n",
        MagicSquare->displayMagicSquare());

    ExpectTrue(present("rune", this_object()));
}
