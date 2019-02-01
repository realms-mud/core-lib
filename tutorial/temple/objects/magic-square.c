//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping squareDisplay = ([
    "Y":([
        "character":([
            "unicode": "\xe1\x9a\xa1",
            "ascii": "Y"
        ]),
        "color":([
            "none": "",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;28;1m",
            "24-bit": "\x1b[0;38;2;0;180;0;1m"
        ]),
        "next": "A"
    ]),
    "A":([
        "character":([
            "unicode": "\xe1\x9a\xa3",
            "ascii": "A"
        ]),
        "color":([
            "none": "",
            "3-bit": "\x1b[0;37;1m",
            "8-bit": "\x1b[0;38;5;15;1m",
            "24-bit": "\x1b[0;38;2;255;255;255;1m"
        ]),
        "next": "F"
    ]),
    "F":([
        "character":([
            "unicode": "\xe1\x9a\xab",
            "ascii": "F"
        ]),
        "color":([
            "none": "",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;124;1m",
            "24-bit": "\x1b[0;38;2;180;0;0;1m"
        ]),
        "next": "H"
    ]),
    "H":([
        "character":([
            "unicode": "\xe1\x9a\xbb",
            "ascii": "H"
        ]),
        "color": ([
            "none": "",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;0;220;1m"
        ]),
        "next": "Y"
    ]),
    "E":([
        "character":([
            "unicode": "\xe2\x88\xb7",
            "ascii": "."
        ]),
        "color":([
            "none": "",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;244;1m",
            "24-bit": "\x1b[0;38;2;120;120;120;1m"
        ]),
        "next": "Y"
    ]),
    "grid":([
        "none": "",
        "3-bit": "\x1b[0;31m",
        "8-bit": "\x1b[0;38;5;9m",
        "24-bit": "\x1b[0;38;2;200;0;0m"
    ]),
]);

private mapping gridDisplay = ([
    "/":([
        "unicode": "\xe2\x95\x94",
        "ascii": "+"
    ]),
    "`":([
        "unicode": "\xe2\x95\x97",
        "ascii": "+"
    ]),
    "~":([
        "unicode": "\xe2\x95\x90",
        "ascii": "="
    ]),
    "-":([
        "unicode": "\xe2\x94\x88",
        "ascii": "-"
    ]),
    "T":([
        "unicode": "\xe2\x95\xa6",
        "ascii": "+"
    ]),
    "t":([
        "unicode": "\xe2\x95\xa4",
        "ascii": "+"
    ]),
    "I":([
        "unicode": "\xe2\x95\x91",
        "ascii": "|"
    ]),
    ":":([
        "unicode": "\xe2\x94\x8a",
        "ascii": ":"
    ]),
    "<":([
        "unicode": "\xe2\x95\x9f",
        "ascii": "+"
    ]),
    ">":([
        "unicode": "\xe2\x95\xa2",
        "ascii": "+"
    ]),
    "#":([
        "unicode": "\xe2\x95\xab",
        "ascii": "+"
    ]),
    "v":([
        "unicode": "+",
        "ascii": "+"
    ]),
    "x":([
        "unicode": "\xe2\x95\xaa",
        "ascii": "+"
    ]),
    "X":([
        "unicode": "\xe2\x95\xac",
        "ascii": "+"
    ]),
    "L":([
        "unicode": "\xe2\x95\x9a",
        "ascii": "+"
    ]),
    "l":([
        "unicode": "\xe2\x95\x9d",
        "ascii": "+"
    ]),
    "U":([
        "unicode": "\xe2\x95\xa9",
        "ascii": "+"
    ]),
    "u":([
        "unicode": "\xe2\x95\xa7",
        "ascii": "+"
    ]),
]);

private mapping magicSquare = ([
    "A1":([
        "initial": "E",
        "current": "E",
        "solved": "Y",
    ]),
    "A2":([
        "initial": "A",
        "current": "A",
        "solved": "A",
    ]),
    "A3":([
        "initial": "E",
        "current": "E",
        "solved": "F",
    ]),
    "A4":([
        "initial": "H",
        "current": "H",
        "solved": "H",
    ]),
    "B1":([
        "initial": "E",
        "current": "E",
        "solved": "F",
    ]),
    "B2":([
        "initial": "H",
        "current": "H",
        "solved": "H",
    ]),
    "B3":([
        "initial": "Y",
        "current": "Y",
        "solved": "Y",
    ]),
    "B4":([
        "initial": "E",
        "current": "E",
        "solved": "A",
    ]),
    "C1":([
        "initial": "E",
        "current": "E",
        "solved": "H",
    ]),
    "C2":([
        "initial": "F",
        "current": "F",
        "solved": "F",
    ]),
    "C3":([
        "initial": "A",
        "current": "A",
        "solved": "A",
    ]),
    "C4":([
        "initial": "E",
        "current": "E",
        "solved": "Y",
    ]),
    "D1":([
        "initial": "E",
        "current": "E",
        "solved": "A",
    ]),
    "D2":([
        "initial": "E",
        "current": "E",
        "solved": "Y",
    ]),
    "D3":([
        "initial": "E",
        "current": "E",
        "solved": "H",
    ]),
    "D4":([
        "initial": "E",
        "current": "E",
        "solved": "F",
    ]),
]);

