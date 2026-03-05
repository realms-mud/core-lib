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

private mapping borderChars = ([
    "/":([
        "unicode": "\u2554",
        "ascii": "+"
    ]),
    "`":([
        "unicode": "\u2557",
        "ascii": "+"
    ]),
    "L":([
        "unicode": "\u255a",
        "ascii": "+"
    ]),
    "J":([
        "unicode": "\u255d",
        "ascii": "+"
    ]),
    "T":([
        "unicode": "\u2566",
        "ascii": "+"
    ]),
    "U":([
        "unicode": "\u2569",
        "ascii": "+"
    ]),
    "~":([
        "unicode": "\u2550",
        "ascii": "-"
    ]),
]);

// The six memory fragments. Correct chronological order is 1-6.
// Labels are intentionally non-sequential to prevent alphabetical solving.
private mapping fragments = ([
    "R":([
        "text": "A young mage kneels before an altar, swearing fealty",
        "detail": "A young man in simple grey robes kneels before an "
            "altar of dark stone. His face is eager, flushed with "
            "ambition. An unseen presence accepts his oath and shadows "
            "curl around his outstretched hands like living things. He "
            "does not flinch. In his eyes burns the absolute certainty "
            "of youth - that power, once gained, can be controlled.",
        "correct": 1,
        "current": 0,
    ]),
    "K":([
        "text": "The mage is gifted a staff of bone and whispers",
        "detail": "The same man, older now, receives a staff carved "
            "from a single enormous bone. As his fingers close around "
            "it, whispered voices fill the air - promises of power, "
            "secrets of the dead. His eyes glow briefly with violet "
            "light. He smiles, and it is the last genuine smile you "
            "see from him.",
        "correct": 2,
        "current": 0,
    ]),
    "W":([
        "text": "A city burns as the mage watches from a dark tower",
        "detail": "A great city burns below a tower of black stone. "
            "The mage stands at its peak, staff raised, his face a "
            "mask of terrible concentration. Below, people flee "
            "through streets choked with flame and ash. He does not "
            "look away. Not because he is cruel, but because looking "
            "away would mean acknowledging what he has become.",
        "correct": 3,
        "current": 0,
    ]),
    "M":([
        "text": "The mage weeps over a broken talisman, alone",
        "detail": "In a bare stone cell, the mage cradles the "
            "shattered remains of a small talisman - perhaps a "
            "locket, perhaps a charm of warding. His robes are torn, "
            "his face gaunt with exhaustion. He weeps without sound. "
            "The shadows that once embraced him draw away, leaving "
            "him utterly alone in the cold light.",
        "correct": 4,
        "current": 0,
    ]),
    "P":([
        "text": "Chains of light bind the mage to a wall of amethyst",
        "detail": "Brilliant chains of white-gold light pin the mage "
            "against a wall of raw amethyst. His staff lies broken "
            "at his feet. A towering figure, radiant and terrible, "
            "pronounces judgment in words that crackle like thunder. "
            "The mage does not resist. His eyes hold no defiance - "
            "only the quiet recognition of one who always knew this "
            "moment would come.",
        "correct": 5,
        "current": 0,
    ]),
    "Q":([
        "text": "A skeletal figure tends a wall of runes, eternal",
        "detail": "A skeletal figure in tattered robes carefully "
            "tends a wall covered in glowing runes. There is no "
            "anger in its movements, no urgency - only the patient, "
            "endless work of one who has accepted an eternity of "
            "servitude. A faint violet glow pulses in its hollow eye "
            "sockets. It pauses, bony fingers tracing a rune, and "
            "for a moment something like peace crosses its fleshless "
            "features.",
        "correct": 6,
        "current": 0,
    ]),
]);

// Scrambled display order
private string *displayOrder = ({ "M", "R", "Q", "W", "K", "P" });
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

            tell_object(person, echoColors[colorKey][colorConfig] +
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
    string charsetConfig = (objectp(user) && user->charsetConfiguration()) ?
        user->charsetConfiguration() : "ascii";

    string closing = (colorConfig == "none") ? "" : "\x1b[0m";
    string bc = echoColors["border"][colorConfig];
    string vbar = (charsetConfig == "unicode") ? "\u2551" : "|";

    string topBorder =
        "/~~~T~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`";
    string botBorder =
        "L~~~U~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~J";

    foreach(string ch in m_indices(borderChars))
    {
        topBorder = regreplace(topBorder, ch,
            borderChars[ch][charsetConfig], 1);
        botBorder = regreplace(botBorder, ch,
            borderChars[ch][charsetConfig], 1);
    }

    string ret = "\n" + bc + "\t" + topBorder + closing + "\n";

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

        ret += bc + "\t" + vbar + " " +
            echoColors["slot"][colorConfig] + slot + " " +
            bc + vbar + " " +
            slotColor + sprintf("%-56s",
                sprintf("[%s] %s", key, fragments[key]["text"])) +
            " " + bc + vbar + closing + "\n";
    }

    ret += bc + "\t" + botBorder + closing + "\n";

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

        tellRoom(environment(this_player()), "success", format(
            "The echoes harmonize into a single voice. Two "
            "runes rise from the depths of the pool.", 78));

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
public int visionEcho(string str)
{
    if (puzzleSolved)
    {
        write("The pool is still. The echoes have already been ordered.\n");
        return 1;
    }

    if (stringp(str) && sizeof(str))
    {
        string letter = upper_case(str);
        if (member(fragments, letter))
        {
            object user = this_player();
            string colorConfig = (objectp(user) &&
                user->colorConfiguration()) ?
                user->colorConfiguration() : "none";
            string closing = (colorConfig == "none") ? "" : "\x1b[0m";

            write(echoColors["description"][colorConfig] +
                format("You gaze deeply into echo " + letter +
                    "...\n\n" + fragments[letter]["detail"], 78) +
                closing + "\n");
            return 1;
        }
    }

    notify_fail("Which echo do you wish to examine? "
        "Use 'vision <letter>'.\n");
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("orderEcho", "order");
    add_action("clearEchoes", "clear");
    add_action("visionEcho", "vision");
}
