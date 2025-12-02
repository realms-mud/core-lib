//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

private int ritualPerformed;
private int applyMultiplier;

/////////////////////////////////////////////////////////////////////////////
public void TogglePerformRitual()
{
    ritualPerformed = !ritualPerformed;
}

/////////////////////////////////////////////////////////////////////////////
public void ToggleMultiplier()
{
    applyMultiplier = !applyMultiplier;
}

/////////////////////////////////////////////////////////////////////////////
public int performRitual(object initiator)
{
    return ritualPerformed;
}

/////////////////////////////////////////////////////////////////////////////
public int ritualMultiplier(string type, int value)
{
    return value * (1 + applyMultiplier);
}

/////////////////////////////////////////////////////////////////////////////
public int testAddSpecification(string type, mixed value)
{
    return instantaneousRitualResearchItem::addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public int testApplyBeneficialEffect(object initiator, object target)
{
    return instantaneousRitualResearchItem::applyBeneficialEffect(initiator, target);
}

/////////////////////////////////////////////////////////////////////////////
public int testApplyEffect(object initiator, object target)
{
    return instantaneousRitualResearchItem::applyEffect(initiator, target);
}
