//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int sealBroken = 0;
private object Seilyndria;

private mapping sealColors = ([
    "ritual":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;31;1m",
        "8-bit": "\x1b[0;38;5;124;1m",
        "24-bit": "\x1b[0;38;2;180;0;0;1m"
    ]),
    "success":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;35;1m",
        "8-bit": "\x1b[0;38;5;128;1m",
        "24-bit": "\x1b[0;38;2;190;90;210;1m"
    ]),
]);

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return item == "seal-hidden" || item == "blade" ||
        item == "crescent blade" || item == "crescent";
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

            tell_object(person, sealColors[colorKey][colorConfig] +
                message + closing);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public void initiateSeilyndriaConversation()
{
    object *players = filter(all_inventory(environment(this_object())),
        (: $1->isRealizationOfPlayer() :));

    if (sizeof(players) && objectp(Seilyndria))
    {
        players[0]->characterState(Seilyndria, "seal broken");
        command("talk woman", players[0]);
    }
}

/////////////////////////////////////////////////////////////////////////////
public int cutBlade(string str)
{
    if (sealBroken)
    {
        write("The blade is dull and lifeless. The seal has already "
            "been broken.\n");
        return 1;
    }

    if (!stringp(str) || !sizeof(regexp(({ lower_case(str) }),
        "(blade|hand|self|myself|palm|crescent)")))
    {
        return 0;
    }

    sealBroken = 1;

    tellRoom(environment(this_object()), "ritual", format(
        "You draw your hand across the crescent blade. Pain flares "
        "as blood wells from the cut, dripping down the blade's edge "
        "and into the channel that funnels it toward the vessel. The "
        "blood flows through the four tubes and drips onto the "
        "withered heart.\n\n"
        "For a moment, nothing happens. Then the heart shudders. A "
        "second beat follows, then a third - each stronger than the "
        "last. The heart swells, dark veins pulsing with stolen life. "
        "Ancient gears grind somewhere deep within the walls. The "
        "massive sealed door shakes, dust cascading from its frame, "
        "and slowly, inexorably, begins to open.\n\n"
        "Beyond the door is absolute darkness. Then... footsteps.",
        78));

    object stateMachineService = getService("stateMachine");
    object player = this_player();
    object party = player->getParty();
    string owner = party ? party->partyName() : player->RealName();

    object stateMachine = stateMachineService->getStateMachine(
        "/areas/tol-dhurath/state-machine/obedience-quest.c",
        owner);

    if (stateMachine)
    {
        stateMachine->receiveEvent(player, "questCompleted");
    }

    Seilyndria = clone_object(
        "/areas/tol-dhurath/characters/seilyndria/seilyndria.c");
    move_object(Seilyndria, environment(this_object()));

    call_out("initiateSeilyndriaConversation", 1);

    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public string short()
{
    return sealBroken ? "A dull crescent blade above a beating heart" :
        "A crescent blade suspended above a withered heart";
}

/////////////////////////////////////////////////////////////////////////////
public string long()
{
    if (sealBroken)
    {
        return format("The crescent blade hangs motionless, its edge "
            "stained with blood. Below it, the once-withered heart now "
            "beats with a slow, dark rhythm. The massive door beyond "
            "stands open, revealing an empty chamber.", 78);
    }

    return format("A tall pillar of dark stone dominates the center of "
        "the chamber. Atop it sits a vessel of tarnished bronze, "
        "ancient and corroded. Four narrow tubes extend from the "
        "vessel, curving downward to converge upon a suspended heart "
        "- shrivelled, blackened, and impossibly old. The heart "
        "hangs motionless in a cage of copper wire.\n\n"
        "Above the heart, a long crescent blade is mounted on a "
        "pivot, its edge gleaming despite the ages. A narrow channel "
        "runs from the blade's edge down into the vessel, clearly "
        "designed to funnel liquid - or blood - into the mechanism.\n\n"
        "An inscription is carved into the vessel:\n"
        "  Heart of the damned,\n"
        "  Liquid of life,\n"
        "  The flames that bring cleansing,\n"
        "  Bring an end to your strife.\n\n"
        "You could 'cut blade' to draw your hand across the edge.",
        78);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("cutBlade", "cut");
    add_action("cutBlade", "touch");
    add_action("cutBlade", "use");
    add_action("cutBlade", "slash");
}
