//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping orbDisplay = ([
    "green":([
        "character":([
            "unicode": "\u229b",
            "ascii": "G"
        ]),
        "color":([
            "grayscale": "\x1b[0;38;5;251;1m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;28;1m",
            "24-bit": "\x1b[0;38;2;0;180;0;1m"
        ]),
    ]),
    "white":([
        "character":([
            "unicode": "\u229b",
            "ascii": "W"
        ]),
        "color":([
            "grayscale": "\x1b[0;38;5;15;1m",
            "3-bit": "\x1b[0;37;1m",
            "8-bit": "\x1b[0;38;5;15;1m",
            "24-bit": "\x1b[0;38;2;255;255;255;1m"
        ]),
    ]),
    "red":([
        "character":([
            "unicode": "\u229b",
            "ascii": "R"
        ]),
        "color":([
            "grayscale": "\x1b[0;38;5;236;1m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;124;1m",
            "24-bit": "\x1b[0;38;2;180;0;0;1m"
        ]),
    ]),
    "blue":([
        "character":([
            "unicode": "\u229b",
            "ascii": "B"
        ]),
        "color": ([
            "grayscale": "\x1b[0;38;5;248;1m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;0;220;1m"
        ]),
    ]),
    "default":([
        "character":([
            "unicode": "\u229b",
            "ascii": "@"
        ]),
        "color":([
            "grayscale": "\x1b[0;38;5;244;1m",
            "3-bit": "\x1b[0;35;6m",
            "8-bit": "\x1b[0;38;5;244;1m",
            "24-bit": "\x1b[0;38;2;120;120;120;1m"
        ]),
    ]),
]);

private string currentTest = "none";
private int platesCanBePressed = 0;

private string *orbOrder = ({ "blue", "green", "red", "white" });
private mapping orbs = (["north":-1, "south" : -1, "east" : -1, "west" : -1]);

// Sequences are:
//     endurance: envy, envy, envy, fear, fear, wrath
//     flame: envy, fear, sorrow, wrath
//     frost: envy, envy, envy, envy, fear, fear, fear, fear (among others)
//     envy: envy, fear, sorrow, wrath, envy, fear, sorrow, wrath
//     weakness: sorrow, wrath
//     strength: envy, fear
//     stealth: fear, fear, fear, wrath, wrath, envy
private mapping validSequences = ([
    "endurance":(["north":3, "south" : 2, "east" : 0, "west" : 1]),
    "flame" : (["north":2, "south" : 2, "east" : 2, "west" : 2]),
    "frost" : (["north":3, "south" : 3, "east" : 3, "west" : 3]),
    "envy" : (["north":1, "south" : 1, "east" : 1, "west" : 1]),
    "weakness" : (["north":1, "south" : 1, "east" : 0, "west" : 0]),
    "strength" : (["north":0, "south" : 0, "east" : 1, "west" : 1]),
    "stealth" : (["north":2, "south" : 0, "east" : 3, "west" : 1]),
]);

/////////////////////////////////////////////////////////////////////////////
private string orb(string color)
{
    object user = this_player();
    string orb = "X";

    string colorConfig = (objectp(user) && user->colorConfiguration()) ? 
        user->colorConfiguration() : "none";

    string characterConfig = (objectp(user) && user->charsetConfiguration()) ?
        user->charsetConfiguration() : "ascii";

    if (member(orbDisplay, color))
    {
        orb = orbDisplay[color]["character"][characterConfig];
        if (member(orbDisplay[color]["color"], colorConfig))
        {
            orb = orbDisplay[color]["color"][colorConfig] + orb + "\x1b[0m";
        }
    }
    return orb;
}

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return item == "pedestal-hidden";
}

