//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping echoColors = ([
    "ordered":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;35;1m",
        "8-bit": "\x1b[0;38;5;128;1m",
        "24-bit": "\x1b[0;38;2;190;90;210;1m"
    ]),
    "unordered":([
        "none": "",
        "grayscale": "\x1b[0;38;5;240m",
        "3-bit": "\x1b[0;33m",
        "8-bit": "\x1b[0;38;5;130m",
        "24-bit": "\x1b[0;38;2;170;120;60m"
    ]),
    "slot":([
        "none": "",
        "grayscale": "\x1b[0;38;5;237m",
        "3-bit": "\x1b[0;31m",
        "8-bit": "\x1b[0;38;5;124m",
        "24-bit": "\x1b[0;38;2;180;0;0m"
    ]),
    "border":([
        "none": "",
        "grayscale": "\x1b[0;38;5;234m",
        "3-bit": "\x1b[0;35m",
        "8-bit": "\x1b[0;38;5;23m",
        "24-bit": "\x1b[0;38;2;0;85;90m"
    ]),
    "description":([
        "none": "",
        "grayscale": "\x1b[0;38;5;250m",
        "3-bit": "\x1b[0;33m",
        "8-bit": "\x1b[0;38;5;42m",
        "24-bit": "\x1b[0;38;2;10;200;100m"
    ]),
    "instructions":([
        "none": "",
        "grayscale": "\x1b[0;38;5;250;1m",
        "3-bit": "\x1b[0;32;1m",
        "8-bit": "\x1b[0;38;5;2;1m",
        "24-bit": "\x1b[0;38;2;160;220;60;1m"
    ]),
    "success":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;34;1m",
        "8-bit": "\x1b[0;38;5;20;1m",
        "24-bit": "\x1b[0;38;2;0;0;220;1m"
    ]),
]);

// The six memory fragments. Correct chronological order is 1-6.
private mapping fragments = ([
    "A":([
        "text": "A young mage kneels before an altar, swearing fealty",
        "correct": 1,
        "current": 0,
    ]),
    "B":([
        "text": "The mage is gifted a staff of bone and whispers",
        "correct": 2,
        "current": 0,
    ]),
    "C":([
        "text": "A city burns as the mage watches from a dark tower",
        "correct": 3,
        "current": 0,
    ]),
    "D":([
        "text": "The mage weeps over a broken talisman, alone",
        "correct": 4,
        "current": 0,
    ]),
    "E":([
        "text": "Chains of light bind the mage to a wall of amethyst",
        "correct": 5,
        "current": 0,
    ]),
    "F":([
        "text": "A skeletal figure tends a wall of runes, eternal",
        "correct": 6,
        "current": 0,
    ]),
]);

// Scrambled display order
private string *displayOrder = ({ "D", "A", "F", "C", "B", "E" });
private int puzzleSolved = 0;

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return item == "pool-hidden";
}

