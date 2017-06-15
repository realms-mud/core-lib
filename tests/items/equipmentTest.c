//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

#include "/lib/include/inventory.h"

object Equipment;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Equipment = clone_object("/lib/items/equipment"); 
   
    object dictionary = load_object("/lib/dictionaries/guildsDictionary.c");
    object mageGuild = load_object("/lib/tests/support/guilds/mageGuild.c");
    mageGuild->init();

    object fighterGuild = load_object("/lib/tests/support/guilds/fighterGuild.c");
    fighterGuild->init();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Equipment);
}

/////////////////////////////////////////////////////////////////////////////
void ItemPropertiesCanBeSet()
{
    // Only test a few of these - the full set is tested in items/itemTest
    ExpectTrue(Equipment->set("bonus armor class", 5), "bonus armor class can be set");
    ExpectEq(5, Equipment->query("bonus armor class"), "bonus armor class query returns correctly");

    ExpectTrue(Equipment->set("value", 850), "value can be set");
    ExpectEq(850, Equipment->query("value"), "850 value was returned");

    ExpectTrue(Equipment->set("no sell", 1), "no sell can be set");
    ExpectEq(1, Equipment->query("no sell"), "1 no sell was returned");

    ExpectTrue(Equipment->set("name", "blah"), "name can be set");
    ExpectEq("blah", Equipment->query("name"), "'blah' name was returned");
}

