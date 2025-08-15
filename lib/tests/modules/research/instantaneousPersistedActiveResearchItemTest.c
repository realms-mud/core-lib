//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object ResearchItem;
object User;
object Target;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchItem = 
        clone_object("/lib/tests/support/research/testInstantaneousPersistedActiveResearchItem");
    ResearchItem.testAddSpecification("command template", "zap ##Target##");
    ResearchItem.testAddSpecification("scope", "targeted");
    ResearchItem.testAddSpecification("damage type", "magical");

    User = clone_object("/lib/tests/support/services/combatWithMockServices");
    User.Name("Bob");
    User.addAlias("bob");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.hitPoints(User.maxHitPoints());
    User.spellPoints(User.maxSpellPoints());
    User.staminaPoints(User.maxStaminaPoints());
    User.addSkillPoints(200);
    User.advanceSkill("long sword", 5);
    User.toggleKillList();
    User.ToggleMockResearch();

    Target = clone_object("/lib/realizations/monster");
    Target.Name("Frank");
    Target.addAlias("frank");
    Target.Str(20);
    Target.Int(20);
    Target.Dex(20);
    Target.Con(20);
    Target.Wis(20);
    Target.Chr(20);
    Target.hitPoints(50);
    Target.spellPoints(50);
    Target.staminaPoints(50);
    Target.addSkillPoints(200);
    Target.advanceSkill("long sword", 10);

    Room = clone_object("/lib/environment/environment");
    move_object(User, Room);
    move_object(Target, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Target);
    destruct(User);
    destruct(ResearchItem);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationAllowsInstantaneousAndPersisted()
{
    // Instantaneous
    mapping* damage = ({
        (["probability":100, "base damage" : 10, "range" : 0])
        });
    ExpectTrue(ResearchItem.testAddSpecification("damage hit points", damage));
    ExpectTrue(ResearchItem.testAddSpecification("damage type", "physical"));

    // Persisted
    ExpectTrue(ResearchItem.testAddSpecification("apply slow", 1));
    ExpectTrue(ResearchItem.testAddSpecification("duration", 10));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesBothInstantaneousAndPersistedEffects()
{
    mapping* damage = ({
        (["probability":100, "base damage" : 14, "range" : 0])
        });
    ResearchItem.testAddSpecification("damage hit points", damage);
    ResearchItem.testAddSpecification("damage type", "physical");
    ResearchItem.testAddSpecification("apply slow", 1);
    ResearchItem.testAddSpecification("duration", 10);

    int initialHP = Target.hitPoints();
    ExpectTrue(ResearchItem.execute("zap frank", User), "can execute command");

    // Instantaneous effect: damage
    ExpectEq(initialHP - 10, Target.hitPoints(), "target took damage");

    // Persisted effect: slow
    object modifier = Target.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName());
    ExpectTrue(modifier, "Modifier with FQN is registered");
    ExpectTrue(Target.inventoryGetModifier("combatModifiers", "slow"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnSelfAppliesBothInstantaneousAndPersistedEffects()
{
    mapping* heal = ({
        (["probability":100, "base damage" : 10, "range" : 0])
        });
    ResearchItem.testAddSpecification("increase hit points", heal);
    ResearchItem.testAddSpecification("apply haste", 1);
    ResearchItem.testAddSpecification("duration", 10);

    int before = User.hitPoints();
    ExpectEq(150, User.hitPoints(), "user healed");

    ExpectTrue(ResearchItem.execute("zap bob", User), "can execute command");

    // Instantaneous effect: heal
    ExpectEq(before + 10, User.hitPoints(), "user healed");

    // Persisted effect: haste
    object modifier = User.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName());
    ExpectTrue(modifier, "Modifier with FQN is registered");
    ExpectTrue(User.inventoryGetModifier("combatModifiers", "haste"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteInAreaAppliesBothInstantaneousAndPersistedEffectsToProperLiving()
{
    object bystander = clone_object("/lib/tests/support/services/combatWithMockServices");
    bystander.Name("Earl");
    bystander.addAlias("earl");
    bystander.Str(20);
    bystander.addSkillPoints(200);
    bystander.advanceSkill("long sword", 10);
    move_object(bystander, Room);

    object badguy = clone_object("/lib/realizations/monster");
    badguy.Name("Fred");
    badguy.addAlias("fred");
    badguy.Str(20);
    badguy.Int(20);
    badguy.Dex(20);
    badguy.Con(20);
    badguy.Wis(20);
    badguy.Chr(20);
    badguy.addSkillPoints(200);
    badguy.advanceSkill("long sword", 10);
    badguy.hitPoints(badguy.maxHitPoints());
    move_object(badguy, Room);

    mapping* damage = ({
        (["probability":100, "base damage" : 9, "range" : 0])
        });
    ResearchItem.testAddSpecification("damage hit points", damage);
    ResearchItem.testAddSpecification("damage type", "physical");
    ResearchItem.testAddSpecification("apply enfeebled", 1);
    ResearchItem.testAddSpecification("duration", 10);
    ResearchItem.testAddSpecification("scope", "area");
    ResearchItem.testAddSpecification("command template", "zap");

    int initialHP = Target.hitPoints();
    int badguyHP = badguy.hitPoints();
    int bystanderHP = bystander.hitPoints();

    ExpectTrue(ResearchItem.execute("zap", User), "can execute command");

    ExpectEq(initialHP - 5, Target.hitPoints(), "target took area damage");
    ExpectEq(badguyHP - 5, badguy.hitPoints(), "badguy took area damage");
    ExpectEq(bystanderHP, bystander.hitPoints(), "bystander took area damage");

    // Both should have enfeebled
    object targetModifier = 
        Target.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName());
    object bystanderModifier = 
        bystander.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName());
    object badGuyModifier = 
        badguy.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName());

    ExpectTrue(targetModifier, "Target modifier registered");
    ExpectTrue(badGuyModifier, "Bad guy modifier registered");
    ExpectFalse(bystanderModifier, "Bystander modifier registered");

    ExpectTrue(Target.inventoryGetModifier("combatModifiers", "enfeebled"));
    ExpectTrue(badguy.inventoryGetModifier("combatModifiers", "enfeebled"));
    ExpectFalse(bystander.inventoryGetModifier("combatModifiers", "enfeebled"));
}

/////////////////////////////////////////////////////////////////////////////
void NegativeExecuteInAreaAppliedOnCorrectTargets()
{
    object bystander = clone_object("/lib/tests/support/services/combatWithMockServices");
    bystander.Name("Earl");
    bystander.addAlias("earl");
    bystander.Str(20);
    bystander.addSkillPoints(200);
    bystander.advanceSkill("long sword", 10);
    move_object(bystander, Room);

    object badguy = clone_object("/lib/realizations/monster");
    badguy.Name("Fred");
    badguy.addAlias("fred");
    badguy.Str(20);
    badguy.addSkillPoints(200);
    badguy.advanceSkill("long sword", 10);
    move_object(badguy, Room);

    ExpectTrue(ResearchItem.testAddSpecification("penalty to long sword", 5));
    ExpectTrue(ResearchItem.testAddSpecification("duration", 10));
    ResearchItem.testAddSpecification("scope", "area");
    ResearchItem.testAddSpecification("command template", "zap");

    ExpectEq(7, User.getSkill("long sword"), "initial user long sword skill");
    ExpectEq(10, Target.getSkill("long sword"), "initial target long sword skill");
    ExpectEq(10, bystander.getSkill("long sword"), "initial bystander long sword skill");
    ExpectEq(10, badguy.getSkill("long sword"), "initial badguy long sword skill");
    ExpectTrue(ResearchItem.execute("zap", User), "can execute command");

    ExpectFalse(User.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName()));
    ExpectTrue(Target.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName()));
    ExpectTrue(badguy.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName()));
    ExpectFalse(bystander.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName()));
    ExpectEq(7, User.getSkill("long sword"), "user long sword skill after research used");
    ExpectEq(5, Target.getSkill("long sword"), "target long sword skill after research used");
    ExpectEq(10, bystander.getSkill("long sword"), "bystander long sword skill after research used");
    ExpectEq(5, badguy.getSkill("long sword"), "badguy long sword skill after research used");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteInAreaAppliedOnCorrectTargets()
{
    object bystander = clone_object("/lib/tests/support/services/combatWithMockServices");
    bystander.Name("Earl");
    bystander.addAlias("earl");
    bystander.Str(20);
    bystander.addSkillPoints(200);
    bystander.advanceSkill("long sword", 10);
    move_object(bystander, Room);

    object badguy = clone_object("/lib/realizations/monster");
    badguy.Name("Fred");
    badguy.addAlias("fred");
    badguy.Str(20);
    badguy.addSkillPoints(200);
    badguy.advanceSkill("long sword", 10);
    move_object(badguy, Room);

    ExpectTrue(ResearchItem.testAddSpecification("bonus long sword", 5));
    ExpectTrue(ResearchItem.testAddSpecification("duration", 10));
    ResearchItem.testAddSpecification("scope", "area");
    ResearchItem.testAddSpecification("command template", "zap");

    ExpectEq(7, User.getSkill("long sword"), "initial user long sword skill");
    ExpectEq(10, Target.getSkill("long sword"), "initial target long sword skill");
    ExpectEq(10, bystander.getSkill("long sword"), "initial bystander long sword skill");
    ExpectEq(10, badguy.getSkill("long sword"), "initial badguy long sword skill");
    ExpectTrue(ResearchItem.execute("zap", User), "can execute command");

    ExpectTrue(User.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName()));
    ExpectFalse(Target.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName()));
    ExpectFalse(badguy.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName()));
    ExpectTrue(bystander.registeredInventoryObject(program_name(ResearchItem) + "#" + User.RealName()));
    ExpectEq(12, User.getSkill("long sword"), "user long sword skill after research used");
    ExpectEq(10, Target.getSkill("long sword"), "target long sword skill after research used");
    ExpectEq(15, bystander.getSkill("long sword"), "bystander long sword skill after research used");
    ExpectEq(10, badguy.getSkill("long sword"), "badguy long sword skill after research used");
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationThrowsForInvalidInstantaneous()
{
    string err = catch (ResearchItem.testAddSpecification("damage hit points", "not a formula"); nolog);
    string expectedError = "*ERROR - instantaneousEffect: the 'damage hit points' specification must be a properly formatted formula.\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationThrowsForInvalidPersisted()
{
    string err = catch (ResearchItem.testAddSpecification("apply blarg", 10); nolog);
    string expectedError = "*ERROR - instantaneousPersistedActiveResearchItem: the 'apply blarg' specification must be a valid modifier as defined in /lib/services/bonusesService.c\n";
    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid value");
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationAllowsTraitToBeApplied()
{
    ExpectTrue(ResearchItem.testAddSpecification("trait", "/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AddSpecificationAllowsNegativeTraitToBeApplied()
{
    ExpectTrue(ResearchItem.testAddSpecification("negative trait", "/lib/tests/support/traits/testTraitWithDuration.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesTrait()
{
    mapping *heal = ({
        (["probability":100, "base damage" : 10, "range" : 0])
    });

    ResearchItem.testAddSpecification("increase hit points", heal);
    ResearchItem.testAddSpecification("trait", "/lib/tests/support/traits/testTraitWithDuration.c");

    ExpectTrue(ResearchItem.execute("zap frank", User), "can execute command");
    ExpectTrue(Target.isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"), "trait set on Frank");
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteOnTargetAppliesNegativeTrait()
{
    mapping *damage = ({
        (["probability":100, "base damage" : 10, "range" : 0])
    });
    ResearchItem.testAddSpecification("negative trait", "/lib/tests/support/traits/testTraitWithDuration.c");
    ResearchItem.testAddSpecification("damage hit points", damage);
    ResearchItem.testAddSpecification("damage type", "physical");

    Target.toggleKillList();
    User.toggleKillList();
    ExpectTrue(ResearchItem.execute("zap frank", User), "can execute command");
    ExpectTrue(Target.isTraitOf("/lib/tests/support/traits/testTraitWithDuration.c"));
}
