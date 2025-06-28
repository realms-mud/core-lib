//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping pathfindingCache = ([]);
private int cacheTimeout = 300; // 5 minutes

// Delayed movement system variables
private string *currentPath = ({});
private object currentTarget = 0;
private int movementDelay = 5; // seconds between moves
private int isPathing = 0;

/////////////////////////////////////////////////////////////////////////////
private int heuristicDistance(object env1, object env2)
{
    // If both environments are in the same region, use Manhattan distance
    object region1 = env1->getRegion();
    object region2 = env2->getRegion();

    if (objectp(region1) && objectp(region2) && region1 == region2)
    {
        string coords1 = env1->getCoordinates();
        string coords2 = env2->getCoordinates();

        if (coords1 && coords2)
        {
            int x1 = to_int(regreplace(coords1, "([0-9]+)x[0-9]+", "\\1", 1));
            int y1 = to_int(regreplace(coords1, "[0-9]+x([0-9]+)", "\\1", 1));
            int x2 = to_int(regreplace(coords2, "([0-9]+)x[0-9]+", "\\1", 1));
            int y2 = to_int(regreplace(coords2, "[0-9]+x([0-9]+)", "\\1", 1));

            return abs(x1 - x2) + abs(y1 - y2);
        }
    }

    // Default heuristic for cross-region or unknown distances
    return 10;
}

/////////////////////////////////////////////////////////////////////////////
private string getLowestFScore(mapping openSet, mapping fScore)
{
    string lowest = "";  // Use empty string instead of 0
    int lowestScore = 999999;
    int foundAny = 0;

    foreach(string key in m_indices(openSet))
    {
        if (member(fScore, key) && fScore[key] < lowestScore)
        {
            lowest = key;
            lowestScore = fScore[key];
            foundAny = 1;
        }
    }

    return foundAny ? lowest : 0;  // Return 0 (null) if nothing found
}

/////////////////////////////////////////////////////////////////////////////
private object getNeighborEnvironment(object env, string direction)
{
    mapping exitData = env->getExitDirections();
    string state = env->currentState();
    string destination = 0;

    // Check current state first
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
    // Then check default state
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

    if (!destination)
    {
        return 0;
    }

    // First try region-based lookup
    object currentRegion = env->getRegion();
    if (objectp(currentRegion))
    {
        string coords = regreplace(destination, ".*/([0-9]+x[0-9]+)\\.c", "\\1", 1);
        if (coords != destination) // Regex matched
        {
            object neighbor = currentRegion->getEnvironment(coords);
            if (objectp(neighbor))
            {
                return neighbor;
            }
        }
    }
    
