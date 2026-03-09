//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping crucibleColors = ([
    "flame":([
        "none": "",
        "grayscale": "\x1b[0;38;5;251;1m",
        "3-bit": "\x1b[0;31;1m",
        "8-bit": "\x1b[0;38;5;196;1m",
        "24-bit": "\x1b[0;38;2;255;80;0;1m"
    ]),
    "frost":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;34;1m",
        "8-bit": "\x1b[0;38;5;39;1m",
        "24-bit": "\x1b[0;38;2;100;180;255;1m"
    ]),
    "inactive":([
        "none": "",
        "grayscale": "\x1b[0;38;5;237m",
        "3-bit": "\x1b[0;37m",
        "8-bit": "\x1b[0;38;5;240m",
        "24-bit": "\x1b[0;38;2;100;100;100m"
    ]),
    "charged":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;35;1m",
        "8-bit": "\x1b[0;38;5;128;1m",
        "24-bit": "\x1b[0;38;2;190;90;210;1m"
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
    "pain":([
        "none": "",
        "grayscale": "\x1b[0;38;5;236;1m",
        "3-bit": "\x1b[0;31;1m",
        "8-bit": "\x1b[0;38;5;124;1m",
        "24-bit": "\x1b[0;38;2;180;0;0;1m"
    ]),
    "hint":([
        "none": "",
        "grayscale": "\x1b[0;38;5;246;1m",
        "3-bit": "\x1b[0;33;1m",
        "8-bit": "\x1b[0;38;5;130;1m",
        "24-bit": "\x1b[0;38;2;200;160;40;1m"
    ]),
]);

private int flameCharges = 0;
private int frostCharges = 0;
private int requiredCharges = 3;
private int puzzleSolved = 0;
private int touchCooldown = 0;

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return item == "crucible-hidden";
}

/////////////////////////////////////////////////////////////////////////////
private int isValidPattern()
{
    return puzzleSolved || 
        (flameCharges >= requiredCharges && frostCharges >= requiredCharges);
}

