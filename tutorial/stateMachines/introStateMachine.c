//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/stateMachine.c";
inherit "/tutorial/stateMachines/actors.c";
inherit "/tutorial/stateMachines/introductionDisplay.c";
inherit "/tutorial/stateMachines/initiateBackgroundStory.c";

private object Player;

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
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

    addState("on the trail", "");
    addEntryAction("on the trail", "onTheTrail");
    addTransition("first fight", "on the trail", "first fight is over");

    addState("wake up, Donald", "");
    addEntryAction("wake up, Donald", "wakeDonald");
    addTransition("on the trail", "wake up, Donald", "halgaladhAwakensDonald");

    addState("fight at the entrance", "");
    addEntryAction("fight at the entrance", "setupFightAtTheEntrance");
    addTransition("wake up, Donald", "fight at the entrance", "fightAtTheEntrance");

    addState("enter the lair", "");
    addTransition("fight at the entrance", "enter the lair", "enterTheLair");

    setInitialState("initiate story");
}

/////////////////////////////////////////////////////////////////////////////
public void beginIntroduction(object player)
{

    foreach(string actor in m_indices(actors))
    {
        if (objectp(actors[actor]))
        {
            foreach(object item in deep_inventory(actors[actor]))
            {
                destruct(item);
            }
            destruct(actors[actor]);
        }
        m_delete(actors, actor);
    }

    setUpActors();

    if (objectp(Player))
    {
        unregisterStateActor(Player);
        Player->unregisterEvent(this_object());
    }
    Player = player;
    registerStateActor(Player);
    Player->registerEvent(this_object());

    foreach(string actor in m_indices(actors))
    {
        registerStateActor(actors[actor]);
        actors[actor]->setLeader(Player);
    }

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
public void displayIntroduction()
{
    actors["galadhel"]->move("/tutorial/rooms/battleScene.c", "", 1);
    actors["berenar"]->move("/tutorial/rooms/battleScene.c", "", 1);
    call_out("partOne", 0, Player);
}

/////////////////////////////////////////////////////////////////////////////
public void playerTransitionsToBackgroundStory()
{
    call_out("slipIntoUnconsciousness", 8, Player);
}

/////////////////////////////////////////////////////////////////////////////
public void firstFight()
{
    tell_object(Player, format(
        "\n\x1b[0;36mAlmost as soon as Galadhel and Berenar finish "
        "administering to your wounds, a black-robed figure enters "
        "the clearing, several... walking corpses... in tow.\n\x1b[0m", 78));

    armPlayer(Player);
    addBattleSceneBadGuys(environment(Player));

    actors["zombie 1"]->attack(actors["galadhel"]);
    actors["berenar"]->attack(actors["zombie 1"]);
    actors["jerith"]->attack(actors["zombie 1"]);
    actors["keeper"]->attack(actors["jerith"]);

    actors["zombie 2"]->attack(Player);
}

/////////////////////////////////////////////////////////////////////////////
public void beginConversation(string id)
{
    notify("onTriggerConversation", id);
}

/////////////////////////////////////////////////////////////////////////////
public void galadhelExclaims()
{
    notify("onTriggerConversation", "jerith dies");
}

/////////////////////////////////////////////////////////////////////////////
public void onDeath(object caller)
{
    if (caller && (program_name(caller) == "/tutorial/characters/jerith.c"))
    {
        handleJerithDeath(environment(Player));
        m_delete(actors, "jerith");

        call_out("galadhelExclaims", 0);
    }

    else if (caller && (program_name(caller) == "/tutorial/characters/keeper-of-the-night.c"))
    {
        object *corpses = filter(all_inventory(environment(Player)),
            (: (member(inherit_list($1), "/lib/items/corpse.c") > -1) :));

        foreach(object corpse in corpses)
        {
            object *equipment = all_inventory(corpse);
            foreach(object item in equipment)
            {
                destruct(item);
            }
        }
        receiveEvent(this_object(), "first fight is over", Player);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onTheTrailPartTwo()
{
    if (actors["berenar"])
    {
        actors["berenar"]->onTriggerConversation(Player, "on the trail");
        move_object(Player, environment(Player));
        moveSquad("west", "/tutorial/rooms/fallenAegis.c");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onTheTrail()
{
    call_out("onTheTrailPartTwo", 2);
}

/////////////////////////////////////////////////////////////////////////////
public void wakeUpSir()
{
    if (actors["halgaladh"])
    {
        actors["halgaladh"]->onTriggerConversation(Player, "wake up sir");
    }
    else if (actors["donald"])
    {
        actors["donald"]->onTriggerConversation(Player, "you hit me");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void wakeDonald()
{
    call_out("wakeUpSir", 8);
}

/////////////////////////////////////////////////////////////////////////////
public void setupFightAtTheEntrance()
{
    addEntranceBadGuys(environment(Player), Player);
}
