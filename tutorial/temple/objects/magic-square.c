//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping squareDisplay = ([
    "Y":([
        "character":([
            "unicode": "\u16a1",
            "ascii": "Y"
        ]),
        "color":([
            "none": "",
            "grayscale": "\x1b[0;38;5;246;1m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;28;1m",
            "24-bit": "\x1b[0;38;2;0;180;0;1m"
        ]),
        "next": "A"
    ]),
    "A":([
        "character":([
            "unicode": "\u16a3",
            "ascii": "A"
        ]),
        "color":([
            "none": "",
            "grayscale": "\x1b[0;38;5;15;1m",
            "3-bit": "\x1b[0;37;1m",
            "8-bit": "\x1b[0;38;5;15;1m",
            "24-bit": "\x1b[0;38;2;255;255;255;1m"
        ]),
        "next": "F"
    ]),
    "F":([
        "character":([
            "unicode": "\u16ab",
            "ascii": "F"
        ]),
        "color":([
            "none": "",
            "grayscale": "\x1b[0;38;5;236;1m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;124;1m",
            "24-bit": "\x1b[0;38;2;180;0;0;1m"
        ]),
        "next": "H"
    ]),
    "H":([
        "character":([
            "unicode": "\u16bb",
            "ascii": "H"
        ]),
        "color": ([
            "none": "",
            "grayscale": "\x1b[0;38;5;251;1m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;0;220;1m"
        ]),
        "next": "Y"
    ]),
    "E":([
        "character":([
            "unicode": "\u2237",
            "ascii": "."
        ]),
        "color":([
            "none": "",
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;244;1m",
            "24-bit": "\x1b[0;38;2;120;120;120;1m"
        ]),
        "next": "Y"
    ]),
    "grid":([
        "none": "",
        "grayscale": "\x1b[0;38;5;233m",
        "3-bit": "\x1b[0;31m",
        "8-bit": "\x1b[0;38;5;9m",
        "24-bit": "\x1b[0;38;2;200;0;0m"
    ]),
    "button":([
        "none": "",
        "grayscale": "\x1b[0;38;5;244m",
        "3-bit": "\x1b[0;35m",
        "8-bit": "\x1b[0;38;5;244m",
        "24-bit": "\x1b[0;38;2;120;120;160m"
    ]),
]);

private mapping gridDisplay = ([
    "/":([
        "unicode": "\u2554",
        "ascii": "+"
    ]),
    "`":([
        "unicode": "\u2557",
        "ascii": "+"
    ]),
    "~":([
        "unicode": "\u2550",
        "ascii": "="
    ]),
    "-":([
        "unicode": "\u2508",
        "ascii": "-"
    ]),
    "T":([
        "unicode": "\u2566",
        "ascii": "+"
    ]),
    "t":([
        "unicode": "\u2564",
        "ascii": "+"
    ]),
    "I":([
        "unicode": "\u2551",
        "ascii": "|"
    ]),
    ":":([
        "unicode": "\u250a",
        "ascii": ":"
    ]),
    "<":([
        "unicode": "\u255f",
        "ascii": "+"
    ]),
    ">":([
        "unicode": "\u2562",
        "ascii": "+"
    ]),
    "#":([
        "unicode": "\u256b",
        "ascii": "+"
    ]),
    "v":([
        "unicode": "+",
        "ascii": "+"
    ]),
    "x":([
        "unicode": "\u256a",
        "ascii": "+"
    ]),
    "X":([
        "unicode": "\u256c",
        "ascii": "+"
    ]),
    "L":([
        "unicode": "\u255a",
        "ascii": "+"
    ]),
    "l":([
        "unicode": "\u255d",
        "ascii": "+"
    ]),
    "U":([
        "unicode": "\u2569",
        "ascii": "+"
    ]),
    "u":([
        "unicode": "\u2567",
        "ascii": "+"
    ]),
]);

