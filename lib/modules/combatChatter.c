//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

private nosave mapping combatChatter = ([
    "defensive hit": ([
        "is knocking on death's door.": ({}),
        "is severely injured.": ({}),
        "has taken a beating.": ({}),
        "has been roughed up.": ({}),
        "has some minor injuries.": ({}),
        "is barely inured.": ({}),
        "is in good shape.": ({}),
        "any": ({})
    ]),
    "defensive miss": ([
        "any": ({})
    ]),
    "offensive hit": ([
        "is knocking on death's door.": ({}),
        "is severely injured.": ({}),
        "has taken a beating.": ({}),
        "has been roughed up.": ({}),
        "has some minor injuries.": ({}),
        "is barely inured.": ({}),
        "is in good shape.": ({}),
        "any": ({})
    ]),
    "offensive miss": ([
        "any":({})
    ]),
    "death": ([
        "any":({})
    ]),
    "kill": ([
        "any":({})
    ]),
]);

/////////////////////////////////////////////////////////////////////////////
private nomask void addCombatMessage(string message, string type, string state)
{
    if (!state || !member(combatChatter[type], state))
    {
        state = "any";
    }

    if (message && stringp(message))
    {
        combatChatter[type][state] += ({ message });
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void addDefensiveHitCombatMessage(string message, string state)
{
    addCombatMessage(message, "defensive hit", state);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void addDefensiveMissCombatMessage(string message, string state)
{
    addCombatMessage(message, "defensive miss", state);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void addOffensiveHitCombatMessage(string message, string state)
{
    addCombatMessage(message, "offensive hit", state);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void addOffensiveMissCombatMessage(string message, string state)
{
    addCombatMessage(message, "offensive miss", state);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void addDeathMessage(string message, string state)
{
    addCombatMessage(message, "death", state);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void addKillMessage(string message, string state)
{
    addCombatMessage(message, "kill", state);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getMessage(string type, string state)
{
    string message = 0;
    string *messages = combatChatter[type][state];
    if (sizeof(messages))
    {
        message = messages[random(sizeof(messages))];
    }
    return message;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string speakCombatChatter(string type, object actor, 
    int alwaysDisplay)
{
    string message = 0;
    if (member(({ "defensive miss", "offensive miss", "death", "kill" }), type) > -1)
    {
        message = getMessage(type, "any");
    }
    else if (member(({ "defensive hit", "offensive hit" }), type) > -1)
    {
        string damageLevel = actor->healthDescription();
        if (!member(combatChatter[type], damageLevel))
        {
            damageLevel = "any";
        }
        message = getMessage(type, damageLevel);
    }

    return  (alwaysDisplay || !random(10) || (type == "death") || (type == "kill")) ? message : 0;
}
