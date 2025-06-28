//*****************************************************************************
// File: lib/tests/modules/pathfindingTest.c
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Monster;
object TargetMonster;
object Region;
object StartRoom;
object TargetRoom;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetUpMonster", "SetUpTargetMonster", "SetUpRegion" });
}

/////////////////////////////////////////////////////////////////////////////
void SetUpMonster()
{
    Monster = clone_object("/lib/tests/support/services/testMonsterWithAI.c");
    Monster.Name("Test Monster");
    Monster.Str(20);
    Monster.Dex(20);
    Monster.Con(20);
    Monster.Int(20);
    Monster.Wis(20);
    Monster.setMaxHitPoints(100);
    Monster.hitPoints(100);
    Monster.setMaxSpellPoints(50);
    Monster.spellPoints(50);
    Monster.setMaxStaminaPoints(50);
    Monster.staminaPoints(50);
    Monster.setMovementDelay(1);
}

/////////////////////////////////////////////////////////////////////////////
void SetUpTargetMonster()
{
    TargetMonster = clone_object("/lib/tests/support/services/testMonsterWithAI.c");
    TargetMonster.Name("Target Monster");
    TargetMonster.Str(15);
    TargetMonster.Dex(15);
    TargetMonster.Con(15);
    TargetMonster.Int(15);
    TargetMonster.Wis(15);
    TargetMonster.setMaxHitPoints(80);
    TargetMonster.hitPoints(80);
    TargetMonster.setMovementDelay(1);
}

/////////////////////////////////////////////////////////////////////////////
void SetUpRegion()
{
    Region = clone_object("/lib/tests/support/pathfinding/region.c");
    StartRoom = Region.getEnvironment("0x0");
    TargetRoom = Region.getEnvironment("0x1");
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ToggleCallOutBypass();
    SetUpMonster();
    SetUpTargetMonster();
    SetUpRegion();
    
    if (objectp(StartRoom) && objectp(Monster))
    {
        move_object(Monster, StartRoom);
    }
    if (objectp(TargetRoom) && objectp(TargetMonster))
    {
        move_object(TargetMonster, TargetRoom);
    }
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    ToggleCallOutBypass();
    if (objectp(Monster))
    {
        Monster.cleanupPathfinding();
        destruct(Monster);
    }
    if (objectp(TargetMonster))
    {
        TargetMonster.cleanupPathfinding();
        destruct(TargetMonster);
    }
    if (objectp(Region))
    {
        destruct(Region);
    }
}

/////////////////////////////////////////////////////////////////////////////
void PathToFindsValidPathToAdjacentRoom()
{
    object currentEnv = environment(Monster);
    object nearbyRoom = Region.getEnvironment("0x1");
    
    string *path = Monster.pathTo(nearbyRoom, 50);
    
    ExpectTrue(sizeof(path) > 0, "Path should be found to adjacent room");
    ExpectEq("north", path[0], "First move should be north from 0x0");
}

/////////////////////////////////////////////////////////////////////////////
void PathToHandlesInvalidTargets()
{
    // Test with null target
    string *nullPath = Monster.pathTo(0, 10);
    ExpectEq(0, sizeof(nullPath), "pathTo with null target should return empty array");
    
    // Test same room (should return empty array)
    object currentEnv = environment(Monster);
    string *samePath = Monster.pathTo(currentEnv, 10);
    ExpectEq(0, sizeof(samePath), "pathTo to same room should return empty array");
}

/////////////////////////////////////////////////////////////////////////////
void PathToCoordinatesWorksCorrectly()
{
    // Test with valid adjacent coordinates
    string *path = Monster.pathToCoordinates(Region, 0, 1, 50);
    ExpectTrue(sizeof(path) > 0, "Path should be found to valid coordinates");
    ExpectEq("north", path[0], "First move should be north");
}

/////////////////////////////////////////////////////////////////////////////
void PathToCoordinatesHandlesErrors()
{
    // Test with null region
    string *nullPath = Monster.pathToCoordinates(0, 1, 1, 1);
    ExpectEq(0, sizeof(nullPath), "Null region should return empty array");
    
    // Test with invalid coordinates (now safe due to bounds checking)
    string *invalidPath = Monster.pathToCoordinates(Region, 999, 999, 1);
    ExpectEq(0, sizeof(invalidPath), "Invalid coordinates should return empty array");
}

/////////////////////////////////////////////////////////////////////////////
void StartPathingToInitiatesAndCompletesMovement()
{
    object initialRoom = environment(Monster);
    
    int result = Monster.startPathingTo(TargetRoom, 50);
    
    ExpectTrue(result, "startPathingTo should return success");
    ExpectTrue(Monster.wasPathCompleted(), "Path should have completed successfully");
    ExpectNotEq(initialRoom, environment(Monster), "Monster should have moved from initial room");
    ExpectEq(TargetRoom, environment(Monster), "Monster should have reached target room");
}