private mapping magicSquare = ([
    "A1":([
        "initial": "E",
        "current": "E",
        "solved": "Y",
        "button": ([ "A5": "w" ]),
    ]),
    "A2":([
        "initial": "A",
        "current": "A",
        "solved": "A",
        "button": ([ "A6" : "z" ]),
    ]),
    "A3":([
        "initial": "E",
        "current": "E",
        "solved": "F",
        "button": ([ "A7": "s" ]),
    ]),
    "A4":([
        "initial": "H",
        "current": "H",
        "solved": "H",
        "button": ([ "A8": "y" ]),
    ]),
    "B1":([
        "initial": "E",
        "current": "E",
        "solved": "F",
        "button": ([ "B5": "a" ]),
    ]),
    "B2":([
        "initial": "H",
        "current": "H",
        "solved": "H",
        "button": ([ "B6": "x" ]),
    ]),
    "B3":([
        "initial": "Y",
        "current": "Y",
        "solved": "Y",
        "button": ([ "B7": "v" ]),
    ]),
    "B4":([
        "initial": "E",
        "current": "E",
        "solved": "A",
        "button": ([ "B8": "f" ]),
    ]),
    "C1":([
        "initial": "E",
        "current": "E",
        "solved": "H",
        "button": ([ "C5": "n" ]),
    ]),
    "C2":([
        "initial": "F",
        "current": "F",
        "solved": "F",
        "button": ([ "C6": "b" ]),
    ]),
    "C3":([
        "initial": "A",
        "current": "A",
        "solved": "A",
        "button": ([ "C7": "m" ]),
    ]),
    "C4":([
        "initial": "E",
        "current": "E",
        "solved": "Y",
        "button": ([ "C8": "r" ]),
    ]),
    "D1":([
        "initial": "E",
        "current": "E",
        "solved": "A",
        "button": ([ "D5": "p" ]),
    ]),
    "D2":([
        "initial": "E",
        "current": "E",
        "solved": "Y",
        "button": ([ "D6": "e" ]),
    ]),
    "D3":([
        "initial": "E",
        "current": "E",
        "solved": "H",
        "button": ([ "D7": "d" ]),
    ]),
    "D4":([
        "initial": "E",
        "current": "E",
        "solved": "F",
        "button": ([ "D8": "t" ]),
    ]),
]);

private mapping buttons = ([
    "W": "A1",
    "Z": "A2",
    "S": "A3",
    "Y": "A4",
    "A": "B1",
    "X": "B2",
    "V": "B3",
    "F": "B4",
    "N": "C1",
    "B": "C2",
    "M": "C3",
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
    string grid = "\n\t\t/~~~t~~~T~~~t~~~`        /~~~t~~~T~~~t~~~`\n"
                  "\t\tI A1: A2I A3: A4I        I A5: A6I A7: A8I\n"
                  "\t\t<---v---#---v--->        <---v---#---v--->\n"
                  "\t\tI B1: B2I B3: B4I        I B5: B6I B7: B8I\n"
                  "\t\t<~~~x~~~X~~~x~~~>        <~~~x~~~X~~~x~~~>\n"
                  "\t\tI C1: C2I C3: C4I        I C5: C6I C7: C8I\n"
                  "\t\t<---v---#---v--->        <---v---#---v--->\n"
                  "\t\tI D1: D2I D3: D4I        I D5: D6I D7: D8I\n"
                  "\t\tL~~~u~~~U~~~u~~~l        L~~~u~~~U~~~u~~~l\n";

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

        mapping buttonDisplay = magicSquare[entry]["button"];
        foreach(string buttonLocation in m_indices(buttonDisplay))
        {
            replacementString = squareDisplay["button"][colorConfig] +
                ((magicSquare[entry]["initial"] == "E") ?
                buttonDisplay[buttonLocation] : " ") + " " +
                squareDisplay["grid"][colorConfig];
            grid = regreplace(grid, buttonLocation, replacementString);
        }
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
                clone_object("/tutorial/temple/objects/rune-negation.c");
            move_object(rune, environment(this_object()));

            object stateMachineDictionary =
                load_object("/lib/dictionaries/stateMachineDictionary.c");

            object party = this_player()->getParty();
            string owner = party ? party->partyName() : this_player()->RealName();

            object stateMachine = stateMachineDictionary->getStateMachine(
                "/tutorial/temple/stateMachine/obedienceStateMachine.c",
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
    if (sizeof(regexp(({ str }), "(W|Z|S|Y|A|X|V|F|N|B|M|R|P|E|D|T)( cube|)")))
    {
        string letter = 
            regreplace(str, "(W|Z|S|Y|A|X|V|F|N|B|M|R|P|E|D|T)( cube|)", "\\1");

        if (member(buttons, letter) &&
            (magicSquare[buttons[letter]]["initial"] == "E"))
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
