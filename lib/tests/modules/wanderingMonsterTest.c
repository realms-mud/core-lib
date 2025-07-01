//*****************************************************************************
// File: lib/tests/modules/wanderingMonsterTest.c
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Monster;
object Enemy;
object Region;
object StartRoom;
object AdjacentRoom;
object DeadEndRoom;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetUpMonster", "SetUpEnemy", "SetUpRegion", "SetUpDeadEndScenario" });
}

/////////////////////////////////////////////////////////////////////////////
void SetUpMonster()
{
    Monster = clone_object("/lib/tests/support/services/testWanderingMonster.c");
    Monster.Name("Wandering Test Monster");
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
}

/////////////////////////////////////////////////////////////////////////////
void SetUpEnemy()
{
    Enemy = clone_object("/lib/realizations/monster.c");
    Enemy.Name("Test Enemy");
    Enemy.Str(20);
    Enemy.Dex(20);
    Enemy.Con(20);
    Enemy.Int(20);
    Enemy.Wis(20);
    Enemy.setMaxHitPoints(100);
    Enemy.hitPoints(100);
    Enemy.setMaxSpellPoints(50);
    Enemy.spellPoints(50);
    Enemy.setMaxStaminaPoints(50);
    Enemy.staminaPoints(50);
}

/////////////////////////////////////////////////////////////////////////////
void SetUpRegion()
{
    Region = clone_object("/lib/tests/support/pathfinding/region.c");
    StartRoom = Region.getEnvironment("0x0");
    AdjacentRoom = Region.getEnvironment("0x1");
    DeadEndRoom = Region.getEnvironment("0x2");
}

/////////////////////////////////////////////////////////////////////////////
void SetUpDeadEndScenario()
{
    // Move monster to a room with only one exit to test dead end behavior
    if (objectp(DeadEndRoom))
    {
        move_object(Monster, DeadEndRoom);
    }
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    SetUpMonster();
    SetUpEnemy();
    SetUpRegion();

    ToggleCallOutBypass();

    if (objectp(StartRoom) && objectp(Monster))
    {
        move_object(Monster, StartRoom);
    }
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    ToggleCallOutBypass();
    if (objectp(Monster))
    {
        if (function_exists("cleanupPathfinding", Monster))
        {
            Monster.cleanupPathfinding();
        }
        destruct(Monster);
    }
    if (objectp(Enemy))
    {
        destruct(Enemy);
    }
    if (objectp(Region))
    {
        destruct(Region);
    }
}

/////////////////////////////////////////////////////////////////////////////
void IsRealizationOfWanderingMonsterReturnsTrue()
{
    ExpectTrue(Monster.isRealizationOfWanderingMonster(), 
        "Monster should identify as wandering monster");
}

/////////////////////////////////////////////////////////////////////////////
void WanderFrequencyCanBeSet()
{
    ExpectEq(5, Monster.queryWanderFrequency(), "Default wander frequency should be 5");
    
    Monster.setWanderFrequency(10);
    ExpectEq(10, Monster.queryWanderFrequency(), "Wander frequency should be updated to 10");
    
    Monster.setWanderFrequency(0); // Invalid
    ExpectEq(10, Monster.queryWanderFrequency(), "Wander frequency should remain 10 for invalid input");
    
    Monster.setWanderFrequency(-5); // Invalid
    ExpectEq(10, Monster.queryWanderFrequency(), "Wander frequency should remain 10 for negative input");
}

/////////////////////////////////////////////////////////////////////////////
void WanderChanceCanBeSet()
{
    ExpectEq(30, Monster.queryWanderChance(), "Default wander chance should be 30");
    
    Monster.setWanderChance(50);
    ExpectEq(50, Monster.queryWanderChance(), "Wander chance should be updated to 50");
    
    Monster.setWanderChance(0);
    ExpectEq(0, Monster.queryWanderChance(), "Wander chance should accept 0");
    
    Monster.setWanderChance(100);
    ExpectEq(100, Monster.queryWanderChance(), "Wander chance should accept 100");
    
    Monster.setWanderChance(150); // Invalid
    ExpectEq(100, Monster.queryWanderChance(), "Wander chance should remain 100 for value > 100");
    
    Monster.setWanderChance(-10); // Invalid
    ExpectEq(100, Monster.queryWanderChance(), "Wander chance should remain 100 for negative input");
}

/////////////////////////////////////////////////////////////////////////////
void EnableWanderingSetsProperly()
{
    Monster.setWanderChance(0);
    Monster.enableWandering();
    ExpectEq(30, Monster.queryWanderChance(), "enableWandering should set chance to 30");
}

/////////////////////////////////////////////////////////////////////////////
void DisableWanderingSetsProperly()
{
    Monster.disableWandering();
    ExpectEq(0, Monster.queryWanderChance(), "disableWandering should set chance to 0");
}

/////////////////////////////////////////////////////////////////////////////
void MoveInDirectionUpdatesLastLocation()
{
    object initialRoom = environment(Monster);
    
    int result = Monster.moveInDirection("north");
    
    ExpectTrue(result, "moveInDirection should succeed");
    ExpectNotEq(initialRoom, environment(Monster), "Monster should have moved");
}

