//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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
public void reset(int arg)
{
    if (!arg)
    {
        resetWall();
    }
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
            messageParser->displayMessage(configuration->decorate(
                sprintf(msg, whichRune),
                "rune wall", "tutorial", this_player()->colorConfiguration()),
                this_player());

            if (whichRune == "resistance")
            {
                object stateMachine =
                    load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");

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
public string long()
{
    string missing = getPiecesMissing();
    if (missing != "")
    {
        missing = sprintf(" There %s in the runes%s.",
            missing, (missing == "is one gap") ? "" :
            ", each shaped differently as though pieces to a "
            "puzzle were missing");
    }

    string long = sprintf("\x1b[0;33mYou gaze at the wall of runes. As you "
        "decipher them, you note that they form a poem.%s\x1b[0m\nAs near "
        "as you can tell, this is what the runes spell out:\n"
        "\t\t\x1b[0;35m+-----------------------------------------+\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m|   %-35s   |\x1b[0m\n"
        "\t\t\x1b[0;35m+-----------------------------------------+\x1b[0m\n%s",
        missing,
        wall["weakness"],
        wall["strength"],
        wall["flame"],
        wall["frost"],
        wall["aegis"],
        wall["negation"], "",
        wall["senses"],
        wall["wisdom"],
        wall["endurance"],
        wall["resistance"],
        wall["death"],
        wall["torment"], "",
        wall["doom"],
        wall["phantom"],
        wall["fear"],
        wall["domination"],
        wall["sanctuary"],
        wall["envy"],
        (missing == "") ? "" : "If you find some runes, perhaps you can place"
        " them...");
    return format(long, 78);
}