/////////////////////////////////////////////////////////////////////////////
private void tellRoom(object room, string colorKey, string message)
{
    object *characters = filter(all_inventory(room),
        (: $1->isRealizationOfLiving() :));

    foreach(object person in characters)
    {
        if (objectp(person))
        {
            string colorConfig = (person->colorConfiguration()) ?
                person->colorConfiguration() : "none";
            string closing = (colorConfig == "none") ? "" : "\x1b[0m";

            tell_object(person, crucibleColors[colorKey][colorConfig] +
                message + closing);
        }
    }
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

        write(crucibleColors["border"][colorConfig] + message + closing + "\n");
        ret = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string chargeBar(int charges, string element)
{
    object user = this_player();
    string colorConfig = (objectp(user) && user->colorConfiguration()) ?
        user->colorConfiguration() : "none";
    string closing = (colorConfig == "none") ? "" : "\x1b[0m";

    string activeColor = crucibleColors[element][colorConfig];
    string inactiveColor = crucibleColors["inactive"][colorConfig];
    string ret = "";

    for (int i = 0; i < requiredCharges; i++)
    {
        if (i < charges)
        {
            ret += activeColor + "#";
        }
        else
        {
            ret += inactiveColor + ".";
        }
    }
    return ret + closing;
}

/////////////////////////////////////////////////////////////////////////////
public string displayCrucible()
{
    object user = this_player();
    string colorConfig = (objectp(user) && user->colorConfiguration()) ?
        user->colorConfiguration() : "none";
    string closing = (colorConfig == "none") ? "" : "\x1b[0m";

    string flameLabel = crucibleColors["flame"][colorConfig] + "Flame" + closing;
    string frostLabel = crucibleColors["frost"][colorConfig] + "Frost" + closing;
    string border = crucibleColors["border"][colorConfig];

    return sprintf("\n%s\t+-------+---------+%s\n"
        "%s\t| %s %s| %s %s|%s\n"
        "%s\t| %s %s| %s %s|%s\n"
        "%s\t+-------+---------+%s\n",
        border, closing,
        border, flameLabel, border, chargeBar(flameCharges, "flame"), border, closing,
        border, frostLabel, border, chargeBar(frostCharges, "frost"), border, closing,
        border, closing);
}

/////////////////////////////////////////////////////////////////////////////
public void completeCrucible()
{
    puzzleSolved = 1;

    tellRoom(environment(this_player()), "success", format(
        "The braziers flare brilliantly and then go dark. "
        "Two runes materialize between them, hovering in the air before "
        "clattering to the floor.", 78));

    object rune1 =
        clone_object("/areas/tol-dhurath/objects/rune-flame.c");
    move_object(rune1, environment(this_object()));

    object rune2 =
        clone_object("/areas/tol-dhurath/objects/rune-frost.c");
    move_object(rune2, environment(this_object()));

    object stateMachineService = getService("stateMachine");

    object party = this_player()->getParty();
    string owner = party ? party->partyName() : this_player()->RealName();

    object stateMachine = stateMachineService->getStateMachine(
        "/areas/tol-dhurath/state-machine/obedience-quest.c",
        owner);

    stateMachine->receiveEvent(this_player(), "startFourthTest");
}

/////////////////////////////////////////////////////////////////////////////
public void finishTouch(string element)
{
    touchCooldown = 0;

    if (puzzleSolved)
    {
        return;
    }

    if (element == "flame" && flameCharges >= requiredCharges &&
        frostCharges >= requiredCharges)
    {
        completeCrucible();
    }
    else if (element == "frost" && flameCharges >= requiredCharges &&
        frostCharges >= requiredCharges)
    {
        completeCrucible();
    }
    else
    {
        tell_room(environment(this_player()),
            sprintf("The braziers pulse with energy:%s",
                displayCrucible()));
    }
}

/////////////////////////////////////////////////////////////////////////////
public int touchBrazier(string str)
{
    int ret = 0;

    if (puzzleSolved)
    {
        write("The braziers are dark and cold. Their power has been spent.\n");
        return 1;
    }

    if (touchCooldown)
    {
        write("The brazier's energy is still settling. Wait a moment.\n");
        return 1;
    }

    if (stringp(str))
    {
        string element = lower_case(str);
        element = regreplace(element, " ?(brazier|flame|fire)$", "");

        object user = this_player();
        string colorConfig = (objectp(user) && user->colorConfiguration()) ?
            user->colorConfiguration() : "none";
        string closing = (colorConfig == "none") ? "" : "\x1b[0m";

        if (element == "flame" || element == "fire" || element == "left")
        {
            ret = 1;
            touchCooldown = 1;
            flameCharges++;

            if (flameCharges > requiredCharges)
            {
                flameCharges = requiredCharges;
            }

            write(crucibleColors["pain"][colorConfig] +
                "You thrust your hand into the spectral flame. Searing "
                "pain lances through you!" + closing + "\n");
            say(sprintf("%s thrusts a hand into the spectral flame and "
                "cries out!\n", this_player()->Name()));

            this_player()->hit(15, "fire");

            call_out("finishTouch", 2, "flame");
        }
        else if (element == "frost" || element == "ice" || 
            element == "cold" || element == "right")
        {
            ret = 1;
            touchCooldown = 1;
            frostCharges++;

            if (frostCharges > requiredCharges)
            {
                frostCharges = requiredCharges;
            }

            write(crucibleColors["pain"][colorConfig] +
                "You plunge your hand into the spectral frost. Biting "
                "cold numbs you to the bone!" + closing + "\n");
            say(sprintf("%s plunges a hand into the spectral frost and "
                "shudders!\n", this_player()->Name()));

            this_player()->hit(15, "cold");

            call_out("finishTouch", 2, "frost");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string short()
{
    return "Two spectral braziers";
}

/////////////////////////////////////////////////////////////////////////////
public string long()
{
    object user = this_player();
    string colorConfig = (objectp(user) && user->colorConfiguration()) ?
        user->colorConfiguration() : "none";
    string closing = (colorConfig == "none") ? "" : "\x1b[0m";

    if (puzzleSolved)
    {
        return format("The braziers are dark. Their purpose has been served.", 78);
    }

    string desc = sprintf("%sTwo spectral braziers stand at the center of "
        "the chamber. The left one burns with ghostly flame that gives no "
        "warmth. The right one radiates an unearthly frost that chills the "
        "soul. Between them, a faint inscription reads: 'To free what is "
        "bound, you must share in its suffering.'%s\n%s\n"
        "%sUse 'touch flame' and 'touch frost' to charge the braziers. "
        "Each touch will cost you dearly.%s\n",
        crucibleColors["description"][colorConfig],
        closing,
        displayCrucible(),
        crucibleColors["instructions"][colorConfig],
        closing);

    return format(desc, 78);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("touchBrazier", "touch");
}
