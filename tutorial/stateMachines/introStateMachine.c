//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/stateMachine.c";

private object Player;
private object Galadhel;
private object Berenar;

/////////////////////////////////////////////////////////////////////////////
private void setUpActors()
{
    if (!Galadhel)
    {
        Galadhel = clone_object("/lib/tutorial/characters/galadhel/galadhel.c");
        registerStateActor(Galadhel);
        Galadhel->registerEvent(this_object());
    }

    if (!Berenar)
    {
        Berenar = clone_object("/lib/tutorial/characters/berenar/berenar.c");
        registerStateActor(Berenar);
        Berenar->registerEvent(this_object());
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
    call_out("partThree", 4, player);
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
    call_out("partTwo", 4, player);
}

/////////////////////////////////////////////////////////////////////////////
public void displayIntroduction()
{
    move_object(Galadhel, "/lib/tutorial/rooms/battleScene.c");
    move_object(Berenar, "/lib/tutorial/rooms/battleScene.c");
    call_out("partOne", 2, Player);
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
    call_out("slipIntoUnconsciousnessPartThree", 4);
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
    call_out("slipIntoUnconsciousnessPartTwo", 4);
}

/////////////////////////////////////////////////////////////////////////////
public void playerTransitionsToBackgroundStory()
{
    call_out("slipIntoUnconsciousness", 6);
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


    object keeper = clone_object("/lib/tutorial/characters/keeper-of-the-night.c");
    move_object(keeper, "/lib/tutorial/rooms/battleScene.c");

    object jerith = clone_object("/lib/tutorial/characters/jerith.c");
    move_object(jerith, "/lib/tutorial/rooms/battleScene.c");
    jerith->registerEvent(Galadhel);
    keeper->attack(jerith);

    object monster = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(monster, "/lib/tutorial/rooms/battleScene.c");
    monster->attack(Galadhel);

    monster = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(monster, "/lib/tutorial/rooms/battleScene.c");
    //monster->attack(Player);
}

/////////////////////////////////////////////////////////////////////////////
public void finishBackgroundStory()
{
    // introductionCompleted(Player);
}
