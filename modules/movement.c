//*****************************************************************************
// Class: movement
// File Name: movement.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
public varargs nomask int move(string location, string direction)
{
    int ret = 0;
    object environmentDictionary = getDictionary("environment");
    if (environmentDictionary)
    {
        object newLocation = environmentDictionary->getLocation(location);
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
                !materialAttributes->Invisibility())
            {
                say(sprintf("%s %s.\n", capitalize(materialAttributes->Name()),
                    (direction ? sprintf("%s %s", materialAttributes->MessageOut(),
                        direction) : materialAttributes->MagicalMessageOut())));
            }

            move_object(this_object(), newLocation);

            if (materialAttributes->canSee() && 
                !materialAttributes->Invisibility())
            {
                say(sprintf("%s %s.\n", capitalize(materialAttributes->Name()),
                    (direction ? materialAttributes->MessageIn() :
                        materialAttributes->MagicalMessageIn())));
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
                tell_object(this_object(), environment()->long(player->brief()));
            }
        }
    }
    else
    {
        raise_error("ERROR: The environment dictionary could not be loaded!\n");
    }
    return ret;
}

