//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object EffectModifier;
object User;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    EffectModifier = clone_object("/lib/tests/support/research/testEffectModifier");

    User = clone_object("/lib/tests/support/services/combatWithMockServices");
    User->Name("Bob");
    User->Str(20);
    User->Int(20);
    User->Dex(20);
    User->Con(20);
    User->Wis(20);
    User->Chr(20);
    User->hitPoints(User->maxHitPoints());
    User->spellPoints(User->maxSpellPoints());
    User->staminaPoints(User->maxStaminaPoints());
    User->addSkillPoints(200);
    User->advanceSkill("long sword", 16);
    User->SetLevel(10);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(EffectModifier);
}

/////////////////////////////////////////////////////////////////////////////
void IsValidModifierReturnsTrueForSkillModifier()
{
    mapping modifier = ([
        "type":"skill",
        "name": "long sword",
        "formula": "additive",
        "rate": 1.1
    ]);

    ExpectTrue(EffectModifier->testIsValidModifier(modifier));
}

/////////////////////////////////////////////////////////////////////////////
void IsValidModifierReturnsTrueForAttributeModifier()
{
    mapping modifier = ([
        "type":"attribute",
        "name": "strength",
        "formula": "subtractive",
        "rate": 0.25
    ]);

    ExpectTrue(EffectModifier->testIsValidModifier(modifier));
}

/////////////////////////////////////////////////////////////////////////////
void IsValidModifierReturnsFalseForInvalidModifier()
{
    mapping modifier = ([
        "type": "blarg",
        "name": "strength",
        "formula": "subtractive",
        "rate": 1.2
    ]);

    ExpectFalse(EffectModifier->testIsValidModifier(modifier));

    modifier["type"] = "attribute";
    ExpectTrue(EffectModifier->testIsValidModifier(modifier));
    modifier["formula"] = "blah";
    ExpectFalse(EffectModifier->testIsValidModifier(modifier));
}

/////////////////////////////////////////////////////////////////////////////
void IsValidModifierReturnsTrueForAttributeBonusModifier()
{
    mapping modifier = ([
        "type":"attribute bonus",
        "name": "strength",
        "formula": "logarithmic",
        "base value": 8,
        "rate": 1.2
    ]);

    ExpectTrue(EffectModifier->testIsValidModifier(modifier));
}

/////////////////////////////////////////////////////////////////////////////
void IsValidModifierReturnsTrueForSkillBonusModifier()
{
    mapping modifier = ([
        "type":"skill bonus",
        "name": "long sword",
        "formula": "multiplicative",
        "base value": 5,
        "rate": 1.2
    ]);

    ExpectTrue(EffectModifier->testIsValidModifier(modifier));
}

/////////////////////////////////////////////////////////////////////////////
void IsValidModifierReturnsTrueForLevelModifier()
{
    mapping modifier = ([
        "type":"level",
        "name": "mage",
        "formula": "subtractive",
        "base value": 5,
        "rate": 1.1
    ]);

    ExpectTrue(EffectModifier->testIsValidModifier(modifier));
}

/////////////////////////////////////////////////////////////////////////////
void IsValidModifierReturnsTrueForResearchModifier()
{
    mapping modifier = ([
        "type":"research",
        "research item": "stuff",
        "name": "blah",
        "formula": "subtractive",
        "base value": 5,
        "rate": 1.1
    ]);

    ExpectTrue(EffectModifier->testIsValidModifier(modifier));
}

/////////////////////////////////////////////////////////////////////////////
void IsValidModifierReturnsTrueForTraitModifier()
{
    mapping modifier = ([
        "type":"trait",
        "trait": "stuff",
        "name": "blah",
        "formula": "subtractive",
        "base value": 5,
        "rate": 1.1
    ]);

    ExpectTrue(EffectModifier->testIsValidModifier(modifier));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyModifiersCorrectlyAddsToSkill()
{
    mapping modifier = ([
        "type":"skill",
        "name": "long sword",
        "formula": "additive",
        "rate": 1.25
    ]);

    ExpectEq(20, EffectModifier->testApplyModifiers(0, User, ({ modifier })));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyModifiersCorrectlySubtractsFromAttribute()
{
    mapping modifier = ([
        "type":"attribute",
        "name": "wisdom",
        "formula": "subtractive",
        "rate": 0.25
    ]);

    ExpectEq(15, EffectModifier->testApplyModifiers(0, User, ({ modifier })));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyModifiersCorrectlyMultipliesToSkillBonus()
{
    mapping modifier = ([
        "type":"skill bonus",
        "name": "long sword",
        "formula": "multiplicative",
        "rate": 1.5
    ]);

    ExpectEq(9, User->getSkillModifier("long sword"));
    ExpectEq(13, EffectModifier->testApplyModifiers(1, User, ({ modifier })));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyModifiersCorrectlyAppliesLogToAttributeBonus()
{
    mapping modifier = ([
        "type":"attribute bonus",
        "name": "dexterity",
        "formula": "logarithmic",
        "rate": 1.6
    ]);

    ExpectEq(3, EffectModifier->testApplyModifiers(1, User, ({ modifier })));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyModifiersCorrectlyAppliesBaseValues()
{
    mapping modifier = ([
        "type":"attribute",
        "name": "dexterity",
        "formula": "additive",
        "base value": 10,
        "rate": 1.6
    ]);

    ExpectEq(16, EffectModifier->testApplyModifiers(1, User, ({ modifier })));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyModifiersCorrectlyAppliesLevelModifier()
{
    mapping modifier = ([
        "type":"level",
        "name": "mage",
        "formula": "additive",
        "rate": 1.2
    ]);

    User->ToggleMockGuilds();
    User->SetGuild("mage");
    ExpectEq(12, EffectModifier->testApplyModifiers(1, User, ({ modifier })));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyModifiersCorrectlyAppliesResearchModifier()
{
    mapping modifier = ([
        "type":"research",
        "name": "blah",
        "research item": "test",
        "formula": "additive",
        "base value": 10,
        "rate": 1.5
    ]);

    User->ToggleMockResearch();
    ExpectEq(15, EffectModifier->testApplyModifiers(0, User, ({ modifier })));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyModifiersCorrectlyAppliesTraitModifier()
{
    mapping modifier = ([
        "type":"trait",
        "name": "blah",
        "trait": "test",
        "formula": "additive",
        "base value": 10,
        "rate": 1.5
    ]);

    User->addTrait("test");
    User->ToggleMockTrait();
    ExpectEq(15, EffectModifier->testApplyModifiers(0, User, ({ modifier })));
}
/////////////////////////////////////////////////////////////////////////////
void ApplyModifiersAppliesSpecialModifier()
{
    mapping modifier = ([
        "type":"skill",
        "name": "long sword",
        "formula": "additive",
        "rate": 1.25
    ]);

    ExpectEq(20, EffectModifier->testApplyModifiers(0, User, ({ modifier })));
    EffectModifier->ToggleSpecialModifier();
    ExpectEq(40, EffectModifier->testApplyModifiers(0, User, ({ modifier })));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyModifiersCorrectlyAddsMultipleModifiers()
{
    mapping *modifiers = ({ ([
        "type":"skill",
        "name": "long sword",
        "formula": "additive",
        "rate": 1.25
    ]),
    ([
        "type":"attribute",
        "name": "strength",
        "formula": "subtractive",
        "rate": 0.25
    ]) });

    ExpectEq(35, EffectModifier->testApplyModifiers(0, User, modifiers));
}

