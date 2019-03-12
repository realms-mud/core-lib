//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/events.c"; 

protected mapping actors = ([]);

/////////////////////////////////////////////////////////////////////////////
protected void setUpActors()
{
    if (!actors["galadhel"])
    {
        actors["galadhel"] = clone_object("/lib/tutorial/characters/galadhel/galadhel.c");
        actors["galadhel"]->registerEvent(this_object());
    }

    if (!actors["berenar"])
    {
        actors["berenar"] = clone_object("/lib/tutorial/characters/berenar/berenar.c");
        actors["berenar"]->registerEvent(this_object());
    }

    if (!actors["alberich"])
    {
        actors["alberich"] = clone_object("/lib/tutorial/characters/alberich/alberich.c");
        actors["alberich"]->registerEvent(this_object());
    }

    if (!actors["donald"])
    {
        actors["donald"] = clone_object("/lib/tutorial/characters/donald/donald.c");
        actors["donald"]->registerEvent(this_object());
    }

    if (!actors["halgaladh"])
    {
        actors["halgaladh"] = clone_object("/lib/tutorial/characters/halgaladh/halgaladh.c");
        actors["halgaladh"]->registerEvent(this_object());
    }

    if (!actors["thomas"])
    {
        actors["thomas"] = clone_object("/lib/tutorial/characters/thomas/thomas.c");
        actors["thomas"]->registerEvent(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
protected void handleJerithDeath(object location)
{
    tell_room(location,
        sprintf("Hearing the ongoing commotion, several additional Aegis "
            "Guardsmen rush into the fray.\n"));
    actors["berenar"]->attack(actors["keeper"]);

    move_object(actors["alberich"], location);
    actors["alberich"]->attack(actors["keeper"]);

    move_object(actors["donald"], location);
    actors["donald"]->attack(actors["keeper"]);

    move_object(actors["halgaladh"], location);
    actors["halgaladh"]->attack(actors["keeper"]);

    move_object(actors["thomas"], location);

    if (actors["zombie 1"])
    {
        actors["zombie 1"]->attack(actors["halgaladh"]);
        actors["zombie 1"]->attack(actors["alberich"]);
        actors["zombie 1"]->attack(actors["thomas"]);
        actors["thomas"]->attack(actors["zombie 1"]);
    }
    if (actors["zombie 2"])
    {
        actors["zombie 2"]->attack(actors["halgaladh"]);
        actors["zombie 2"]->attack(actors["thomas"]);
        actors["zombie 2"]->attack(actors["donald"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected void addBattleSceneBadGuys(object location)
{
    actors["keeper"] = clone_object("/lib/tutorial/characters/keeper-of-the-night.c");
    move_object(actors["keeper"], location);
    actors["keeper"]->registerEvent(this_object());

    actors["jerith"] = clone_object("/lib/tutorial/characters/jerith.c");
    move_object(actors["jerith"], location);
    actors["jerith"]->hit(140, "physical");
    actors["jerith"]->registerEvent(this_object());

    actors["zombie 1"] = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(actors["zombie 1"], location);

    actors["zombie 2"] = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(actors["zombie 2"], location);
    actors["keeper"]->registerEvent(actors["zombie 1"]);
    actors["keeper"]->registerEvent(actors["zombie 2"]);
}

/////////////////////////////////////////////////////////////////////////////
protected void addEntranceBadGuys(object location, object player)
{
    actors["keeper"] = clone_object("/lib/tutorial/characters/bregar/bregar.c");
    move_object(actors["keeper"], location);
    actors["keeper"]->registerEvent(this_object());

    actors["alberich"]->attack(actors["keeper"]);
    actors["donald"]->attack(actors["keeper"]);
    actors["halgaladh"]->attack(actors["keeper"]);

    actors["zombie 1"] = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(actors["zombie 1"], location);
    actors["galadhel"]->attack(actors["zombie 1"]);

    actors["zombie 2"] = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(actors["zombie 2"], location);
    actors["thomas"]->attack(actors["zombie 2"]);

    actors["zombie 3"] = clone_object("/lib/tutorial/characters/animated-corpse.c");
    move_object(actors["zombie 3"], location);
    player->attack(actors["zombie 3"]);

    actors["keeper"]->registerEvent(actors["zombie 1"]);
    actors["keeper"]->registerEvent(actors["zombie 2"]);
    actors["keeper"]->registerEvent(actors["zombie 3"]);
    move_object(player, location);
}

/////////////////////////////////////////////////////////////////////////////
protected void armPlayer(object player)
{
    if (!player->equipmentInSlot("wielded primary"))
    {
        tell_object(player, format(
            "\n\x1b[0;36mBerenar thrusts a sword and several potions into your hands and "
            "shouts, \x1b[0;32m`Take this! The enemy is upon us!'\x1b[0;36m"
            " Without another word, he lunges into the fray.\n\x1b[0m", 78));

        object equipment = clone_object("/lib/instances/items/weapons/swords/short-sword.c");
        equipment->set("identified", 1);
        equipment->set("craftsmanship", 50);
        equipment->set("material", "steel");
        move_object(equipment, player);
        player->equip(equipment, 1);

    }

    for (int i = 0; i < 4; i++)
    {
        object potion = clone_object("/lib/instances/items/potions/healing.c");
        move_object(potion, player);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void moveSquad(string direction, string location)
{
    tell_room(environment(actors["alberich"]),
        sprintf("Alberich, Halgaladh, Thomas, "
            "Donald, and Galadhel leave to the %s.\n", direction));

    actors["alberich"]->move(location, direction, 1);
    actors["thomas"]->move(location, direction, 1);
    actors["donald"]->move(location, direction, 1);
    actors["halgaladh"]->move(location, direction, 1);
    actors["galadhel"]->move(location, direction, 1);
}

/////////////////////////////////////////////////////////////////////////////
public void finishProd(object actor, string direction, object location)
{
    if (objectp(actor) && objectp(location) && stringp(direction))
    {
        command(direction, actor);
        move_object(actor, location);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void prodPlayer(object player, string actor, string message,
    string direction)
{
    if (member(actors, actor) && objectp(actors[actor]) && objectp(player))
    {
        object startingLocation = environment(actors[actor]);
        move_object(actors[actor], environment(player));

        tell_room(environment(player), sprintf("%s arrives from the %s.\n",
            capitalize(actors[actor]->Name()), direction));

        notify("onTriggerConversation", message);
        call_out("finishProd", 2, actors[actor], direction, startingLocation);
    }
}