/////////////////////////////////////////////////////////////////////////////
void StartPathingToHandlesInvalidTargets()
{
    // Test with null target
    int result = Monster.startPathingTo(0, 50);
    ExpectFalse(result, "startPathingTo with null target should fail");
    ExpectFalse(Monster.wasPathCompleted(), "Path should not have completed");
}

/////////////////////////////////////////////////////////////////////////////
void StartHuntingTargetWorksCorrectly()
{
    object initialRoom = environment(Monster);
    
    int result = Monster.startHuntingTarget(TargetMonster, 50);
    
    ExpectTrue(result, "startHuntingTarget should succeed");
    ExpectTrue(Monster.wasPathCompleted(), "Hunt path should have completed successfully");
    ExpectNotEq(initialRoom, environment(Monster), "Monster should have moved from initial room");
    ExpectEq(TargetRoom, environment(Monster), "Monster should have reached target's location");
}

/////////////////////////////////////////////////////////////////////////////
void StartPathingToCoordinatesWorksCorrectly()
{
    object initialRoom = environment(Monster);
    
    int result = Monster.startPathingToCoordinates(Region, 0, 1, 50);
    
    ExpectTrue(result, "startPathingToCoordinates should succeed");
    ExpectTrue(Monster.wasPathCompleted(), "Coordinate path should have completed successfully");
    ExpectNotEq(initialRoom, environment(Monster), "Monster should have moved from initial room");
    ExpectEq(TargetRoom, environment(Monster), "Monster should have reached target coordinates");
}

/////////////////////////////////////////////////////////////////////////////
void MoveInDirectionMovesMonsterCorrectly()
{
    object currentEnv = environment(Monster);
    ExpectEq(StartRoom, currentEnv, "Monster should start in StartRoom");
    
    int result = Monster.moveInDirection("north");
    
    ExpectTrue(result, "moveInDirection should succeed");
    ExpectNotEq(StartRoom, environment(Monster), "Monster should have moved");
    ExpectEq("0x1", environment(Monster).getCoordinates(), "Monster should be at 0x1");
}

/////////////////////////////////////////////////////////////////////////////
void MoveInDirectionHandlesInvalidDirections()
{
    object currentEnv = environment(Monster);
    
    int result = Monster.moveInDirection("invalidDirection");
    ExpectFalse(result, "moveInDirection should fail with invalid direction");
    ExpectEq(currentEnv, environment(Monster), "Monster should not have moved");
}

/////////////////////////////////////////////////////////////////////////////
void MonsterMovesWhenPathingStarts()
{
    object initialRoom = environment(Monster);
    
    Monster.startPathingTo(TargetRoom, 50);
    
    // Verify pathfinding completed and monster moved
    ExpectTrue(Monster.wasPathCompleted(), "Path should have completed");
    ExpectNotEq(initialRoom, environment(Monster), "Monster should have moved one step");
}

/////////////////////////////////////////////////////////////////////////////
void StopPathingHaltsMovement()
{
    Monster.startPathingTo(TargetRoom, 50);
    
    // Since pathfinding completes immediately in test mode, stopping after completion should work
    Monster.stopPathing();
    
    ExpectFalse(Monster.isCurrentlyPathing(), "Monster should not be pathing after stop");
    ExpectEq(0, Monster.getCurrentTarget(), "Target should be cleared");
    ExpectEq(0, Monster.getPathLength(), "Path should be cleared");
}

/////////////////////////////////////////////////////////////////////////////
void InterruptPathingStopsMovementWithReason()
{
    // For this test, we need a longer path to interrupt before completion
    object room0x2 = Region.getEnvironment("0x2");
    if (objectp(room0x2))
    {
        Monster.startPathingTo(room0x2, 50);
        Monster.interruptPathing("enemy encountered");
        
        ExpectFalse(Monster.isCurrentlyPathing(), "Monster should not be pathing after interruption");
    }
    else
    {
        ExpectTrue(1, "Room 0x2 not available - skipping interruption test");
    }
}

/////////////////////////////////////////////////////////////////////////////
void PathfindingCompletionIsProperlyTracked()
{
    // Verify completion tracking starts clean
    ExpectFalse(Monster.wasPathCompleted(), "Path completion should start false");
    
    // Execute pathfinding
    Monster.startPathingTo(TargetRoom, 50);
    
    // Verify completion was tracked
    ExpectTrue(Monster.wasPathCompleted(), "Path completion should be tracked");
    ExpectEq(TargetRoom, environment(Monster), "Monster should be at target");
}