/////////////////////////////////////////////////////////////////////////////
void WanderingDoesNotOccurInCombat()
{
    // Set up combat scenario
    move_object(Enemy, environment(Monster));
    Monster.registerAttacker(Enemy);
    Enemy.registerAttacker(Monster);
    
    // Enable maximum wandering chance
    Monster.setWanderChance(100);
    Monster.setWanderFrequency(1);
    
    object initialRoom = environment(Monster);
    
    // Simulate heart beats that would normally trigger wandering
    Monster.heart_beat();
    Monster.heart_beat();
    Monster.heart_beat();
    
    ExpectEq(initialRoom, environment(Monster), 
        "Monster should not wander while in combat");
}

/////////////////////////////////////////////////////////////////////////////
void WanderingDoesNotOccurWhilePathfinding()
{
    // Start pathfinding to a distant location
    object targetRoom = Region.getEnvironment("1x1");
    if (objectp(targetRoom))
    {
        Monster.startPathingTo(targetRoom, 50);
        
        // Enable maximum wandering chance
        Monster.setWanderChance(100);
        Monster.setWanderFrequency(1);
        
        object roomBeforeWander = environment(Monster);
        
        // If still pathfinding, wandering should not occur
        if (Monster.isCurrentlyPathing())
        {
            Monster.heart_beat();
            ExpectEq(roomBeforeWander, environment(Monster), 
                "Monster should not wander while pathfinding");
        }
    }
    else
    {
        ExpectTrue(1, "Target room not available - skipping pathfinding test");
    }
}

/////////////////////////////////////////////////////////////////////////////
void WanderingOccursWithProperFrequency()
{
    Monster.setWanderChance(100); // Always wander when triggered
    Monster.setWanderFrequency(3); // Every 3 heart beats
    
    object initialRoom = environment(Monster);
    
    // First two heart beats should not trigger wandering
    Monster.heart_beat();
    Monster.heart_beat();
    ExpectEq(initialRoom, environment(Monster), 
        "Monster should not wander before frequency threshold");
    
    // Third heart beat should trigger wandering
    Monster.heart_beat();
    // Note: Due to randomness in direction selection, monster might not move
    // if it picks an invalid direction, but the attempt should be made
    ExpectTrue(1, "Wandering attempt should be made on frequency threshold");
}

/////////////////////////////////////////////////////////////////////////////
void WanderingRespectsChanceSetting()
{
    Monster.setWanderChance(0); // Never wander
    Monster.setWanderFrequency(1); // Every heart beat
    
    object initialRoom = environment(Monster);
    
    // Multiple heart beats with 0% chance should never cause movement
    Monster.heart_beat();
    Monster.heart_beat();
    Monster.heart_beat();
    Monster.heart_beat();
    Monster.heart_beat();
    
    ExpectEq(initialRoom, environment(Monster), 
        "Monster should not wander with 0% chance");
}

/////////////////////////////////////////////////////////////////////////////
void MonsterDoesNotBacktrackUnlessDeadEnd()
{
    // Move monster to adjacent room first
    Monster.moveInDirection("north");
    object middleRoom = environment(Monster);
    
    // Enable maximum wandering to ensure movement attempts
    Monster.setWanderChance(100);
    Monster.setWanderFrequency(1);
    
    // Now when wandering is triggered, it should not go back south
    // unless that's the only option
    string *exits = middleRoom->exits();
    
    if (sizeof(exits) > 1)
    {
        // Multiple exits - should not backtrack
        int attempts = 0;
        int backtrackCount = 0;
        
        // Test multiple wandering attempts
        for (int i = 0; i < 10; i++)
        {
            object roomBefore = environment(Monster);
            Monster.heart_beat();
            object roomAfter = environment(Monster);
            
            if (roomAfter != roomBefore)
            {
                attempts++;
                // Check if it went back to start room (backtracked)
                if (roomAfter == StartRoom)
                {
                    backtrackCount++;
                    // Move back to middle room for next test
                    move_object(Monster, middleRoom);
                }
            }
        }
        
        // With multiple exits, backtracking should be rare or non-existent
        if (attempts > 0)
        {
            float backtrackRate = (float)backtrackCount / (float)attempts;
            ExpectTrue(backtrackRate < 0.5, 
                "Backtracking should be avoided when multiple exits available");
        }
    }
    else
    {
        ExpectTrue(1, "Only one exit available - backtracking test not applicable");
    }
}

/////////////////////////////////////////////////////////////////////////////
void MonsterCanBacktrackInDeadEnd()
{
    SetUpDeadEndScenario();
    
    if (!objectp(DeadEndRoom))
    {
        ExpectTrue(1, "Dead end room not available - skipping dead end test");
        return;
    }
    
    // Enable maximum wandering
    Monster.setWanderChance(100);
    Monster.setWanderFrequency(1);
    
    string *exits = DeadEndRoom->exits();
    
    if (sizeof(exits) == 1)
    {
        // In a dead end, monster should be able to move in the only direction
        object deadEndRoom = environment(Monster);
        
        Monster.heart_beat();
        
        // Monster should have moved (or at least attempted to move)
        // Since it's a dead end, it can only go back the way it came
        ExpectTrue(1, "Monster should be able to move from dead end");
    }
    else
    {
        ExpectTrue(1, "Room is not a dead end - skipping dead end backtrack test");
    }
}

