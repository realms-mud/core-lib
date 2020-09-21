//*****************************************************************************
// Class: movement
// File Name: movement.c
//
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
    
/////////////////////////////////////////////////////////////////////////////
public nomask void runAway()
{
    object originalLocation = environment();
    if(originalLocation && function_exists("exits", originalLocation))
    {
        string *possibleDestinations = originalLocation->exits();
        object materialAttributes = getService("materialAttributes");

        if(possibleDestinations && materialAttributes &&
            !materialAttributes->queryProperty("no fear"))
        {
            int attemptsToRun = 0;
            while((attemptsToRun < 12) && (originalLocation == environment()))
            {
                string direction = 
                    possibleDestinations[random(sizeof(possibleDestinations))];
                command(direction);
                attemptsToRun++;
            }
            
            if(originalLocation == environment())
            {
                write("You tried, but failed to run away.\n");
                say(sprintf("%s tried, but failed to run away.", 
                    materialAttributes->Name()));
            }
            else
            {
                write("Your legs run away with you!\n");
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private int checkForImpairedVision(object player)
{
    int ret = 0;

    object configuration = getDictionary("configuration");
    string colorConfiguration = this_object()->colorConfiguration() || "none";

    if (player->hasTraitOfRoot("blind"))
    {
        tell_object(player, configuration->decorate("You are blind.\n",
            "too dark", "environment", colorConfiguration));
        ret = 1;
    }
    else if (!player->canSee())
    {
        ret = 1;
        tell_object(player, configuration->decorate("It is too dark.\n",
            "too dark", "environment", colorConfiguration));

        object *environmentInventory = filter(
            all_inventory(environment(player)),
            (: $1->isRealizationOfLiving() &&
                !$1->hasTraitOfRoot("ethereal") &&
                !$1->hasTraitOfRoot("undead") :));

        if (player->hasTraitOfRoot("infravision") &&
            sizeof(environmentInventory))
        {
            string visibleList = configuration->decorate(
                "You can see objects faintly glowing in red:\n",
                "too dark", "environment", colorConfiguration);

            foreach(object environmentItem in environmentInventory)
            {
                string shortDesc = environmentItem->short();
                if (shortDesc && (shortDesc != ""))
                {
                    visibleList += configuration->decorate(
                        capitalize(shortDesc),
                        "infravision", "environment", colorConfiguration);
                }
            }

            if (visibleList != "")
            {
                tell_object(player, visibleList);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs nomask int move(string location, string direction, 
    int silently, object region)
{
    int ret = 0;
    object environmentDictionary = getDictionary("environment");
    if (environmentDictionary)
    {
        object newLocation = region ? region->getEnvironment(location) :
            environmentDictionary->getEnvironment(location);

        if (environmentDictionary->canMakeMove(this_object(), environment(),
            newLocation))
        {
            ret = 1;
            object combat = getService("combat");
            if (combat)
            {
                combat->handleMoveFromCombat();
            }

            object materialAttributes = getService("materialAttributes");
            if (materialAttributes->canSee() &&
                !materialAttributes->Invisibility() && !silently)
            {
                say(sprintf("%s %s.\n", capitalize(materialAttributes->Name()),
                    (direction ? sprintf("%s %s", getMessageParser()->parseVerbs(
                        materialAttributes->MessageOut()),
                        direction) : getMessageParser()->parseVerbs(
                            materialAttributes->MagicalMessageOut()))));
            }

            newLocation->enterEnvironment(this_object(), 
                this_object()->getParty());

            if (materialAttributes->canSee() && 
                !materialAttributes->Invisibility() && !silently)
            {
                say(sprintf("%s %s.\n", capitalize(materialAttributes->Name()),
                    (direction ? getMessageParser()->parseVerbs(
                        materialAttributes->MessageIn()) :
                        getMessageParser()->parseVerbs(
                            materialAttributes->MagicalMessageIn()))));
            }

            object eventObj = getService("events");
            if (objectp(eventObj))
            {
                eventObj->notify("onMove", ([ "from": environment(),
                                               "to": newLocation ]));
            }

            object player = getService("player");
            if (player && environment())
            {
                if(!checkForImpairedVision(player))
                {
                    tell_object(this_object(), environment()->long(player->brief()));
                }
            }
        }
    }
    else
    {
        raise_error("ERROR: The environment dictionary could not be loaded!\n");
    }
    return ret;
}
