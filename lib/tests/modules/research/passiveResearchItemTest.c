//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object ResearchItem;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchItem = clone_object("/lib/tests/support/research/testPassiveResearchItem");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(ResearchItem);
}

/////////////////////////////////////////////////////////////////////////////
void TypeIsPassive()
{
    ExpectEq("passive", ResearchItem.query("type"), "query the research type");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidBonusThrowsError()
{
    string err = catch (ResearchItem.addSpecification("bonus llama", 2); nolog);
    string expectedError = "*ERROR - passiveResearchItem: the 'bonus llama' specification must be a valid modifier as defined in /lib/services/bonusesService.c\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid names");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetBonusAttributes()
{
    ExpectEq(1, ResearchItem.addSpecification("bonus strength", 2), "set bonus strength to 2");
    ExpectEq(2, ResearchItem.query("bonus strength"), "can query the bonus");
    ExpectEq(2, ResearchItem.queryBonus("bonus strength"), "queryBonus returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetPenaltyAttributes()
{
    ExpectEq(1, ResearchItem.addSpecification("penalty to strength", 2), "set penalty to strength to 2");
    ExpectEq(-2, ResearchItem.query("bonus strength"), "querying the bonus applies the penalty");
    ExpectEq(-2, ResearchItem.queryBonus("bonus strength"), "queryBonus returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetBonusSkill()
{
    ExpectEq(1, ResearchItem.addSpecification("bonus long sword", 3), "set bonus long sword to 2");
    ExpectEq(3, ResearchItem.query("bonus long sword"), "can query the bonus");
    ExpectEq(3, ResearchItem.queryBonus("bonus long sword"), "queryBonus returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetPenaltyToSkill()
{
    ExpectEq(1, ResearchItem.addSpecification("penalty to long sword", 3), "set penalty to long sword to 2");
    ExpectEq(-3, ResearchItem.query("bonus long sword"), "querying the bonus applies the penalty");
    ExpectEq(-3, ResearchItem.queryBonus("bonus long sword"), "queryBonus returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void SetBonusAttackAddsExtraAttack()
{
    mapping *expectedAttacks = ({ (["attack type":"fire", "damage": 15, "to hit": 60]) });

    ExpectEq(1, ResearchItem.addSpecification("bonus fire attack", 15), "set bonus fire attack");
    ExpectEq(expectedAttacks, ResearchItem.getExtraAttacks(), "getExtraAttacks returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void SetBonusWeaponAttackAddsExtraAttack()
{
    mapping *expectedAttacks = ({ (["attack type":"weapon"]), (["attack type":"weapon"]) });

    ExpectEq(1, ResearchItem.addSpecification("bonus weapon attack", 2), "set bonus weapon attack");
    ExpectEq(expectedAttacks, ResearchItem.getExtraAttacks(), "getExtraAttacks returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMultipleBonusAttacks()
{
    mapping *expectedAttacks = ({ (["attack type":"fire", "damage": 15, "to hit": 60]), (["attack type":"weapon"]) });

    ExpectEq(1, ResearchItem.addSpecification("bonus fire attack", 15), "set bonus fire attack");
    ExpectEq(1, ResearchItem.addSpecification("bonus weapon attack", 1), "set bonus weapon attack");
    ExpectEq(expectedAttacks, ResearchItem.getExtraAttacks(), "getExtraAttacks returns the correct result");
}

/////////////////////////////////////////////////////////////////////////////
void CanAddEnchantments()
{
    ExpectTrue(ResearchItem.addSpecification("bonus fire enchantment", 3), "set bonus fire enchantment to 3");
    ExpectTrue(ResearchItem.addSpecification("bonus electricity enchantment", 5), "set bonus fire enchantment to 3");
    ExpectEq(3, ResearchItem.query("bonus fire enchantment"), "can query the bonus");
    ExpectEq(([ "fire": 3, "electricity": 5 ]), ResearchItem.query("enchantments"), "query enchantments returns the correct result");
}
