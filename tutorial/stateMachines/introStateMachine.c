//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/stateMachine.c";

private object Player;
private mapping actors = ([]);

/////////////////////////////////////////////////////////////////////////////
private void setUpActors()
{
    if (!actors["galadhel"])
    {
        actors["galadhel"] = clone_object("/lib/tutorial/characters/galadhel/galadhel.c");
        registerStateActor(actors["galadhel"]);
        actors["galadhel"]->registerEvent(this_object());
    }

    if (!actors["berenar"])
    {
        actors["berenar"] = clone_object("/lib/tutorial/characters/berenar/berenar.c");
        registerStateActor(actors["berenar"]);
        actors["berenar"]->registerEvent(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        "stateMachine"::reset(arg);
        addState("initiate story", "");
        addEntryAction("initiate story", "displayIntroduction");

        addState("regain consciousness", "");
        addEntryAction("regain consciousness", "galadhelAwakensPlayer");
        addTransition("initiate story", "regain consciousness", "regainConsciousness");

        addState("berenar interjects", "");
        addEntryAction("berenar interjects", "berenarBeginsConversation");
        addTransition("regain consciousness", "berenar interjects", "berenarInterjects");

        addState("background story", "");
        addEntryAction("background story", "playerTransitionsToBackgroundStory");
        addTransition("berenar interjects", "background story", "playerAgainLosesConsciousness");

        addState("first fight", "");
        addEntryAction("first fight", "firstFight");
        addTransition("background story", "first fight", "onJoinGuild");

        setInitialState("initiate story");

        setUpActors();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void beginIntroduction(object player)
{
    if (objectp(Player))
    {
        unregisterStateActor(Player);
        Player->unregisterEvent(this_object());
    }
    Player = player;
    registerStateActor(Player);
    Player->registerEvent(this_object());
    startStateMachine();
}

/////////////////////////////////////////////////////////////////////////////
public void galadhelAwakensPlayer()
{
    notify("onTriggerConversation", "galadhel awakens player");
}

/////////////////////////////////////////////////////////////////////////////
public void berenarBeginsConversation()
{
    notify("onTriggerConversation", "berenar interjects");
}

/////////////////////////////////////////////////////////////////////////////
public void partThree(object player)
{
    tell_object(player,
        "\n\x1b[0;36mBasil was an expert in crushing hope too. \x1b[0;32m`An ill "
        "omen...'\x1b[0m\x1b[0;36m muttered Basil.\n\x1b[0;32m`Blood will be spilled "
        "today.'\x1b[0m\x1b[0;36m Captain Basil, was never one for euphemisms.\n"
        "Poor bastard. Little did he know at the time that the blood would "
        "be his own...\x1b[0m\n\n");
    call_out("receiveEvent", 4, player, "regainConsciousness", player);
}

/////////////////////////////////////////////////////////////////////////////
public void partTwo(object player)
{
    tell_object(player, format(
        "\n\x1b[0;36mBasil, your company commander, imparted these words of wisdom "
        "on you countless times in the past. He'd said as much with a wry "
        "smile as he ordered you to patrol this accursed road for the 26th "
        "time since the stalemate was broken. It's funny. As the first "
        "flame-red rays of the new day pierced the thin wisps of fog, "
        "you couldn't help but think of how beautiful it was, despite your "
        "mundane and lamentably never-ending task.\x1b[0m", 78));
    call_out("partThree", 8, player);
}

/////////////////////////////////////////////////////////////////////////////
public void partOne(object player)
{
    tell_object(player, format(
        "\x1b[0;36mOn a long campaign, sometimes routine is the only thing that "
        "keeps one going. Any good commander knows this - keep your men "
        "focused on the task at hand and keep them too exhausted for idle "
        "thought. Dig a ditch if you must, if for no other reason than to "
        "keep 'em busy. Another day can be spent filling the damned thing "
        "later.\x1b[0m", 78));
    call_out("partTwo", 8, player);
}

/////////////////////////////////////////////////////////////////////////////
public void displayIntroduction()
{
    move_object(actors["galadhel"], "/lib/tutorial/rooms/battleScene.c");
    move_object(actors["berenar"], "/lib/tutorial/rooms/battleScene.c");
    call_out("partOne", 0, Player);
}

/////////////////////////////////////////////////////////////////////////////
public void slipIntoUnconsciousnessPartThree()
{
    load_object("/lib/dictionaries/guildsDictionary.c");
    load_object("/lib/guilds/background/background.c");

    if (!Player->memberOfGuild("background"))
    {
        Player->joinGuild("background");
    }
    else
    {
        Player->notify("onJoinGuild");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void slipIntoUnconsciousnessPartTwo()
{
    tell_object(Player, format(
        "\n\x1b[0;36mWith crystal clarity, the "
        "fog in your mind clears. You are back in time... that very day "
        "you made the decisions that started the chain of events "
        "leading you to your current, sorry state.\n\n"
        "\x1b[0;33;1mThis is where the background quest stuff would "
        "normally get triggered. Since I don't have any here, we will "
        "short-circuit that right now.\x1b[0m", 78));
    call_out("slipIntoUnconsciousnessPartThree", 8);
}

/////////////////////////////////////////////////////////////////////////////
public void slipIntoUnconsciousness()
{
    tell_object(Player, format(
        "\n\x1b[0;36mAs Berenar and Galadhel tend to your injuries, it hurts "
        "like nothing you've felt before. Unbidden, the thought comes to your "
        "mind, \x1b[0;32m`So this is what it feels like to die.'\x1b[0;36m "
        "Angry that those thoughts came so easily... angry that you're lying "
        "in a pool of your own damned blood, you shake your head. That act "
        "proves to be most unwise as a wave of lightheadedness overtakes "
        "you and your eyesight goes blurry.\n\x1b[0m", 78));
    call_out("slipIntoUnconsciousnessPartTwo", 8);
}

/////////////////////////////////////////////////////////////////////////////
public void playerTransitionsToBackgroundStory()
{
    call_out("slipIntoUnconsciousness", 8);
}

/////////////////////////////////////////////////////////////////////////////
public void firstFight()
{
    tell_object(Player, format(
        "\n\x1b[0;36mAlmost as soon as Galadhel and Berenar finish "
        "administering to your wounds, a black-robed figure enters "
        "the clearing, several... walking corpses... in tow.\n\x1b[0m", 78));

    if (!Player->equipmentInSlot("wielded primary"))
    {
        tell_object(Player, format(
            "\n\x1b[0;36mBerenar thrusts a sword into your hands and "
            "shouts, \x1b[0;32m`Take this! The enemy is upon us!'\x1b[0;36m"
            " Without another word, he lunges into the fray.\n\x1b[0m", 78));

        object equipment = clone_object("/lib/instances/items/weapons/swords/short-sword.c");
        equipment->set("identified", 1); 
        equipment->set("craftsmanship", 50);
        equipment->set("material", "steel");
        move_object(equipment, Player);
        Player->equip(equipment, 1);
    }

    actors["keeper"] = clone_object("/lib/tutorial/characters/keeper-of-the-night.c");
    move_object(actors["keeper"], "/lib/tutorial/rooms/battleScene.c");
    actors["keeper"]->registerEvent(this_object());

    object jerith = clone_object("/lib/tutorial/characters/jerith.c");
    move_object(jerith, "/lib/tutorial/rooms/battleScene.c");
    jerith->hit(140, "physical");
    jerith->registerEvent(actors["galadhel"]);
    jerith->registerEvent(this_object());

    actors["zombie 1"] = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(actors["zombie 1"], "/lib/tutorial/rooms/battleScene.c");
    actors["zombie 1"]->attack(actors["galadhel"]);
    actors["berenar"]->attack(actors["zombie 1"]);
    jerith->attack(actors["zombie 1"]);
    actors["keeper"]->attack(jerith);

    actors["zombie 1"] = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(actors["zombie 1"], "/lib/tutorial/rooms/battleScene.c");
    actors["zombie 1"]->attack(Player);
    actors["berenar"]->attack(actors["zombie 1"]);
}

/////////////////////////////////////////////////////////////////////////////
public void onDeath(object caller)
{
    tell_room(environment(Player), sprintf("This guy => %O\n", program_name(caller)));

    if (caller && (program_name(caller) == "lib/tutorial/characters/jerith.c"))
    {
        tell_room(environment(Player),
            sprintf("Hearing the ongoing commotion, several additional Aegis "
                "Guardsmen rush into the fray.\n"));
        actors["berenar"]->attack(actors["keeper"]);

        actors["alberich"] = clone_object("/lib/tutorial/characters/alberich/alberich.c");
        move_object(actors["alberich"], "/lib/tutorial/rooms/battleScene.c");
        actors["alberich"]->attack(actors["keeper"]);

        actors["donald"] = clone_object("/lib/tutorial/characters/donald/donald.c");
        move_object(actors["donald"], "/lib/tutorial/rooms/battleScene.c");
        actors["donald"]->attack(actors["keeper"]);

        actors["halgaladh"] = clone_object("/lib/tutorial/characters/halgaladh/halgaladh.c");
        move_object(actors["halgaladh"], "/lib/tutorial/rooms/battleScene.c");
        actors["halgaladh"]->attack(actors["keeper"]);

        actors["thomas"] = clone_object("/lib/tutorial/characters/halgaladh/halgaladh.c");
        move_object(actors["thomas"], "/lib/tutorial/rooms/battleScene.c");

        if (actors["zombie 1"])
        {
            actors["zombie 1"]->attack(actors["halgaladh"]);
            actors["zombie 1"]->attack(actors["alberich"]);
            actors["zombie 1"]->attack(actors["thomas"]);
        }
        if (actors["zombie 2"])
        {
            actors["zombie 2"]->attack(actors["halgaladh"]);
            actors["zombie 2"]->attack(actors["thomas"]);
            actors["zombie 2"]->attack(actors["donald"]);
        }
    }

    else if (caller && (program_name(caller) == "lib/tutorial/characters/keeper-of-the-night.c"))
    {
        tell_room(environment(Player),
            sprintf("Yay! the keeper bought the farm!\n"));
    }
}

/////////////////////////////////////////////////////////////////////////////
public void finishBackgroundStory()
{
    // introductionCompleted(Player);
}