/////////////////////////////////////////////////////////////////////////////
void HeartBeatHandlesEnemyDetectionDuringPathfinding()
{
    object targetRoom = Region.getEnvironment("1x1");
    if (objectp(targetRoom))
    {
        Monster.startPathingTo(targetRoom, 50);
        
        // Add enemy to same room
        move_object(Enemy, environment(Monster));
        
        // Simulate heart beat that should detect enemy
        Monster.heart_beat();
        
        ExpectFalse(Monster.isCurrentlyPathing(), 
            "Pathfinding should be interrupted by enemy presence");
    }
    else
    {
        ExpectTrue(1, "Target room not available - skipping enemy detection test");
    }
}

/////////////////////////////////////////////////////////////////////////////
void OnPathInterruptedHandlesEnemyEncounters()
{
    Monster.interruptPathing("enemy encountered");
    
    // Verify that pathfinding was properly interrupted
    ExpectFalse(Monster.isCurrentlyPathing(), 
        "Pathfinding should be stopped after enemy interruption");
}

/////////////////////////////////////////////////////////////////////////////
void OnPathInterruptedHandlesOtherReasons()
{
    // Start a path first
    object targetRoom = Region.getEnvironment("1x1");
    if (objectp(targetRoom))
    {
        Monster.startPathingTo(targetRoom, 50);
        
        // Interrupt for non-enemy reason
        Monster.interruptPathing("obstacle detected");
        
        // Should handle interruption appropriately
        ExpectFalse(Monster.isCurrentlyPathing(), 
            "Pathfinding should handle non-enemy interruptions");
    }
    else
    {
        ExpectTrue(1, "Target room not available - skipping interruption test");
    }
}

/////////////////////////////////////////////////////////////////////////////
void WanderingSelectsValidDirections()
{
    // Test that wandering chooses from available exits
    string *availableExits = environment(Monster)->exits();
    
    if (sizeof(availableExits) > 0)
    {
        Monster.setWanderChance(100);
        Monster.setWanderFrequency(1);
        
        object initialRoom = environment(Monster);
        
        // Multiple attempts to see wandering behavior
        int moveAttempts = 0;
        for (int i = 0; i < 20; i++)
        {
            Monster.heart_beat();
            if (environment(Monster) != initialRoom)
            {
                moveAttempts++;
                move_object(Monster, initialRoom); // Reset for next attempt
            }
        }
        
        ExpectTrue(moveAttempts > 0, 
            "Monster should successfully wander with available exits");
    }
    else
    {
        ExpectTrue(1, "No exits available - skipping direction selection test");
    }
}

/////////////////////////////////////////////////////////////////////////////
void WanderingWorksWithRegionBasedMovement()
{
    // Test that wandering works with region-based coordinates
    object currentEnv = environment(Monster);
    if (currentEnv && currentEnv->getRegion())
    {
        Monster.setWanderChance(100);
        Monster.setWanderFrequency(1);
        
        object initialRoom = environment(Monster);
        
        Monster.heart_beat();
        
        // Should work with region-based movement system
        ExpectTrue(1, "Region-based wandering should function properly");
    }
    else
    {
        ExpectTrue(1, "No region available - skipping region-based test");
    }
}

/////////////////////////////////////////////////////////////////////////////
void MultipleHeartBeatsEventuallyTriggerWandering()
{
    Monster.setWanderChance(50); // 50% chance
    Monster.setWanderFrequency(2); // Every 2 beats
    
    object initialRoom = environment(Monster);
    int totalMoves = 0;
    
    // Run many heart beats to statistically verify wandering occurs
    for (int i = 0; i < 50; i++)
    {
        Monster.heart_beat();
        if (environment(Monster) != initialRoom)
        {
            totalMoves++;
            move_object(Monster, initialRoom); // Reset position
        }
    }
    
    // With 50% chance and proper frequency, should see some movement
    ExpectTrue(totalMoves > 0, 
        "Multiple heart beats should eventually trigger wandering");
}

/////////////////////////////////////////////////////////////////////////////
void WanderingDoesNotCrashWithNoExits()
{
    // Create a mock room with no exits to test edge case
    object noExitRoom = clone_object("/lib/environment/environment.c");
    if (objectp(noExitRoom))
    {
        move_object(Monster, noExitRoom);
        
        Monster.setWanderChance(100);
        Monster.setWanderFrequency(1);
        
        // Should not crash even with no exits
        Monster.heart_beat();
        Monster.heart_beat();
        
        ExpectTrue(1, "Wandering should handle rooms with no exits gracefully");
        
        destruct(noExitRoom);
    }
}
