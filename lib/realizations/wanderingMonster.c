//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/monster.c";
virtual inherit "/lib/modules/pathfinding.c";

private int wanderCounter = 0;
private int wanderFrequency = 5; // How often to attempt wandering (heart beats)
private int wanderChance = 30;   // Percentage chance to wander when counter triggers
private object lastLocation = 0; // Track previous location to avoid backtracking

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfWanderingMonster()
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
                // Store the current location before moving
                lastLocation = currentEnv;
                
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
private int canWander()
{
    int canWanderResult = 1;
    
    // Don't wander if in combat
    object combat = getModule("combat");
    if (combat && combat->inCombat())
    {
        canWanderResult = 0;
    }
    
    // Don't wander if currently pathfinding
    if (canWanderResult && isCurrentlyPathing())
    {
        canWanderResult = 0;
    }
    
    // Don't wander if paralyzed
    if (canWanderResult && combat && combat->isParalyzed())
    {
        canWanderResult = 0;
    }
    
    return canWanderResult;
}

/////////////////////////////////////////////////////////////////////////////
private string *getValidWanderDirections()
{
    string *validDirections = ({});
    object currentEnv = environment(this_object());
    
    if (objectp(currentEnv))
    {
        string *availableExits = currentEnv->exits();
        
        if (sizeof(availableExits))
        {
            foreach (string direction in availableExits)
            {
                int shouldAdd = 1;
                
                // Check if this direction leads back to our previous location
                if (objectp(lastLocation))
                {
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
                    
                    // Check if destination matches our last location
                    if (destination && (object_name(lastLocation) == destination))
                    {
                        shouldAdd = 0;
                    }
                }
                
                if (shouldAdd)
                {
                    validDirections += ({ direction });
                }
            }
            
            // If no valid directions (we're in a dead end), allow backtracking
            if (!sizeof(validDirections))
            {
                validDirections = availableExits;
            }
        }
    }
    
    return validDirections;
}

/////////////////////////////////////////////////////////////////////////////
private void attemptRandomWander()
{
    if (canWander())
    {
        object currentEnv = environment(this_object());
        if (objectp(currentEnv))
        {
            string *validDirections = getValidWanderDirections();
            
            if (sizeof(validDirections))
            {
                // Random chance to actually wander
                if (random(100) < wanderChance)
                {
                    // Pick a random direction from valid directions
                    string direction = validDirections[random(sizeof(validDirections))];
                    
                    // Attempt to move in that direction
                    moveInDirection(direction);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setWanderFrequency(int frequency)
{
    if (frequency > 0)
    {
        wanderFrequency = frequency;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int queryWanderFrequency()
{
    return wanderFrequency;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setWanderChance(int chance)
{
    if (chance >= 0 && chance <= 100)
    {
        wanderChance = chance;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int queryWanderChance()
{
    return wanderChance;
}

/////////////////////////////////////////////////////////////////////////////
public varargs nomask void enableWandering(int percentChance)
{
    wanderChance = percentChance ? percentChance : 30; // Default chance
}

/////////////////////////////////////////////////////////////////////////////
public nomask void disableWandering()
{
    wanderChance = 0;
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
    if (reason != "enemy encountered")
    {
        // For non-enemy interruptions, use the default behavior
        pathfinding::onPathInterrupted(reason);
    }
    // Don't resume pathing until combat is resolved for enemy encounters
}

/////////////////////////////////////////////////////////////////////////////
public void heart_beat()
{
    monster::heart_beat();
    
    // Check for interruptions during pathing
    if (isCurrentlyPathing())
    {
        object *enemies = filter(all_inventory(environment(this_object())),
            (: living($1) && 
                !$1->isRealizationOfMonster() && 
                this_object()->isHostileTo($1) :));
        
        if (sizeof(enemies))
        {
            interruptPathing("enemy encountered");
        }
    }
    
    // Handle random wandering
    wanderCounter++;
    if (wanderCounter >= wanderFrequency)
    {
        wanderCounter = 0;
        attemptRandomWander();
    }
}
