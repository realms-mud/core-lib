//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("test element");
    addDescriptionTemplate("a test item");
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayBySeason(string season)
{
    limitDisplayBySeason(season);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByTimeOfDay(string timeOfDay)
{
    limitDisplayByTimeOfDay(timeOfDay);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByMoonPhase(string moonPhase)
{
    limitDisplayByMoonPhase(moonPhase);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByState(string state)
{
    limitDisplayByState(state);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByEquipment(string tool)
{
    limitDisplayByEquipment(tool);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByOneOfEquipment(string *tools)
{
    limitDisplayByOneOfEquipment(tools);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayBySkill(string skill, int value)
{
    limitDisplayBySkill(skill, value);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByAttribute(string attribute, int value)
{
    limitDisplayByAttribute(attribute, value);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByQuest(string quest)
{
    limitDisplayByQuest(quest);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByResearch(string research)
{
    limitDisplayByResearch(research);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByTrait(string trait)
{
    limitDisplayByTrait(trait);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByResearchThatIsActive(string research)
{
    limitDisplayByResearchThatIsActive(research);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByIntoxication(int value)
{
    limitDisplayByIntoxication(value);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByDrugEffect(int value)
{
    limitDisplayByDrugEffect(value);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByNearnessToDeath(int value)
{
    limitDisplayByNearnessToDeath(value);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayBySpellPointsDrained(int value)
{
    limitDisplayBySpellPointsDrained(value);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testLimitDisplayByStaminaDrained(int value)
{
    limitDisplayByStaminaDrained(value);
}