private mapping buttons = ([
    "W": "A1",
    "S": "A3",
    "A": "B1",
    "F": "B4",
    "N": "C1",
    "R": "C4",
    "P": "D1",
    "E": "D2",
    "D": "D3",
    "T": "D4"
]);

private int buttonsCanBePressed = 1;

/////////////////////////////////////////////////////////////////////////////
private int isValidPattern()
{
    int ret = 1;
    foreach(string entry in m_indices(magicSquare))
    {
        ret &&= magicSquare[entry]["current"] ==
            magicSquare[entry]["solved"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string grid(object configuration, string colorConfig, 
    string charsetConfig)
{
    string grid = "\n\t\t\t/~~~t~~~T~~~t~~~`\n"
                  "\t\t\tI A1: A2I A3: A4I\n"
                  "\t\t\t<---v---#---v--->\n"
                  "\t\t\tI B1: B2I B3: B4I\n"
                  "\t\t\t<~~~x~~~X~~~x~~~>\n"
                  "\t\t\tI C1: C2I C3: C4I\n"
                  "\t\t\t<---v---#---v--->\n"
                  "\t\t\tI D1: D2I D3: D4I\n"
                  "\t\t\tL~~~u~~~U~~~u~~~l\n";

    foreach(string character in m_indices(gridDisplay))
    {
        grid = regreplace(grid, character, 
            gridDisplay[character][charsetConfig], 1);
    }

    return configuration->decorate(grid, "display", "grid", colorConfig);
}

/////////////////////////////////////////////////////////////////////////////
public string displayMagicSquare()
{
    object user = this_player();

    object configuration = load_object("/lib/dictionaries/configurationDictionary.c");
    string colorConfig = (objectp(user) && user->colorConfiguration()) ?
        user->colorConfiguration() : "none";

    string charsetConfig = (objectp(user) && user->charsetConfiguration()) ?
        user->charsetConfiguration() : "ascii";

    string grid = grid(configuration, colorConfig, charsetConfig);

    foreach(string entry in m_indices(magicSquare))
    {
        string currentEntry = magicSquare[entry]["current"];
        string replacementString =
            squareDisplay[currentEntry]["color"][colorConfig] +
            squareDisplay[currentEntry]["character"][charsetConfig] + " " +
            squareDisplay["grid"][colorConfig];

        grid = regreplace(grid, entry, replacementString);
    }

    return grid;
}

/////////////////////////////////////////////////////////////////////////////
public void finishPress()
{
    if (buttonsCanBePressed)
    {
        tell_room(environment(this_player()), 
            sprintf("The surface of the grid on the table transforms: %s", 
                displayMagicSquare()));

        if (isValidPattern())
        {
            tell_room(environment(this_player()), format(
                "\x1b[0;34;1mA rune appears on the table.\x1b[0m", 78));

            object rune = 
                clone_object("/lib/tutorial/temple/objects/rune-negation.c");
            move_object(rune, environment(this_object()));

            object stateMachineDictionary =
                load_object("/lib/dictionaries/stateMachineDictionary.c");

            object party = this_player()->getParty();
            string owner = party ? party->partyName() : this_player()->RealName();

            object stateMachine = stateMachineDictionary->getStateMachine(
                "/lib/tutorial/temple/stateMachine/obedienceStateMachine.c",
                owner);

            buttonsCanBePressed = 0;
            stateMachine->receiveEvent(this_player(), "magicSquareCompleted");
        }
    }
    else
    {
        write("Nothing happens.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public int allowMove()
{
    int ret = 1;

    if (!isValidPattern())
    {
        string message = format("As you approach the liquid, a brilliant arc of "
            "lightning crosses your path. You decide against "
            "proceeding.", 78);

        write("\x1b[0;35m" + message + "\x1b[0m\n");
        ret = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int press(string str)
{
    int ret = 0;
    
    str = stringp(str) ? capitalize(str) : "invalid";
    if (sizeof(regexp(({ str }), "(W|S|A|F|N|R|P|E|D|T)( cube|)")))
    {
        string letter = 
            regreplace(str, "(W|S|A|F|N|R|P|E|D|T)( cube|)", "\\1");

        if (member(buttons, capitalize(letter)))
        {
            ret = 1;
            string gridLocation = buttons[capitalize(letter)];
            magicSquare[gridLocation]["current"] =
                squareDisplay[magicSquare[gridLocation]["current"]]["next"];
            call_out("finishPress", 1);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("press", "push");
    add_action("press", "touch");
}
