//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/monster.c";
virtual inherit "/lib/modules/artificialIntelligence.c";
virtual inherit "/lib/modules/pathfinding.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfMonsterWithAI()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int moveInDirection(string direction)
{
    int ret = 0;
    object currentEnv = environment(this_object());
    
    if (objectp(currentEnv))
    {
        string *availableExits = currentEnv->exits();
        if (member(availableExits, direction) != -1)
        {
            // Get the destination
            mapping exitData = currentEnv->getExitDirections();
            string state = currentEnv->currentState();
            string destination = 0;
            
            if (member(exitData, state) && member(exitData[state], direction))
            {
                if (stringp(exitData[state][direction]))
                {
                    destination = exitData[state][direction];
                }
                else if (mappingp(exitData[state][direction]))
                {
                    destination = exitData[state][direction]["destination"];
                }
            }
            else if (member(exitData, "default") && member(exitData["default"], direction))
            {
                if (stringp(exitData["default"][direction]))
                {
                    destination = exitData["default"][direction];
                }
                else if (mappingp(exitData["default"][direction]))
                {
                    destination = exitData["default"][direction]["destination"];
                }
            }
            
            if (destination)
            {
                // Extract coordinates from destination path for region-based movement
                object currentRegion = currentEnv->getRegion();
                if (objectp(currentRegion))
                {
                    string coords = regreplace(destination, ".*/([0-9]+x[0-9]+)\\.c", "\\1", 1);
                    if (coords != destination) // Regex matched and extracted coordinates
                    {
                        // Use the movement module's move() method with region
                        ret = move(coords, direction, 0, currentRegion);
                    }
                }
                
                if (!ret)
                {
                    // Fallback to path-based movement for non-region environments
                    ret = move(destination, direction);
                }
            }
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected void onPathCompleted()
{
    // AI monsters can implement specific behavior when reaching destinations
    // This could trigger patrol behavior, idle actions, etc.
}

/////////////////////////////////////////////////////////////////////////////
protected void onPathFailed()
{
    // AI monsters can implement fallback behavior when pathfinding fails
    // This could trigger alternative routes, return to spawn, etc.
}

/////////////////////////////////////////////////////////////////////////////
protected void onPathInterrupted(string reason)
{
    if (reason == "enemy encountered")
    {
        // Don't resume pathing until combat is resolved
        return;
    }
    
    // For other interruptions, use the default behavior
    pathfinding::onPathInterrupted(reason);
}

/////////////////////////////////////////////////////////////////////////////
public void heart_beat()
{
    monster::heart_beat();
    
    // Check for interruptions during pathing
    if (isCurrentlyPathing())
    {
        object *enemies = filter(all_inventory(environment(this_object())),
            (: living($1) && !$1->isRealizationOfMonster() && this_object()->isHostileTo($1) :));
        
        if (sizeof(enemies))
        {
            interruptPathing("enemy encountered");
        }
    }
}