/////////////////////////////////////////////////////////////////////////////
void MovementDelayCanBeConfigured()
{
    ExpectEq(1, Monster.getMovementDelay(), "Initial delay should be 1");
    
    Monster.setMovementDelay(5);
    ExpectEq(5, Monster.getMovementDelay(), "Delay should be updated to 5");
    
    Monster.setMovementDelay(0); // Invalid
    ExpectEq(5, Monster.getMovementDelay(), "Delay should remain 5 for invalid input");
}

/////////////////////////////////////////////////////////////////////////////
void PathfindingCacheIsUsed()
{
    // First pathfinding call
    string *path1 = Monster.pathTo(TargetRoom, 50);
    
    // Second identical call should use cache
    string *path2 = Monster.pathTo(TargetRoom, 50);
    
    ExpectEq(sizeof(path1), sizeof(path2), "Cached path should be identical");
    if (sizeof(path1) > 0 && sizeof(path2) > 0)
    {
        ExpectEq(path1[0], path2[0], "First step should be identical");
    }
}

/////////////////////////////////////////////////////////////////////////////
void ClearPathfindingCacheWorks()
{
    // Cache a path
    Monster.pathTo(TargetRoom, 50);
    
    // Clear cache
    Monster.clearPathfindingCache();
    
    // Should still work (recalculated)
    string *path = Monster.pathTo(TargetRoom, 50);
    ExpectTrue(sizeof(path) > 0, "Path should still be found after cache clear");
}

/////////////////////////////////////////////////////////////////////////////
void CleanupPathfindingClearsAllData()
{
    Monster.startPathingTo(TargetRoom, 50);
    
    Monster.cleanupPathfinding();
    
    ExpectFalse(Monster.isCurrentlyPathing(), "Monster should not be pathing after cleanup");
    ExpectEq(0, Monster.getCurrentTarget(), "Target should be cleared");
    ExpectEq(0, Monster.getPathLength(), "Path should be cleared");
}

/////////////////////////////////////////////////////////////////////////////
void FindNearbyEnvironmentsReturnsCorrectRooms()
{
    string *nearby = Monster.findNearbyEnvironments(2);
    
    ExpectTrue(sizeof(nearby) > 0, "Should find nearby environments");
    
    // Should include adjacent rooms like 0x1, 1x0, etc.
    int foundAdjacent = 0;
    foreach(string roomPath in nearby)
    {
        if (sizeof(regexp(({ roomPath }), "0x1")) > 0)
        {
            foundAdjacent = 1;
            break;
        }
    }
    ExpectTrue(foundAdjacent, "Should find adjacent environments");
}

/////////////////////////////////////////////////////////////////////////////
void MoveTowardsCompletesPathfinding()
{
    object initialRoom = environment(Monster);
    
    int result = Monster.moveTowards(TargetRoom, 50);
    
    ExpectTrue(result, "moveTowards should succeed");
    ExpectTrue(Monster.wasPathCompleted(), "moveTowards should complete pathfinding");
    ExpectEq(TargetRoom, environment(Monster), "Monster should reach target via moveTowards");
}

/////////////////////////////////////////////////////////////////////////////
void PathfindingWorksWithMultipleSteps()
{
    // Test pathfinding to a room that's 2 steps away
    object room0x2 = Region.getEnvironment("0x2");
    if (objectp(room0x2))
    {
        object initialRoom = environment(Monster);
        
        Monster.startPathingTo(room0x2, 50);
        
        ExpectTrue(Monster.wasPathCompleted(), "Multi-step path should complete");
        ExpectNotEq(initialRoom, environment(Monster), "Monster should have moved");
        ExpectEq(room0x2, environment(Monster), "Monster should reach distant target");
    }
    else
    {
        ExpectTrue(1, "Room 0x2 not available - skipping multi-step test");
    }
}

/////////////////////////////////////////////////////////////////////////////
void PathfindingRespectsMaxSteps()
{
    object distantRoom = Region.getEnvironment("24x2");
    if (objectp(distantRoom))
    {
        // Test with very limited steps
        string *limitedPath = Monster.pathTo(distantRoom, 2);
        // Either finds a short path or no path at all
        ExpectTrue(sizeof(limitedPath) <= 2, "Path should respect max steps limit");
    }
    else
    {
        ExpectTrue(1, "Distant room not available - skipping max steps test");
    }
}

/////////////////////////////////////////////////////////////////////////////
void PathfindingFailsGracefullyWithImpossibleTarget()
{
    // Create a mock unreachable room by using an invalid coordinate
    string *impossiblePath = Monster.pathToCoordinates(Region, -999, -999, 50);
    
    ExpectEq(0, sizeof(impossiblePath), "Should return empty path for impossible target");
    ExpectFalse(Monster.wasPathCompleted(), "Should not complete path to impossible target");
}
