//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/interactive_info.h"

/////////////////////////////////////////////////////////////////////////////
private nomask int isInteractive(object actor)
{
    return actor && interactive(actor) &&
        interactive_info(actor, II_IP_NUMBER);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void destroyActor(object actor)
{
    actor->notify("onDestructed");
    destruct(actor);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int moveInteractiveObjectToSafety(object actor)
{
    int ret = 0;
    if(isInteractive(actor))
    {
        object actorEnvironment;
        actorEnvironment = environment(actor);

        move_object(actor, find_object("/secure/master"));

        // Uh oh. We're already in master.c!
        if (actorEnvironment == environment(actor))
        {
            destroyActor(actor);
        }
        ret = 1;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void moveOrDestruct(object actor, object destination)
{
    string temp;

    string shortDescription = 0;

    catch (shortDescription = actor->short());

    if (actor->drop() || !shortDescription)
    {
        destroyActor(actor);
    }
    else if (catch (move_object(actor, destination)) ||
        (environment(actor) != destination))
    {
        moveInteractiveObjectToSafety(actor);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask mixed prepare_destruct(object actor)
{
    object actorEnvironment = environment(actor);
    object *actorInventory = all_inventory(actor);

    if (actor->has("pathfinding"))
    {
        catch (actor->cleanupPathfinding());
    }

    // A destruct here can cause extra junk to get placed in the environment.
    // Keep going until there isn't any more stuff
    while (sizeof(actorInventory))
    {
        foreach(object item in actorInventory)
        {
            if (actorEnvironment)
            {
                moveOrDestruct(item, actorEnvironment);
            }
            else
            {
                if (!moveInteractiveObjectToSafety(item))
                {
                    destroyActor(item);
                }
            }
        }

        actorInventory = all_inventory(actor);
    }

    return 0;
}