/////////////////////////////////////////////////////////////////////////////
private int isValidPattern()
{
    if (puzzleSolved)
    {
        return 1;
    }

    foreach(string key in m_indices(fragments))
    {
        if (fragments[key]["current"] != fragments[key]["correct"])
        {
            return 0;
        }
    }
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int allowMove()
{
    int ret = 1;

    if (!isValidPattern())
    {
        object user = this_player();
        string colorConfig = (objectp(user) && user->colorConfiguration()) ?
            user->colorConfiguration() : "none";
        string closing = (colorConfig == "none") ? "" : "\x1b[0m";

        string message = format("As you approach the liquid, a brilliant arc of "
            "lightning crosses your path. You decide against "
            "proceeding.", 78);

        write(echoColors["border"][colorConfig] + message + closing + "\n");
        ret = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string displayEchoes()
{
    object user = this_player();
    string colorConfig = (objectp(user) && user->colorConfiguration()) ?
        user->colorConfiguration() : "none";

    string closing = (colorConfig == "none") ? "" : "\x1b[0m";

    string ret = "\n" + echoColors["border"][colorConfig] +
        "\t+---+-------------------------------------------+" + closing + "\n";

    foreach(string key in displayOrder)
    {
        string slotColor;
        if (fragments[key]["current"] > 0)
        {
            slotColor = echoColors["ordered"][colorConfig];
        }
        else
        {
            slotColor = echoColors["unordered"][colorConfig];
        }

        string slot = (fragments[key]["current"] > 0) ?
            sprintf("%d", fragments[key]["current"]) : ".";

        ret += echoColors["border"][colorConfig] + "\t| " +
            echoColors["slot"][colorConfig] + slot + " " +
            echoColors["border"][colorConfig] + "| " +
            slotColor + sprintf("%-41s", 
                sprintf("[%s] %s", key, fragments[key]["text"])) +
            echoColors["border"][colorConfig] + " |" + closing + "\n";
    }

    ret += echoColors["border"][colorConfig] +
        "\t+---+-------------------------------------------+" + closing + "\n";

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void finishOrder()
{
    tell_room(environment(this_player()),
        sprintf("The surface of the pool ripples and the echoes "
            "shift:%s", displayEchoes()));

    if (isValidPattern())
    {
        puzzleSolved = 1;

        object user = this_player();
        string colorConfig = (objectp(user) && user->colorConfiguration()) ?
            user->colorConfiguration() : "none";
        string closing = (colorConfig == "none") ? "" : "\x1b[0m";

        tell_room(environment(this_player()), format(
            echoColors["success"][colorConfig] +
            "The echoes harmonize into a single voice. Two "
            "runes rise from the depths of the pool." + closing, 78));

        object rune1 =
            clone_object("/tutorial/temple/objects/rune-weakness.c");
        move_object(rune1, environment(this_object()));

        object rune2 =
            clone_object("/tutorial/temple/objects/rune-strength.c");
        move_object(rune2, environment(this_object()));

        object stateMachineService = getService("stateMachine");

        object party = this_player()->getParty();
        string owner = party ? party->partyName() : this_player()->RealName();

        object stateMachine = stateMachineService->getStateMachine(
            "/tutorial/temple/stateMachine/obedienceStateMachine.c",
            owner);

        stateMachine->receiveEvent(this_player(), "startThirdTest");
    }
}

/////////////////////////////////////////////////////////////////////////////
public int orderEcho(string str)
{
    int ret = 0;

    if (puzzleSolved)
    {
        write("The pool is still. The echoes have already been ordered.\n");
        return 1;
    }

    if (stringp(str))
    {
        string letter;
        int position;

        if (sscanf(str, "%s %d", letter, position) == 2 ||
            sscanf(str, "%s to %d", letter, position) == 2 ||
            sscanf(str, "%s in %d", letter, position) == 2)
        {
            letter = upper_case(letter);
            if (member(fragments, letter) && position >= 1 && position <= 6)
            {
                ret = 1;

                // Clear any other fragment in that position
                foreach(string key in m_indices(fragments))
                {
                    if (fragments[key]["current"] == position)
                    {
                        fragments[key]["current"] = 0;
                    }
                }

                fragments[letter]["current"] = position;
                write(sprintf("You place echo %s in position %d.\n",
                    letter, position));
                call_out("finishOrder", 1);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int clearEchoes(string str)
{
    if (puzzleSolved)
    {
        write("The pool is still. The echoes have already been ordered.\n");
        return 1;
    }

    foreach(string key in m_indices(fragments))
    {
        fragments[key]["current"] = 0;
    }
    write("You sweep your hand across the pool and the echoes scatter.\n");
    tell_room(environment(this_player()), displayEchoes());
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public string short()
{
    return "A shimmering pool of purple liquid";
}

/////////////////////////////////////////////////////////////////////////////
public string long()
{
    object user = this_player();
    string colorConfig = (objectp(user) && user->colorConfiguration()) ?
        user->colorConfiguration() : "none";
    string closing = (colorConfig == "none") ? "" : "\x1b[0m";

    string desc = sprintf("%sThe pool shimmers with an inner light. As you "
        "gaze into its depths, ghostly images swirl and fragment — echoes "
        "of a life lived long ago. Six scenes replay in jumbled disorder. "
        "Each is labeled with a letter. They seem to tell a story, if only "
        "you could determine the correct order.%s\n%s\n"
        "%sUse 'order <letter> <position>' to arrange them (1-6). "
        "Use 'clear echoes' to reset.%s\n",
        echoColors["description"][colorConfig],
        closing,
        displayEchoes(),
        echoColors["instructions"][colorConfig],
        closing);

    return format(desc, 78);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("orderEcho", "order");
    add_action("clearEchoes", "clear");
}
