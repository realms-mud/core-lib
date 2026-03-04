//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping mirrorColors = ([
    "shadow":([
        "none": "",
        "grayscale": "\x1b[0;38;5;237m",
        "3-bit": "\x1b[0;31m",
        "8-bit": "\x1b[0;38;5;52m",
        "24-bit": "\x1b[0;38;2;80;0;0m"
    ]),
    "calm":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;35;1m",
        "8-bit": "\x1b[0;38;5;128;1m",
        "24-bit": "\x1b[0;38;2;190;90;210;1m"
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

private int ignoreCount = 0;
private int requiredIgnores = 3;
private int puzzleSolved = 0;
private int actionCooldown = 0;

private string *attackMessages = ({
    "Your shadow lunges at you with claws of darkness!",
    "The dark reflection swings a blade of shadow!",
    "Your mirror-self strikes with a fist of pure malice!",
    "The shadow unleashes a howl of fury and rakes at you!",
    "Your reflection's eyes burn red as it lashes out!"
});

private string *ignoreMessages = ({
    "You close your eyes and stand firm. The shadow hisses.",
    "You turn away from the mirror. The shadow flickers uncertainly.",
    "You refuse to engage. The shadow's form wavers and thins."
});

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return item == "mirror-hidden";
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

            tell_object(person, mirrorColors[colorKey][colorConfig] +
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

        write(mirrorColors["shadow"][colorConfig] + message + closing + "\n");
        ret = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void completeMirror()
{
    puzzleSolved = 1;

    tellRoom(environment(this_player()), "success", format(
        "The shadow dissolves into wisps of darkness that "
        "spiral away into nothing. The mirror cracks and falls silent. "
        "Two runes clatter to the floor where the shadow stood.",
        78));

    object rune1 =
        clone_object("/tutorial/temple/objects/rune-fear.c");
    move_object(rune1, environment(this_object()));

    object rune2 =
        clone_object("/tutorial/temple/objects/rune-doom.c");
    move_object(rune2, environment(this_object()));

    object stateMachineService = getService("stateMachine");

    object party = this_player()->getParty();
    string owner = party ? party->partyName() : this_player()->RealName();

    object stateMachine = stateMachineService->getStateMachine(
        "/tutorial/temple/stateMachine/obedienceStateMachine.c",
        owner);

    stateMachine->receiveEvent(this_player(), "startFifthTest");
}

/////////////////////////////////////////////////////////////////////////////
public void finishAction()
{
    actionCooldown = 0;
}

/////////////////////////////////////////////////////////////////////////////
public int attackShadow(string str)
{
    if (puzzleSolved)
    {
        write("The mirror is cracked and dark. Nothing stirs within.\n");
        return 1;
    }

    if (actionCooldown)
    {
        write("You are still recovering from your last action.\n");
        return 1;
    }

    if (!stringp(str) || 
        !sizeof(regexp(({ lower_case(str) }), 
            "(shadow|reflection|mirror|self|it)")))
    {
        return 0;
    }

    actionCooldown = 1;
    ignoreCount = 0;

    string msg = attackMessages[random(sizeof(attackMessages))];

    write("You strike at the shadow in the mirror!\n");
    say(sprintf("%s strikes at the shadow in the mirror!\n",
        this_player()->Name()));

    tellRoom(environment(this_player()), "pain", sprintf(
        "The mirror cracks where you struck it, then reforms. "
        "Your reflection grins and strikes back!\n%s\n", msg));

    this_player()->hit(20, "magical");

    tellRoom(environment(this_player()), "hint",
        "The shadow reforms, stronger than before. Perhaps "
        "fighting is not the answer.\n");

    call_out("finishAction", 2);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int ignoreShadow(string str)
{
    if (puzzleSolved)
    {
        write("The mirror is cracked and dark. Nothing stirs within.\n");
        return 1;
    }

    if (actionCooldown)
    {
        write("You are still recovering from your last action.\n");
        return 1;
    }

    actionCooldown = 1;
    ignoreCount++;

    string msg = ignoreMessages[min(ignoreCount - 1,
        sizeof(ignoreMessages) - 1)];

    tellRoom(environment(this_player()), "calm",
        sprintf("%s\n", msg));

    if (ignoreCount >= requiredIgnores)
    {
        call_out("completeMirror", 2);
    }
    else
    {
        tellRoom(environment(this_player()), "hint",
            sprintf("The shadow seems weaker. Continue to "
            "resist the urge to fight. (%d/%d)\n",
            ignoreCount, requiredIgnores));
        call_out("finishAction", 2);
    }
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public string short()
{
    return puzzleSolved ? "A cracked mirror" : "A dark mirror with a living shadow";
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
        return format("The mirror is cracked and lifeless. The shadow "
            "is gone.", 78);
    }

    string desc = sprintf("%sA towering mirror of dark glass stands at "
        "the center of the room. Within it, your reflection moves "
        "independently - a shadow-version of yourself that snarls and "
        "claws at the glass, eager to strike. Its eyes burn with malice. "
        "It is everything you fear about yourself made manifest.%s\n\n"
        "%sYou can 'attack shadow' or you can 'ignore shadow', "
        "'turn away', or 'close eyes'. Not every battle is won with a "
        "blade.%s\n",
        mirrorColors["description"][colorConfig],
        closing,
        mirrorColors["instructions"][colorConfig],
        closing);

    return format(desc, 78);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("attackShadow", "attack");
    add_action("attackShadow", "strike");
    add_action("attackShadow", "fight");
    add_action("attackShadow", "hit");
    add_action("attackShadow", "kill");
    add_action("ignoreShadow", "ignore");
    add_action("ignoreShadow", "turn");
    add_action("ignoreShadow", "close");
    add_action("ignoreShadow", "refuse");
    add_action("ignoreShadow", "resist");
}
