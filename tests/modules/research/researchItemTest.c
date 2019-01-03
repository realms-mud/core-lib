//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object ResearchItem;
object Attacker;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchItem = clone_object("/lib/tests/support/research/testResearchItem");
    Attacker = clone_object("/lib/tests/support/services/combatWithMockServices");
    Attacker->Name("Earl");
    Attacker->Str(20);
    Attacker->Int(20);
    Attacker->Dex(20);
    Attacker->Con(20);
    Attacker->Wis(20);
    Attacker->Chr(20);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(ResearchItem);
    destruct(Attacker);
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetValidTypeFromResearchItemClass()
{
    string err = catch (ResearchItem->addSpecification("type", "active"));
    string expectedError = "*ERROR - researchItem: A 'active' type specification can only be used if 'activeResearchItem.c' is inherited.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting types");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetInvalidType()
{
    string err = catch (ResearchItem->addSpecification("type", "weasel"));
    string expectedError = "*ERROR - researchItem: The value of 'type' must be one of: active, passive, sustained, ritual, or knowledge.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid type");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetInvalidScope()
{
    string err = catch (ResearchItem->addSpecification("scope", "weasel"));
    string expectedError = "*ERROR - researchItem: The value of 'scope' must be one of: self, targeted, area, environmental, region, or global.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid scope");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetScopeToSelf()
{
    ExpectTrue(ResearchItem->addSpecification("scope", "self"), "set the research scope");
    ExpectEq("self", ResearchItem->query("scope"), "query the research scope");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetScopeToTargeted()
{
    ExpectTrue(ResearchItem->addSpecification("scope", "targeted"), "set the research scope");
    ExpectEq("targeted", ResearchItem->query("scope"), "query the research scope");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetScopeToArea()
{
    ExpectTrue(ResearchItem->addSpecification("scope", "area"), "set the research scope");
    ExpectEq("area", ResearchItem->query("scope"), "query the research scope");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetScopeToEnvironmental()
{
    ExpectTrue(ResearchItem->addSpecification("scope", "environmental"), "set the research scope");
    ExpectEq("environmental", ResearchItem->query("scope"), "query the research scope");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetScopeToRegion()
{
    ExpectTrue(ResearchItem->addSpecification("scope", "region"), "set the research scope");
    ExpectEq("region", ResearchItem->query("scope"), "query the research scope");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetScopeToGlobal()
{
    ExpectTrue(ResearchItem->addSpecification("scope", "global"), "set the research scope");
    ExpectEq("global", ResearchItem->query("scope"), "query the research scope");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetInvalidEffect()
{
    string err = catch (ResearchItem->addSpecification("effect", "weasel"));
    string expectedError = "*ERROR - researchItem: The value of 'effect' must be one of: beneficial, combat, enchantment, summoning, or strategic.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid effect");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetEffectToBeneficial()
{
    ExpectTrue(ResearchItem->addSpecification("effect", "beneficial"), "set the research effect");
    ExpectEq("beneficial", ResearchItem->query("effect"), "query the research effect");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetEffectToCombat()
{
    ExpectTrue(ResearchItem->addSpecification("effect", "combat"), "set the research effect");
    ExpectEq("combat", ResearchItem->query("effect"), "query the research effect");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetEffectToEnchantment()
{
    ExpectTrue(ResearchItem->addSpecification("effect", "enchantment"), "set the research effect");
    ExpectEq("enchantment", ResearchItem->query("effect"), "query the research effect");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetEffectToSummoning()
{
    ExpectTrue(ResearchItem->addSpecification("effect", "summoning"), "set the research effect");
    ExpectEq("summoning", ResearchItem->query("effect"), "query the research effect");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetEffectToStrategic()
{
    ExpectTrue(ResearchItem->addSpecification("effect", "strategic"), "set the research effect");
    ExpectEq("strategic", ResearchItem->query("effect"), "query the research effect");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetInvalidResearchType()
{
    string err = catch (ResearchItem->addSpecification("research type", "weasel"));
    string expectedError = "*ERROR - researchItem: The value of 'research type' must be one of: points, timed, or tree root.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid research type");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetResearchTypeToPoints()
{
    ExpectTrue(ResearchItem->addSpecification("research type", "points"), "set the research type");
    ExpectEq("points", ResearchItem->query("research type"), "query the research type");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetResearchTypeToTimed()
{
    ExpectTrue(ResearchItem->addSpecification("research type", "timed"), "set the research type");
    ExpectEq("timed", ResearchItem->query("research type"), "query the research type");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetResearchTypeToTreeRoot()
{
    ExpectTrue(ResearchItem->addSpecification("research type", "tree root"), "set the research type");
    ExpectEq("tree root", ResearchItem->query("research type"), "query the research type");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetResearchTypeToGranted()
{
    ExpectTrue(ResearchItem->addSpecification("research type", "granted"), "set the research type");
    ExpectEq("granted", ResearchItem->query("research type"), "query the research type");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetResearchCostNegative()
{
    string err = catch (ResearchItem->addSpecification("research cost", -2));
    string expectedError = "*ERROR - researchItem: The value of 'research cost' must be an integer value greater than 0.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid research type");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetResearchCostToZero()
{
    string err = catch (ResearchItem->addSpecification("research cost", 0));
    string expectedError = "*ERROR - researchItem: The value of 'research cost' must be an integer value greater than 0.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid research type");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetResearchCostToIntegerGreaterThanZero()
{
    ExpectTrue(ResearchItem->addSpecification("research cost", 1), "set the research cost");
    ExpectEq(1, ResearchItem->query("research cost"), "query the research cost");

    ExpectTrue(ResearchItem->addSpecification("research cost", 3), "set the research cost");
    ExpectEq(3, ResearchItem->query("research cost"), "query the research cost");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetSourceToNonString()
{
    string err = catch (ResearchItem->addSpecification("source", 0));
    string expectedError = "*ERROR - researchItem: The value of 'source' must be a string value.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid source");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetSourceToStringValue()
{
    ExpectTrue(ResearchItem->addSpecification("source", "mage guild"), "set the source");
    ExpectEq("mage guild", ResearchItem->query("source"), "query the source");

    ExpectTrue(ResearchItem->addSpecification("source", "save the llamas quest"), "set the source");
    ExpectEq("save the llamas quest", ResearchItem->query("source"), "query the source");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetPrerequisites()
{
    mapping prereqs = ([ "fetch a pencil": (["type":"quest"]),
        "guild": (["type":"guild", "value": ({ "test" }) ]),
        "race": (["type":"race", "value": ({ "elf", "high elf", "half elf" }) ])
    ]);

    ExpectTrue(mappingp(prereqs));
    ExpectTrue(ResearchItem->addSpecification("prerequisites", prereqs), "set the prereqs");
    ExpectEq("([ fetch a pencil: ([ type: quest, ]), guild: ([ type: guild, value: ({ test, }), ]), race: ([ type: race, value: ({ elf, half elf, high elf, }), ]), ])",
        ResearchItem->query("prerequisites"));
}
