//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping verses = ([
    "weakness":"I am weak",
    "strength" : "I am strong",
    "flame" : "Burning",
    "frost" : "Freezing",
    "aegis" : "Hiding behind inconsequential armor",
    "negation" : "I negate my greatest fears",
    "senses" : "Unseeing, unhearing",
    "wisdom" : "Feeling wise beyond my years",
    "endurance" : "Pushed past endurance",
    "resistance" : "Resisting no longer",
    "death" : "I feel death's loving caress",
    "torment" : "Dispel my torment",
    "doom" : "My doom awaits me",
    "phantom" : "My phantoms assail me",
    "fear" : "Held in my tracks by fear",
    "domination" : "Dominated by my inadequacies",
    "sanctuary" : "I find no sanctuary",
    "envy" : "I long for freedom restored"
]);

private mapping colors = ([
    "description": ([
        "none": "",
        "grayscale": "\x1b[0;38;5;250m",
        "3-bit": "\x1b[0;33m",
        "8-bit": "\x1b[0;38;5;42m",
        "24-bit": "\x1b[0;38;2;10;200;100m"
    ]),
    "border":([
        "none": "",
        "grayscale": "\x1b[0;38;5;234m",
        "3-bit": "\x1b[0;35m",
        "8-bit": "\x1b[0;38;5;23m",
        "24-bit": "\x1b[0;38;2;0;85;90m"
    ]), 
    "message": ([
        "none": "",
        "grayscale": "\x1b[0;38;5;245m",
        "3-bit": "\x1b[0;35;1m",
        "8-bit": "\x1b[0;38;5;126m",
        "24-bit": "\x1b[0;38;2;170;20;180m"
    ]), 
    "missing": ([
        "none": "",
        "grayscale": "\x1b[0;38;5;237m",
        "3-bit": "\x1b[0;31m",
        "8-bit": "\x1b[0;38;5;124m",
        "24-bit": "\x1b[0;38;2;180;0;0m"
    ]), 
    "placed": ([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;35;1m",
        "8-bit": "\x1b[0;38;5;128;1m",
        "24-bit": "\x1b[0;38;2;190;90;210;1m"
    ]),
    "instructions": ([
        "none": "",
        "grayscale": "\x1b[0;38;5;250;1m",
        "3-bit": "\x1b[0;32;1m",
        "8-bit": "\x1b[0;38;5;2;1m",
        "24-bit": "\x1b[0;38;2;160;220;60;1m"
    ]),
]);

private mapping wall = ([]);

