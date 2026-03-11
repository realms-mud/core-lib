//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping dreamColors = ([
    "portal":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;35;1m",
        "8-bit": "\x1b[0;38;5;128;1m",
        "24-bit": "\x1b[0;38;2;190;90;210;1m"
    ]),
    "success":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;34;1m",
        "8-bit": "\x1b[0;38;5;20;1m",
        "24-bit": "\x1b[0;38;2;0;0;220;1m"
    ]),
]);

private int dreamActive = 0;
private int puzzleSolved = 0;

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return item == "dream-hidden";
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

            tell_object(person, dreamColors[colorKey][colorConfig] +
                message + closing);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private string *colorInfo()
{
    object user = this_player();
    string colorConfig = (objectp(user) && user->colorConfiguration()) ?
        user->colorConfiguration() : "none";
    string closing = (colorConfig == "none") ? "" : "\x1b[0m";
    return ({ colorConfig, closing });
}

/////////////////////////////////////////////////////////////////////////////
public int allowMove()
{
    int ret = 1;

    if (!isValidPattern())
    {
        string *ci = colorInfo();

        string message = format("As you approach the liquid, a brilliant arc of "
            "lightning crosses your path. You decide against "
            "proceeding.", 78);

        write(dreamColors["portal"][ci[0]] + message + ci[1] + "\n");
        ret = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void applyExperience()
{
    string colorConfiguration = this_player()->colorConfiguration();
    object configuration = getService("configuration");

    object party = this_player()->getParty();
    if (objectp(party))
    {
        object* members = party->members(1);
        foreach(object member in members)
        {
            if (objectp(member))
            {
                colorConfiguration = member->colorConfiguration();
                member->addExperience(100, "background", 1);
                tell_object(member, configuration->decorate(
                    "You have gained 100 experience.\n", "level up", "score",
                    colorConfiguration));
            }
        }
    }
    else
    {
        this_player()->addExperience(100, "background", 1);
        tell_object(this_player(), configuration->decorate(
            "You have gained 100 experience.\n", "level up", "score",
            colorConfiguration));
    }
}

/////////////////////////////////////////////////////////////////////////////
public void dreamCompleted(object player)
{
    puzzleSolved = 1;
    dreamActive = 0;

    tellRoom(environment(this_object()), "success", format(
        "The pool's glow fades to a gentle shimmer. Two "
        "runes rest on its surface, glistening with moisture.",
        78));

    object rune1 =
        clone_object("/areas/tol-dhurath/objects/rune-wisdom.c");
    move_object(rune1, environment(this_object()));

    object rune2 =
        clone_object("/areas/tol-dhurath/objects/rune-endurance.c");
    move_object(rune2, environment(this_object()));
    applyExperience();

    object stateMachineService = getService("stateMachine");

    object party = player->getParty();
    string owner = party ? party->partyName() : player->RealName();

    object stateMachine = stateMachineService->getStateMachine(
        "/areas/tol-dhurath/state-machine/obedience-quest.c",
        owner);

    stateMachine->receiveEvent(player, "startSixthTest");
}

/////////////////////////////////////////////////////////////////////////////
public int touchPool(string str)
{
    if (puzzleSolved)
    {
        write("The pool is calm and still. Its visions have been spent.\n");
        return 1;
    }

    if (!stringp(str) ||
        !sizeof(regexp(({ lower_case(str) }), "(pool|liquid|water|surface)")))
    {
        return 0;
    }

    if (dreamActive)
    {
        write("The pool's surface is already disturbed.\n");
        return 1;
    }

    dreamActive = 1;

    write("You reach toward the pool's surface...\n");
    say(sprintf("%s reaches toward the shimmering pool...\n",
        this_player()->Name()));

    tellRoom(environment(this_player()), "portal",
        "The liquid surges upward, enveloping your hand. "
        "The world dissolves into purple mist...\n");

    object dreamEntry = 
        load_object("/areas/tol-dhurath/temple-interior/dream/dream-entry.c");
    dreamEntry->setReturnPool(this_object());
    move_object(this_player(), dreamEntry);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public string short()
{
    return puzzleSolved ? "A still pool" : "A shimmering pool of deep purple";
}

/////////////////////////////////////////////////////////////////////////////
public string long()
{
    if (puzzleSolved)
    {
        return format("The pool is calm and dark, its visions spent.", 78);
    }

    return format("A pool of deep purple liquid shimmers with an "
        "otherworldly light. Ghostly images flicker just beneath the "
        "surface - faces, places, moments from another life. The liquid "
        "seems to beckon, promising understanding at the cost of "
        "experience.\n\nYou could 'touch pool' to enter the vision.", 78);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("touchPool", "touch");
    add_action("touchPool", "enter");
}