/////////////////////////////////////////////////////////////////////////////
private int isValidPattern()
{
    int ret = 0;

    if (member(validSequences, currentTest))
    {
        ret = ((orbs["north"] % 4) == validSequences[currentTest]["north"]) &&
            ((orbs["south"] % 4) == validSequences[currentTest]["south"]) &&
            ((orbs["east"] % 4) == validSequences[currentTest]["east"]) &&
            ((orbs["west"] % 4) == validSequences[currentTest]["west"]);
        platesCanBePressed = !ret;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private int canTransition()
{
    return isValidPattern();
}

/////////////////////////////////////////////////////////////////////////////
private string getOrb(string which)
{
    return (orbs[which] == -1) ? orb("default") : 
        orb(orbOrder[(orbs[which] % 4)]);
}

/////////////////////////////////////////////////////////////////////////////
public string displayOrbs()
{
    return sprintf("\n%33s%s\n%30s%s%5s%s\n%33s%s\n", "", getOrb("north"), "",
        getOrb("west"), "", getOrb("east"), "", getOrb("south"));
}

/////////////////////////////////////////////////////////////////////////////
public void pressPlateOfSorrow()
{
    if (platesCanBePressed)
    {
        orbs["north"]++;
        orbs["south"]++;
        orbs["east"]++;
    }
}

/////////////////////////////////////////////////////////////////////////////
public void pressPlateOfWrath()
{
    if (platesCanBePressed)
    {
        orbs["north"]++;
        orbs["south"]++;
        orbs["west"]++;
    }
}

/////////////////////////////////////////////////////////////////////////////
public void pressPlateOfEnvy()
{
    if (platesCanBePressed)
    {
        orbs["north"]++;
        orbs["east"]++;
        orbs["west"]++;
    }
}

/////////////////////////////////////////////////////////////////////////////
public void pressPlateOfFear()
{
    if (platesCanBePressed)
    {
        orbs["south"]++;
        orbs["east"]++;
        orbs["west"]++;
    }
}

/////////////////////////////////////////////////////////////////////////////
public varargs void pressPlateOfDeath(int fullReset)
{
    if (platesCanBePressed || fullReset)
    {
        orbs["north"] = -1;
        orbs["south"] = -1;
        orbs["east"] = -1;
        orbs["west"] = -1;
    }
}

/////////////////////////////////////////////////////////////////////////////
private int isValidPlate(string plate)
{
    int ret = 0;

    switch (plate)
    {
        case "death":
        {
            pressPlateOfDeath();
            ret = 1;
            break;
        }
        case "sorrow":
        {
            pressPlateOfSorrow();
            ret = 1;
            break;
        }
        case "wrath":
        {
            pressPlateOfWrath();
            ret = 1;
            break;
        }
        case "envy":
        {
            pressPlateOfEnvy();
            ret = 1;
            break;
        }
        case "fear":
        {
            pressPlateOfFear();
            ret = 1;
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void finishPress()
{
    if (platesCanBePressed)
    {
        tell_room(environment(this_player()), 
            sprintf("The orbs of energy atop the pedestals swirl vigorously "
                "and a new pattern emerges:%s", displayOrbs()));

        if (isValidPattern())
        {
            tell_room(environment(this_player()), format(
                "\x1b[0;34mThe liquid surrounding the passage way "
                "widens, allowing safe passage\x1b[0m", 78));

            object stateMachineDictionary =
                load_object("/lib/dictionaries/stateMachineDictionary.c");

            object party = this_player()->getParty();
            string owner = party ? party->partyName() : this_player()->RealName();

            object stateMachine = stateMachineDictionary->getStateMachine(
                "/tutorial/temple/stateMachine/obedienceStateMachine.c",
                owner);

            stateMachine->receiveEvent(this_player(),
                sprintf("%sPassageOpened", currentTest));
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
    string whichPlate;

    if (stringp(str) && (sscanf(str, "plate of %s", whichPlate) ||
        sscanf(str, "on plate of %s", whichPlate) ||
        sscanf(str, "at plate of %s", whichPlate) ||
        sscanf(str, "%s", whichPlate)) && isValidPlate(whichPlate))
    {
        ret = 1;
        write(sprintf("You press the plate of %s...\n", whichPlate));
        say(sprintf("%s presses the plate of %s...\n",
            this_player()->Name(), whichPlate));
        call_out("finishPress", 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void startFirstTest()
{
    currentTest = "endurance";
    platesCanBePressed = 1;
    pressPlateOfDeath();
}

/////////////////////////////////////////////////////////////////////////////
public void startSecondTest()
{
    currentTest = "flame";
    platesCanBePressed = 1;
    pressPlateOfDeath();
}

/////////////////////////////////////////////////////////////////////////////
public void startThirdTest()
{
    currentTest = "frost";
    platesCanBePressed = 1;
    pressPlateOfDeath();
}

/////////////////////////////////////////////////////////////////////////////
public void startFourthTest()
{
    currentTest = "envy";
    platesCanBePressed = 1;
    pressPlateOfDeath();
}

/////////////////////////////////////////////////////////////////////////////
public void startFifthTest()
{
    currentTest = "weakness";
    platesCanBePressed = 1;
    pressPlateOfDeath();
}

/////////////////////////////////////////////////////////////////////////////
public void startSixthTest()
{
    currentTest = "strength";
    platesCanBePressed = 1;
    pressPlateOfDeath();
}

/////////////////////////////////////////////////////////////////////////////
public void startSeventhTest()
{
    currentTest = "stealth";
    platesCanBePressed = 1;
    pressPlateOfDeath();
}

/////////////////////////////////////////////////////////////////////////////
public void startEighthTest()
{
    currentTest = "none";
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("press", "push");
    add_action("press", "press");
    add_action("press", "depress");
    add_action("press", "touch");
    add_action("press", "stand");
    add_action("press", "hit");
    add_action("press", "kick");
}
