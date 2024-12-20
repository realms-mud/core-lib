//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing";

private int useResearch = 0;
private int useCooldown = 0;
private object researchObject = 0;
private string researchName = "";

/////////////////////////////////////////////////////////////////////////////
public void ToggleMockResearch()
{
    useResearch = !useResearch;
    this_object()->resetCaches();
}

/////////////////////////////////////////////////////////////////////////////
public void ToggleCooldown()
{
    useCooldown = !useCooldown;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int researchBonusTo(string bonus)
{
    int ret = useResearch * 2;
    if (researchObject && (member(({ "MaxHitPoints", "MaxSpellPoints",
        "MaxStaminaPoints" }), bonus) > -1))
    {
        ret -= researchObject->applySustainedCost(bonus);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *researchExtraAttacks()
{
    return useResearch ? ({ (["attack type":"weapon"]) }) : ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int researchAttributeBonus(string attribute)
{
    return useResearch * 2;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isResearched(string attribute)
{
    return useResearch;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int blockedByCooldown(string name)
{
    return useCooldown;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int deactivateSustainedResearch(string name)
{
    researchObject = 0;
    researchName = "";
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int activateSustainedResearch(object research, object modifier)
{
    researchObject = research;
    researchName = program_name(research);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int sustainedResearchIsActive(string name)
{
    return name == researchName;
}
