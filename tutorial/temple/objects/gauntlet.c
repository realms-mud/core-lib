//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int currentWave = 0;
private int totalWaves = 8;
private int puzzleSolved = 0;
private int gauntletActive = 0;

private mapping gauntletColors = ([
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
    "wave":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;31;1m",
        "8-bit": "\x1b[0;38;5;196;1m",
        "24-bit": "\x1b[0;38;2;255;50;50;1m"
    ]),
    "success":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;34;1m",
        "8-bit": "\x1b[0;38;5;20;1m",
        "24-bit": "\x1b[0;38;2;0;0;220;1m"
    ]),
    "start":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;35;1m",
        "8-bit": "\x1b[0;38;5;128;1m",
        "24-bit": "\x1b[0;38;2;190;90;210;1m"
    ]),
]);

private mixed *waves = ({
    ({ "A volley of spectral arrows streaks from the walls!", "physical", 10 }),
    ({ "Ghostly flames erupt from the floor beneath you!", "fire", 12 }),
    ({ "A wave of freezing mist rolls through the chamber!", "cold", 12 }),
    ({ "Bolts of dark energy lance from the ceiling!", "energy", 14 }),
    ({ "The floor splits and spectral hands claw at your legs!", "physical", 14 }),
    ({ "A deafening shriek of sonic force slams into you!", "sonic", 16 }),
    ({ "Pillars of lightning arc between the walls through you!", "electricity", 16 }),
    ({ "The full force of the gauntlet unleashes upon you!", "magical", 20 }),
});

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return item == "gauntlet-hidden";
}

/////////////////////////////////////////////////////////////////////////////
private int isValidPattern()
{
    return puzzleSolved;
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

            tell_object(person, gauntletColors[colorKey][colorConfig] +
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

        write(gauntletColors["start"][colorConfig] + message + closing + "\n");
        ret = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void completeGauntlet()
{
    puzzleSolved = 1;
    gauntletActive = 0;

    tellRoom(environment(this_object()), "success", format(
        "Silence falls. The chamber is still. You have "
        "endured. A single rune materializes in the air before you, "
        "drifting gently to the floor.", 78));

    object rune1 =
        clone_object("/tutorial/temple/objects/rune-death.c");
    move_object(rune1, environment(this_object()));

    object stateMachineService = getService("stateMachine");

    object *players = filter(all_inventory(environment(this_object())),
        (: $1->isRealizationOfPlayer() :));

    if (sizeof(players))
    {
        object player = players[0];
        object party = player->getParty();
        string owner = party ? party->partyName() : player->RealName();

        object stateMachine = stateMachineService->getStateMachine(
            "/tutorial/temple/stateMachine/obedienceStateMachine.c",
            owner);

        stateMachine->receiveEvent(player, "startSeventhTest");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void fireWave()
{
    if (puzzleSolved || !gauntletActive)
    {
        return;
    }

    object room = environment(this_object());
    if (!room)
    {
        return;
    }

    object *players = filter(all_inventory(room),
        (: $1->isRealizationOfPlayer() :));

    if (!sizeof(players))
    {
        gauntletActive = 0;
        currentWave = 0;
        return;
    }

    if (currentWave >= totalWaves)
    {
        completeGauntlet();
        return;
    }

    string message = waves[currentWave][0];
    string damageType = waves[currentWave][1];
    int damage = waves[currentWave][2];

    tellRoom(room, "wave", sprintf(
        "\n--- Wave %d of %d ---\n%s\n",
        currentWave + 1, totalWaves, message));

    foreach(object player in players)
    {
        player->hit(damage, damageType);
    }

    currentWave++;
    call_out("fireWave", 6);
}

/////////////////////////////////////////////////////////////////////////////
public int beginGauntlet(string str)
{
    if (puzzleSolved)
    {
        write("The chamber is silent. The gauntlet has been overcome.\n");
        return 1;
    }

    if (gauntletActive)
    {
        write("The gauntlet is already underway! Endure!\n");
        return 1;
    }

    gauntletActive = 1;
    currentWave = 0;

    tellRoom(environment(this_player()), "start", format(
        "You steel yourself and step onto the central glyph. "
        "The chamber hums with gathering energy. The gauntlet begins!",
        78));

    call_out("fireWave", 3);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public string short()
{
    return puzzleSolved ? "A silent chamber" : 
        "A chamber with a glowing glyph on the floor";
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
        return format("The chamber is silent and still. Scorch marks "
            "and frost patterns on the walls are the only evidence of "
            "the gauntlet you survived.", 78);
    }

    string desc = sprintf("%sThe chamber thrums with contained energy. "
        "Strange marks score the walls - burns, frost patterns, and "
        "gouges that speak of terrible forces. At the center of the "
        "floor, a glyph pulses with a slow, ominous light. An "
        "inscription reads: 'Step forth and endure. There is no victory "
        "here save survival.'%s\n\n"
        "%sStep onto the glyph to begin. Use 'step onto glyph' or "
        "'begin gauntlet'.%s\n",
        gauntletColors["description"][colorConfig],
        closing,
        gauntletColors["instructions"][colorConfig],
        closing);

    return format(desc, 78);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("beginGauntlet", "step");
    add_action("beginGauntlet", "begin");
    add_action("beginGauntlet", "start");
}