/////////////////////////////////////////////////////////////////////////////
void ArmorClassCannotBeSet()
{
    string expected = "*Equipment: It is illegal to set the 'armor class' element for this type of object.\n";

    string err = catch (Equipment->set("armor class", 10));
    ExpectEq(expected, err, "armor class cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void DefenseClassCannotBeSet()
{
    string expected = "*Equipment: It is illegal to set the 'defense class' element for this type of object.\n";

    string err = catch (Equipment->set("defense class", 10));
    ExpectEq(expected, err, "defense class cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponClassCannotBeSet()
{
    string expected = "*Equipment: It is illegal to set the 'weapon class' element for this type of object.\n";

    string err = catch (Equipment->set("weapon class", 10));
    ExpectEq(expected, err, "weapon class cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void HitMethodCannotBeSet()
{
    string expected = "*Equipment: It is illegal to set the 'hit method' element for this type of object.\n";

    string err = catch (Equipment->set("hit method", "blah"));
    ExpectEq(expected, err, "hit method cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void ArmorTypeCannotBeSet()
{
    string expected = "*Equipment: It is illegal to set the 'armor type' element for this type of object.\n";

    string err = catch (Equipment->set("armor type", "blah"));
    ExpectEq(expected, err, "armor type cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponTypeCannotBeSet()
{
    string expected = "*Equipment: It is illegal to set the 'weapon type' element for this type of object.\n";

    string err = catch (Equipment->set("weapon type", "blah"));
    ExpectEq(expected, err, "weapon type cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void OffhandCannotBeSet()
{
    string expected = "*Equipment: It is illegal to set the 'offhand' element for this type of object.\n";

    string err = catch (Equipment->set("offhand", "blah"));
    ExpectEq(expected, err, "offhand cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetEquipMessageOnItems()
{
    ExpectTrue(Equipment->set("equip message", "blah"), "equip message can be set");
    ExpectEq("blah", Equipment->query("equip message"), "'blah' equip message was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidEquipMessageThrowsError()
{
    string expected = "*Equipment: The passed 'equip message' data must be a string.\n";

    string err = catch (Equipment->set("equip message", 1));
    ExpectEq(expected, err, "equip message cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetEquipMethodOnItems()
{
    ExpectTrue(Equipment->set("equip method", "query"), "equip method can be set");
    ExpectEq("query", Equipment->query("equip method"), "'query' equip method was returned");
}

/////////////////////////////////////////////////////////////////////////////
void EquipMethodMustExistOnObjectToBeSet()
{
    string expected = "*Equipment: The passed 'blah' equip method must be a function that exists in this item.\n";

    string err = catch (Equipment->set("equip method", "blah"));
    ExpectEq(expected, err, "equip method must exist on the item");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetUnequipMessageOnItems()
{
    ExpectTrue(Equipment->set("unequip message", "blah"), "unequip message can be set");
    ExpectEq("blah", Equipment->query("unequip message"), "'blah' unequip message was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidUnequipMessageThrowsError()
{
    string expected = "*Equipment: The passed 'unequip message' data must be a string.\n";

    string err = catch (Equipment->set("unequip message", 1));
    ExpectEq(expected, err, "unequip message cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentLocationsCanBeSet()
{
    ExpectTrue(Equipment->set("equipment locations", TwohandedWeapon), "equipment locations can be set");
    ExpectEq(TwohandedWeapon, Equipment->query("equipment locations"), "'TwohandedWeapon' equipment location was returned");
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentLocationsMustBeAnInteger()
{
    string expected = "*Equipment: The passed 'equipment locations' data must be an integer.\n";

    string err = catch (Equipment->set("equipment locations", "blah"));
    ExpectEq(expected, err, "equipment locations cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetUnequipMethodOnItems()
{
    ExpectTrue(Equipment->set("unequip method", "query"), "unequip method can be set");
    ExpectEq("query", Equipment->query("unequip method"), "'query' unequip method was returned");
}

/////////////////////////////////////////////////////////////////////////////
void UnequipMethodMustExistOnObjectToBeSet()
{
    string expected = "*Equipment: The passed 'blah' unequip method must be a function that exists in this item.\n";

    string err = catch (Equipment->set("unequip method", "blah"));
    ExpectEq(expected, err, "unequip method must exist on the item");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLevelPrerequisite()
{
    ExpectTrue(Equipment->set("prerequisites", (["level": 10 ])), "level prerequisites can be set");
    ExpectEq(10, Equipment->query("prerequisites")["level"], "'10' level prerequisites returned");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetRacePrerequisite()
{
    ExpectTrue(Equipment->set("prerequisites", (["race":"elf"])), "race prerequisites can be set");
    ExpectEq("elf", Equipment->query("prerequisites")["race"], "'elf' race prerequisites returned");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetInvalidRacePrerequisite()
{
    string expected = "*Equipment: The passed 'prerequisites' mapping is invalid.\n";

    string err = catch (Equipment->set("prerequisites", (["race":"turnip"])));
    ExpectEq(expected, err, "race prerequisites must be valid");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetSkillsPrerequisite()
{
    ExpectTrue(Equipment->set("prerequisites", (["skills": (["long sword":5, "dodge":6 ]) ])), "skills prerequisites can be set");
    ExpectTrue(member(Equipment->query("prerequisites")["skills"], "long sword"), "'long sword' skills prerequisites returned");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetInvalidSkillsPrerequisite()
{
    string expected = "*Equipment: The 'skills' element must be a string as defined in the keys of the skills mapping in /lib/dictionaries/skillsDictionary.c.\n";

    string err = catch (Equipment->set("prerequisites", (["skills":(["basket weaving":5]) ]) ));
    ExpectEq(expected, err, "skills prerequisites must be valid");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetGuildPrerequisite()
{
    mapping guilds = (["guilds":([
            "allowed" : ({ "fighter" }),
            "message": "blarg"
        ])
    ]);

    ExpectTrue(Equipment->set("prerequisites", guilds), "guild prerequisites can be set");
    ExpectTrue(member(Equipment->query("prerequisites")["guilds"], "allowed"), "guild prerequisites returned");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetInvalidGuildPrerequisite()
{
    string expected = "*Equipment: The passed 'guilds' mapping contains an invalid guild.\n";
    mapping guilds = (["guilds":([
            "allowed":({ "weasel" }),
            "message" : "blarg"
        ])
    ]);

    string err = catch (Equipment->set("prerequisites", guilds));
    ExpectEq(expected, err, "guilds prerequisites must be valid");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetGuildPrerequisiteWithBothAllowedAndProhibited()
{
    string expected = "*Equipment: The passed 'guilds' data is not properly constructed. It must contain only one of 'prohibited' or 'allowed'.\n";
    mapping guilds = (["guilds":([
            "allowed":({ "mage" }),
            "prohibited":({ "fighter" }),
            "message" : "blarg"
        ])
    ]);

    string err = catch (Equipment->set("prerequisites", guilds));
    ExpectEq(expected, err, "guilds prerequisites must be valid");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetResearchPrerequisite()
{
    mapping research = (["research":([
            "use gelatin": 1
        ])
    ]);

    ExpectTrue(Equipment->set("prerequisites", research), "research prerequisites can be set");
    ExpectTrue(member(Equipment->query("prerequisites")["research"], "use gelatin"), "research prerequisites returned");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetQuestPrerequisite()
{
    mapping quests = (["quests":([
            "placate the squid":1
        ])
    ]);

    ExpectTrue(Equipment->set("prerequisites", quests), "quest prerequisites can be set");
    ExpectTrue(member(Equipment->query("prerequisites")["quests"], "placate the squid"), "quest prerequisites returned");
}

/////////////////////////////////////////////////////////////////////////////
void CursedInformationCanBeSet()
{
    mapping curseInfo = ([
        "equip message": "blah",
        "failed unequip message" : "halb"
    ]);

    ExpectTrue(Equipment->set("cursed", curseInfo), "cursed can be set");
    ExpectEq("blah", Equipment->query("cursed")["equip message"], "cursed contains equip message");
    ExpectEq("halb", Equipment->query("cursed")["failed unequip message"], "cursed contains failed unequip message");
}

/////////////////////////////////////////////////////////////////////////////
void CursedInformationWithoutFailMessageThrowsError()
{
    string expected = "*Equipment: The cursed element must be a mapping containing the 'equip message' and 'failed unequip message' keys.\n";
    mapping curseInfo = ([
        "equip message":"blah",
    ]);

    string err = catch (Equipment->set("cursed", curseInfo));
    ExpectEq(expected, err, "cursed mapping must be valid");
}

/////////////////////////////////////////////////////////////////////////////
void CursedInformationWithoutEquipMessageThrowsError()
{
    string expected = "*Equipment: The cursed element must be a mapping containing the 'equip message' and 'failed unequip message' keys.\n";
    mapping curseInfo = ([
        "failed unequip message":"blah",
    ]);

    string err = catch (Equipment->set("cursed", curseInfo));
    ExpectEq(expected, err, "cursed mapping must be valid");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetBlueprint()
{
    string expected = "*Equipment: The blueprint can only be set from a derived type.\n";

    string err = catch (Equipment->set("blueprint", "long sword"));
    ExpectEq(expected, err, "blueprint cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsTrueIfNoConditionsSet()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    ExpectTrue(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsTrueIfAllConditionsMet()
{
    mapping prereqs = ([
        "quests":([ "/lib/tests/support/quests/mockQuest.c":1 ]),
        "research":([ "/lib/tests/support/research/mockResearch.c":1 ]),
        "guilds" : ([
            "allowed":({ "fighter" }),
            "message" : "blarg"
        ]),
        "skills" : ([ "long sword":5 ]),
        "level" : 1,
        "race" : "elf"
    ]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/combatWithMockServices.c");
    move_object(Equipment, owner);
    owner->ToggleMockGuilds();
    owner->SetGuild("fighter");
    owner->Race("elf");
    owner->Str(10);
    owner->ToggleMockQuests();
    owner->addSkillPoints(100);
    owner->advanceSkill("long sword", 6);
    owner->ToggleMockResearch();
    ExpectTrue(Equipment->canEquip(owner), "canEquip");
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsTrueForCorrectLevelPrerequisite()
{
    mapping prereqs = ([ "level" : 1 ]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    ExpectTrue(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsFalseForLevelPrerequisite()
{
    mapping prereqs = (["level":2]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    ExpectFalse(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsTrueForCorrectRacePrerequisite()
{
    mapping prereqs = (["race":"elf"]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    owner->Race("elf");
    ExpectTrue(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsFalseForRacePrerequisite()
{
    mapping prereqs = (["race":"elf"]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    ExpectFalse(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsTrueForCorrectQuestPrerequisite()
{
    mapping prereqs = ([ "quests":(["/lib/tests/support/quests/mockQuest.c":1]) ]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/combatWithMockServices.c");
    move_object(Equipment, owner);
    owner->ToggleMockQuests();
    ExpectTrue(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsFalseForQuestPrerequisite()
{
    mapping prereqs = (["quests":(["/lib/tests/support/quests/mockQuest.c":1])]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    ExpectFalse(Equipment->canEquip(owner), "cannot equip when quest not started");
    owner->beginQuest("/lib/tests/support/quests/mockQuest.c");
    ExpectFalse(Equipment->canEquip(owner), "cannot equip when quest not completed");
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsTrueIfSkillPrerequisiteMet()
{
    mapping prereqs = ([ "skills" : (["long sword":5]) ]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    owner->Str(10);
    owner->addSkillPoints(100);
    owner->advanceSkill("long sword", 5);

    ExpectTrue(Equipment->canEquip(owner), "canEquip");
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsFalseIfSkillPrerequisiteNotMet()
{
    mapping prereqs = (["skills":(["long sword":5])]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    owner->Str(10);
    ExpectFalse(Equipment->canEquip(owner), "skill not set");
    owner->addSkillPoints(100);
    owner->advanceSkill("long sword", 4);

    ExpectFalse(Equipment->canEquip(owner), "skill too low");
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsTrueIfResearchPrerequisiteMet()
{
    mapping prereqs = ([ "research" : (["/lib/tests/support/research/mockResearch.c":1]) ]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    owner->initiateResearch("/lib/tests/support/research/mockResearch.c");
    ExpectTrue(Equipment->canEquip(owner), "canEquip");
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsTrueIfResearchPrerequisiteNotMet()
{
    mapping prereqs = (["research":(["/lib/tests/support/research/mockResearchTimed.c":1])]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    ExpectFalse(Equipment->canEquip(owner), "research not started");
    owner->initiateResearch("/lib/tests/support/research/mockResearchTimed.c");
    ExpectFalse(Equipment->canEquip(owner), "research not completed");
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsTrueIfInGuild()
{
    mapping prereqs = ([
        "guilds":([
            "allowed":({ "fighter" }),
            "message" : "blarg"
        ]),
    ]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    owner->joinGuild("fighter");

    ExpectTrue(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsFalseIfNotInGuild()
{
    mapping prereqs = ([
        "guilds":([
            "allowed":({ "fighter" }),
            "message" : "blarg"
        ]),
    ]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);

    ExpectFalse(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsFalseIfInProhibitedGuild()
{
    mapping prereqs = ([
        "guilds":([
            "prohibited":({ "fighter" }),
            "message" : "blarg"
        ]),
    ]);
    Equipment->set("prerequisites", prereqs);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    owner->joinGuild("fighter");

    ExpectFalse(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsFalseIfSpellActionSet()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);

    owner->spellAction(1);
    ExpectFalse(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanEquipReturnsFalseIfOwnerSetButNotCorrect()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);
    owner->Name("Fred");

    Equipment->set("owner", "Harold");
    ExpectFalse(Equipment->canEquip(owner));
}

/////////////////////////////////////////////////////////////////////////////
void CanUnequipReturnsTrueByDefault()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);

    ExpectTrue(Equipment->canUnequip());
}

/////////////////////////////////////////////////////////////////////////////
void CanUnequipReturnsFalseIfSpellActionSet()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);

    owner->spellAction(1);
    ExpectFalse(Equipment->canUnequip());
}

/////////////////////////////////////////////////////////////////////////////
void CanUnequipReturnsFalseIfCursed()
{
    mapping curseInfo = ([
        "equip message":"blah",
            "failed unequip message" : "halb"
    ]);

    Equipment->set("cursed", curseInfo);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(Equipment, owner);

    ExpectFalse(Equipment->canUnequip());
}

/////////////////////////////////////////////////////////////////////////////
void EquipReturnsFalseIfItemNotValidId()
{
    // equip must happen on either armor or a weapon and it is blueprint-checked
    destruct(Equipment);
    Equipment = clone_object("/lib/items/armor");

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Equipment, owner);
    Equipment->set("name", "thingy");
    Equipment->set("equipment locations", Cloak);

    ExpectFalse(Equipment->equip("blarg"), "equip");
}

/////////////////////////////////////////////////////////////////////////////
void UnequipReturnsFalseIfItemNotValidId()
{
    // equip must happen on either armor or a weapon and it is blueprint-checked
    destruct(Equipment);
    Equipment = clone_object("/lib/items/armor");

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Equipment, owner);
    Equipment->set("name", "thingy");
    Equipment->set("equipment locations", Cloak);

    ExpectTrue(Equipment->equip("thingy"), "equip");
    ExpectFalse(Equipment->unequip("blarg"), "unequip");
}

/////////////////////////////////////////////////////////////////////////////
void EquipAndUnequipReturnTrueOnSuccess()
{
    // equip must happen on either armor or a weapon and it is blueprint-checked
    destruct(Equipment);
    Equipment = clone_object("/lib/items/armor");

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Equipment, owner);
    Equipment->set("name", "thingy");
    Equipment->set("equipment locations", Cloak);

    ExpectTrue(Equipment->equip("thingy"), "equip");
    ExpectTrue(Equipment->unequip("thingy"), "unequip");

    // Check test output too!
}

/////////////////////////////////////////////////////////////////////////////
void EquipAndUnequipOutputCustomMessages()
{
    // equip must happen on either armor or a weapon and it is blueprint-checked
    destruct(Equipment);
    Equipment = clone_object("/lib/items/armor");

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Equipment, owner);
    Equipment->set("name", "thingy");
    Equipment->set("equipment locations", Cloak);
    Equipment->set("equip message", "custom equip message");
    Equipment->set("unequip message", "custom unequip message");

    ExpectTrue(Equipment->equip("thingy"), "equip");
    ExpectTrue(Equipment->unequip("thingy"), "unequip");

    // Check test output too!
}

/////////////////////////////////////////////////////////////////////////////
void EquipExecutesEquipMethodOnSuccess()
{
    // equip must happen on either armor or a weapon and it is blueprint-checked
    destruct(Equipment);
    Equipment = clone_object("/lib/tests/support/items/mockArmorWithEvents.c");

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Equipment, owner);
    Equipment->set("name", "thingy");
    Equipment->set("equipment locations", Cloak);
    Equipment->set("equip method", "equipMethod");

    string expected = "*event handler: equipMethod called";
    string err = catch (ExpectTrue(Equipment->equip("thingy")));
    ExpectEq(expected, err, "equip method called");
}

/////////////////////////////////////////////////////////////////////////////
void UnequipExecutesUnequipMethodOnSuccess()
{
    // equip must happen on either armor or a weapon and it is blueprint-checked
    destruct(Equipment);
    Equipment = clone_object("/lib/tests/support/items/mockArmorWithEvents.c");

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Equipment, owner);
    Equipment->set("name", "thingy");
    Equipment->set("equipment locations", Cloak);
    Equipment->set("unequip method", "unequipMethod");

    ExpectTrue(Equipment->equip("thingy"));

    string expected = "*event handler: unequipMethod called";
    string err = catch (ExpectTrue(Equipment->unequip("thingy")));
    ExpectEq(expected, err, "unequip method called");
}


/////////////////////////////////////////////////////////////////////////////
void UnequipFailsWhenItemCursed()
{
    // equip must happen on either armor or a weapon and it is blueprint-checked
    destruct(Equipment);
    Equipment = clone_object("/lib/items/armor");

    mapping curseInfo = ([
        "equip message":"you're cursed",
        "failed unequip message" : "nope... can't do that"
    ]);

    Equipment->set("cursed", curseInfo);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Equipment, owner);
    Equipment->set("name", "thingy");
    Equipment->set("equipment locations", Cloak);

    ExpectTrue(Equipment->equip("thingy"), "equip");
    ExpectFalse(Equipment->unequip("thingy"), "unequip");
}

/////////////////////////////////////////////////////////////////////////////
void DropMovesItemOutOfInventory()
{
    // equip must happen on either armor or a weapon and it is blueprint-checked
    destruct(Equipment);
    Equipment = clone_object("/lib/items/armor");

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Equipment, owner);

    object container = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(owner, container);

    Equipment->set("name", "thingy");
    Equipment->set("equipment locations", Cloak);

    ExpectEq(file_name(owner), file_name(environment(Equipment)));
    ExpectTrue(Equipment->equip("thingy"), "equip");
    ExpectFalse(Equipment->drop(), "drop");
    ExpectEq(file_name(container), file_name(environment(Equipment)));
}

/////////////////////////////////////////////////////////////////////////////
void DropDoesNotMoveCursedOutOfInventory()
{
    // equip must happen on either armor or a weapon and it is blueprint-checked
    destruct(Equipment);
    Equipment = clone_object("/lib/items/armor");

    mapping curseInfo = ([
        "equip message":"you're cursed",
        "failed unequip message" : "nope... can't do that"
    ]);

    Equipment->set("cursed", curseInfo);

    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Equipment, owner);

    object container = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    move_object(owner, container);

    Equipment->set("name", "thingy");
    Equipment->set("equipment locations", Cloak);

    ExpectEq(file_name(owner), file_name(environment(Equipment)));
    ExpectTrue(Equipment->equip("thingy"), "equip");
    ExpectTrue(Equipment->drop(), "drop");
    ExpectEq(file_name(owner), file_name(environment(Equipment)));
}