/////////////////////////////////////////////////////////////////////////////
public void resetWall()
{
    wall = ([
        "weakness":"<missing>"; 1,
        "strength": "<missing>"; 1,
        "flame": "<missing>"; 1,
        "frost": "<missing>"; 1,
        "aegis": "Hiding behind inconsequential armor"; 0,
        "negation": "I <missing> fears"; 1,
        "senses": "Unseeing, unhearing"; 0,
        "wisdom": "<missing> my years"; 1,
        "endurance": "Pushed <missing>"; 1,
        "resistance": "<missing> no longer"; 1,
        "death": "I feel <missing> loving caress"; 1,
        "torment": "Dispel my torment"; 0,
        "doom": "<missing> awaits me"; 1,
        "phantom": "My phantoms assail me"; 0,
        "fear": "Held <missing>"; 1,
        "domination": "Dominated by my inadequacies"; 0,
        "sanctuary": "I find no sanctuary"; 0,
        "envy": "<missing> restored"; 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public int canTransToEndurance()
{
    return (wall["resistance", 1] == 0);
}

/////////////////////////////////////////////////////////////////////////////
public int allRunesPlaced()
{
    int *items = m_values(wall, 1);
    items -= ({ 0 });

    return (sizeof(items) == 18);
}

/////////////////////////////////////////////////////////////////////////////
public string getPiecesMissing()
{
    string ret;

    int *items = m_values(wall, 1);
    items -= ({ 0 });

    switch (sizeof(items))
    {
        case 1: 
        {
            ret = "is one gap";
            break;
        }
        case 2: 
        {
            ret = "are two gaps";
            break;
        }
        case 3: 
        {
            ret = "are three gaps";
            break;
        }
        case 4: 
        {
            ret = "are four gaps";
            break;
        }
        case 5: 
        {
            ret = "are five gaps";
            break;
        }
        case 6: 
        {
            ret = "are six gaps";
            break;
        }
        case 7: 
        {
            ret = "are seven gaps";
            break;
        }
        case 8: 
        {
            ret = "are eight gaps";
            break;
        }
        case 9: 
        {
            ret = "are nine gaps";
            break;
        }
        case 10: 
        {
            ret = "are ten gaps";
            break;
        }
        case 11: 
        {
            ret = "are eleven gaps";
            break;
        }
        case 12: 
        {
            ret = "are twelve gaps";
            break;
        }
        default: 
        {
            ret = "";
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    resetWall();
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("placeRune", "place");
}

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return ((item == "runes") || (item == "wall") || (item == "rune wall"));
}

/////////////////////////////////////////////////////////////////////////////
public int placeRune(string rune)
{
    int ret = 0;

    // For now, we'll assume that this is a rune
    object runeToAdd;
    if (rune)
    {
        runeToAdd = present(rune) || present(rune, this_player());
        if (present(rune))
        {
            environment()->canGet(runeToAdd);
        }
    }

    if (runeToAdd && runeToAdd->isObedienceRune())
    {
        string whichRune = runeToAdd->getRuneType();
        destruct(runeToAdd);
 
        if (member(wall, whichRune) && member(verses, whichRune))
        {
            wall[whichRune, 0] = verses[whichRune];
            wall[whichRune, 1] = 0;
            string msg = "##InitiatorName::capitalize## ##Infinitive::locate## a gap that "
                "fits and ##Infinitive::place## the rune of %s on the wall.\n";

            object configuration =
                load_object("/lib/dictionaries/configurationDictionary.c");

            object messageParser = load_object("/lib/core/messageParser.c");
            messageParser->displayMessage(sprintf(msg, whichRune), this_player(), 0,
                "rune wall", "tutorial");

            if (whichRune == "resistance")
            {
                object stateMachineDictionary =
                    load_object("/lib/dictionaries/stateMachineDictionary.c");

                object party = this_player()->getParty();
                string owner = party ? party->partyName() : this_player()->RealName();

                object stateMachine = stateMachineDictionary->getStateMachine(
                    "/tutorial/temple/stateMachine/obedienceStateMachine.c",
                    owner);

                if (stateMachine)
                {
                    stateMachine->receiveEvent(this_player(), "resistanceRunePlaced");
                }
            }
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string short()
{
    return "A wall with many runes etched into it";
}

/////////////////////////////////////////////////////////////////////////////
private string runeEntry(string message, string colorConfiguration)
{
    string ret = message;

    if (sizeof(regexp(({ message }), "<missing>")))
    {
        ret = colors["message"][colorConfiguration] + 
            regreplace(sprintf("%-35s", ret),
            "(<missing>)",
            colors["missing"][colorConfiguration] + "\\1" +
            colors["message"][colorConfiguration], 1);
    }                            
    else
    {
        ret = colors["placed"][colorConfiguration] + sprintf("%-35s", ret);
    }

    return "\t\t" + colors["border"][colorConfiguration] + "|   " + ret +
        colors["border"][colorConfiguration] + "   |" +
        ((colorConfiguration == "none") ? "" : "\x1b[0m") + "\n";
}

/////////////////////////////////////////////////////////////////////////////
public string long()
{
    string colorConfiguration = 
        (this_player() && this_player()->colorConfiguration()) ?
        this_player()->colorConfiguration() : "none";

    string closing = (colorConfiguration == "none") ? "" : "\x1b[0m";

    string missing = getPiecesMissing();
    if (missing != "")
    {
        missing = sprintf(" There %s in the runes%s.",
            missing, (missing == "is one gap") ? "" :
            ", each shaped differently as though pieces to a "
            "puzzle were missing");
    }

    string poem = runeEntry(wall["weakness"], colorConfiguration) +
        runeEntry(wall["strength"], colorConfiguration) +
        runeEntry(wall["flame"], colorConfiguration) +
        runeEntry(wall["frost"], colorConfiguration) +
        runeEntry(wall["aegis"], colorConfiguration) +
        runeEntry(wall["negation"], colorConfiguration) +
        runeEntry("", colorConfiguration) +
        runeEntry(wall["senses"], colorConfiguration) +
        runeEntry(wall["wisdom"], colorConfiguration) +
        runeEntry(wall["endurance"], colorConfiguration) +
        runeEntry(wall["resistance"], colorConfiguration) +
        runeEntry(wall["death"], colorConfiguration) +
        runeEntry(wall["torment"], colorConfiguration) +
        runeEntry("", colorConfiguration) +
        runeEntry(wall["doom"], colorConfiguration) +
        runeEntry(wall["phantom"], colorConfiguration) +
        runeEntry(wall["fear"], colorConfiguration) +
        runeEntry(wall["domination"], colorConfiguration) +
        runeEntry(wall["sanctuary"], colorConfiguration) +
        runeEntry(wall["envy"], colorConfiguration);

    string long = sprintf("%sYou gaze at the wall of runes. As you "
        "decipher them, you note that they form a poem.%s\n\nAs near "
        "as you can tell, this is what the runes spell out:\n"
        "\t\t%s+-----------------------------------------+%s\n%s"
        "\t\t%s+-----------------------------------------+%s\n%s%s%s",
        colors["description"][colorConfiguration],
        missing,
        colors["border"][colorConfiguration], closing,
        poem,
        colors["border"][colorConfiguration], closing,
        colors["instructions"][colorConfiguration],
        (missing == "") ? "" : "If you find some runes, perhaps you can place"
        " them...",
        closing);
    return format(long, 78);
}