    // Fallback to load_object
    object neighbor = 0;
    string loadError = catch(neighbor = load_object(destination));
    if (!loadError && objectp(neighbor))
    {
        return neighbor;
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private string getDirectionBetween(object fromEnv, object toEnv)
{
    string toPath = object_name(toEnv);
    mapping exitData = fromEnv->getExitDirections();
    string state = fromEnv->currentState();

    // Check current state exits first
    if (member(exitData, state))
    {
        foreach(string direction in m_indices(exitData[state]))
        {
            string dest = 0;
            if (stringp(exitData[state][direction]))
            {
                dest = exitData[state][direction];
            }
            else if (mappingp(exitData[state][direction]))
            {
                dest = exitData[state][direction]["destination"];
            }

            // Remove .c extension from destination for comparison
            string destWithoutExt = regreplace(dest, "\\.c$", "", 1);
            if (destWithoutExt == toPath)
            {
                return direction;
            }
        }
    }

    // Check default exits
    if (member(exitData, "default"))
    {
        foreach(string direction in m_indices(exitData["default"]))
        {
            string dest = 0;
            if (stringp(exitData["default"][direction]))
            {
                dest = exitData["default"][direction];
            }
            else if (mappingp(exitData["default"][direction]))
            {
                dest = exitData["default"][direction]["destination"];
            }

            // Remove .c extension from destination for comparison
            string destWithoutExt = regreplace(dest, "\\.c$", "", 1);
            if (destWithoutExt == toPath)
            {
                return direction;
            }
        }
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private string *reconstructPath(mapping cameFrom, string current)
{
    string *path = ({});

    while (member(cameFrom, current))
    {
        string previous = cameFrom[current];
        object prevEnv = 0;
        object currentEnv = 0;
        
        // Try region-based approach first
        object thisEnv = environment(this_object());
        if (objectp(thisEnv))
        {
            object thisRegion = thisEnv->getRegion();
            if (objectp(thisRegion))
            {
                string prevCoords = regreplace(previous, ".*/([0-9]+x[0-9]+)", "\\1", 1);
                string currentCoords = regreplace(current, ".*/([0-9]+x[0-9]+)", "\\1", 1);
                
                if (prevCoords != previous)
                {
                    prevEnv = thisRegion->getEnvironment(prevCoords);
                }
                if (currentCoords != current)
                {
                    currentEnv = thisRegion->getEnvironment(currentCoords);
                }
            }
        }
        
        // Fallback to load_object
        if (!objectp(prevEnv))
        {
            string loadError = catch(prevEnv = load_object(previous));
        }
        if (!objectp(currentEnv))
        {
            string loadError = catch(currentEnv = load_object(current));
        }

        if (objectp(prevEnv) && objectp(currentEnv))
        {
            string direction = getDirectionBetween(prevEnv, currentEnv);
            if (direction)
            {
                path = ({ direction }) + path;
            }
        }
        current = previous;
    }

    return path;
}

/////////////////////////////////////////////////////////////////////////////
// Fixed A* pathfinding algorithm implementation
private string *findPath(object startEnv, object targetEnv, int maxDepth)
{
    if (!objectp(startEnv) || !objectp(targetEnv))
    {
        return ({});
    }

    if (startEnv == targetEnv)
    {
        return ({});
    }

    // Check cache first
    string cacheKey = sprintf("%s->%s", object_name(startEnv), object_name(targetEnv));
    if (member(pathfindingCache, cacheKey) &&
        pathfindingCache[cacheKey]["time"] > time() - cacheTimeout)
    {
        return pathfindingCache[cacheKey]["path"];
    }

    mapping openSet = ([]);
    mapping closedSet = ([]);
    mapping cameFrom = ([]);
    mapping gScore = ([]);
    mapping fScore = ([]);

    string startKey = object_name(startEnv);
    string targetKey = object_name(targetEnv);

    // Initialize starting node
    openSet[startKey] = startEnv;
    gScore[startKey] = 0;
    fScore[startKey] = heuristicDistance(startEnv, targetEnv);

    int iterations = 0;

    while (sizeof(openSet) && iterations < maxDepth)
    {
        iterations++;

        // Find node in openSet with lowest fScore
        string current = getLowestFScore(openSet, fScore);
        
        // Proper null check for LPC
        if (!current || current == "")
        {
            break; // No valid node found
        }
        
        object currentEnv = openSet[current];

        // Check if we reached the target
        if (current == targetKey)
        {
            string *path = reconstructPath(cameFrom, current);

            // Cache the result
            pathfindingCache[cacheKey] = ([
                "path": path,
                "time": time()
            ]);

            return path;
        }

        // Move current from openSet to closedSet
        m_delete(openSet, current);
        closedSet[current] = 1;

        // Examine all neighbors
        string *exits = currentEnv->exits();
        if (!exits || !sizeof(exits))
        {
            continue; // No exits from this room
        }

        foreach(string direction in exits)
        {
            object neighbor = getNeighborEnvironment(currentEnv, direction);
            if (!objectp(neighbor))
            {
                continue; // Invalid neighbor
            }

            string neighborKey = object_name(neighbor);

            if (member(closedSet, neighborKey))
            {
                continue; // Already processed
            }

            int tentativeGScore = gScore[current] + 1;

            // If neighbor not in openSet, add it
            if (!member(openSet, neighborKey))
            {
                openSet[neighborKey] = neighbor;
                gScore[neighborKey] = tentativeGScore;
                fScore[neighborKey] = tentativeGScore + heuristicDistance(neighbor, targetEnv);
                cameFrom[neighborKey] = current;
            }
            // If this path to neighbor is better, update it
            else if (tentativeGScore < gScore[neighborKey])
            {
                gScore[neighborKey] = tentativeGScore;
                fScore[neighborKey] = tentativeGScore + heuristicDistance(neighbor, targetEnv);
                cameFrom[neighborKey] = current;
            }
        }
    }

    // No path found - cache the failure
    pathfindingCache[cacheKey] = ([
        "path": ({}),
        "time": time()
    ]);

    return ({});
}

/////////////////////////////////////////////////////////////////////////////
// Movement delay configuration
public void setMovementDelay(int delay)
{
    if (delay > 0)
    {
        movementDelay = delay;
    }
}

/////////////////////////////////////////////////////////////////////////////
public int getMovementDelay()
{
    return movementDelay;
}

/////////////////////////////////////////////////////////////////////////////
private int calculateMovementDelay()
{
    int baseDelay = movementDelay;
    object currentEnv = environment(this_object());
    
    if (objectp(currentEnv))
    {
        // Slower movement in difficult terrain
        if (currentEnv->id("swamp") || currentEnv->id("marsh"))
        {
            baseDelay += 3;
        }
        else if (currentEnv->id("mountain") || currentEnv->id("rocky"))
        {
            baseDelay += 2;
        }
        else if (currentEnv->id("road") || currentEnv->id("path"))
        {
            baseDelay -= 1;
        }
    }
    
    // Factor in monster's condition
    int healthPercent = (this_object()->hitPoints() * 100) / this_object()->maxHitPoints();
    if (healthPercent < 25)
    {
        baseDelay += 2; // Injured monsters move slower
    }
    else if (healthPercent < 50)
    {
        baseDelay += 1;
    }
    
    // Minimum delay
    if (baseDelay < 1)
    {
        baseDelay = 1;
    }
    
    return baseDelay;
}

/////////////////////////////////////////////////////////////////////////////
public void stopPathing()
{
    remove_call_out("executeNextMove");
    remove_call_out("resumePathing");
    
    isPathing = 0;
    currentPath = ({});
    currentTarget = 0;
}

/////////////////////////////////////////////////////////////////////////////
// Callback methods
protected void onPathCompleted()
{
    // Default: do nothing
}

/////////////////////////////////////////////////////////////////////////////
protected void onPathFailed()
{
    // Default: do nothing
}

/////////////////////////////////////////////////////////////////////////////
protected void onPathInterrupted(string reason)
{
    // Default behavior: try to resume pathing after a delay
    if (objectp(currentTarget))
    {
        call_out("resumePathing", 10);
    }
}

/////////////////////////////////////////////////////////////////////////////
private void recalculatePath()
{
    if (!objectp(currentTarget))
    {
        return;
    }
    
    string *newPath = findPath(environment(this_object()), currentTarget, 50);
    
    if (sizeof(newPath))
    {
        currentPath = newPath;
        call_out("executeNextMove", calculateMovementDelay());
    }
    else
    {
        // Can't find path, stop trying
        isPathing = 0;
        currentTarget = 0;
        onPathFailed();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void executeNextMove()
{
    if (!sizeof(currentPath))
    {
        isPathing = 0;
        currentTarget = 0;
        onPathCompleted();
        return;
    }
    
    string nextDirection = currentPath[0];
    currentPath = currentPath[1..];
    
    // Attempt the move - this calls the monster's moveInDirection method
    if (this_object()->moveInDirection(nextDirection))
    {
        // Move successful, schedule next move if path continues
        if (sizeof(currentPath))
        {
            int delay = calculateMovementDelay();
            call_out("executeNextMove", delay);
        }
        else
        {
            // Path completed
            isPathing = 0;
            currentTarget = 0;
            onPathCompleted();
        }
    }
    else
    {
        // Path completed - verify we actually reached the target
        if (environment(this_object()) == currentTarget)
        {
            // Successfully reached target
            isPathing = 0;
            currentTarget = 0;
            onPathCompleted();
        }
        else
        {
            // Path exhausted but didn't reach target - recalculate
            recalculatePath();
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public int startPathingTo(object targetEnvironment, int maxSteps)
{
    int ret = 0;
    
    if (isPathing)
    {
        stopPathing();
    }
    
    if (objectp(targetEnvironment))
    {
        string *path = findPath(environment(this_object()), targetEnvironment, maxSteps);
        
        if (sizeof(path))
        {
            currentPath = path;
            currentTarget = targetEnvironment;
            isPathing = 1;
         
            // Start the movement chain with immediate execution
            call_out("executeNextMove", 0);
            
            ret = 1;
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int startHuntingTarget(object target, int maxSteps)
{
    int ret = 0;
    
    if (objectp(target))
    {
        object targetEnv = environment(target);
        if (objectp(targetEnv))
        {
            ret = startPathingTo(targetEnv, maxSteps);
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int startPathingToCoordinates(object region, int targetX, int targetY, int maxSteps)
{
    int ret = 0;
    
    if (objectp(region))
    {
        string targetLocation = sprintf("%dx%d", targetX, targetY);
        object targetEnv = region->getEnvironment(targetLocation);
        
        if (objectp(targetEnv))
        {
            ret = startPathingTo(targetEnv, maxSteps);
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void interruptPathing(string reason)
{
    if (isPathing)
    {
        stopPathing();
        onPathInterrupted(reason);
    }
}

/////////////////////////////////////////////////////////////////////////////
private void resumePathing()
{
    if (objectp(currentTarget) && !isPathing)
    {
        startPathingTo(currentTarget, 50);
    }
}

/////////////////////////////////////////////////////////////////////////////
// Status methods
public int isCurrentlyPathing()
{
    return isPathing;
}

/////////////////////////////////////////////////////////////////////////////
public string *getCurrentPath()
{
    return currentPath + ({});
}

/////////////////////////////////////////////////////////////////////////////
public object getCurrentTarget()
{
    return currentTarget;
}

/////////////////////////////////////////////////////////////////////////////
public int getPathLength()
{
    return sizeof(currentPath);
}

/////////////////////////////////////////////////////////////////////////////
// Legacy/immediate pathfinding methods
public string *pathTo(object targetEnvironment, int maxSteps)
{
    string *ret = ({});
    
    if (!maxSteps)
    {
        maxSteps = 50; // Default maximum search depth
    }

    object currentEnv = environment(this_object());
    if (objectp(currentEnv))
    {
        ret = findPath(currentEnv, targetEnvironment, maxSteps);
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string *pathToCoordinates(object region, int targetX, int targetY, int maxSteps)
{
    string *ret = ({});
    
    if (objectp(region))
    {
        string targetLocation = sprintf("%dx%d", targetX, targetY);
        object targetEnv = region->getEnvironment(targetLocation);

        if (objectp(targetEnv))
        {
            ret = pathTo(targetEnv, maxSteps);
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int moveTowards(object targetEnvironment, int maxSteps)
{
    return startPathingTo(targetEnvironment, maxSteps);
}

/////////////////////////////////////////////////////////////////////////////
// Environment discovery methods
public string *findNearbyEnvironments(int radius)
{
    string *nearbyRooms = ({});
    object currentEnv = environment(this_object());
    
    if (objectp(currentEnv))
    {
        object region = currentEnv->getRegion();
        
        if (objectp(region))
        {
            string coords = currentEnv->getCoordinates();
            if (coords)
            {
                int currentX = to_int(regreplace(coords, "([0-9]+)x[0-9]+", "\\1", 1));
                int currentY = to_int(regreplace(coords, "[0-9]+x([0-9]+)", "\\1", 1));
                
                for (int x = currentX - radius; x <= currentX + radius; x++)
                {
                    for (int y = currentY - radius; y <= currentY + radius; y++)
                    {
                        if (x >= 0 && y >= 0 && (x != currentX || y != currentY))
                        {
                            string location = sprintf("%dx%d", x, y);
                            object env = region->getEnvironment(location);
                            if (objectp(env))
                            {
                                nearbyRooms += ({ object_name(env) });
                            }
                        }
                    }
                }
            }
        }
    }
    
    return nearbyRooms;
}

/////////////////////////////////////////////////////////////////////////////
public object findNearestEnvironmentWithCreature(string creatureType, int maxDistance)
{
    object ret = 0;
    string *nearby = findNearbyEnvironments(maxDistance);
    
    foreach (string roomPath in nearby)
    {
        object room = load_object(roomPath);
        if (objectp(room))
        {
            object *creatures = filter(all_inventory(room),
                (: living($1) && $1->isRealizationOfMonster() :));
            
            foreach (object creature in creatures)
            {
                if (creature->query("race") == creatureType)
                {
                    ret = room;
                    break;
                }
            }
            if (ret)
            {
                break;
            }
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
// Cache and cleanup methods
public void clearPathfindingCache()
{
    pathfindingCache = ([]);
}

/////////////////////////////////////////////////////////////////////////////
public void cleanupPathfinding()
{
    stopPathing();
    clearPathfindingCache();
}
